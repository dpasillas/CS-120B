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
#define TICKS_PER_MS 5
#define INTS_PER_MS 125
#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <ucr/timer.h>
const unsigned char prescaler = PRESCALER_64;

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned long ulong;

ushort diff[5][8][8] = {{{0}}};

typedef struct task { //this task was taken from the PES pdf, and modified.
uchar state; // Task’s current state
ulong period; // Task period
ulong elapsedTime; // Time since last tick
uchar (*TickFct)(uchar); // Task tick function
} task;

enum {TOUCH, LED_M, NUM_TASKS}; //to reorder tasks, simply reorder this enum
task tasks[NUM_TASKS];

inline void taskInit(uchar n, ulong period, uchar(*fnct)(uchar))
{
	tasks[n].state=0xFF;
	tasks[n].period = period;
	tasks[n].elapsedTime = period;
	tasks[n].TickFct = fnct;
}

void SPI_Setup()
{
	/* Set MOSI and SCK output, all others input */
	DDRB = 0xFF;//(1<<5)|(1<<7);
	/* Enable SPI, Master, set clock rate fck/16 */
	/* Enable SPI, Master, 2x clock rate, Data order*/
	SPCR = (1<<SPE) | (1<<MSTR) | (1 << SPI2X) /*|(1<<SPR0)*/ | (1 << DORD);
}

void SPI_MasterTransmit(char cData)
{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
}

void LED_MatrixTransmit(uchar r, uchar g, uchar b, uchar com)
{
	//PORTC = 0;
	//PORTB &= ~2; //Master Reset on
	PORTB |= 2;
	PORTB |= 1;  //MR off, Latch on
	PORTB &= ~1;  //Latch off
	SPI_MasterTransmit(~com);
	SPI_MasterTransmit(b);
	SPI_MasterTransmit(g);
	PORTA = r;
	PORTB |= 1;
	PORTB &= ~1;
}

#define ADMUX_BASE 0
void ADC_Setup()
{
	SFIOR |= /*(1 << PUD) |*/ (1 << ACME); //Pull-up disable, Analog Converter Multiplexer enable
	
	ADMUX = ADMUX_BASE;//(1 << REFS0);// | (1 << REFS1);// | (1 << ADLAR);
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) /*| (1 << ADPS0)*/; //enable, prescalar 64. 8,000,000 / 64 = 125,000
}

unsigned short analogRead(unsigned char channel)
{
	unsigned char chan = (channel & 0b00000111);
	ADMUX = ADMUX_BASE | chan;
	//ADCSRA &= ~(1 << ADEN);
	//ADCSRA |= (1<<ADEN);
	ADCSRA |= 1 << ADSC; // start analog read
	
	//224
	//141
	while(!(ADCSRA & (1<<ADIF))); //poll until ready
	//DDRA |= chan;
	return ADC;
}

uchar LED_Display(uchar state)
{
	PORTA = 0x00;
	DDRA = 0xFF;
	state = (state + 1) & 0b00111111;
	uchar row = state & 0b0111;
	uchar pwm = 0;//state >> 3;
	
	uchar col;
	uchar cmask;
	for(col = 0; col < 8; ++col)
	{
		cmask >>= 1;
		cmask |= ((diff[1][row][col] + diff[2][row][col] + diff[3][row][col] + diff[4][row][col]) > (pwm + 3)) << 7;
	}
	
	LED_MatrixTransmit(cmask, 0, 0, 1 << row);	
	return state;
}

