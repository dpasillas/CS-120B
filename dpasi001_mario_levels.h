/* dpasi001_mario_levels.h - 3/15/2013
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

#ifndef MARIO_MAPS
#define MARIO_MAPS

#include <dpasi001_tone.h>
#include <dpasi001_characters.h>
#include <dpasi001_pixel.h>
#include <avr/pgmspace.h>

//this is done this way so that levels may be stored in the program memory, rather than Data memory, which is significantly more limited.
//	each level is 480 bytes in data memory.  As a function, this adds 2828 bytes.

/*****************LEVEL********************/
#define LEVEL_SIZE 120
unsigned char RedLevelData[LEVEL_SIZE] = {};//{0x00,0x00,0x40,0xC0,0x40,0x00,0x00,0x08,0x00,0x08,0x28,0x08,0x00,0x00,0x00,0x00,0x80,0xC0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x40,0xC0,0xE0,0x40,0x00,0x04,0x04,0x10,0x10,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x14,0x00,0x00,0x48,0xC8,0xC0,0x80,0x08,0x00,0x28,0x00,0x08,0x00,0x00,0x20,0x20,0x00,0x00,0x28,0x20,0x00,0x00,0x02,0x06,0x0E,0x00,0x0E,0x06,0x42,0xC0,0x40,0x02,0x06,0x0E,0x0E,0x00,0x0E,0x06,0x02,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x00,0x00,0x02,0x06,0x0E,0x1E,0x00,0x00,0x00,0x00,0x00,0x40,0xE0,0xE0,0x4E,0x1E,0x18,0x1E,0x0E,0x00,0x00};
unsigned char GreenLevelData[LEVEL_SIZE] = {};//{0x01,0x01,0x41,0xC1,0x41,0x01,0x01,0x09,0x01,0x09,0x29,0x09,0x01,0x01,0x01,0x01,0x87,0xC7,0x41,0x01,0x01,0x0F,0x0F,0x01,0x01,0x0F,0x0F,0x01,0x01,0x0F,0x0F,0x01,0x01,0x09,0x01,0x01,0x41,0xC1,0xE0,0x40,0x01,0x05,0x05,0x11,0x11,0x11,0x11,0x01,0x01,0x00,0x00,0x00,0x11,0x15,0x01,0x01,0x49,0xC9,0xC1,0x81,0x09,0x01,0x29,0x01,0x09,0x01,0x01,0x21,0x21,0x01,0x01,0x29,0x21,0x01,0x01,0x03,0x07,0x0F,0x01,0x0F,0x07,0x43,0xC1,0x41,0x03,0x07,0x0F,0x0F,0x00,0x0F,0x07,0x03,0x01,0x07,0x07,0x01,0x01,0x09,0x09,0x01,0x01,0x03,0x07,0x0F,0x1F,0x01,0x01,0x01,0x01,0x01,0x41,0xE1,0xE1,0x4F,0x1F,0x19,0x1F,0x0F,0x01,0x01};
unsigned char BlueLevelData[LEVEL_SIZE] = {};//{0x00,0x00,0x40,0xC0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xC0,0xE0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xC0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xE0,0xE0,0x40,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char BarrierLevelData[120] = {};//{0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x09,0x01,0x09,0x29,0x09,0x01,0x01,0x01,0x01,0x07,0x07,0x01,0x01,0x01,0x0F,0x0F,0x01,0x01,0x0F,0x0F,0x01,0x01,0x0F,0x0F,0x01,0x01,0x09,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x05,0x05,0x11,0x11,0x11,0x11,0x01,0x01,0x00,0x00,0x00,0x11,0x15,0x01,0x01,0x09,0x09,0x01,0x01,0x09,0x01,0x29,0x01,0x09,0x01,0x01,0x21,0x21,0x01,0x01,0x29,0x21,0x01,0x01,0x03,0x07,0x0F,0x01,0x0F,0x07,0x03,0x01,0x01,0x03,0x07,0x0F,0x0F,0x00,0x0F,0x07,0x03,0x01,0x07,0x07,0x01,0x01,0x09,0x09,0x01,0x01,0x03,0x07,0x0F,0x1F,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x09,0x19,0x19,0x1F,0x0F,0x01,0x01};
/*****************LEVEL********************/

void loadLevel1();
void loadLevel2();
void loadLevel3();
void loadLevel4();

unsigned char current_level = 0;
char level_pos = -1;

Pixel background;

void loadLevel(unsigned char level)
{
	if(level != current_level)
	{
		switch(level)
		{
			case 1:
					loadLevel1(); 
					current_song.song = mario_main_song;
					current_song.dur = sizeof(mario_main_song)/sizeof(Note);
					current_song.pos = 0;
					PIX_EQ(background,0,1,1);
					break;
			case 2:
					loadLevel2(); 
					current_song.song = mario_underground;
					current_song.dur = sizeof(mario_underground)/sizeof(Note);
					current_song.pos = 0;
					PIX_EQ(background,0,0,0);
					break;
			case 3:
					loadLevel3();
					current_song.song = mario_main_song;
					current_song.dur = sizeof(mario_main_song)/sizeof(Note);
					current_song.pos = 0;
					PIX_EQ(background,0,1,1);
					break;
			case 4:
					loadLevel4(); 
					current_song.song = mario_castle;
					current_song.dur = sizeof(mario_castle)/sizeof(Note);
					current_song.pos = 0;
					PIX_EQ(background,1,1,1);
				
					for(unsigned char i = 0; i < 120; i++)
						BlueLevelData[i] &= ~(GreenLevelData[i] & RedLevelData[i]),
						GreenLevelData[i] |= BlueLevelData[i], //barriers should be stored as blue, should be gray
						RedLevelData[i] |= BlueLevelData[i];
					break;
			default: break;
		}
	}
	//if((level % 2))
	//{	//this colors doorways white
		RedLevelData[115] |= 6;
		BlueLevelData[115] |= 6;
		GreenLevelData[115] |= 6;
	//}
	
	level_pos = -1;
	
	mario.x = 1;
	mario.y = 3;
}

