#include <avr/io.h>
#include <avr/interrupt.h>
#include <ucr/bit.h>
#include <ucr/timer.h>
//********* LCD interface synchSM *********************************************
// Define LCD port assignments here so easier to change than if hardcoded below
unsigned char *LCD_Data = &PORTD; // LCD 8-bit data bus
unsigned char *LCD_Ctrl = &PORTB; // LCD needs 2-bits for control, use port B
const unsigned char LCD_RS = 3; // LCD Reset pin is PB3
const unsigned char LCD_E = 4; // LCD Enable pin is PB4
unsigned char LCD_rdy_g = 0; // Set by LCD interface synchSM, ready to display new string
unsigned char LCD_go_g = 0; // Set by user synchSM wishing to display string in LCD_string_g
unsigned char LCD_string_g[17]; // Filled by user synchSM, 16 chars plus end-of-string char
void LCD_WriteCmdStart(unsigned char cmd) {
	*LCD_Ctrl = SetBit(*LCD_Ctrl,LCD_RS, 0);
	*LCD_Data = cmd;
	*LCD_Ctrl = SetBit(*LCD_Ctrl,LCD_E, 1);
}
void LCD_WriteCmdEnd() {
	*LCD_Ctrl = SetBit(*LCD_Ctrl,LCD_E, 0);
}
void LCD_WriteDataStart(unsigned char Data) {
	*LCD_Ctrl = SetBit(*LCD_Ctrl,LCD_RS,1);
	*LCD_Data = Data;
	*LCD_Ctrl = SetBit(*LCD_Ctrl,LCD_E, 1);
}
void LCD_WriteDataEnd() {
	*LCD_Ctrl = SetBit(*LCD_Ctrl,LCD_E, 0);
}
void LCD_Cursor(unsigned char column ) {
	if ( column < 16 ) { // IEEE change this value to 16, was 8
	LCD_WriteCmdStart(0x80+column);
}
else {
	LCD_WriteCmdStart(0xBF+column); // IEEE change this value to 0xBF+column // was B8
}
}
enum LI_States { LI_Init1, LI_Init2, LI_Init3, LI_Init4, LI_Init5, LI_Init6,
		LI_WaitDisplayString, LI_Clr, LI_PositionCursor, LI_DisplayChar, LI_WaitGo0 } LI_State;
void LI_Tick() {
	static unsigned char i;
	switch(LI_State) { // Transitions
	case -1:
		LI_State = LI_Init1;
		break;
	case LI_Init1:
		LI_State = LI_Init2;
		i=0;
		break;
	case LI_Init2:
		if (i<10) { // Wait 100 ms after power up
			LI_State = LI_Init2;
		}
		else {
			LI_State = LI_Init3;
		}
		break;
	case LI_Init3:
		LI_State = LI_Init4;
		LCD_WriteCmdEnd();
		break;
	case LI_Init4:
		LI_State = LI_Init5;
		LCD_WriteCmdEnd();
		break;
	case LI_Init5:
		LI_State = LI_Init6;
		LCD_WriteCmdEnd();
		break;
	case LI_Init6:
		LI_State = LI_WaitDisplayString;
		LCD_WriteCmdEnd();
		break;
	//////////////////////////////////////////////
	case LI_WaitDisplayString:
		if (!LCD_go_g) {
			LI_State = LI_WaitDisplayString;
		}
		else if (LCD_go_g) {
			LCD_rdy_g = 0;
			LI_State = LI_Clr;
		}
		break;
	case LI_Clr:
		LI_State = LI_PositionCursor;
		LCD_WriteCmdEnd();
		i=0;
		break;
	case LI_PositionCursor:
		LI_State = LI_DisplayChar;
		LCD_WriteCmdEnd();
		break;
	case LI_DisplayChar:
		if (i<16) {
			LI_State = LI_PositionCursor;
			LCD_WriteDataEnd();
			i++;
		}
		else {
			LI_State = LI_WaitGo0;
			LCD_WriteDataEnd();
		}
		break;
	case LI_WaitGo0:
		if (!LCD_go_g) {
			LI_State = LI_WaitDisplayString;
		}
		else if (LCD_go_g) {
			LI_State = LI_WaitGo0;
		}
		break;
	default:
		LI_State = LI_Init1;
	} // Transitions
	
	switch(LI_State) { // State actions
	case LI_Init1:
		LCD_rdy_g = 0;
		break;
	case LI_Init2:
		i++; // Waiting after power up
		break;
	case LI_Init3:
		LCD_WriteCmdStart(0x38);
		break;
	case LI_Init4:
		LCD_WriteCmdStart(0x06);
		break;
	case LI_Init5:
		LCD_WriteCmdStart(0x0F);
		break;
	case LI_Init6:
		LCD_WriteCmdStart(0x01); // Clear
		break;
	//////////////////////////////////////////////
	case LI_WaitDisplayString:
		LCD_rdy_g = 1;
		break;
	case LI_Clr:
		LCD_WriteCmdStart(0x01);
		break;
	case LI_PositionCursor:
		LCD_Cursor(i);
		break;
	case LI_DisplayChar:
		LCD_WriteDataStart(LCD_string_g[i]);
		break;
	case LI_WaitGo0:
		break;
	default:
		break;
	} // State actions
}
	//--------END LCD interface synchSM------------------------------------------------
	// SynchSM for testing the LCD interface -- waits for button press, fills LCD with repeated random num
