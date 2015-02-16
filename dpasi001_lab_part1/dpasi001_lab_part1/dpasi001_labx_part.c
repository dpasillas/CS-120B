/* dpasi001_lab8_part2.c - [DATE]
 * Name & E-mail: Daniel Pasillas - dpasi001@ucr.edu
 * CS Login: dpasi001
 * Partner(s) Name & E-mail: [NAME] - [E-MAIL]
 * Lab Section: 23
 * Assignment: Lab # x  Exercise # y
 * Exercise Description:
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <ucr/bit.h>
//#include <ucr/timer.h>
// Returns '\0' if no key pressed, else returns char '1', '2', ... '9', 'A', ...
// If multiple keys pressed, returns leftmost-topmost one
// Keypad must be connected to port C
/* Keypad arrangement
PC4 PC5 PC6 PC7
col 1 2 3 4
row
PC0 1 1 | 2 | 3 | A
PC1 2 4 | 5 | 6 | B
PC2 3 7 | 8 | 9 | C
PC3 4 * | 0 | # | D
*/

typedef unsigned char uchar;

volatile unsigned char TimerFlag = 0; // TimerISR() sets this to 1. C programmer should clear to 0.

// Internal variables for mapping AVR's ISR to our cleaner TimerISR model.
unsigned long _avr_timer_M = 1; // Start count from here, down to 0. Default 1 ms.
unsigned long _avr_timer_cntcurr = 0; // Current internal count of 1ms ticks

volatile unsigned short lp = 300, bp = 1000, lt = 300, bt = 1000,
sp = 2, st = 2;

void TimerOn() {
	// AVR timer/counter controller register TCCR0
	TCCR0 = 0x0B;	// bit3bit6=10: CTC mode (clear timer on compare)
	// bit2bit1bit0=011: pre-scaler /64
	// 00001011: 0x0B
	// SO, 8 MHz clock or 8,000,000 /64 = 125,000 ticks/s
	// Thus, TCNT0 register will count at 125,000 ticks/s

	// AVR output compare register OCR0.
	OCR0 = 125;	// Timer interrupt will be generated when TCNT0==OCR0
	// We want a 1 ms tick. 0.001 s * 125,000 ticks/s = 125
	// So when TCNT0 register equals 125,
	// 1 ms has passed. Thus, we compare to 125.
	// AVR timer interrupt mask register
	TIMSK = 0x02; // bit1: OCIE0 -- enables compare match interrupt

	//Initialize avr counter
	TCNT0=0;

	_avr_timer_cntcurr = _avr_timer_M;
	// TimerISR will be called every _avr_timer_cntcurr milliseconds

	//Enable global interrupts
	SREG |= 0x80; // 0x80: 1000000
}

void TimerOff() {
	TCCR0 = 0x00; // bit2bit1bit0=000: timer off
}

void TimerISR() {
	TimerFlag = 1;
}

// In our approach, the C programmer does not touch this ISR, but rather TimerISR()
ISR(TIMER0_COMP_vect) {
	// CPU automatically calls when TCNT0 == OCR0 (every 1 ms per TimerOn settings)
	--_avr_timer_cntcurr; // Count down to 0 rather than up to TOP
	if (_avr_timer_cntcurr == 0) { // results in a more efficient compare
	TimerISR(); // Call the ISR that the user uses
	_avr_timer_cntcurr = _avr_timer_M;
}
}

// Set TimerISR() to tick every M ms
void TimerSet(unsigned long M) {
	_avr_timer_M = M;
	_avr_timer_cntcurr = _avr_timer_M;
}


