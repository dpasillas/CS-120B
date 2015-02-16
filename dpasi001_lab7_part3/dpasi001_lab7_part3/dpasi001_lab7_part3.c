/* dpasi001_labx_party.c - Feb 7, 2013
 * Name & E-mail: Daniel Pasillas - dpasi001@ucr.edu
 * CS Login: dpasi001
 * Partner(s) Name & E-mail: Willy Yong - wyong001@ucr.edu
 * Lab Section: 23
 * Assignment: Lab # 7  Exercise # 3
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
	OCR0 = 25;	// Timer interrupt will be generated when TCNT0==OCR0
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

enum {INIT = -1};
enum {L0, L1, L2} l_state;
enum {B0, B1} b_state;

unsigned char led_states;
	
void LED_TICK()
{
	//transitions
	switch(l_state)
	{
	case INIT:
	    l_state = L0;
		break;
	case L0:
	    l_state = L1;
		break;
	case L1:
	    l_state = L2;
		break;
	case L2:
	    l_state = L0;
		break;
	default:
	    l_state = L0;
	}
	
	//
	switch(l_state)
	{
	case L0:
	    led_states = 0x01;
		break;
	case L1:
	    led_states = 0x02;
		break;
	case L2:
	    led_states = 0x04;
		break;
    default:
	    break; //this line should never be reached!
	}
}

unsigned char blink_state = 0;

void BLINK_TICK()
{
	switch(b_state)
	{
	case INIT: b_state = B0; break;
	case B0: b_state = B1; break;
	case B1: b_state = B0;
	default: break; 
	}
	
	switch(b_state)
	{
	case B0: blink_state = 0x00; break;
	case B1: blink_state = 0x08; break;
	default: break;
	}
}

unsigned char sound_state = 0;
void SOUND_TICK()
{
	if(~PINA & 4)
	    sound_state ^= 0x10;
}
#define TICKS_PER_MS 5

unsigned short gcd(unsigned short a, unsigned short b)
{
	if(b == 0)
	    return a;
	else
	    return gcd(b, a % b);
}
void main()
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0xFF;
	
	TimerSet(1 * TICKS_PER_MS);
	TimerOn();
	
	unsigned short lp = 300, bp = 1000, lt = lp, bt = bp,
	               sp = 2, st = sp;
	
	while(1) {
		if(lt >= lp)
		{
            LED_TICK(); lt = 0;
		}
		if(bt >= bp)
		{
			BLINK_TICK(); bt = 0;
		}
		if(st >= sp)
		{
		    SOUND_TICK(); st = 0;
		}		
		bt += 1;
		lt += 1;
		st += 1;
		PORTB = led_states | blink_state | sound_state;
		
        while (!TimerFlag);	// Wait 1 sec
		TimerFlag = 0;
	}
}