uchar LED_Input(uchar state)
{
	PORTA = 0x00;
	DDRA = 0xFF; //input
	//PORTA = 0x00; // no pull-up
	++state;
	uchar row = state & 0b0111;
	uchar col = (state >> 3) & 0b0111;
	uchar pass = (state >> 6) + 1;
	ushort val = 0;
	
	//LED_MatrixTransmit(0xFF, 0xFF, 0xFF, 1 << row);
	//The reason for lighting the full row is to eliminate flicker when scanning.
	/*       -RD-					  -GN-					   -BL-
	O  O  O  O  O  O  O  O | O  O  O  O  O  O  O  O | O  O  O  O  O  O  O  O 
	O  O  O  O  O  O  O  O | O  O  O  O  O  O  O  O | O  O  O  O  O  O  O  O
	X  X  X  T  X  X  X  X | X  X  X  X  X  X  X  X | X  X  X  X  X  X  X  X
	O  O  O  O  O  O  O  O | O  O  O  O  O  O  O  O | O  O  O  O  O  O  O  O
	O  O  O  O  O  O  O  O | O  O  O  O  O  O  O  O | O  O  O  O  O  O  O  O
	O  O  O  O  O  O  O  O | O  O  O  O  O  O  O  O | O  O  O  O  O  O  O  O
	O  O  O  O  O  O  O  O | O  O  O  O  O  O  O  O | O  O  O  O  O  O  O  O
	O  O  O  O  O  O  O  O | O  O  O  O  O  O  O  O | O  O  O  O  O  O  O  O
	*/
	LED_MatrixTransmit(0, 0xFF, 0xFF, 1 << row);
	DDRA = ~(1 << col);
	val = analogRead(col);
	
	//if(val > diff[0][row][col])
	//	diff[0][row][col] = val;
	
	if(~PINC & 1)
		diff[0][row][col] = val;
	
	diff[pass][row][col] = (diff[0][row][col] > val)?(0):(val - diff[0][row][col]);
	
	//PORTB &= ~2; //Master reset
	//PORTB |= 2;
	//PORTB |= 1; //latch
	//PORTB &= ~1;
	
	
	
	return state;
}

void calibrate()
{
	DDRA = 0x00;
	PORTA = 0x00;
	uchar row, col;
	ushort val;
	for(col = 0; col < 8; ++col)
	{
		for(row = 0; row < 8; ++row)
		{
			LED_MatrixTransmit(0, 1 << col, 1 << col, 1 << row);
			val = analogRead(col);
			val = analogRead(col);
			diff[0][row][col] = val;
			
		}
	}
	_delay_ms(1000);
}

int main(void)
{
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0x00; PORTC = 0xFF;
	SPI_Setup();
	ADC_Setup();
	TimerSet(1);
	TimerOn();
	
	taskInit(LED_M,8,LED_Display);
	taskInit(TOUCH,8,LED_Input);
	uchar index = 0;
	ushort temp = 0,temp2 = 0;
	uchar i;
	calibrate();
	DDRA = 0xFF;
	/*
	//char something = 0;
	//char row = 0, col = 0;
    while(0)
	{
		row = something >> 3;
		col = something & 0b0111;
		//DDRC = 0x01;
		//LED_MatrixTransmit(1,1,1,1); // light, discharge
		DDRA = 0xFF;
		//LED_MatrixTransmit(0,0,0,0);
		LED_MatrixTransmit(0,1 << col,1 << col,1 << row);
		//DDRA = ~2;
		//LED_MatrixTransmit(0,1,1,1);
		//PORTC = 1;
		//PORTA = 1;
		//PORTA = 0;
		//_delay_ms(1);
		DDRA = ~(1 << col); //high impedance
		temp = analogRead(col);
		DDRA = 0xFF;
		LED_MatrixTransmit(0,temp >> 8, temp, 0x80);
		//DDRA = 0xFF;
		for(i = 0; i < 10; ++i)
	    _delay_ms(10);
		something = (something + 1) & 0b00111111;
	}
	*/
	while(1)
    {
		//while(1)
			//index = LED_Input(index);
		
		//if(~PINC & 1)
		//	calibrate();
		
		for (i = 0; i < NUM_TASKS; ++i) { // Heart of scheduler code
			if ( tasks[i].elapsedTime >= tasks[i].period ) { // Ready
				tasks[i].state = tasks[i].TickFct(tasks[i].state);
				tasks[i].elapsedTime = 0;
			}
			++tasks[i].elapsedTime;
		}
		
		while(!TimerFlag);
		TimerFlag = 0;
    }
}