void loadLevel1()
{
		/*0*/ RedLevelData[0] = 0x00; GreenLevelData[0] = 0x01; BlueLevelData[0] = 0x00; BarrierLevelData[0] = 0x01;
		/*1*/ RedLevelData[1] = 0x00; GreenLevelData[1] = 0x01; BlueLevelData[1] = 0x00; BarrierLevelData[1] = 0x01;
		/*2*/ RedLevelData[2] = 0x40; GreenLevelData[2] = 0x41; BlueLevelData[2] = 0x40; BarrierLevelData[2] = 0x01;
		/*3*/ RedLevelData[3] = 0xC0; GreenLevelData[3] = 0xC1; BlueLevelData[3] = 0xC0; BarrierLevelData[3] = 0x01;
		/*4*/ RedLevelData[4] = 0x40; GreenLevelData[4] = 0x41; BlueLevelData[4] = 0x40; BarrierLevelData[4] = 0x01;
		/*5*/ RedLevelData[5] = 0x00; GreenLevelData[5] = 0x01; BlueLevelData[5] = 0x00; BarrierLevelData[5] = 0x01;
		/*6*/ RedLevelData[6] = 0x00; GreenLevelData[6] = 0x01; BlueLevelData[6] = 0x00; BarrierLevelData[6] = 0x01;
		/*7*/ RedLevelData[7] = 0x08; GreenLevelData[7] = 0x09; BlueLevelData[7] = 0x00; BarrierLevelData[7] = 0x09;
		/*8*/ RedLevelData[8] = 0x00; GreenLevelData[8] = 0x01; BlueLevelData[8] = 0x00; BarrierLevelData[8] = 0x01;
		/*9*/ RedLevelData[9] = 0x08; GreenLevelData[9] = 0x09; BlueLevelData[9] = 0x00; BarrierLevelData[9] = 0x09;
		/*10*/ RedLevelData[10] = 0x28; GreenLevelData[10] = 0x29; BlueLevelData[10] = 0x00; BarrierLevelData[10] = 0x29;
		/*11*/ RedLevelData[11] = 0x08; GreenLevelData[11] = 0x09; BlueLevelData[11] = 0x00; BarrierLevelData[11] = 0x09;
		/*12*/ RedLevelData[12] = 0x00; GreenLevelData[12] = 0x01; BlueLevelData[12] = 0x00; BarrierLevelData[12] = 0x01;
		/*13*/ RedLevelData[13] = 0x00; GreenLevelData[13] = 0x01; BlueLevelData[13] = 0x00; BarrierLevelData[13] = 0x01;
		/*14*/ RedLevelData[14] = 0x00; GreenLevelData[14] = 0x01; BlueLevelData[14] = 0x00; BarrierLevelData[14] = 0x01;
		/*15*/ RedLevelData[15] = 0x00; GreenLevelData[15] = 0x01; BlueLevelData[15] = 0x00; BarrierLevelData[15] = 0x01;
		/*16*/ RedLevelData[16] = 0x80; GreenLevelData[16] = 0x87; BlueLevelData[16] = 0x80; BarrierLevelData[16] = 0x07;
		/*17*/ RedLevelData[17] = 0xC0; GreenLevelData[17] = 0xC7; BlueLevelData[17] = 0xC0; BarrierLevelData[17] = 0x07;
		/*18*/ RedLevelData[18] = 0x40; GreenLevelData[18] = 0x41; BlueLevelData[18] = 0x40; BarrierLevelData[18] = 0x01;
		/*19*/ RedLevelData[19] = 0x00; GreenLevelData[19] = 0x01; BlueLevelData[19] = 0x00; BarrierLevelData[19] = 0x01;
		/*20*/ RedLevelData[20] = 0x00; GreenLevelData[20] = 0x01; BlueLevelData[20] = 0x00; BarrierLevelData[20] = 0x01;
		/*21*/ RedLevelData[21] = 0x00; GreenLevelData[21] = 0x0F; BlueLevelData[21] = 0x00; BarrierLevelData[21] = 0x0F;
		/*22*/ RedLevelData[22] = 0x00; GreenLevelData[22] = 0x0F; BlueLevelData[22] = 0x00; BarrierLevelData[22] = 0x0F;
		/*23*/ RedLevelData[23] = 0x00; GreenLevelData[23] = 0x01; BlueLevelData[23] = 0x00; BarrierLevelData[23] = 0x01;
		/*24*/ RedLevelData[24] = 0x00; GreenLevelData[24] = 0x01; BlueLevelData[24] = 0x00; BarrierLevelData[24] = 0x01;
		/*25*/ RedLevelData[25] = 0x00; GreenLevelData[25] = 0x0F; BlueLevelData[25] = 0x00; BarrierLevelData[25] = 0x0F;
		/*26*/ RedLevelData[26] = 0x00; GreenLevelData[26] = 0x0F; BlueLevelData[26] = 0x00; BarrierLevelData[26] = 0x0F;
		/*27*/ RedLevelData[27] = 0x00; GreenLevelData[27] = 0x01; BlueLevelData[27] = 0x00; BarrierLevelData[27] = 0x01;
		/*28*/ RedLevelData[28] = 0x00; GreenLevelData[28] = 0x01; BlueLevelData[28] = 0x00; BarrierLevelData[28] = 0x01;
		/*29*/ RedLevelData[29] = 0x00; GreenLevelData[29] = 0x0F; BlueLevelData[29] = 0x00; BarrierLevelData[29] = 0x0F;
		/*30*/ RedLevelData[30] = 0x00; GreenLevelData[30] = 0x0F; BlueLevelData[30] = 0x00; BarrierLevelData[30] = 0x0F;
		/*31*/ RedLevelData[31] = 0x00; GreenLevelData[31] = 0x01; BlueLevelData[31] = 0x00; BarrierLevelData[31] = 0x01;
		/*32*/ RedLevelData[32] = 0x00; GreenLevelData[32] = 0x01; BlueLevelData[32] = 0x00; BarrierLevelData[32] = 0x01;
		/*33*/ RedLevelData[33] = 0x08; GreenLevelData[33] = 0x09; BlueLevelData[33] = 0x00; BarrierLevelData[33] = 0x09;
		/*34*/ RedLevelData[34] = 0x00; GreenLevelData[34] = 0x01; BlueLevelData[34] = 0x00; BarrierLevelData[34] = 0x01;
		/*35*/ RedLevelData[35] = 0x00; GreenLevelData[35] = 0x01; BlueLevelData[35] = 0x00; BarrierLevelData[35] = 0x01;
		/*36*/ RedLevelData[36] = 0x40; GreenLevelData[36] = 0x41; BlueLevelData[36] = 0x40; BarrierLevelData[36] = 0x01;
		/*37*/ RedLevelData[37] = 0xC0; GreenLevelData[37] = 0xC1; BlueLevelData[37] = 0xC0; BarrierLevelData[37] = 0x01;
		/*38*/ RedLevelData[38] = 0xE0; GreenLevelData[38] = 0xE0; BlueLevelData[38] = 0xE0; BarrierLevelData[38] = 0x00;
		/*39*/ RedLevelData[39] = 0x40; GreenLevelData[39] = 0x40; BlueLevelData[39] = 0x40; BarrierLevelData[39] = 0x00;
		/*40*/ RedLevelData[40] = 0x00; GreenLevelData[40] = 0x01; BlueLevelData[40] = 0x00; BarrierLevelData[40] = 0x01;
		/*41*/ RedLevelData[41] = 0x04; GreenLevelData[41] = 0x05; BlueLevelData[41] = 0x00; BarrierLevelData[41] = 0x05;
		/*42*/ RedLevelData[42] = 0x04; GreenLevelData[42] = 0x05; BlueLevelData[42] = 0x00; BarrierLevelData[42] = 0x05;
		/*43*/ RedLevelData[43] = 0x10; GreenLevelData[43] = 0x11; BlueLevelData[43] = 0x00; BarrierLevelData[43] = 0x11;
		/*44*/ RedLevelData[44] = 0x10; GreenLevelData[44] = 0x11; BlueLevelData[44] = 0x00; BarrierLevelData[44] = 0x11;
		/*45*/ RedLevelData[45] = 0x10; GreenLevelData[45] = 0x11; BlueLevelData[45] = 0x00; BarrierLevelData[45] = 0x11;
		/*46*/ RedLevelData[46] = 0x10; GreenLevelData[46] = 0x11; BlueLevelData[46] = 0x00; BarrierLevelData[46] = 0x11;
		/*47*/ RedLevelData[47] = 0x00; GreenLevelData[47] = 0x01; BlueLevelData[47] = 0x00; BarrierLevelData[47] = 0x01;
		/*48*/ RedLevelData[48] = 0x00; GreenLevelData[48] = 0x01; BlueLevelData[48] = 0x00; BarrierLevelData[48] = 0x01;
		/*49*/ RedLevelData[49] = 0x00; GreenLevelData[49] = 0x00; BlueLevelData[49] = 0x00; BarrierLevelData[49] = 0x00;
		/*50*/ RedLevelData[50] = 0x00; GreenLevelData[50] = 0x00; BlueLevelData[50] = 0x00; BarrierLevelData[50] = 0x00;
		/*51*/ RedLevelData[51] = 0x00; GreenLevelData[51] = 0x00; BlueLevelData[51] = 0x00; BarrierLevelData[51] = 0x00;
		/*52*/ RedLevelData[52] = 0x10; GreenLevelData[52] = 0x11; BlueLevelData[52] = 0x00; BarrierLevelData[52] = 0x11;
		/*53*/ RedLevelData[53] = 0x14; GreenLevelData[53] = 0x15; BlueLevelData[53] = 0x00; BarrierLevelData[53] = 0x15;
		/*54*/ RedLevelData[54] = 0x00; GreenLevelData[54] = 0x01; BlueLevelData[54] = 0x00; BarrierLevelData[54] = 0x01;
		/*55*/ RedLevelData[55] = 0x00; GreenLevelData[55] = 0x01; BlueLevelData[55] = 0x00; BarrierLevelData[55] = 0x01;
		/*56*/ RedLevelData[56] = 0x48; GreenLevelData[56] = 0x49; BlueLevelData[56] = 0x40; BarrierLevelData[56] = 0x09;
		/*57*/ RedLevelData[57] = 0xC8; GreenLevelData[57] = 0xC9; BlueLevelData[57] = 0xC0; BarrierLevelData[57] = 0x09;
		/*58*/ RedLevelData[58] = 0xC0; GreenLevelData[58] = 0xC1; BlueLevelData[58] = 0xC0; BarrierLevelData[58] = 0x01;
		/*59*/ RedLevelData[59] = 0x80; GreenLevelData[59] = 0x81; BlueLevelData[59] = 0x80; BarrierLevelData[59] = 0x01;
		/*60*/ RedLevelData[60] = 0x08; GreenLevelData[60] = 0x09; BlueLevelData[60] = 0x00; BarrierLevelData[60] = 0x09;
		/*61*/ RedLevelData[61] = 0x00; GreenLevelData[61] = 0x01; BlueLevelData[61] = 0x00; BarrierLevelData[61] = 0x01;
		/*62*/ RedLevelData[62] = 0x28; GreenLevelData[62] = 0x29; BlueLevelData[62] = 0x00; BarrierLevelData[62] = 0x29;
		/*63*/ RedLevelData[63] = 0x00; GreenLevelData[63] = 0x01; BlueLevelData[63] = 0x00; BarrierLevelData[63] = 0x01;
		/*64*/ RedLevelData[64] = 0x08; GreenLevelData[64] = 0x09; BlueLevelData[64] = 0x00; BarrierLevelData[64] = 0x09;
		/*65*/ RedLevelData[65] = 0x00; GreenLevelData[65] = 0x01; BlueLevelData[65] = 0x00; BarrierLevelData[65] = 0x01;
		/*66*/ RedLevelData[66] = 0x00; GreenLevelData[66] = 0x01; BlueLevelData[66] = 0x00; BarrierLevelData[66] = 0x01;
		/*67*/ RedLevelData[67] = 0x20; GreenLevelData[67] = 0x21; BlueLevelData[67] = 0x00; BarrierLevelData[67] = 0x21;
		/*68*/ RedLevelData[68] = 0x20; GreenLevelData[68] = 0x21; BlueLevelData[68] = 0x00; BarrierLevelData[68] = 0x21;
		/*69*/ RedLevelData[69] = 0x00; GreenLevelData[69] = 0x01; BlueLevelData[69] = 0x00; BarrierLevelData[69] = 0x01;
		/*70*/ RedLevelData[70] = 0x00; GreenLevelData[70] = 0x01; BlueLevelData[70] = 0x00; BarrierLevelData[70] = 0x01;
		/*71*/ RedLevelData[71] = 0x28; GreenLevelData[71] = 0x29; BlueLevelData[71] = 0x00; BarrierLevelData[71] = 0x29;
		/*72*/ RedLevelData[72] = 0x20; GreenLevelData[72] = 0x21; BlueLevelData[72] = 0x00; BarrierLevelData[72] = 0x21;
		/*73*/ RedLevelData[73] = 0x00; GreenLevelData[73] = 0x01; BlueLevelData[73] = 0x00; BarrierLevelData[73] = 0x01;
		/*74*/ RedLevelData[74] = 0x00; GreenLevelData[74] = 0x01; BlueLevelData[74] = 0x00; BarrierLevelData[74] = 0x01;
		/*75*/ RedLevelData[75] = 0x02; GreenLevelData[75] = 0x03; BlueLevelData[75] = 0x00; BarrierLevelData[75] = 0x03;
		/*76*/ RedLevelData[76] = 0x06; GreenLevelData[76] = 0x07; BlueLevelData[76] = 0x00; BarrierLevelData[76] = 0x07;
		/*77*/ RedLevelData[77] = 0x0E; GreenLevelData[77] = 0x0F; BlueLevelData[77] = 0x00; BarrierLevelData[77] = 0x0F;
		/*78*/ RedLevelData[78] = 0x00; GreenLevelData[78] = 0x01; BlueLevelData[78] = 0x00; BarrierLevelData[78] = 0x01;
		/*79*/ RedLevelData[79] = 0x0E; GreenLevelData[79] = 0x0F; BlueLevelData[79] = 0x00; BarrierLevelData[79] = 0x0F;
		/*80*/ RedLevelData[80] = 0x06; GreenLevelData[80] = 0x07; BlueLevelData[80] = 0x00; BarrierLevelData[80] = 0x07;
		/*81*/ RedLevelData[81] = 0x42; GreenLevelData[81] = 0x43; BlueLevelData[81] = 0x40; BarrierLevelData[81] = 0x03;
		/*82*/ RedLevelData[82] = 0xC0; GreenLevelData[82] = 0xC1; BlueLevelData[82] = 0xC0; BarrierLevelData[82] = 0x01;
		/*83*/ RedLevelData[83] = 0x40; GreenLevelData[83] = 0x41; BlueLevelData[83] = 0x40; BarrierLevelData[83] = 0x01;
		/*84*/ RedLevelData[84] = 0x02; GreenLevelData[84] = 0x03; BlueLevelData[84] = 0x00; BarrierLevelData[84] = 0x03;
		/*85*/ RedLevelData[85] = 0x06; GreenLevelData[85] = 0x07; BlueLevelData[85] = 0x00; BarrierLevelData[85] = 0x07;
		/*86*/ RedLevelData[86] = 0x0E; GreenLevelData[86] = 0x0F; BlueLevelData[86] = 0x00; BarrierLevelData[86] = 0x0F;
		/*87*/ RedLevelData[87] = 0x0E; GreenLevelData[87] = 0x0F; BlueLevelData[87] = 0x00; BarrierLevelData[87] = 0x0F;
		/*88*/ RedLevelData[88] = 0x00; GreenLevelData[88] = 0x00; BlueLevelData[88] = 0x00; BarrierLevelData[88] = 0x00;
		/*89*/ RedLevelData[89] = 0x0E; GreenLevelData[89] = 0x0F; BlueLevelData[89] = 0x00; BarrierLevelData[89] = 0x0F;
		/*90*/ RedLevelData[90] = 0x06; GreenLevelData[90] = 0x07; BlueLevelData[90] = 0x00; BarrierLevelData[90] = 0x07;
		/*91*/ RedLevelData[91] = 0x02; GreenLevelData[91] = 0x03; BlueLevelData[91] = 0x00; BarrierLevelData[91] = 0x03;
		/*92*/ RedLevelData[92] = 0x00; GreenLevelData[92] = 0x01; BlueLevelData[92] = 0x00; BarrierLevelData[92] = 0x01;
		/*93*/ RedLevelData[93] = 0x00; GreenLevelData[93] = 0x07; BlueLevelData[93] = 0x00; BarrierLevelData[93] = 0x07;
		/*94*/ RedLevelData[94] = 0x00; GreenLevelData[94] = 0x07; BlueLevelData[94] = 0x00; BarrierLevelData[94] = 0x07;
		/*95*/ RedLevelData[95] = 0x00; GreenLevelData[95] = 0x01; BlueLevelData[95] = 0x00; BarrierLevelData[95] = 0x01;
		/*96*/ RedLevelData[96] = 0x00; GreenLevelData[96] = 0x01; BlueLevelData[96] = 0x00; BarrierLevelData[96] = 0x01;
		/*97*/ RedLevelData[97] = 0x08; GreenLevelData[97] = 0x09; BlueLevelData[97] = 0x00; BarrierLevelData[97] = 0x09;
		/*98*/ RedLevelData[98] = 0x08; GreenLevelData[98] = 0x09; BlueLevelData[98] = 0x00; BarrierLevelData[98] = 0x09;
		/*99*/ RedLevelData[99] = 0x00; GreenLevelData[99] = 0x01; BlueLevelData[99] = 0x00; BarrierLevelData[99] = 0x01;
		/*100*/ RedLevelData[100] = 0x00; GreenLevelData[100] = 0x01; BlueLevelData[100] = 0x00; BarrierLevelData[100] = 0x01;
		/*101*/ RedLevelData[101] = 0x02; GreenLevelData[101] = 0x03; BlueLevelData[101] = 0x00; BarrierLevelData[101] = 0x03;
		/*102*/ RedLevelData[102] = 0x06; GreenLevelData[102] = 0x07; BlueLevelData[102] = 0x00; BarrierLevelData[102] = 0x07;
		/*103*/ RedLevelData[103] = 0x0E; GreenLevelData[103] = 0x0F; BlueLevelData[103] = 0x00; BarrierLevelData[103] = 0x0F;
		/*104*/ RedLevelData[104] = 0x1E; GreenLevelData[104] = 0x1F; BlueLevelData[104] = 0x00; BarrierLevelData[104] = 0x1F;
		/*105*/ RedLevelData[105] = 0x00; GreenLevelData[105] = 0x01; BlueLevelData[105] = 0x00; BarrierLevelData[105] = 0x01;
		/*106*/ RedLevelData[106] = 0x00; GreenLevelData[106] = 0x01; BlueLevelData[106] = 0x00; BarrierLevelData[106] = 0x01;
		/*107*/ RedLevelData[107] = 0x00; GreenLevelData[107] = 0x01; BlueLevelData[107] = 0x00; BarrierLevelData[107] = 0x01;
		/*108*/ RedLevelData[108] = 0x00; GreenLevelData[108] = 0x01; BlueLevelData[108] = 0x00; BarrierLevelData[108] = 0x01;
		/*109*/ RedLevelData[109] = 0x00; GreenLevelData[109] = 0x01; BlueLevelData[109] = 0x00; BarrierLevelData[109] = 0x01;
		/*110*/ RedLevelData[110] = 0x40; GreenLevelData[110] = 0x41; BlueLevelData[110] = 0x40; BarrierLevelData[110] = 0x01;
		/*111*/ RedLevelData[111] = 0xE0; GreenLevelData[111] = 0xE1; BlueLevelData[111] = 0xE0; BarrierLevelData[111] = 0x01;
		/*112*/ RedLevelData[112] = 0xE0; GreenLevelData[112] = 0xE1; BlueLevelData[112] = 0xE0; BarrierLevelData[112] = 0x01;
		/*113*/ RedLevelData[113] = 0x4E; GreenLevelData[113] = 0x4F; BlueLevelData[113] = 0x40; BarrierLevelData[113] = 0x09;
		/*114*/ RedLevelData[114] = 0x1E; GreenLevelData[114] = 0x1F; BlueLevelData[114] = 0x00; BarrierLevelData[114] = 0x19;
		/*115*/ RedLevelData[115] = 0x18; GreenLevelData[115] = 0x19; BlueLevelData[115] = 0x00; BarrierLevelData[115] = 0x19;
		/*116*/ RedLevelData[116] = 0x1E; GreenLevelData[116] = 0x1F; BlueLevelData[116] = 0x00; BarrierLevelData[116] = 0x1F;
		/*117*/ RedLevelData[117] = 0x0E; GreenLevelData[117] = 0x0F; BlueLevelData[117] = 0x00; BarrierLevelData[117] = 0x0F;
		/*118*/ RedLevelData[118] = 0x00; GreenLevelData[118] = 0x01; BlueLevelData[118] = 0x00; BarrierLevelData[118] = 0x01;
		/*119*/ RedLevelData[119] = 0x00; GreenLevelData[119] = 0x01; BlueLevelData[119] = 0x00; BarrierLevelData[119] = 0x01;
		
}