unsigned char GetKeypadKey() {
	PORTC = 0xEF; // Enable col 4 with 0, disable others with 1’s
	//1110 1111
	asm("nop"); // add a delay to allow PORTC to stabilize before checking
	if (GetBit(PINC,0)==0) { return('1'); }
	if (GetBit(PINC,1)==0) { return('4'); }
	if (GetBit(PINC,2)==0) { return('7'); }
	if (GetBit(PINC,3)==0) { return('*'); }
	// Check keys in col 2
	PORTC = 0xDF; // Enable col 5 with 0, disable others with 1’s
	//1101 1111
	asm("nop"); // add a delay to allow PORTC to stabilize before checking
	if (GetBit(PINC,0)==0) { return('2'); }
	if (GetBit(PINC,1)==0) { return('5'); }
	if (GetBit(PINC,2)==0) { return('8'); }
	if (GetBit(PINC,3)==0) { return('0'); }
	// ... *****FINISH*****
	// Check keys in col 3
	PORTC = 0xBF; // Enable col 6 with 0, disable others with 1’s
	//1011 1111
	asm("nop"); // add a delay to allow PORTC to stabilize before checking
	if (GetBit(PINC,0)==0) { return('3'); }
	if (GetBit(PINC,1)==0) { return('6'); }
	if (GetBit(PINC,2)==0) { return('9'); }
	if (GetBit(PINC,3)==0) { return('#'); }
	// ... *****FINISH*****
	PORTC = 0x7F;
	//0111 1111
	asm("nop");
	if (GetBit(PINC,0)==0) { return('A'); }
	if (GetBit(PINC,1)==0) { return('B'); }
	if (GetBit(PINC,2)==0) { return('C'); }
	if (GetBit(PINC,3)==0) { return('D'); }
	// Check keys in col 4
	// ... *****FINISH*****
	return('\0'); // default value
}

uchar key = 0;

uchar keyTick(uchar state)
{
	key = GetKeypadKey();
	return 0;
}

//LCD CODE//
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
uchar LI_Tick(uchar LI_State) {
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
	return LI_State;
}
	//--------END LCD interface synchSM------------------------------------------------
	// SynchSM for testing the LCD interface -- waits for button press, fills LCD with repeated random num
enum LT_States { LT_s0, LT_WaitLcdRdy, LT_WaitButton, LT_FillAndDispString,
				LT_HoldGo1, LT_WaitBtnRelease } LT_State;
uchar LT_Tick(uchar LT_State) {
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
		if (!key){//GetBit(PINA,0)==1) {
			LT_State = LT_WaitButton;
		}
		else if (key){//GetBit(PINA,0)==0) { // Button active low
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
		if (key){//GetBit(PINA,0)==0) { // Wait for button release
			LT_State = LT_WaitBtnRelease;
		}
		else if (!key){//GetBit(PINA,0)==1) {
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
		c = key;//(char)(((int)'0')+x); // c is ascii of num x
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
	return LT_State;
}
//LCD CODE//

unsigned long int findGCD(unsigned long int a, unsigned long int b)
{
	unsigned long int c;
	while(1){
		c = a%b;
	if(c==0){return b;}
	a = b;
	b = c;
}
return 0;
}
//--------End find GCD function ----------------------------------------------
//--------Task scheduler data structure---------------------------------------
// Struct for Tasks represent a running process in our simple real-time operating system.
typedef struct _task {
/*Tasks should have members that include: state, period,
a measurement of elapsed time, and a function pointer.*/
	signed char state; //Task's current state
	unsigned long period; //Task period
	unsigned long elapsedTime; //Time elapsed since last task tick
	uchar (*TickFct)(uchar); //Task tick function
} task;

void taskInit(task *t, unsigned long period, uchar(*fptr)(uchar))
{
	t->state = -1;
	t->period = period;
	t->elapsedTime = period;
	t->TickFct = fptr;
}

task task1, task2, task3;
task* tasks[] = {&task1,&task2,&task3};
const unsigned char numTasks = sizeof(tasks) / sizeof(task*);

int main(void)
{
	taskInit(tasks[0],100,keyTick);
	taskInit(tasks[1],100,LI_Tick);
	taskInit(tasks[2],100,LT_Tick);
	
	unsigned long period = 100;
	DDRB = 0xFF; PORTB = 0x00; // PORTB set to output, outputs init 0s
	DDRC = 0xF0; PORTC = 0x0F; // PC7..4 outputs init 0s, PC3..0 inputs init 1s
	
	DDRD = 0xFF; // Set port D to output
	DDRA = 0x00; PORTA = 0xFF;
	
	TimerSet(period);
	TimerOn();
	
	while(1) {
		for(int i = 0; i < numTasks; ++i)
		{
			if(tasks[i]->elapsedTime >= tasks[i]->period)
			{
				tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
				tasks[i]->elapsedTime = 0;
			}
			tasks[i]->elapsedTime += period;
		}
		while(!TimerFlag);
		TimerFlag = 0;
	}
}