enum LT_States { LT_s0, LT_WaitLcdRdy, LT_WaitButton, LT_FillAndDispString,
				LT_HoldGo1, LT_WaitBtnRelease } LT_State;
void LT_Tick() {
	static unsigned short j;
	static unsigned char i, x, c;
	switch(LT_State) { // Transitions
	case -1:
		LT_State = LT_s0;
		break;
	case LT_s0:
		LT_State = LT_WaitLcdRdy;
		break;
	case LT_WaitLcdRdy:
		if (!LCD_rdy_g) {
			LT_State = LT_WaitLcdRdy;
		}
		else if (LCD_rdy_g) {
			LT_State = LT_WaitButton;
		}
		break;
	case LT_WaitButton:
		if (GetBit(PINA,0)==1) {
			LT_State = LT_WaitButton;
		}
		else if (GetBit(PINA,0)==0) { // Button active low
			LT_State = LT_FillAndDispString;
		}
		break;
	case LT_FillAndDispString:
		LT_State = LT_HoldGo1;
		break;
	case LT_HoldGo1:
		LCD_go_g=0;
		LT_State = LT_WaitBtnRelease;
		break;
	case LT_WaitBtnRelease:
		if (GetBit(PINA,0)==0) { // Wait for button release
			LT_State = LT_WaitBtnRelease;
		}
		else if (GetBit(PINA,0)==1) {
			LT_State = LT_WaitLcdRdy;
		}
		break;
	default:
		LT_State = LT_s0;
	} // Transitions
	
	switch(LT_State) { // State actions
	case LT_s0:
		LCD_go_g=0;
		strcpy(LCD_string_g, "1234567890123456"); // Init, but never seen, shows use of strcpy though
		break;
	case LT_WaitLcdRdy:
		break;
	case LT_WaitButton:
		break;
	case LT_FillAndDispString:
		x = rand() % 10; // x is rand num 0-9
		c = (char)(((int)'0')+x); // c is ascii of num x
		for (i=0; i<16; i++) { // Fill string with c
			LCD_string_g[i] = c;
		}
		LCD_string_g[i] = '\0'; // End-of-string char
		LCD_go_g = 1; // Display string
		break;
	case LT_HoldGo1:
		break;
	case LT_WaitBtnRelease:
		break;
	default:
		break;
	} // State actions
}
int main() {
	DDRB = 0xFF; // Set port B to output
	DDRD = 0xFF; // Set port D to output
	DDRA = 0x00; PORTA = 0xFF;
	TimerSet(10);
	TimerOn();
	LI_State = -1;
	LT_State = -1;
	while(1) {
		LI_Tick();
		LT_Tick();
		while (!TimerFlag);
			TimerFlag = 0;
	}
}
