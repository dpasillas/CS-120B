#include <avr/io.h>


// Bit-access functions
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
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

int rand(void);

int main(void)
{
	unsigned char cnt=0;
	DDRA = 0x00; PORTA = 0xFF; // Config port A as inputs, init 1s
	DDRC = 0xFF; PORTC = 0x00; // Config port C as outputs, init 0s
	
	while(1)
	{
		if (GetBit(PINA, 0)==0) 
		{ // Button pressed
		    cnt = rand() % 10; // cnt is rand num from 0-9
		    Write7Seg(cnt);
	    }
		
			
    }
}	