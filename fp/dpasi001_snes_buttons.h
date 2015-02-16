#ifndef SNES_CONTROLLER_H
#define SNES_CONTROLLER_H

unsigned short buttons;

//define NES or SNES depending on the controller desired
#define NES

#ifdef SNES
#define SNES_R  0x0001
#define SNES_L  0x0002
#define SNES_X  0x0004
#define SNES_A  0x0008
#define SNES_RT 0x0010
#define SNES_LT 0x0020
#define SNES_DN 0x0040
#define SNES_UP 0x0080
#define SNES_ST 0x0100
#define SNES_SL 0x0200
#define SNES_Y  0x0400
#define SNES_B  0x0800
#define NUM_BUTTONS 12
#define RUN_B SNES_Y
#define JUMP_B SNES_B
#endif
#ifdef NES
#define SNES_A 0x80
#define SNES_B 0x40
#define SNES_SL 0x20
#define SNES_ST 0x10
#define SNES_UP 0x08
#define SNES_DN 0x04
#define SNES_LT 0x02
#define SNES_RT 0x01
#define NUM_BUTTONS 8
#define RUN_B SNES_B
#define JUMP_B SNES_A
#endif

#define SNES_DATA_POS 0
#define SNES_DATA 0x01
#define SNES_LATCH 0x02
#define SNES_CLOCK 0x04

unsigned char SNES_controller_tick(unsigned char state)
{
	PORT_OR_EQ(PORTB,SNES_LATCH);
	PORT_AND_EQ(PORTB,~SNES_LATCH);
	buttons = 0;
	char i;
	for(i = 0; i < NUM_BUTTONS; i++)
	{
		buttons <<= 1;
		buttons |= !(PINB & SNES_DATA);
		PORT_OR_EQ(PORTB,SNES_CLOCK);
		PORT_AND_EQ(PORTB,~SNES_CLOCK);
	}
	return 0;
}

#endif