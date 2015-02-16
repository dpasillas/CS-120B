/* dpasi001_pixel.h - 3/15/2013
 * Name & E-mail: Daniel Pasillas - dpasi001@ucr.edu
 * CS Login: dpasi001
 * Partner(s) Name & E-mail: Valeed Malik - vmali001@ucr.edu
 * Lab Section: 23
 * Assignment: Final Project
 * Exercise Description:
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */

#ifndef PIXEL_H
#define PIXEL_H

typedef struct Pixel{
	uchar r, g, b;
} Pixel;

Pixel pixels[8][8];

#define PIX_EQ(pix,red,green,blue)(pix.r=red, pix.g=green, pix.b=blue)

#define PWM_MAX 8

uchar vals[PWM_MAX << 1]; //for pulsing colors
uchar pwm8[9] = {0x00,			//0000 0000
0x01,	//0000 0001
0x11,	//0001 0001
0x25,	//0010 0101
0x55,	//0101 0101
0x5C,	//0101 1011
0x77,	//0111 0111
0x7F,	//0111 1111
						0xFF};	//1111 1111
uchar pwm8_split[9][8] = {{0,0,0,0, 0,0,0,0}, //faster, but requires more memory
							{0,0,0,0, 0,0,0,1},
							{0,0,0,1, 0,0,0,1},
							{0,0,1,0, 0,1,0,1},
							{0,1,0,1, 0,1,0,1},
							{0,1,0,1, 1,0,1,1},
							{0,1,1,1, 0,1,1,1},
							{0,1,1,1, 0,1,1,1},
							{1,1,1,1, 1,1,1,1}};

#endif PIXEL_H