void loadLevel2()
{
		/*0*/ RedLevelData[0] = 0x00; GreenLevelData[0] = 0x00; BlueLevelData[0] = 0xFF; BarrierLevelData[0] = 0xFF;
		/*1*/ RedLevelData[1] = 0x00; GreenLevelData[1] = 0x00; BlueLevelData[1] = 0x01; BarrierLevelData[1] = 0x01;
		/*2*/ RedLevelData[2] = 0x00; GreenLevelData[2] = 0x00; BlueLevelData[2] = 0x01; BarrierLevelData[2] = 0x01;
		/*3*/ RedLevelData[3] = 0x00; GreenLevelData[3] = 0x00; BlueLevelData[3] = 0x01; BarrierLevelData[3] = 0x01;
		/*4*/ RedLevelData[4] = 0x00; GreenLevelData[4] = 0x00; BlueLevelData[4] = 0x01; BarrierLevelData[4] = 0x01;
		/*5*/ RedLevelData[5] = 0x00; GreenLevelData[5] = 0x00; BlueLevelData[5] = 0x01; BarrierLevelData[5] = 0x01;
		/*6*/ RedLevelData[6] = 0x08; GreenLevelData[6] = 0x08; BlueLevelData[6] = 0x01; BarrierLevelData[6] = 0x09;
		/*7*/ RedLevelData[7] = 0x08; GreenLevelData[7] = 0x08; BlueLevelData[7] = 0x81; BarrierLevelData[7] = 0x89;
		/*8*/ RedLevelData[8] = 0x08; GreenLevelData[8] = 0x08; BlueLevelData[8] = 0x81; BarrierLevelData[8] = 0x89;
		/*9*/ RedLevelData[9] = 0x08; GreenLevelData[9] = 0x08; BlueLevelData[9] = 0x81; BarrierLevelData[9] = 0x89;
		/*10*/ RedLevelData[10] = 0x00; GreenLevelData[10] = 0x00; BlueLevelData[10] = 0x81; BarrierLevelData[10] = 0x81;
		/*11*/ RedLevelData[11] = 0x00; GreenLevelData[11] = 0x00; BlueLevelData[11] = 0x81; BarrierLevelData[11] = 0x81;
		/*12*/ RedLevelData[12] = 0x00; GreenLevelData[12] = 0x00; BlueLevelData[12] = 0x83; BarrierLevelData[12] = 0x83;
		/*13*/ RedLevelData[13] = 0x00; GreenLevelData[13] = 0x00; BlueLevelData[13] = 0x81; BarrierLevelData[13] = 0x81;
		/*14*/ RedLevelData[14] = 0x00; GreenLevelData[14] = 0x00; BlueLevelData[14] = 0x87; BarrierLevelData[14] = 0x87;
		/*15*/ RedLevelData[15] = 0x00; GreenLevelData[15] = 0x00; BlueLevelData[15] = 0x81; BarrierLevelData[15] = 0x81;
		/*16*/ RedLevelData[16] = 0x00; GreenLevelData[16] = 0x00; BlueLevelData[16] = 0x8F; BarrierLevelData[16] = 0x8F;
		/*17*/ RedLevelData[17] = 0x00; GreenLevelData[17] = 0x00; BlueLevelData[17] = 0x81; BarrierLevelData[17] = 0x81;
		/*18*/ RedLevelData[18] = 0x00; GreenLevelData[18] = 0x00; BlueLevelData[18] = 0x8F; BarrierLevelData[18] = 0x8F;
		/*19*/ RedLevelData[19] = 0x00; GreenLevelData[19] = 0x00; BlueLevelData[19] = 0x81; BarrierLevelData[19] = 0x81;
		/*20*/ RedLevelData[20] = 0x00; GreenLevelData[20] = 0x00; BlueLevelData[20] = 0x87; BarrierLevelData[20] = 0x87;
		/*21*/ RedLevelData[21] = 0x00; GreenLevelData[21] = 0x00; BlueLevelData[21] = 0x81; BarrierLevelData[21] = 0x81;
		/*22*/ RedLevelData[22] = 0x00; GreenLevelData[22] = 0x00; BlueLevelData[22] = 0x81; BarrierLevelData[22] = 0x81;
		/*23*/ RedLevelData[23] = 0x00; GreenLevelData[23] = 0x00; BlueLevelData[23] = 0x81; BarrierLevelData[23] = 0x81;
		/*24*/ RedLevelData[24] = 0x00; GreenLevelData[24] = 0x00; BlueLevelData[24] = 0x99; BarrierLevelData[24] = 0x99;
		/*25*/ RedLevelData[25] = 0x00; GreenLevelData[25] = 0x00; BlueLevelData[25] = 0x89; BarrierLevelData[25] = 0x89;
		/*26*/ RedLevelData[26] = 0x00; GreenLevelData[26] = 0x00; BlueLevelData[26] = 0x99; BarrierLevelData[26] = 0x99;
		/*27*/ RedLevelData[27] = 0x00; GreenLevelData[27] = 0x00; BlueLevelData[27] = 0x91; BarrierLevelData[27] = 0x91;
		/*28*/ RedLevelData[28] = 0x00; GreenLevelData[28] = 0x00; BlueLevelData[28] = 0x99; BarrierLevelData[28] = 0x99;
		/*29*/ RedLevelData[29] = 0x00; GreenLevelData[29] = 0x00; BlueLevelData[29] = 0x89; BarrierLevelData[29] = 0x89;
		/*30*/ RedLevelData[30] = 0x00; GreenLevelData[30] = 0x00; BlueLevelData[30] = 0x99; BarrierLevelData[30] = 0x99;
		/*31*/ RedLevelData[31] = 0x00; GreenLevelData[31] = 0x00; BlueLevelData[31] = 0x81; BarrierLevelData[31] = 0x81;
		/*32*/ RedLevelData[32] = 0x00; GreenLevelData[32] = 0x00; BlueLevelData[32] = 0x81; BarrierLevelData[32] = 0x81;
		/*33*/ RedLevelData[33] = 0x00; GreenLevelData[33] = 0x00; BlueLevelData[33] = 0xB1; BarrierLevelData[33] = 0xB1;
		/*34*/ RedLevelData[34] = 0x00; GreenLevelData[34] = 0x00; BlueLevelData[34] = 0xFD; BarrierLevelData[34] = 0xFD;
		/*35*/ RedLevelData[35] = 0x00; GreenLevelData[35] = 0x00; BlueLevelData[35] = 0xCD; BarrierLevelData[35] = 0xCD;
		/*36*/ RedLevelData[36] = 0x00; GreenLevelData[36] = 0x00; BlueLevelData[36] = 0x81; BarrierLevelData[36] = 0x81;
		/*37*/ RedLevelData[37] = 0x00; GreenLevelData[37] = 0x00; BlueLevelData[37] = 0xC9; BarrierLevelData[37] = 0xC9;
		/*38*/ RedLevelData[38] = 0x00; GreenLevelData[38] = 0x00; BlueLevelData[38] = 0xC9; BarrierLevelData[38] = 0xC9;
		/*39*/ RedLevelData[39] = 0x00; GreenLevelData[39] = 0x00; BlueLevelData[39] = 0xF9; BarrierLevelData[39] = 0xF9;
		/*40*/ RedLevelData[40] = 0x00; GreenLevelData[40] = 0x00; BlueLevelData[40] = 0x81; BarrierLevelData[40] = 0x81;
		/*41*/ RedLevelData[41] = 0x00; GreenLevelData[41] = 0x00; BlueLevelData[41] = 0xC1; BarrierLevelData[41] = 0xC1;
		/*42*/ RedLevelData[42] = 0x00; GreenLevelData[42] = 0x00; BlueLevelData[42] = 0xF9; BarrierLevelData[42] = 0xF9;
		/*43*/ RedLevelData[43] = 0x00; GreenLevelData[43] = 0x00; BlueLevelData[43] = 0x89; BarrierLevelData[43] = 0x89;
		/*44*/ RedLevelData[44] = 0x00; GreenLevelData[44] = 0x00; BlueLevelData[44] = 0x99; BarrierLevelData[44] = 0x99;
		/*45*/ RedLevelData[45] = 0x00; GreenLevelData[45] = 0x00; BlueLevelData[45] = 0x81; BarrierLevelData[45] = 0x81;
		/*46*/ RedLevelData[46] = 0x00; GreenLevelData[46] = 0x00; BlueLevelData[46] = 0x9D; BarrierLevelData[46] = 0x9D;
		/*47*/ RedLevelData[47] = 0x00; GreenLevelData[47] = 0x00; BlueLevelData[47] = 0x9D; BarrierLevelData[47] = 0x9D;
		/*48*/ RedLevelData[48] = 0x00; GreenLevelData[48] = 0x00; BlueLevelData[48] = 0x81; BarrierLevelData[48] = 0x81;
		/*49*/ RedLevelData[49] = 0x00; GreenLevelData[49] = 0x00; BlueLevelData[49] = 0xC9; BarrierLevelData[49] = 0xC9;
		/*50*/ RedLevelData[50] = 0x00; GreenLevelData[50] = 0x00; BlueLevelData[50] = 0xC9; BarrierLevelData[50] = 0xC9;
		/*51*/ RedLevelData[51] = 0x00; GreenLevelData[51] = 0x00; BlueLevelData[51] = 0x80; BarrierLevelData[51] = 0x80;
		/*52*/ RedLevelData[52] = 0x00; GreenLevelData[52] = 0x00; BlueLevelData[52] = 0x80; BarrierLevelData[52] = 0x80;
		/*53*/ RedLevelData[53] = 0x00; GreenLevelData[53] = 0x00; BlueLevelData[53] = 0x81; BarrierLevelData[53] = 0x81;
		/*54*/ RedLevelData[54] = 0x00; GreenLevelData[54] = 0x00; BlueLevelData[54] = 0x89; BarrierLevelData[54] = 0x89;
		/*55*/ RedLevelData[55] = 0x00; GreenLevelData[55] = 0x00; BlueLevelData[55] = 0x89; BarrierLevelData[55] = 0x89;
		/*56*/ RedLevelData[56] = 0x00; GreenLevelData[56] = 0x00; BlueLevelData[56] = 0x89; BarrierLevelData[56] = 0x89;
		/*57*/ RedLevelData[57] = 0x00; GreenLevelData[57] = 0x00; BlueLevelData[57] = 0x81; BarrierLevelData[57] = 0x81;
		/*58*/ RedLevelData[58] = 0x00; GreenLevelData[58] = 0x00; BlueLevelData[58] = 0x81; BarrierLevelData[58] = 0x81;
		/*59*/ RedLevelData[59] = 0x00; GreenLevelData[59] = 0x00; BlueLevelData[59] = 0x81; BarrierLevelData[59] = 0x81;
		/*60*/ RedLevelData[60] = 0x00; GreenLevelData[60] = 0x00; BlueLevelData[60] = 0x81; BarrierLevelData[60] = 0x81;
		/*61*/ RedLevelData[61] = 0x00; GreenLevelData[61] = 0x00; BlueLevelData[61] = 0x81; BarrierLevelData[61] = 0x81;
		/*62*/ RedLevelData[62] = 0x00; GreenLevelData[62] = 0x00; BlueLevelData[62] = 0x81; BarrierLevelData[62] = 0x81;
		/*63*/ RedLevelData[63] = 0x00; GreenLevelData[63] = 0x00; BlueLevelData[63] = 0x81; BarrierLevelData[63] = 0x81;
		/*64*/ RedLevelData[64] = 0x00; GreenLevelData[64] = 0x06; BlueLevelData[64] = 0x81; BarrierLevelData[64] = 0x87;
		/*65*/ RedLevelData[65] = 0x00; GreenLevelData[65] = 0x06; BlueLevelData[65] = 0x81; BarrierLevelData[65] = 0x87;
		/*66*/ RedLevelData[66] = 0x00; GreenLevelData[66] = 0x00; BlueLevelData[66] = 0x81; BarrierLevelData[66] = 0x81;
		/*67*/ RedLevelData[67] = 0x00; GreenLevelData[67] = 0x00; BlueLevelData[67] = 0x81; BarrierLevelData[67] = 0x81;
		/*68*/ RedLevelData[68] = 0x00; GreenLevelData[68] = 0x0E; BlueLevelData[68] = 0x81; BarrierLevelData[68] = 0x8F;
		/*69*/ RedLevelData[69] = 0x00; GreenLevelData[69] = 0x0E; BlueLevelData[69] = 0x81; BarrierLevelData[69] = 0x8F;
		/*70*/ RedLevelData[70] = 0x00; GreenLevelData[70] = 0x00; BlueLevelData[70] = 0x81; BarrierLevelData[70] = 0x81;
		/*71*/ RedLevelData[71] = 0x00; GreenLevelData[71] = 0x00; BlueLevelData[71] = 0x81; BarrierLevelData[71] = 0x81;
		/*72*/ RedLevelData[72] = 0x00; GreenLevelData[72] = 0x06; BlueLevelData[72] = 0x81; BarrierLevelData[72] = 0x87;
		/*73*/ RedLevelData[73] = 0x00; GreenLevelData[73] = 0x06; BlueLevelData[73] = 0x81; BarrierLevelData[73] = 0x87;
		/*74*/ RedLevelData[74] = 0x00; GreenLevelData[74] = 0x00; BlueLevelData[74] = 0x80; BarrierLevelData[74] = 0x80;
		/*75*/ RedLevelData[75] = 0x00; GreenLevelData[75] = 0x00; BlueLevelData[75] = 0x80; BarrierLevelData[75] = 0x80;
		/*76*/ RedLevelData[76] = 0x00; GreenLevelData[76] = 0x00; BlueLevelData[76] = 0x80; BarrierLevelData[76] = 0x80;
		/*77*/ RedLevelData[77] = 0x00; GreenLevelData[77] = 0x00; BlueLevelData[77] = 0x83; BarrierLevelData[77] = 0x83;
		/*78*/ RedLevelData[78] = 0x00; GreenLevelData[78] = 0x00; BlueLevelData[78] = 0x80; BarrierLevelData[78] = 0x80;
		/*79*/ RedLevelData[79] = 0x00; GreenLevelData[79] = 0x00; BlueLevelData[79] = 0x80; BarrierLevelData[79] = 0x80;
		/*80*/ RedLevelData[80] = 0x00; GreenLevelData[80] = 0x00; BlueLevelData[80] = 0x81; BarrierLevelData[80] = 0x81;
		/*81*/ RedLevelData[81] = 0x00; GreenLevelData[81] = 0x00; BlueLevelData[81] = 0x81; BarrierLevelData[81] = 0x81;
		/*82*/ RedLevelData[82] = 0x00; GreenLevelData[82] = 0x00; BlueLevelData[82] = 0x81; BarrierLevelData[82] = 0x81;
		/*83*/ RedLevelData[83] = 0x00; GreenLevelData[83] = 0x00; BlueLevelData[83] = 0x81; BarrierLevelData[83] = 0x81;
		/*84*/ RedLevelData[84] = 0x00; GreenLevelData[84] = 0x00; BlueLevelData[84] = 0x83; BarrierLevelData[84] = 0x83;
		/*85*/ RedLevelData[85] = 0x00; GreenLevelData[85] = 0x00; BlueLevelData[85] = 0x07; BarrierLevelData[85] = 0x07;
		/*86*/ RedLevelData[86] = 0x00; GreenLevelData[86] = 0x00; BlueLevelData[86] = 0x0F; BarrierLevelData[86] = 0x0F;
		/*87*/ RedLevelData[87] = 0x00; GreenLevelData[87] = 0x00; BlueLevelData[87] = 0x00; BarrierLevelData[87] = 0x00;
		/*88*/ RedLevelData[88] = 0x42; GreenLevelData[88] = 0x42; BlueLevelData[88] = 0x00; BarrierLevelData[88] = 0x42;
		/*89*/ RedLevelData[89] = 0x00; GreenLevelData[89] = 0x00; BlueLevelData[89] = 0x00; BarrierLevelData[89] = 0x00;
		/*90*/ RedLevelData[90] = 0x00; GreenLevelData[90] = 0x00; BlueLevelData[90] = 0x08; BarrierLevelData[90] = 0x08;
		/*91*/ RedLevelData[91] = 0x00; GreenLevelData[91] = 0x00; BlueLevelData[91] = 0x08; BarrierLevelData[91] = 0x08;
		/*92*/ RedLevelData[92] = 0x00; GreenLevelData[92] = 0x00; BlueLevelData[92] = 0x08; BarrierLevelData[92] = 0x08;
		/*93*/ RedLevelData[93] = 0x00; GreenLevelData[93] = 0x00; BlueLevelData[93] = 0x08; BarrierLevelData[93] = 0x08;
		/*94*/ RedLevelData[94] = 0x00; GreenLevelData[94] = 0x00; BlueLevelData[94] = 0x08; BarrierLevelData[94] = 0x08;
		/*95*/ RedLevelData[95] = 0x00; GreenLevelData[95] = 0x00; BlueLevelData[95] = 0x00; BarrierLevelData[95] = 0x00;
		/*96*/ RedLevelData[96] = 0x00; GreenLevelData[96] = 0x00; BlueLevelData[96] = 0x00; BarrierLevelData[96] = 0x00;
		/*97*/ RedLevelData[97] = 0x42; GreenLevelData[97] = 0x42; BlueLevelData[97] = 0x00; BarrierLevelData[97] = 0x42;
		/*98*/ RedLevelData[98] = 0x42; GreenLevelData[98] = 0x42; BlueLevelData[98] = 0x00; BarrierLevelData[98] = 0x42;
		/*99*/ RedLevelData[99] = 0x00; GreenLevelData[99] = 0x00; BlueLevelData[99] = 0x00; BarrierLevelData[99] = 0x00;
		/*100*/ RedLevelData[100] = 0x00; GreenLevelData[100] = 0x00; BlueLevelData[100] = 0x00; BarrierLevelData[100] = 0x00;
		/*101*/ RedLevelData[101] = 0x00; GreenLevelData[101] = 0x00; BlueLevelData[101] = 0x83; BarrierLevelData[101] = 0x83;
		/*102*/ RedLevelData[102] = 0x00; GreenLevelData[102] = 0x00; BlueLevelData[102] = 0x83; BarrierLevelData[102] = 0x83;
		/*103*/ RedLevelData[103] = 0x00; GreenLevelData[103] = 0x00; BlueLevelData[103] = 0x83; BarrierLevelData[103] = 0x83;
		/*104*/ RedLevelData[104] = 0x00; GreenLevelData[104] = 0x00; BlueLevelData[104] = 0x83; BarrierLevelData[104] = 0x83;
		/*105*/ RedLevelData[105] = 0x00; GreenLevelData[105] = 0x00; BlueLevelData[105] = 0x83; BarrierLevelData[105] = 0x83;
		/*106*/ RedLevelData[106] = 0x00; GreenLevelData[106] = 0x00; BlueLevelData[106] = 0x83; BarrierLevelData[106] = 0x83;
		/*107*/ RedLevelData[107] = 0x00; GreenLevelData[107] = 0x00; BlueLevelData[107] = 0x83; BarrierLevelData[107] = 0x83;
		/*108*/ RedLevelData[108] = 0x00; GreenLevelData[108] = 0x00; BlueLevelData[108] = 0x83; BarrierLevelData[108] = 0x83;
		/*109*/ RedLevelData[109] = 0x00; GreenLevelData[109] = 0x00; BlueLevelData[109] = 0x83; BarrierLevelData[109] = 0x83;
		/*110*/ RedLevelData[110] = 0x00; GreenLevelData[110] = 0x00; BlueLevelData[110] = 0x83; BarrierLevelData[110] = 0x83;
		/*111*/ RedLevelData[111] = 0x00; GreenLevelData[111] = 0x00; BlueLevelData[111] = 0x81; BarrierLevelData[111] = 0x81;
		/*112*/ RedLevelData[112] = 0x00; GreenLevelData[112] = 0x00; BlueLevelData[112] = 0x81; BarrierLevelData[112] = 0x81;
		/*113*/ RedLevelData[113] = 0x00; GreenLevelData[113] = 0x00; BlueLevelData[113] = 0x8F; BarrierLevelData[113] = 0x89;
		/*114*/ RedLevelData[114] = 0x00; GreenLevelData[114] = 0x00; BlueLevelData[114] = 0x9F; BarrierLevelData[114] = 0x99;
		/*115*/ RedLevelData[115] = 0x00; GreenLevelData[115] = 0x00; BlueLevelData[115] = 0x99; BarrierLevelData[115] = 0x99;
		/*116*/ RedLevelData[116] = 0x00; GreenLevelData[116] = 0x00; BlueLevelData[116] = 0x9F; BarrierLevelData[116] = 0x9F;
		/*117*/ RedLevelData[117] = 0x00; GreenLevelData[117] = 0x00; BlueLevelData[117] = 0x8F; BarrierLevelData[117] = 0x8F;
		/*118*/ RedLevelData[118] = 0x00; GreenLevelData[118] = 0x00; BlueLevelData[118] = 0x81; BarrierLevelData[118] = 0x81;
		/*119*/ RedLevelData[119] = 0x00; GreenLevelData[119] = 0x00; BlueLevelData[119] = 0xFF; BarrierLevelData[119] = 0xFF;
}

