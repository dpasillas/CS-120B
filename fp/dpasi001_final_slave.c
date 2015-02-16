/* dpasi001_labx_party.c - [DATE]
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

#define F_CPU 8000000UL
#define INTS_PER_MS 125
#define TICKS_PER_MS 125
//This yields 8,000,000 / 64 == 125,000 ticks per second.

#define SLAVE

#include <avr/io.h>
#include <ucr/timer.h>
const unsigned char prescaler = PRESCALER_64;

#include <dpasi001_tone.h>

int main(void)
{
	DDRA = 0xFF; PORTA = 0x00; //output
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0x00; PORTC = 0xFF;
	
	//k[K_FSH_2] = 79;
	//k[K_GSH_2] = 601;
	
	TimerSet(1);
	TimerOn();
	
	PORTB = (k[K_GSH_2] > k[FSH_2]);
	unsigned short tick = 0;
	unsigned char sample = 0;
	unsigned char out = 0;
	unsigned char state = 0;
    while(1)
    {
		sample = PINC;
		if(sample)
		{
			if(++tick >= k[sample])
				tick = 0, state ^= 1, PORTA = state;
		}
		while(!TimerFlag){}
		TimerFlag = 0;
        //TODO:: Please write your application code 
    }
}