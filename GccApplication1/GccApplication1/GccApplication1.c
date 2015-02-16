/*
 * GccApplication1.c
 *
 * Created: 1/26/2013 1:54:15 AM
 *  Author: Robert
 */ 


#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    while(1)
    {
		PORTC = 1 << (~PINA & 0x0F);
        //TODO:: Please write your application code 
    }
}