void loadLevel3()
{
		/*0*/ RedLevelData[0] = 0x01; GreenLevelData[0] = 0x01; BlueLevelData[0] = 0x00; BarrierLevelData[0] = 0x01;
		/*1*/ RedLevelData[1] = 0x81; GreenLevelData[1] = 0x81; BlueLevelData[1] = 0x80; BarrierLevelData[1] = 0x01;
		/*2*/ RedLevelData[2] = 0xC1; GreenLevelData[2] = 0xC1; BlueLevelData[2] = 0xC0; BarrierLevelData[2] = 0x01;
		/*3*/ RedLevelData[3] = 0x41; GreenLevelData[3] = 0x41; BlueLevelData[3] = 0x40; BarrierLevelData[3] = 0x01;
		/*4*/ RedLevelData[4] = 0x01; GreenLevelData[4] = 0x01; BlueLevelData[4] = 0x00; BarrierLevelData[4] = 0x01;
		/*5*/ RedLevelData[5] = 0x01; GreenLevelData[5] = 0x01; BlueLevelData[5] = 0x00; BarrierLevelData[5] = 0x01;
		/*6*/ RedLevelData[6] = 0x01; GreenLevelData[6] = 0x01; BlueLevelData[6] = 0x00; BarrierLevelData[6] = 0x01;
		/*7*/ RedLevelData[7] = 0x11; GreenLevelData[7] = 0x11; BlueLevelData[7] = 0x10; BarrierLevelData[7] = 0x01;
		/*8*/ RedLevelData[8] = 0x31; GreenLevelData[8] = 0x31; BlueLevelData[8] = 0x30; BarrierLevelData[8] = 0x01;
		/*9*/ RedLevelData[9] = 0x11; GreenLevelData[9] = 0x11; BlueLevelData[9] = 0x10; BarrierLevelData[9] = 0x01;
		/*10*/ RedLevelData[10] = 0x01; GreenLevelData[10] = 0x01; BlueLevelData[10] = 0x00; BarrierLevelData[10] = 0x01;
		/*11*/ RedLevelData[11] = 0x00; GreenLevelData[11] = 0x00; BlueLevelData[11] = 0x00; BarrierLevelData[11] = 0x00;
		/*12*/ RedLevelData[12] = 0x00; GreenLevelData[12] = 0x02; BlueLevelData[12] = 0x00; BarrierLevelData[12] = 0x02;
		/*13*/ RedLevelData[13] = 0x01; GreenLevelData[13] = 0x03; BlueLevelData[13] = 0x00; BarrierLevelData[13] = 0x02;
		/*14*/ RedLevelData[14] = 0x80; GreenLevelData[14] = 0x82; BlueLevelData[14] = 0x80; BarrierLevelData[14] = 0x02;
		/*15*/ RedLevelData[15] = 0x80; GreenLevelData[15] = 0x80; BlueLevelData[15] = 0x80; BarrierLevelData[15] = 0x00;
		/*16*/ RedLevelData[16] = 0x00; GreenLevelData[16] = 0x00; BlueLevelData[16] = 0x00; BarrierLevelData[16] = 0x00;
		/*17*/ RedLevelData[17] = 0x00; GreenLevelData[17] = 0x04; BlueLevelData[17] = 0x00; BarrierLevelData[17] = 0x04;
		/*18*/ RedLevelData[18] = 0x03; GreenLevelData[18] = 0x27; BlueLevelData[18] = 0x00; BarrierLevelData[18] = 0x24;
		/*19*/ RedLevelData[19] = 0x1B; GreenLevelData[19] = 0x3F; BlueLevelData[19] = 0x00; BarrierLevelData[19] = 0x24;
		/*20*/ RedLevelData[20] = 0x1B; GreenLevelData[20] = 0x3F; BlueLevelData[20] = 0x00; BarrierLevelData[20] = 0x24;
		/*21*/ RedLevelData[21] = 0x00; GreenLevelData[21] = 0x24; BlueLevelData[21] = 0x00; BarrierLevelData[21] = 0x24;
		/*22*/ RedLevelData[22] = 0x00; GreenLevelData[22] = 0x00; BlueLevelData[22] = 0x00; BarrierLevelData[22] = 0x00;
		/*23*/ RedLevelData[23] = 0x00; GreenLevelData[23] = 0x02; BlueLevelData[23] = 0x00; BarrierLevelData[23] = 0x02;
		/*24*/ RedLevelData[24] = 0x01; GreenLevelData[24] = 0x03; BlueLevelData[24] = 0x00; BarrierLevelData[24] = 0x02;
		/*25*/ RedLevelData[25] = 0x00; GreenLevelData[25] = 0x02; BlueLevelData[25] = 0x00; BarrierLevelData[25] = 0x02;
		/*26*/ RedLevelData[26] = 0x00; GreenLevelData[26] = 0x08; BlueLevelData[26] = 0x00; BarrierLevelData[26] = 0x08;
		/*27*/ RedLevelData[27] = 0x07; GreenLevelData[27] = 0x0F; BlueLevelData[27] = 0x00; BarrierLevelData[27] = 0x08;
		/*28*/ RedLevelData[28] = 0x07; GreenLevelData[28] = 0x0F; BlueLevelData[28] = 0x00; BarrierLevelData[28] = 0x08;
		/*29*/ RedLevelData[29] = 0x00; GreenLevelData[29] = 0x08; BlueLevelData[29] = 0x00; BarrierLevelData[29] = 0x08;
		/*30*/ RedLevelData[30] = 0x00; GreenLevelData[30] = 0x20; BlueLevelData[30] = 0x00; BarrierLevelData[30] = 0x20;
		/*31*/ RedLevelData[31] = 0x1F; GreenLevelData[31] = 0x3F; BlueLevelData[31] = 0x00; BarrierLevelData[31] = 0x20;
		/*32*/ RedLevelData[32] = 0x1F; GreenLevelData[32] = 0x3F; BlueLevelData[32] = 0x00; BarrierLevelData[32] = 0x20;
		/*33*/ RedLevelData[33] = 0x00; GreenLevelData[33] = 0x20; BlueLevelData[33] = 0x00; BarrierLevelData[33] = 0x20;
		/*34*/ RedLevelData[34] = 0x00; GreenLevelData[34] = 0x00; BlueLevelData[34] = 0x00; BarrierLevelData[34] = 0x00;
		/*35*/ RedLevelData[35] = 0x10; GreenLevelData[35] = 0x11; BlueLevelData[35] = 0x10; BarrierLevelData[35] = 0x01;
		/*36*/ RedLevelData[36] = 0x30; GreenLevelData[36] = 0x31; BlueLevelData[36] = 0x30; BarrierLevelData[36] = 0x01;
		/*37*/ RedLevelData[37] = 0x10; GreenLevelData[37] = 0x11; BlueLevelData[37] = 0x10; BarrierLevelData[37] = 0x01;
		/*38*/ RedLevelData[38] = 0x00; GreenLevelData[38] = 0x00; BlueLevelData[38] = 0x00; BarrierLevelData[38] = 0x00;
		/*39*/ RedLevelData[39] = 0x04; GreenLevelData[39] = 0x04; BlueLevelData[39] = 0x00; BarrierLevelData[39] = 0x04;
		/*40*/ RedLevelData[40] = 0x04; GreenLevelData[40] = 0x04; BlueLevelData[40] = 0x00; BarrierLevelData[40] = 0x04;
		/*41*/ RedLevelData[41] = 0x00; GreenLevelData[41] = 0x00; BlueLevelData[41] = 0x00; BarrierLevelData[41] = 0x00;
		/*42*/ RedLevelData[42] = 0x00; GreenLevelData[42] = 0x00; BlueLevelData[42] = 0x00; BarrierLevelData[42] = 0x00;
		/*43*/ RedLevelData[43] = 0x00; GreenLevelData[43] = 0x01; BlueLevelData[43] = 0x00; BarrierLevelData[43] = 0x01;
		/*44*/ RedLevelData[44] = 0x00; GreenLevelData[44] = 0x11; BlueLevelData[44] = 0x00; BarrierLevelData[44] = 0x11;
		/*45*/ RedLevelData[45] = 0x0E; GreenLevelData[45] = 0x1F; BlueLevelData[45] = 0x00; BarrierLevelData[45] = 0x11;
		/*46*/ RedLevelData[46] = 0x00; GreenLevelData[46] = 0x11; BlueLevelData[46] = 0x00; BarrierLevelData[46] = 0x11;
		/*47*/ RedLevelData[47] = 0x00; GreenLevelData[47] = 0x00; BlueLevelData[47] = 0x00; BarrierLevelData[47] = 0x00;
		/*48*/ RedLevelData[48] = 0x00; GreenLevelData[48] = 0x00; BlueLevelData[48] = 0x00; BarrierLevelData[48] = 0x00;
		/*49*/ RedLevelData[49] = 0x00; GreenLevelData[49] = 0x00; BlueLevelData[49] = 0x00; BarrierLevelData[49] = 0x00;
		/*50*/ RedLevelData[50] = 0x00; GreenLevelData[50] = 0x08; BlueLevelData[50] = 0x00; BarrierLevelData[50] = 0x08;
		/*51*/ RedLevelData[51] = 0x47; GreenLevelData[51] = 0x4F; BlueLevelData[51] = 0x40; BarrierLevelData[51] = 0x08;
		/*52*/ RedLevelData[52] = 0xC0; GreenLevelData[52] = 0xC8; BlueLevelData[52] = 0xC0; BarrierLevelData[52] = 0x08;
		/*53*/ RedLevelData[53] = 0x40; GreenLevelData[53] = 0x40; BlueLevelData[53] = 0x40; BarrierLevelData[53] = 0x00;
		/*54*/ RedLevelData[54] = 0x00; GreenLevelData[54] = 0x00; BlueLevelData[54] = 0x00; BarrierLevelData[54] = 0x00;
		/*55*/ RedLevelData[55] = 0x00; GreenLevelData[55] = 0x10; BlueLevelData[55] = 0x00; BarrierLevelData[55] = 0x10;
		/*56*/ RedLevelData[56] = 0x0F; GreenLevelData[56] = 0x1F; BlueLevelData[56] = 0x00; BarrierLevelData[56] = 0x10;
		/*57*/ RedLevelData[57] = 0x0F; GreenLevelData[57] = 0x1F; BlueLevelData[57] = 0x00; BarrierLevelData[57] = 0x10;
		/*58*/ RedLevelData[58] = 0x00; GreenLevelData[58] = 0x10; BlueLevelData[58] = 0x00; BarrierLevelData[58] = 0x10;
		/*59*/ RedLevelData[59] = 0x00; GreenLevelData[59] = 0x00; BlueLevelData[59] = 0x00; BarrierLevelData[59] = 0x00;
		/*60*/ RedLevelData[60] = 0x00; GreenLevelData[60] = 0x00; BlueLevelData[60] = 0x00; BarrierLevelData[60] = 0x00;
		/*61*/ RedLevelData[61] = 0x08; GreenLevelData[61] = 0x08; BlueLevelData[61] = 0x00; BarrierLevelData[61] = 0x08;
		/*62*/ RedLevelData[62] = 0x08; GreenLevelData[62] = 0x08; BlueLevelData[62] = 0x00; BarrierLevelData[62] = 0x08;
		/*63*/ RedLevelData[63] = 0x00; GreenLevelData[63] = 0x00; BlueLevelData[63] = 0x00; BarrierLevelData[63] = 0x00;
		/*64*/ RedLevelData[64] = 0x00; GreenLevelData[64] = 0x00; BlueLevelData[64] = 0x00; BarrierLevelData[64] = 0x00;
		/*65*/ RedLevelData[65] = 0x00; GreenLevelData[65] = 0x00; BlueLevelData[65] = 0x00; BarrierLevelData[65] = 0x00;
		/*66*/ RedLevelData[66] = 0x44; GreenLevelData[66] = 0x44; BlueLevelData[66] = 0x40; BarrierLevelData[66] = 0x04;
		/*67*/ RedLevelData[67] = 0xC4; GreenLevelData[67] = 0xC4; BlueLevelData[67] = 0xC0; BarrierLevelData[67] = 0x04;
		/*68*/ RedLevelData[68] = 0xC0; GreenLevelData[68] = 0xC0; BlueLevelData[68] = 0xC0; BarrierLevelData[68] = 0x00;
		/*69*/ RedLevelData[69] = 0x80; GreenLevelData[69] = 0x80; BlueLevelData[69] = 0x80; BarrierLevelData[69] = 0x00;
		/*70*/ RedLevelData[70] = 0x00; GreenLevelData[70] = 0x00; BlueLevelData[70] = 0x00; BarrierLevelData[70] = 0x00;
		/*71*/ RedLevelData[71] = 0x00; GreenLevelData[71] = 0x04; BlueLevelData[71] = 0x00; BarrierLevelData[71] = 0x04;
		/*72*/ RedLevelData[72] = 0x03; GreenLevelData[72] = 0x07; BlueLevelData[72] = 0x00; BarrierLevelData[72] = 0x04;
		/*73*/ RedLevelData[73] = 0x00; GreenLevelData[73] = 0x04; BlueLevelData[73] = 0x00; BarrierLevelData[73] = 0x04;
		/*74*/ RedLevelData[74] = 0x00; GreenLevelData[74] = 0x00; BlueLevelData[74] = 0x00; BarrierLevelData[74] = 0x00;
		/*75*/ RedLevelData[75] = 0x00; GreenLevelData[75] = 0x00; BlueLevelData[75] = 0x00; BarrierLevelData[75] = 0x00;
		/*76*/ RedLevelData[76] = 0x00; GreenLevelData[76] = 0x10; BlueLevelData[76] = 0x00; BarrierLevelData[76] = 0x10;
		/*77*/ RedLevelData[77] = 0x0F; GreenLevelData[77] = 0x1F; BlueLevelData[77] = 0x00; BarrierLevelData[77] = 0x10;
		/*78*/ RedLevelData[78] = 0x0F; GreenLevelData[78] = 0x1F; BlueLevelData[78] = 0x00; BarrierLevelData[78] = 0x10;
		/*79*/ RedLevelData[79] = 0x0F; GreenLevelData[79] = 0x1F; BlueLevelData[79] = 0x00; BarrierLevelData[79] = 0x10;
		/*80*/ RedLevelData[80] = 0x0F; GreenLevelData[80] = 0x1F; BlueLevelData[80] = 0x00; BarrierLevelData[80] = 0x10;
		/*81*/ RedLevelData[81] = 0x00; GreenLevelData[81] = 0x10; BlueLevelData[81] = 0x00; BarrierLevelData[81] = 0x10;
		/*82*/ RedLevelData[82] = 0x00; GreenLevelData[82] = 0x00; BlueLevelData[82] = 0x00; BarrierLevelData[82] = 0x00;
		/*83*/ RedLevelData[83] = 0x00; GreenLevelData[83] = 0x00; BlueLevelData[83] = 0x00; BarrierLevelData[83] = 0x00;
		/*84*/ RedLevelData[84] = 0x40; GreenLevelData[84] = 0x40; BlueLevelData[84] = 0x40; BarrierLevelData[84] = 0x00;
		/*85*/ RedLevelData[85] = 0xE0; GreenLevelData[85] = 0xE0; BlueLevelData[85] = 0xE0; BarrierLevelData[85] = 0x00;
		/*86*/ RedLevelData[86] = 0xC0; GreenLevelData[86] = 0xC4; BlueLevelData[86] = 0xC0; BarrierLevelData[86] = 0x04;
		/*87*/ RedLevelData[87] = 0x83; GreenLevelData[87] = 0x87; BlueLevelData[87] = 0x80; BarrierLevelData[87] = 0x04;
		/*88*/ RedLevelData[88] = 0x03; GreenLevelData[88] = 0x07; BlueLevelData[88] = 0x00; BarrierLevelData[88] = 0x04;
		/*89*/ RedLevelData[89] = 0x00; GreenLevelData[89] = 0x04; BlueLevelData[89] = 0x00; BarrierLevelData[89] = 0x04;
		/*90*/ RedLevelData[90] = 0x00; GreenLevelData[90] = 0x00; BlueLevelData[90] = 0x00; BarrierLevelData[90] = 0x00;
		/*91*/ RedLevelData[91] = 0x00; GreenLevelData[91] = 0x00; BlueLevelData[91] = 0x00; BarrierLevelData[91] = 0x00;
		/*92*/ RedLevelData[92] = 0x00; GreenLevelData[92] = 0x00; BlueLevelData[92] = 0x00; BarrierLevelData[92] = 0x00;
		/*93*/ RedLevelData[93] = 0x20; GreenLevelData[93] = 0x20; BlueLevelData[93] = 0x00; BarrierLevelData[93] = 0x20;
		/*94*/ RedLevelData[94] = 0x21; GreenLevelData[94] = 0x21; BlueLevelData[94] = 0x00; BarrierLevelData[94] = 0x21;
		/*95*/ RedLevelData[95] = 0x01; GreenLevelData[95] = 0x01; BlueLevelData[95] = 0x00; BarrierLevelData[95] = 0x01;
		/*96*/ RedLevelData[96] = 0x01; GreenLevelData[96] = 0x01; BlueLevelData[96] = 0x00; BarrierLevelData[96] = 0x01;
		/*97*/ RedLevelData[97] = 0x01; GreenLevelData[97] = 0x01; BlueLevelData[97] = 0x00; BarrierLevelData[97] = 0x01;
		/*98*/ RedLevelData[98] = 0x01; GreenLevelData[98] = 0x01; BlueLevelData[98] = 0x00; BarrierLevelData[98] = 0x01;
		/*99*/ RedLevelData[99] = 0x01; GreenLevelData[99] = 0x01; BlueLevelData[99] = 0x00; BarrierLevelData[99] = 0x01;
		/*100*/ RedLevelData[100] = 0x01; GreenLevelData[100] = 0x01; BlueLevelData[100] = 0x00; BarrierLevelData[100] = 0x01;
		/*101*/ RedLevelData[101] = 0x07; GreenLevelData[101] = 0x07; BlueLevelData[101] = 0x00; BarrierLevelData[101] = 0x07;
		/*102*/ RedLevelData[102] = 0x07; GreenLevelData[102] = 0x07; BlueLevelData[102] = 0x00; BarrierLevelData[102] = 0x07;
		/*103*/ RedLevelData[103] = 0x1F; GreenLevelData[103] = 0x1F; BlueLevelData[103] = 0x00; BarrierLevelData[103] = 0x1F;
		/*104*/ RedLevelData[104] = 0x1F; GreenLevelData[104] = 0x1F; BlueLevelData[104] = 0x00; BarrierLevelData[104] = 0x1F;
		/*105*/ RedLevelData[105] = 0x01; GreenLevelData[105] = 0x01; BlueLevelData[105] = 0x00; BarrierLevelData[105] = 0x01;
		/*106*/ RedLevelData[106] = 0x01; GreenLevelData[106] = 0x01; BlueLevelData[106] = 0x00; BarrierLevelData[106] = 0x01;
		/*107*/ RedLevelData[107] = 0x41; GreenLevelData[107] = 0x41; BlueLevelData[107] = 0x40; BarrierLevelData[107] = 0x01;
		/*108*/ RedLevelData[108] = 0xE1; GreenLevelData[108] = 0xE1; BlueLevelData[108] = 0xE0; BarrierLevelData[108] = 0x01;
		/*109*/ RedLevelData[109] = 0xE1; GreenLevelData[109] = 0xE1; BlueLevelData[109] = 0xE0; BarrierLevelData[109] = 0x01;
		/*110*/ RedLevelData[110] = 0x41; GreenLevelData[110] = 0x41; BlueLevelData[110] = 0x40; BarrierLevelData[110] = 0x01;
		/*111*/ RedLevelData[111] = 0x01; GreenLevelData[111] = 0x01; BlueLevelData[111] = 0x00; BarrierLevelData[111] = 0x01;
		/*112*/ RedLevelData[112] = 0x01; GreenLevelData[112] = 0x01; BlueLevelData[112] = 0x1E; BarrierLevelData[112] = 0x01;
		/*113*/ RedLevelData[113] = 0x01; GreenLevelData[113] = 0x01; BlueLevelData[113] = 0x3E; BarrierLevelData[113] = 0x01;
		/*114*/ RedLevelData[114] = 0x01; GreenLevelData[114] = 0x01; BlueLevelData[114] = 0x6E; BarrierLevelData[114] = 0x01;
		/*115*/ RedLevelData[115] = 0x01; GreenLevelData[115] = 0x01; BlueLevelData[115] = 0xF8; BarrierLevelData[115] = 0x01;
		/*116*/ RedLevelData[116] = 0x01; GreenLevelData[116] = 0x01; BlueLevelData[116] = 0x6E; BarrierLevelData[116] = 0x01;
		/*117*/ RedLevelData[117] = 0x01; GreenLevelData[117] = 0x01; BlueLevelData[117] = 0x3E; BarrierLevelData[117] = 0x01;
		/*118*/ RedLevelData[118] = 0x01; GreenLevelData[118] = 0x01; BlueLevelData[118] = 0x1E; BarrierLevelData[118] = 0x01;
		/*119*/ RedLevelData[119] = 0x01; GreenLevelData[119] = 0x01; BlueLevelData[119] = 0x00; BarrierLevelData[119] = 0x01;		

}

