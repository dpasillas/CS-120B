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

typedef unsigned char uchar;

#include <avr/io.h>

#define F_CPU 8000000UL

#include <util/delay.h>

void SPI_Setup()
{
	/* Set MOSI and SCK output, all others input */
	DDRB = 0xFF;//(1<<5)|(1<<7);
	/* Enable SPI, Master, set clock rate fck/16 */
	/* Enable SPI, Master, 2x clock rate, Data order*/
	SPCR = (1<<SPE) | (1<<MSTR) | (1 << SPI2X) /*|(1<<SPR0)*/ /*| (1 << DORD)*/;
}

void SPI_MasterTransmit(char cData)
{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
}

void LED_RowTransmit(uchar r, uchar g, uchar b, uchar com)
{
	PORTB &= ~2; //Master Reset on
	PORTB |= 2;
	PORTB |= 1;  //MR off, Latch on
	PORTB &= ~1;  //Latch off
	SPI_MasterTransmit(com);
	SPI_MasterTransmit(~g);
	SPI_MasterTransmit(~b);
	PORTA = ~r;
	PORTB |= 1;
	PORTB &= ~1;
}

void ADC_Setup()
{
	SFIOR |= /*(1 << PUD) |*/ (1 << ACME); //Pull-up disable, Analog Converter Multiplexer enable
	
	ADMUX = 0;//(1 << REFS0);// | (1 << ADLAR);
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) /*| (1 << ADPS0)*/; //enable, prescalar 64. 8,000,000 / 64 = 125,000
}

unsigned short analogRead(unsigned char channel)
{
	unsigned char chan = (channel & 0b00000111);
	ADMUX = (ADMUX & ~7) | chan;
	ADCSRA &= ~(1 << ADEN);
	ADCSRA |= (1<<ADEN);
	ADCSRA |= 1 << ADSC; // start analog read
	
	//224
	//141
	while(!(ADCSRA & (1<<ADIF))); //poll until ready
	//DDRA |= chan;
	return ADC;
}

