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

#include <avr/io.h>
#include <avr/delay.h>
#include <ucr/timer.h>

int main(void)
{
	
	unsigned short i;
	unsigned short j;
	unsigned short time_to_off = 0;
	
	SFIOR = SFIOR | (1 << PUD); //Pull-up disable
	DDRA = 0xFF; PORTA = 0x00;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	DDRD = 0xFF; PORTD = 0x00; //LED Anodes low
	
	//init Analog-to-digital conversion
	ADMUX |= 1 << REFS0;
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); //enable, prescalar 64. 8,000,000 / 64 = 125,000
	
	
	//start
	while(1)
	{
		PORTD = 0;
		PORTC = ~0;
		PORTA = ~1;
		PORTD = 0x83; //light
		
		PORTD = 0x82; //reverse-bias
		PORTA = 0xFF;
		
		//input
		DDRA = ~1;
		_delay_ms(100);
		
		ADCSRA |= 1 << ADSC; // start analog read
		//224
		//141
		while(!(ADCSRA & (1<<ADIF))); //poll until ready
		
		ADCSRA|=(1<<ADIF); // clear by writing 1
		PORTD = 0;
		DDRA = 0xFF;
		j = 0;
		unsigned char tmp = 225 - ADC;
		for( i = 0; i < 10; ++i)
			j |= (tmp > 10*i) << i;
		PORTC = ~j;//~(0xFF >> (7 - (ADC >> 7)));//~ADC >> 2;
		PORTA = 0xFF;
		PORTD = 0x80;
		
		//for(i = 0; i < 1000; ++i)
			_delay_ms(1);
		PORTC = 0xFF;
		//for(i = 0; i < 250; ++i)
			//_delay_ms(1);
		
		
		
		
		//for(i = 0; i < 0x0FFF; ++i)
		//if(PINC & 2)
		//++time_to_off;
		//time_to_off >>= 10;
		//for(i = 0; i < 0x0FFF; ++i)
		//PORTA = (i & time_to_off) == 0;
		//PORTA = 0;//time_to_off ==0;//(0x0FFF >> 9);
		//time_to_off = 0;
	}
    /*while(1)
    {
		time_to_off = 0;
		DDRB = 0xFF; // B is output
		//PORTD = 1; PORTB = 0; //light
		//_delay_ms(1);
		PORTD = 0; PORTB = 1; //reverse-bias LED 0
		//_delay_ms(1);
		//_delay_us(10);
		//PORTB = 0;
		DDRB = 0x00; // B is input now
		PORTB = 0;
		//_delay_ms(100);
		for(i = 0; i < 0x7FFF; ++i)
			if(PINB & 1 && time_to_off % 0x0FFF != 0xFFFF)
				++time_to_off;
		time_to_off >>= 12;
		//time_to_off = ~time_to_off;
		//_delay_ms(1);
		for(i = 0; i < 0x7FFF; ++i)
			PORTA = (i % (time_to_off+1)) == 0;
		//for(i = 0; i < time_to_off; ++i)
		//_delay_ms(1);
		//PORTA = time_to_off < 5000;
		//for(i = 0; i < time_to_off; ++i)
		//	_delay_ms(0.01);
        //TODO:: Please write your application code 
    }*/
	while(1)
	{
		DDRC = 0xFF;
		PORTC = 1; //light
		PORTC = 2; //reverse-bias
		DDRC = ~2;
		for(i = 0; i < 0x0FFF; ++i)
			if(PINC & 2)
				++time_to_off;
	    time_to_off >>= 10;
		for(i = 0; i < 0x0FFF; ++i)
			PORTA = (i & time_to_off) == 0;
		PORTA = 0;//time_to_off ==0;//(0x0FFF >> 9);
		time_to_off = 0;
		
		
	}
}