void loadLevel4()
{
	/*0*/ RedLevelData[0] = 0x00; GreenLevelData[0] = 0x00; BlueLevelData[0] = 0x8F; BarrierLevelData[0] = 0x8F;
	/*1*/ RedLevelData[1] = 0x00; GreenLevelData[1] = 0x00; BlueLevelData[1] = 0x8F; BarrierLevelData[1] = 0x8F;
	/*2*/ RedLevelData[2] = 0x00; GreenLevelData[2] = 0x00; BlueLevelData[2] = 0x87; BarrierLevelData[2] = 0x87;
	/*3*/ RedLevelData[3] = 0x00; GreenLevelData[3] = 0x00; BlueLevelData[3] = 0x83; BarrierLevelData[3] = 0x83;
	/*4*/ RedLevelData[4] = 0x00; GreenLevelData[4] = 0x00; BlueLevelData[4] = 0xC1; BarrierLevelData[4] = 0xC1;
	/*5*/ RedLevelData[5] = 0x00; GreenLevelData[5] = 0x00; BlueLevelData[5] = 0xC1; BarrierLevelData[5] = 0xC1;
	/*6*/ RedLevelData[6] = 0x00; GreenLevelData[6] = 0x00; BlueLevelData[6] = 0xC1; BarrierLevelData[6] = 0xC1;
	/*7*/ RedLevelData[7] = 0x00; GreenLevelData[7] = 0x00; BlueLevelData[7] = 0xC1; BarrierLevelData[7] = 0xC1;
	/*8*/ RedLevelData[8] = 0x00; GreenLevelData[8] = 0x00; BlueLevelData[8] = 0xC1; BarrierLevelData[8] = 0xC1;
	/*9*/ RedLevelData[9] = 0x01; GreenLevelData[9] = 0x00; BlueLevelData[9] = 0xC0; BarrierLevelData[9] = 0xC0;
	/*10*/ RedLevelData[10] = 0x01; GreenLevelData[10] = 0x00; BlueLevelData[10] = 0xC0; BarrierLevelData[10] = 0xC0;
	/*11*/ RedLevelData[11] = 0x00; GreenLevelData[11] = 0x00; BlueLevelData[11] = 0xC1; BarrierLevelData[11] = 0xC1;
	/*12*/ RedLevelData[12] = 0x00; GreenLevelData[12] = 0x00; BlueLevelData[12] = 0xC1; BarrierLevelData[12] = 0xC1;
	/*13*/ RedLevelData[13] = 0x00; GreenLevelData[13] = 0x00; BlueLevelData[13] = 0xC1; BarrierLevelData[13] = 0xC1;
	/*14*/ RedLevelData[14] = 0x00; GreenLevelData[14] = 0x00; BlueLevelData[14] = 0xC1; BarrierLevelData[14] = 0xC1;
	/*15*/ RedLevelData[15] = 0x00; GreenLevelData[15] = 0x00; BlueLevelData[15] = 0xC1; BarrierLevelData[15] = 0xC1;
	/*16*/ RedLevelData[16] = 0x00; GreenLevelData[16] = 0x00; BlueLevelData[16] = 0xE1; BarrierLevelData[16] = 0xE1;
	/*17*/ RedLevelData[17] = 0x00; GreenLevelData[17] = 0x00; BlueLevelData[17] = 0x81; BarrierLevelData[17] = 0x81;
	/*18*/ RedLevelData[18] = 0x00; GreenLevelData[18] = 0x00; BlueLevelData[18] = 0x81; BarrierLevelData[18] = 0x81;
	/*19*/ RedLevelData[19] = 0x01; GreenLevelData[19] = 0x00; BlueLevelData[19] = 0x80; BarrierLevelData[19] = 0x80;
	/*20*/ RedLevelData[20] = 0x01; GreenLevelData[20] = 0x00; BlueLevelData[20] = 0x80; BarrierLevelData[20] = 0x80;
	/*21*/ RedLevelData[21] = 0x00; GreenLevelData[21] = 0x00; BlueLevelData[21] = 0x81; BarrierLevelData[21] = 0x81;
	/*22*/ RedLevelData[22] = 0x00; GreenLevelData[22] = 0x00; BlueLevelData[22] = 0x81; BarrierLevelData[22] = 0x81;
	/*23*/ RedLevelData[23] = 0x00; GreenLevelData[23] = 0x00; BlueLevelData[23] = 0x81; BarrierLevelData[23] = 0x81;
	/*24*/ RedLevelData[24] = 0x00; GreenLevelData[24] = 0x00; BlueLevelData[24] = 0x81; BarrierLevelData[24] = 0x81;
	/*25*/ RedLevelData[25] = 0x01; GreenLevelData[25] = 0x00; BlueLevelData[25] = 0x80; BarrierLevelData[25] = 0x80;
	/*26*/ RedLevelData[26] = 0x01; GreenLevelData[26] = 0x00; BlueLevelData[26] = 0x80; BarrierLevelData[26] = 0x80;
	/*27*/ RedLevelData[27] = 0x20; GreenLevelData[27] = 0x20; BlueLevelData[27] = 0xC7; BarrierLevelData[27] = 0xE7;
	/*28*/ RedLevelData[28] = 0x00; GreenLevelData[28] = 0x00; BlueLevelData[28] = 0xC7; BarrierLevelData[28] = 0xC7;
	/*29*/ RedLevelData[29] = 0x00; GreenLevelData[29] = 0x00; BlueLevelData[29] = 0xC7; BarrierLevelData[29] = 0xC7;
	/*30*/ RedLevelData[30] = 0x00; GreenLevelData[30] = 0x00; BlueLevelData[30] = 0xC7; BarrierLevelData[30] = 0xC7;
	/*31*/ RedLevelData[31] = 0x00; GreenLevelData[31] = 0x00; BlueLevelData[31] = 0xC7; BarrierLevelData[31] = 0xC7;
	/*32*/ RedLevelData[32] = 0x00; GreenLevelData[32] = 0x00; BlueLevelData[32] = 0xC7; BarrierLevelData[32] = 0xC7;
	/*33*/ RedLevelData[33] = 0x00; GreenLevelData[33] = 0x00; BlueLevelData[33] = 0xC7; BarrierLevelData[33] = 0xC7;
	/*34*/ RedLevelData[34] = 0x00; GreenLevelData[34] = 0x00; BlueLevelData[34] = 0xC7; BarrierLevelData[34] = 0xC7;
	/*35*/ RedLevelData[35] = 0x20; GreenLevelData[35] = 0x20; BlueLevelData[35] = 0xC7; BarrierLevelData[35] = 0xE7;
	/*36*/ RedLevelData[36] = 0x00; GreenLevelData[36] = 0x00; BlueLevelData[36] = 0xC7; BarrierLevelData[36] = 0xC7;
	/*37*/ RedLevelData[37] = 0x00; GreenLevelData[37] = 0x00; BlueLevelData[37] = 0xC7; BarrierLevelData[37] = 0xC7;
	/*38*/ RedLevelData[38] = 0x00; GreenLevelData[38] = 0x00; BlueLevelData[38] = 0xC7; BarrierLevelData[38] = 0xC7;
	/*39*/ RedLevelData[39] = 0x00; GreenLevelData[39] = 0x00; BlueLevelData[39] = 0xC7; BarrierLevelData[39] = 0xC7;
	/*40*/ RedLevelData[40] = 0x00; GreenLevelData[40] = 0x00; BlueLevelData[40] = 0xC7; BarrierLevelData[40] = 0xC7;
	/*41*/ RedLevelData[41] = 0x20; GreenLevelData[41] = 0x20; BlueLevelData[41] = 0xC7; BarrierLevelData[41] = 0xE7;
	/*42*/ RedLevelData[42] = 0x00; GreenLevelData[42] = 0x00; BlueLevelData[42] = 0xC7; BarrierLevelData[42] = 0xC7;
	/*43*/ RedLevelData[43] = 0x00; GreenLevelData[43] = 0x00; BlueLevelData[43] = 0xC7; BarrierLevelData[43] = 0xC7;
	/*44*/ RedLevelData[44] = 0x00; GreenLevelData[44] = 0x00; BlueLevelData[44] = 0xC7; BarrierLevelData[44] = 0xC7;
	/*45*/ RedLevelData[45] = 0x00; GreenLevelData[45] = 0x00; BlueLevelData[45] = 0xC7; BarrierLevelData[45] = 0xC7;
	/*46*/ RedLevelData[46] = 0x00; GreenLevelData[46] = 0x00; BlueLevelData[46] = 0xC7; BarrierLevelData[46] = 0xC7;
	/*47*/ RedLevelData[47] = 0x00; GreenLevelData[47] = 0x00; BlueLevelData[47] = 0xC7; BarrierLevelData[47] = 0xC7;
	/*48*/ RedLevelData[48] = 0x00; GreenLevelData[48] = 0x00; BlueLevelData[48] = 0xC7; BarrierLevelData[48] = 0xC7;
	/*49*/ RedLevelData[49] = 0x20; GreenLevelData[49] = 0x20; BlueLevelData[49] = 0xC7; BarrierLevelData[49] = 0xE7;
	/*50*/ RedLevelData[50] = 0x00; GreenLevelData[50] = 0x00; BlueLevelData[50] = 0xC7; BarrierLevelData[50] = 0xC7;
	/*51*/ RedLevelData[51] = 0x00; GreenLevelData[51] = 0x00; BlueLevelData[51] = 0xC7; BarrierLevelData[51] = 0xC7;
	/*52*/ RedLevelData[52] = 0x00; GreenLevelData[52] = 0x00; BlueLevelData[52] = 0xC7; BarrierLevelData[52] = 0xC7;
	/*53*/ RedLevelData[53] = 0x00; GreenLevelData[53] = 0x00; BlueLevelData[53] = 0xC7; BarrierLevelData[53] = 0xC7;
	/*54*/ RedLevelData[54] = 0x00; GreenLevelData[54] = 0x00; BlueLevelData[54] = 0x81; BarrierLevelData[54] = 0x81;
	/*55*/ RedLevelData[55] = 0x00; GreenLevelData[55] = 0x00; BlueLevelData[55] = 0x81; BarrierLevelData[55] = 0x81;
	/*56*/ RedLevelData[56] = 0x02; GreenLevelData[56] = 0x02; BlueLevelData[56] = 0x81; BarrierLevelData[56] = 0x83;
	/*57*/ RedLevelData[57] = 0x00; GreenLevelData[57] = 0x00; BlueLevelData[57] = 0x81; BarrierLevelData[57] = 0x81;
	/*58*/ RedLevelData[58] = 0x00; GreenLevelData[58] = 0x00; BlueLevelData[58] = 0x81; BarrierLevelData[58] = 0x81;
	/*59*/ RedLevelData[59] = 0x20; GreenLevelData[59] = 0x20; BlueLevelData[59] = 0xC1; BarrierLevelData[59] = 0xE1;
	/*60*/ RedLevelData[60] = 0x00; GreenLevelData[60] = 0x00; BlueLevelData[60] = 0x81; BarrierLevelData[60] = 0x81;
	/*61*/ RedLevelData[61] = 0x00; GreenLevelData[61] = 0x00; BlueLevelData[61] = 0x81; BarrierLevelData[61] = 0x81;
	/*62*/ RedLevelData[62] = 0x00; GreenLevelData[62] = 0x00; BlueLevelData[62] = 0x81; BarrierLevelData[62] = 0x81;
	/*63*/ RedLevelData[63] = 0x02; GreenLevelData[63] = 0x02; BlueLevelData[63] = 0x81; BarrierLevelData[63] = 0x83;
	/*64*/ RedLevelData[64] = 0x00; GreenLevelData[64] = 0x00; BlueLevelData[64] = 0x81; BarrierLevelData[64] = 0x81;
	/*65*/ RedLevelData[65] = 0x00; GreenLevelData[65] = 0x00; BlueLevelData[65] = 0x81; BarrierLevelData[65] = 0x81;
	/*66*/ RedLevelData[66] = 0x20; GreenLevelData[66] = 0x20; BlueLevelData[66] = 0xC1; BarrierLevelData[66] = 0xE1;
	/*67*/ RedLevelData[67] = 0x00; GreenLevelData[67] = 0x00; BlueLevelData[67] = 0x81; BarrierLevelData[67] = 0x81;
	/*68*/ RedLevelData[68] = 0x00; GreenLevelData[68] = 0x00; BlueLevelData[68] = 0x81; BarrierLevelData[68] = 0x81;
	/*69*/ RedLevelData[69] = 0x00; GreenLevelData[69] = 0x00; BlueLevelData[69] = 0x81; BarrierLevelData[69] = 0x81;
	/*70*/ RedLevelData[70] = 0x02; GreenLevelData[70] = 0x02; BlueLevelData[70] = 0x81; BarrierLevelData[70] = 0x83;
	/*71*/ RedLevelData[71] = 0x00; GreenLevelData[71] = 0x00; BlueLevelData[71] = 0x81; BarrierLevelData[71] = 0x81;
	/*72*/ RedLevelData[72] = 0x00; GreenLevelData[72] = 0x00; BlueLevelData[72] = 0x81; BarrierLevelData[72] = 0x81;
	/*73*/ RedLevelData[73] = 0x00; GreenLevelData[73] = 0x00; BlueLevelData[73] = 0xC1; BarrierLevelData[73] = 0xC1;
	/*74*/ RedLevelData[74] = 0x00; GreenLevelData[74] = 0x00; BlueLevelData[74] = 0xC1; BarrierLevelData[74] = 0xC1;
	/*75*/ RedLevelData[75] = 0x00; GreenLevelData[75] = 0x00; BlueLevelData[75] = 0xC1; BarrierLevelData[75] = 0xC1;
	/*76*/ RedLevelData[76] = 0x00; GreenLevelData[76] = 0x00; BlueLevelData[76] = 0xC1; BarrierLevelData[76] = 0xC1;
	/*77*/ RedLevelData[77] = 0x00; GreenLevelData[77] = 0x00; BlueLevelData[77] = 0x81; BarrierLevelData[77] = 0x81;
	/*78*/ RedLevelData[78] = 0x00; GreenLevelData[78] = 0x00; BlueLevelData[78] = 0x81; BarrierLevelData[78] = 0x81;
	/*79*/ RedLevelData[79] = 0x00; GreenLevelData[79] = 0x00; BlueLevelData[79] = 0x89; BarrierLevelData[79] = 0x89;
	/*80*/ RedLevelData[80] = 0x00; GreenLevelData[80] = 0x00; BlueLevelData[80] = 0x81; BarrierLevelData[80] = 0x81;
	/*81*/ RedLevelData[81] = 0x00; GreenLevelData[81] = 0x00; BlueLevelData[81] = 0x81; BarrierLevelData[81] = 0x81;
	/*82*/ RedLevelData[82] = 0x00; GreenLevelData[82] = 0x00; BlueLevelData[82] = 0x89; BarrierLevelData[82] = 0x89;
	/*83*/ RedLevelData[83] = 0x00; GreenLevelData[83] = 0x00; BlueLevelData[83] = 0x81; BarrierLevelData[83] = 0x81;
	/*84*/ RedLevelData[84] = 0x00; GreenLevelData[84] = 0x00; BlueLevelData[84] = 0x81; BarrierLevelData[84] = 0x81;
	/*85*/ RedLevelData[85] = 0x00; GreenLevelData[85] = 0x00; BlueLevelData[85] = 0x89; BarrierLevelData[85] = 0x89;
	/*86*/ RedLevelData[86] = 0x00; GreenLevelData[86] = 0x00; BlueLevelData[86] = 0x81; BarrierLevelData[86] = 0x81;
	/*87*/ RedLevelData[87] = 0x00; GreenLevelData[87] = 0x00; BlueLevelData[87] = 0x81; BarrierLevelData[87] = 0x81;
	/*88*/ RedLevelData[88] = 0x00; GreenLevelData[88] = 0x00; BlueLevelData[88] = 0x87; BarrierLevelData[88] = 0x87;
	/*89*/ RedLevelData[89] = 0x00; GreenLevelData[89] = 0x00; BlueLevelData[89] = 0x87; BarrierLevelData[89] = 0x87;
	/*90*/ RedLevelData[90] = 0x00; GreenLevelData[90] = 0x00; BlueLevelData[90] = 0x87; BarrierLevelData[90] = 0x87;
	/*91*/ RedLevelData[91] = 0x00; GreenLevelData[91] = 0x00; BlueLevelData[91] = 0x81; BarrierLevelData[91] = 0x81;
	/*92*/ RedLevelData[92] = 0x00; GreenLevelData[92] = 0x00; BlueLevelData[92] = 0x81; BarrierLevelData[92] = 0x81;
	/*93*/ RedLevelData[93] = 0x00; GreenLevelData[93] = 0x00; BlueLevelData[93] = 0xC7; BarrierLevelData[93] = 0xC7;
	/*94*/ RedLevelData[94] = 0x00; GreenLevelData[94] = 0x00; BlueLevelData[94] = 0xC7; BarrierLevelData[94] = 0xC7;
	/*95*/ RedLevelData[95] = 0x00; GreenLevelData[95] = 0x00; BlueLevelData[95] = 0xC7; BarrierLevelData[95] = 0xC7;
	/*96*/ RedLevelData[96] = 0x03; GreenLevelData[96] = 0x02; BlueLevelData[96] = 0xC6; BarrierLevelData[96] = 0xC6;
	/*97*/ RedLevelData[97] = 0x03; GreenLevelData[97] = 0x02; BlueLevelData[97] = 0x82; BarrierLevelData[97] = 0x82;
	/*98*/ RedLevelData[98] = 0x03; GreenLevelData[98] = 0x02; BlueLevelData[98] = 0x02; BarrierLevelData[98] = 0x02;
	/*99*/ RedLevelData[99] = 0x03; GreenLevelData[99] = 0x02; BlueLevelData[99] = 0x02; BarrierLevelData[99] = 0x02;
	/*100*/ RedLevelData[100] = 0x03; GreenLevelData[100] = 0x02; BlueLevelData[100] = 0x02; BarrierLevelData[100] = 0x02;
	/*101*/ RedLevelData[101] = 0x03; GreenLevelData[101] = 0x02; BlueLevelData[101] = 0x02; BarrierLevelData[101] = 0x02;
	/*102*/ RedLevelData[102] = 0x03; GreenLevelData[102] = 0x02; BlueLevelData[102] = 0x02; BarrierLevelData[102] = 0x02;
	/*103*/ RedLevelData[103] = 0x03; GreenLevelData[103] = 0x02; BlueLevelData[103] = 0x02; BarrierLevelData[103] = 0x02;
	/*104*/ RedLevelData[104] = 0x03; GreenLevelData[104] = 0x02; BlueLevelData[104] = 0x02; BarrierLevelData[104] = 0x02;
	/*105*/ RedLevelData[105] = 0x3C; GreenLevelData[105] = 0x3C; BlueLevelData[105] = 0xC3; BarrierLevelData[105] = 0xFF;
	/*106*/ RedLevelData[106] = 0x00; GreenLevelData[106] = 0x00; BlueLevelData[106] = 0xE7; BarrierLevelData[106] = 0xE7;
	/*107*/ RedLevelData[107] = 0x00; GreenLevelData[107] = 0x00; BlueLevelData[107] = 0x81; BarrierLevelData[107] = 0x81;
	/*108*/ RedLevelData[108] = 0x00; GreenLevelData[108] = 0x00; BlueLevelData[108] = 0x81; BarrierLevelData[108] = 0x81;
	/*109*/ RedLevelData[109] = 0x00; GreenLevelData[109] = 0x00; BlueLevelData[109] = 0x81; BarrierLevelData[109] = 0x81;
	/*110*/ RedLevelData[110] = 0x00; GreenLevelData[110] = 0x00; BlueLevelData[110] = 0x81; BarrierLevelData[110] = 0x81;
	/*111*/ RedLevelData[111] = 0x00; GreenLevelData[111] = 0x00; BlueLevelData[111] = 0x81; BarrierLevelData[111] = 0x81;
	/*112*/ RedLevelData[112] = 0x00; GreenLevelData[112] = 0x00; BlueLevelData[112] = 0x81; BarrierLevelData[112] = 0x81;
	/*113*/ RedLevelData[113] = 0x00; GreenLevelData[113] = 0x00; BlueLevelData[113] = 0x81; BarrierLevelData[113] = 0x81;
	/*114*/ RedLevelData[114] = 0x00; GreenLevelData[114] = 0x00; BlueLevelData[114] = 0x8F; BarrierLevelData[114] = 0x81;
	/*115*/ RedLevelData[115] = 0x00; GreenLevelData[115] = 0x00; BlueLevelData[115] = 0x89; BarrierLevelData[115] = 0x81;
	/*116*/ RedLevelData[116] = 0x00; GreenLevelData[116] = 0x00; BlueLevelData[116] = 0x8F; BarrierLevelData[116] = 0x81;
	/*117*/ RedLevelData[117] = 0x00; GreenLevelData[117] = 0x00; BlueLevelData[117] = 0x81; BarrierLevelData[117] = 0x81;
	/*118*/ RedLevelData[118] = 0x00; GreenLevelData[118] = 0x00; BlueLevelData[118] = 0x81; BarrierLevelData[118] = 0x81;
	/*119*/ RedLevelData[119] = 0x00; GreenLevelData[119] = 0x00; BlueLevelData[119] = 0xFF; BarrierLevelData[119] = 0xFF;

}

