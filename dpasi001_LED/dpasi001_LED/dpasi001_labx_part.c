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


#include <avr/io.h>
#include <ucr/timer.h>

#define PWM_MAX 8

int main(void)
{
	DDRA = 0xFF; PORTA = 0x00;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	
	TimerSet(1);
	TimerOn();
	long count = 1;
	char bits[8];
	char block[8];
	
	for(char i = 0; i < 8; i++)
	{
		bits[i] = 0;
		block[i] = 0;
	}

	char bitss[8][8];
	for(int i = 0; i < 64; i++)
	{
		bitss[i%8][i/8] = 0;//(i/8 + i) % (PWM_MAX+1);
	}
	
#define on(row,col,val)(bitss[row][col] = val)
	
	on(2,2,2);
	//on(1,2,3);
	//on(0,2,4);
	on(2,6,5);
	//on(1,6,6);
	//on(0,6,7);
	//on(4,3,8);
	//on(4,3,8);
	on(5,1,1);
	on(6,2,2);
	on(6,3,3);
	on(6,4,4);
	on(6,5,5);
	on(6,6,6);
	on(5,7,7);
	//on(7,7,8);
	
	
	
	for(char row = 1; row < 7; row++)
	{
		for(char col = 1; col <= row; col++)
			bits[row] |= 1 << (7 - col);
	}
	
	bits[1] |= 1 << 1;
	bits[6] &= ~(1 << 4);
	bits[6] &= ~(1 << 3);
	
	char PWM = 0;
	char enable = 0;
	char red = 0, green = 0, blue = 0, anode = 0;
	//block[0] = 1;
	long tick = 1;
 	unsigned char vals[PWM_MAX * 2];
 	for(int i = 0; i < sizeof(vals)/2; i++)
 		vals[i] = i;
 	for(int i = sizeof(vals)/2; i < sizeof(vals); i++)
 		vals[i] = sizeof(vals) - i;
	block[4] = 0x08;
      while(1)
     {
		 if((tick % 1024) == 0)
			block[0] <<= 1;
		 if(block[0] == 0)
			block[0]++;
		 if(tick % 5000 == 0)
			block[2] ^= 0x08;
		green = 0x08 & ((anode == (1 << 5)) << 3);
		if(tick%(8*PWM_MAX*8) == 0)
			on(4,4,vals[tick/(8*PWM_MAX*8)%sizeof(vals)]);
		 red = 0;
		 for(int i = 0; i < 8; ++i)
		 {
			 red |= (bitss[7-count%8][7-i] > PWM) << i;
		 }
		 static char i;

		 
		 PORTC = 0;//0x20;
		 //PORTB = count % 8;
		 anode = 0x80 >> (count % 8);
		 blue = block[7-count%8];
		 /*for(i = 0; i < 8; i++)
		 {
			 //PORTC = 0;
			 PORTC = 0x07;
			 PORTC |= 0x10;
		 }
		 PORTC |= 0x20;*/
		 for(i = 0; i < 8; i++)
		 {
			 //PORTC = 0;//&= 0x20;
			 PORTC = ((~red >> i) & 0x01) | (((~green >> i)<<1) & 0x02) | (((~blue >> i)<<2) & 0x04) | (((anode >> i)<<3) & 0x08) |
							(((anode >> (i+8))<<6) & 0x40); //data
			 PORTC |= 0x10; //shift in
		 }
		 //01 - red
		 //02 - green
		 //04 - blue
		 //08 - rclk
		 //10 - sclk
		 //20 - en
		 PORTC |= 0x20; //set to register, allow input
		 //asm("nop");
		 //PORTC = 0x20;
	     count++;
		 tick++;
		 count %= 64;
		 if(count % 8 == 0)
			PWM = (PWM + 1) % PWM_MAX;
	     while(!TimerFlag);
	     TimerFlag = 0;
     }
}