int main(void)
{
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0x00; PORTC = 0xFF;
	SPI_Setup();
	ADC_Setup();
	volatile unsigned short tmp = 0;
	unsigned short tmp2 = 0;
	unsigned short diff = 0, diff2 = 0;
	unsigned char index = 0;
	unsigned short diffs[8][8] = {{0}};
	unsigned short diffs2[8][8] = {{0}};
	tmp = analogRead(0);
	tmp = analogRead(1);
	tmp = analogRead(2);
	tmp = analogRead(3);
	tmp = analogRead(4);
	tmp = analogRead(5);
	tmp = analogRead(6);
	tmp = analogRead(7);
	
	DDRA = 0xFF;
	PORTA = 0xFF;
	
	DDRA = 0x00;
	PORTA = 0x00;
	LED_RowTransmit(0,4,4,4); //light
	tmp = analogRead(2);
	LED_RowTransmit(0,4,4,4); //light
	tmp = analogRead(2);
	
	while(1)
	{
		DDRA = 0;
		PORTA = 0;
		tmp = analogRead(0);
		PORTA = 0xFF;
		DDRA = 0xFF;
		LED_RowTransmit(0,tmp >> 8, tmp, 0x80);
	}
	
    while(1)
	{
		for(char c = 0; c < 8; ++c)
		for(char r = 0; r < 8; ++r)
		diffs[r][c] = 0;
		
		for(unsigned char col = 0; col < 8; ++col)
		for(unsigned char row =7; row < 8; --row)
		{
		LED_RowTransmit(0,(1 << col),(1 << col) ,(1 << row));
		tmp = analogRead(col);
		tmp = analogRead(col);
		diffs[row][col] = tmp;
		LED_RowTransmit(0,tmp >> 8, tmp, 0x80);
		_delay_ms(1);
		}
		for(char i = 0; i < 100; ++i)
		{
			_delay_ms(20);	
		}
		while(1)
		{
			
			if(~PINC & 1)
			{
				for(char c = 0; c < 8; ++c)
				for(char r = 0; r < 8; ++r)
				diffs[r][c] = 0;
				
				for(unsigned char col = 0; col < 8; ++col)
				for(unsigned char row =7; row < 8; --row)
				{
					LED_RowTransmit(0,(1 << col),(1 << col) ,(1 << row));
					tmp = analogRead(col);
					tmp = analogRead(col);
					diffs[row][col] = tmp;
					//LED_RowTransmit(0,tmp >> 8, tmp, 0x80);
				}
				for(char i = 0; i < 100; ++i)
				{
					_delay_ms(20);
				}
			}
			
			DDRA = 0x00;
			PORTA = 0;
			for(char c = 0; c < 8; ++c)
			for(char r = 0; r < 8; ++r)
			diffs2[r][c] = 0;
		for(char col = 0; col < 8; ++col)
		for(char row = 7; row < 10; --row)
		{
			LED_RowTransmit(0,(1 << col) ,(1 << col),(1 << row));
			//_delay_ms(1000);
			//_delay_ms(50);
			tmp = analogRead(col);
			tmp = analogRead(col);
			diffs2[row][col] += (tmp > diffs[row][col])?(0):(diffs[row][col]-tmp);
			//LED_RowTransmit(0,tmp >> 8, tmp, 0x80);
		}
		
		PORTA = 0xFF;
		DDRA = 0xFF;
		//PORTA = 0xFF;
		for(char times = 0; times < 100; ++times)
		for(unsigned char pwm = 0; pwm < 24; ++pwm)
		{
			for(unsigned char i = 0; i < 8; ++i)
			{
				uchar cmask = 0;
				for(unsigned char j = 0; j < 8; ++j)
				{
					cmask <<= 1;
					cmask |= diffs2[i][7-j] > (pwm+1);
				}
				//LED_RowTransmit(0,0,0,0);
				//_delay_ms(1);
				LED_RowTransmit(cmask, cmask, cmask, (1 << i)|(i == 0));
			}
		}
		DDRA = 0;
		PORTA = 0;
		}		
		
		
				
	}
	{
		if(index & 0b01000000)
		{
			LED_RowTransmit(0,0,0,0);
			/*for(char pix = 0; pix < 64; ++pix)
			{
				LED_RowTransmit(diffs[pix & 0b111][pix >> 3],diffs[pix & 0b111][pix >> 3]>>8,0,0x80);
			for(char i = 0; i < 100; ++i)
				_delay_ms(10);
			}*/				
			for(char times = 0; times < 100; ++times)
			for(unsigned char pwm = 0; pwm < 32; ++pwm)
			{
				for(unsigned char i = 0; i < 8; ++i)
				{
					uchar cmask = 0;
					for(unsigned char j = 0; j < 8; ++j)
					{
						cmask <<= 1;
						cmask |= diffs[i][7-j] > (pwm+20);
					}
					//LED_RowTransmit(0,0,0,0);
					//_delay_ms(1);
					LED_RowTransmit(cmask, cmask, cmask, 1 << i);
				}
			}
			//LED_RowTransmit(0x55,0x55,0x55,0x55);
			//for(char i = 0; i < 100; ++i)
			//_delay_ms(10);
			//light phase
			index = 0;
		}
		else
		{
			char row = index & 0b0111;
			char col = index >> 3;
			unsigned char mask1 = 1 << col;
			unsigned char mask3 = 1 << (col + 1) | (1 << (col - 1) & ~(col == 0));
			unsigned char mask2 = 1 << row;
			LED_RowTransmit(2,2,2,2); // light;
			LED_RowTransmit(~2,~2,~2,~2); // reverse bias
			//LED_RowTransmit(mask1, mask1, mask1, mask2); // light
			//LED_RowTransmit(mask3, mask3, mask3, ~mask2);
			//_delay_ms(100);
			DDRA &= 0b11111101;//~mask2;
			//_delay_ms(10);
			tmp = analogRead(1);
			//_delay_ms(100);
			tmp2 = analogRead(1);
			DDRA |= 0b11111111;//mask2;
			
			LED_RowTransmit(0,0,0,0);
		
			diff = (tmp - tmp2) * (tmp > tmp2);
			diffs[row][col] = diff;
			for(char time = 0; time < 100; ++time)
			//for(char pwm = 0; pwm < 32; ++pwm)
			//{
			//	char val = (diff > (pwm + 32) << col);
			//	LED_RowTransmit(val,val,val,mask2);
			//}
			//LED_RowTransmit(diff, 0, diff >> 8, 0x80);
			//for(char i = 0; i < 100; ++i)
			//_delay_ms(10);
			//LED_RowTransmit((diff - 4) > diff2,(diff - 3) > diff2,(diff - 2) > diff2,0x80);
			diff2 = diff;
			//_delay_ms(10);
			++index;
		}			
		
	}		
    {
		SPI_MasterTransmit(~0x07);
		SPI_MasterTransmit(~0x07);
		SPI_MasterTransmit(~0x07);
		//PORTA = 0xFF;
		PORTC = 1;
		PORTC = 0;
		PORTA = 0x05;
		//PORTA = 0;
		//_delay_ms(1);
		DDRA = 0b11111101;
		tmp = analogRead(1);
		DDRA = 0b11111111;
		PORTA = 0x00;
		SPI_MasterTransmit(~(tmp>>8));
		SPI_MasterTransmit(~tmp);
		SPI_MasterTransmit(~0);
		PORTC = 1;
		PORTC = 0;
		PORTA = 0x80;
		_delay_ms(1);
		PORTA = 0x00;
		//PORTA = 2;
		//_delay_ms(10);
        //TODO:: Please write your application code 
    }
}