/* dpasi001_labx_party.c - Feb 5, 2013
 * Name & E-mail: Daniel Pasillas - dpasi001@ucr.edu
 * CS Login: dpasi001
 * Partner(s) Name & E-mail: Brendon Parker - dpark007@ucr.edu
 * Lab Section: 23
 * Assignment: Lab # 6  Exercise # 2
 * Exercise Description:
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */


#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char TimerFlag = 0; // TimerISR() sets this to 1. C programmer should clear to 0.

// Internal variables for mapping AVR's ISR to our cleaner TimerISR model.
unsigned long _avr_timer_M = 1; // Start count from here, down to 0. Default 1 ms.
unsigned long _avr_timer_cntcurr = 0; // Current internal count of 1ms ticks

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
	_avr_timer_cntcurr--; // Count down to 0 rather than up to TOP
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

void Write7Seg(unsigned char x) {
	static const unsigned char Seg7[16] = {0x7E, 0x48, //0111 1110, 0100 1000, //0, 1
	0x3D, 0x6D, //0011 1101, 0110 1101, //2, 3
	0x4B, 0x67, //0100 1011, 0110 0111, //4, 5
	0x77, 0x4C, //0111 0111, 0100 1100, //6, 7
	0x7F, 0x6F, //0111 1111, 0111 1111, //8, 9
	0x5F, 0x73, //0101 1111, 0111 0011, //A, B
	0x36, 0x79, //0111 0110, 0111 1001, //C, D
0x37, 0x17};//0011 0111, 0001 0111};//E, F
PORTC = ~Seg7[x%16];
}

enum {INIT, WAITING, UP, DOWN, BOTH} state;
unsigned char val, tick;
	
SM_Tick(unsigned char input)
{
	//transitions
	switch(state)
	{
	case INIT:
	    state = WAITING;
		break;
	case WAITING:
	    //state = UP;
		switch(input)
		{
	    case 0: state = WAITING; break;
		case 1: state = UP; break;
		case 2: state = DOWN; break;
		case 3: state = BOTH; break;
		default: break;
		}
		break;
	case UP:
	    switch(input)
	    {
		    case 0: state = WAITING; break;
		    case 1: state = UP; break;
		    case 2: state = DOWN; tick = 0; break;
		    case 3: state = BOTH; tick = 0; break;
		    default: break;
	    }
		break;
	case DOWN:
	    switch(input)
	    {
		    case 0: state = WAITING; break;
		    case 1: state = UP; tick = 0; break;
		    case 2: state = DOWN; break;
		    case 3: state = BOTH; tick = 0; break;
		    default: break;
	    }
		break;
	default:
	    if(input == 0)
		    state = WAITING;
	}
	
	//
	switch(state)
	{
	case WAITING:
	    //val = 0;
		tick = 0;
		break;
	case UP:
	    if((tick % 50) == 0 && val < 9)
		    ++val;
	    tick++;
		break;
	case DOWN:
	    if(tick % 50 == 0 && val > 0)
	        --val;
		tick++;
		break;
	case BOTH:
	    val = 0;
    default:
	    break; //this line should never be reached!
	}
	Write7Seg(val);
}

void main()
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; // Set port B to output
	PORTB = 0x00; // Init port B to 0s
	DDRC = 0xFF; PORTC = 0x00;
	TimerSet(20);
	TimerOn();
	unsigned char B = 0x00;
	
	state = INIT;
	Write7Seg(0);
	while(1) {
		// User code
		SM_Tick(~PINA & 0x03);
		//Write7Seg(7);
		//PORTB = ~PORTB;	// Toggle PORTB; Temporary, bad programming style
		while (!TimerFlag);	// Wait 1 sec
		TimerFlag = 0;
		// Note: For the above a better style would use a synchSM with TickSM()
		// This example just illustrates the use of the ISR and flag
	}
}