void AdvanceLevel()
{
	int i,j;
	
	if(level_pos == 112)
	return;
	
	//level_pos = (level_pos+1) % LEVEL_SIZE;
	
	if(level_pos < 0)
		level_pos = 0;
	
	level_pos = level_pos + 1;
	
	if(level_pos == 0)
	{
		for(i = 0; i < 8; i++)
		{
			for(j = 0; j < 8; j++)
			{
				pixels[i][j].r = ((RedLevelData[(level_pos+j)%LEVEL_SIZE] & (0x80 >> i))!= 0) << 3;
				pixels[i][j].g = ((GreenLevelData[(level_pos+j)%LEVEL_SIZE] & (0x80 >> i))!= 0) << 3;
				pixels[i][j].b = ((BlueLevelData[(level_pos+j)%LEVEL_SIZE] & (0x80 >> i))!= 0) << 3;
				
				if(!(pixels[i][j].r | pixels[i][j].g | pixels[i][j].b))
					pixels[i][j] = background;
			}
		}
		
	}
	else
	{
		for(i = 0; i < 8; i++)
		{
			for(j = 0; j < 7; j++)
			{
				pixels[i][j].r = pixels[i][j+1].r;
				pixels[i][j].g = pixels[i][j+1].g;
				pixels[i][j].b = pixels[i][j+1].b;
			}
		}
		
		
		j = 7;
		for(i = 0; i < 8; i++)
		{
			pixels[i][j].r = ((RedLevelData[(level_pos+j)%LEVEL_SIZE] & (0x80 >> i))!= 0) << 3;
			pixels[i][j].g = ((GreenLevelData[(level_pos+j)%LEVEL_SIZE] & (0x80 >> i))!= 0) << 3;
			pixels[i][j].b = ((BlueLevelData[(level_pos+j)%LEVEL_SIZE] & (0x80 >> i))!= 0) << 3;
			if(!(pixels[i][j].r | pixels[i][j].g | pixels[i][j].b))
				pixels[i][j] = background;
		}
	}

	return;
}

void animate_title()
{
	static char pass = 0;
	static Pixel p;
	static Pixel black = {0,0,0};
	if(!(pass & 0x0F))
	{
		p.r = rand() & 1;
		p.g = rand() & 1;
		p.b = rand() & 1;
		if(!(p.r | p.g | p.b)) // if p == black
			((char*)&p)[rand()%3] = 1; //selects a random single color and turns it on
		for(char i = 0; i < 8; ++i)
		{
			for(char j = 0; j < 8; ++j)
			{
				if((i == 0 || i == 7 || j == 0 || j == 7) && (i+j + (pass >> 4))%2 )
					pixels[i][j] = p;
				else
					pixels[i][j] = black;
					
			}
		}
	}
	pass = (pass+1) & 0x1F;
}

#endif