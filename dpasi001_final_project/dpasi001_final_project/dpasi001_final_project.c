/* dpasi001_final_project.c - 3/15/2013
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

#define F_CPU 16000000UL

#define INTS_PER_MS 125
#define TICKS_PER_MS 5
//timer counts to 125/5

#define MASTER

#define INIT 0xFF

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned long ulong;

#include <avr/io.h>
#include <ucr/timer.h>
#include <dpasi001_tone.h>
#include <dpasi001_mario_levels.h>
#include <dpasi001_pixel.h>
#include <dpasi001_port_assign.h>
#include <dpasi001_snes_buttons.h>
#include <lcd_run.h>

const unsigned char prescaler = PRESCALER_64;

typedef struct task { //this task was taken from the PES pdf, and modified.
	uchar state; // Task’s current state
	ulong period; // Task period
	ulong elapsedTime; // Time since last tick
	uchar (*TickFct)(uchar); // Task tick function
} task;

enum {LED_M, SNES, GAME, AUDIO, LCDI, LCDT, NUM_TASKS}; //to reorder tasks, simply reorder this enum
task tasks[NUM_TASKS];

inline void taskInit(uchar n, ulong period, uchar(*fnct)(uchar))
{
	tasks[n].state=0xFF;
	tasks[n].period = period;
	tasks[n].elapsedTime = period;
	tasks[n].TickFct = fnct;
}

inline uchar getRed(ushort val) //unused
{	return (val >> 8) & 0x0F;}

inline uchar getGreen(ushort val) //unused
{	return (val >> 4) & 0x0F;}

inline uchar getBlue(ushort val) //unused
{	return val & 0x0F;}


#define SHIFT_IN 0x10
#define SHIFT_OUT 0x20
#define OUTPUT_DISABLE 0x80
uchar LED_Matrix(uchar state)
{
	char red = 0, green = 0, blue = 0, anodes = 0;
	static char PWM = 0;
	static char count = 0;
	static char row, col;
	static char i;
	if(count == 8)
	{
		count = 0;
		PWM = (PWM + 1) % PWM_MAX;
	}
	
	row = 7 - count % 8;
	for(i = 0; i < 8; ++i)
	{
		col = 7 - i;
		red |= pwm8_split[pixels[row][col].r][(PWM+i)%PWM_MAX] << i; // (rgb[row][col].red > PWM) << i
		green |= pwm8_split[pixels[row][col].g][(PWM+i)%PWM_MAX] << i;
		blue |= pwm8_split[pixels[row][col].b][(PWM+i)%PWM_MAX] << i;
	}
	
	anodes = 1 << row;
	
	for(i = 0; i < 8; i++)
	{
		PORT_EQ(PORTC,((~red >> i) & 0x01) | (((~green >> i)<<1) & 0x02) | (((~blue >> i)<<2) & 0x04) | (((anodes >> i)<<3) & 0x08));//data lines, clear off
		PORT_OR_EQ(PORTC, SHIFT_IN); //shift in
	}
	
	//PORTC |= OUTPUT_DISABLE;
	
	PORT_OR_EQ(PORTC,SHIFT_OUT); //shift out
	PORT_AND_EQ(PORTC,~SHIFT_OUT);
	
	//PORTC &= ~OUTPUT_DISABLE;
	++count;
	
	return 0;
}

ulong pass = 0, pos = 0, per = 0;

inline void loadKey(uchar key)
{
	#define S_IN 0x04
	#define S_OUT 0x02
	#define DATA 0x01
	#define DATA_POS 0 //0010 0000
	signed char i;
	for(i = 0; i < 8; ++i)
	{
		PORT_AND_EQ(PORTA,~(S_IN | DATA));
		PORT_OR_EQ(PORTA,(((key >> i) << DATA_POS) & DATA));	
		PORT_OR_EQ(PORTA,S_IN);
	}
	PORT_OR_EQ(PORTA, S_OUT);
	PORT_AND_EQ(PORTA,~S_OUT);
		
}

enum {PLAY_NOTE, BREATH};
uchar audioTick(uchar state)
{
	Note cn;	
	memcpy_P(&cn,current_song.song + current_song.pos, sizeof(Note)); //copies a note from memory
	static ushort dur = 0;
	switch(state)
	{
		case INIT:
			loadKey(cn.key);
			state = 0;
			dur = (NOTE_DURATION * TICKS_PER_MS << 1) * cn.duration - (REST_DURATION * TICKS_PER_MS << 1);
			break;
		case PLAY_NOTE:
				tasks[AUDIO].period = dur;
				state = BREATH;
				loadKey(cn.key);
			break;
		case BREATH:
			{
				tasks[AUDIO].period = REST_DURATION * TICKS_PER_MS * 2; //again, schedules itself 
				current_song.pos = (current_song.pos+1)%(current_song.dur);
				memcpy_P(&cn,current_song.song + current_song.pos, sizeof(Note));
				loadKey(K_REST);
				dur = NOTE_DURATION * TICKS_PER_MS * 2 * cn.duration;
				state = PLAY_NOTE;
			}				
			break;
		default:
			state = 0xFF;
	}
	
	/*switch(state)
	{
		case PLAY_NOTE:
			break;
		case BREATH:
			break;
		default:;
	}*/ //doesn't do anything
	return state;
}

uchar doNothing(uchar state) // place holder for testing
{
	return 0;
}

enum Game_States{GAME_TITLE, PLAY, NEXT_LEVEL, MARIO_DEAD, RESET};
signed char momentum_x, momentum_y = 0, move_x_check = 0, move_y_check = 0, jump = 0, lives = 0, move = 0;
char * mstr = "   PRESS START! ";
char levelStr[] = "    Level:      ";
uchar gameTick(uchar state)
{
	strcpy(str, LCD_string_g);
	switch(state)
	{
		case INIT:
			state = GAME_TITLE;
			PIX_EQ(mario.color,8,0,0);
			PIX_EQ(mario.back,0,0,0);
			current_level = 0;
			//lives = 3;
			mstr = "   PRESS START! ";
			LCD_string_g = mstr;
			adv = 1;
			current_song.song = nothing;
			current_song.pos = 0;
			current_song.dur = sizeof(nothing) / sizeof(Note);
			break;
		case GAME_TITLE:
			if(buttons & SNES_ST)
				state = NEXT_LEVEL;
			break;
		case PLAY:
			if((mario.x==115) /*&& (mario.y) == 7-1 &&*/&& (buttons & SNES_UP))
				state = NEXT_LEVEL;
			if((buttons & SNES_ST) && (buttons & SNES_SL))
			{
				state = RESET;
				LCD_string_g = "   GAME RESET!  ";
				adv = 1;
			}				
			break;
		case RESET:
			if(buttons)
				state = RESET;
			else
				state = INIT;
			break;
		case NEXT_LEVEL:
			levelStr[11] = '0' + current_level;
			LCD_string_g = levelStr;
			adv = 1;
			state = PLAY;
			break;
		case MARIO_DEAD:
			//lives--;
			--current_level;
			state = NEXT_LEVEL;
		default:
			break;
	}
	
	switch(state)
	{
		case GAME_TITLE:
			animate_title();
			break;
		case PLAY:
			moveMario(&state);
			break;
		case RESET:
			break;
		case NEXT_LEVEL:
			loadLevel(current_level+1);
			++current_level;
			//level_pos = -1;
			AdvanceLevel();
			momentum_x = 0;
			momentum_y = 0;
			move_x_check = 0;
			move_y_check = 0;
			pixels[mario.y][mario.x] = mario.color;
			mario.back = background;
			break;
		case MARIO_DEAD:
			break;
		default:
			break;
	}
	return state;
}

void moveMario(uchar * state)
{
#define MOVE_X_LIMIT 15

			if(buttons & SNES_RT)
			{
				if(!move)
				{
					move = 1;
					move_x_check = MOVE_X_LIMIT;
				}
				if(buttons & RUN_B)
					momentum_x = 2;
				else
					momentum_x = 1;
			}
			else if(buttons & SNES_LT)
			{
				if(!move)
				{
					move = 1;
					move_x_check = -MOVE_X_LIMIT;
				}
				if(buttons & RUN_B)
					momentum_x = -2;
				else
					momentum_x = -1;
			}					
			else
				momentum_x = 0, move_x_check = 0, move = 0;
			move_x_check += momentum_x;
			
			if(buttons & JUMP_B)
			{
				if(jump == 0 && momentum_y <= 0 && mario.y < 7 && (BarrierLevelData[mario.x] & (0x80 >> (mario.y+1))) != 0)
				{
					momentum_y = 16;
					jump = 1;
				}
			}									
			else
				jump = 0;
			
			if(momentum_y >= 1 && (momentum_y%5) == 1 && mario.y > 0)
			{
				if((BarrierLevelData[mario.x] & (0x80 >> (mario.y-1) )) != 0 && current_level != 3)
				{
					if(current_level == 3)
						goto UP;
					if(current_level != 4)
					{
						BarrierLevelData[mario.x] &= ~(0x80 >> (mario.y-1));
						PIX_EQ(pixels[mario.y-1][mario.x - level_pos],0,0,0);
					}
						
					momentum_y = 0;
				}
				else{	
				UP:
					pixels[mario.y][mario.x - level_pos] = mario.back;
					mario.y -= 1;
					mario.back = pixels[mario.y][mario.x - level_pos];
					pixels[mario.y][mario.x - level_pos] = mario.color;
				}					
			}
			else if(momentum_y <= -5) 
				if(mario.y < 7 && (BarrierLevelData[mario.x] & (0x80 >> (mario.y+1))) == 0)
				{
					pixels[mario.y][mario.x - level_pos] = mario.back;
					mario.y += 1;
					mario.back = pixels[mario.y][mario.x - level_pos];
					pixels[mario.y][mario.x - level_pos] = mario.color;
					momentum_y = 0;
				} else if(mario.y == 7)
				{
					*state = MARIO_DEAD;
					return;
				}					
			if(momentum_y < -5)
				momentum_y = -5;
			--momentum_y; //gravity
			
			if(move_x_check >= MOVE_X_LIMIT && mario.x < 119 && (BarrierLevelData[mario.x+1] & (0x80 >> mario.y)) == 0)
			{
				pixels[mario.y][mario.x - level_pos] = mario.back;
				mario.x += 1, move_x_check = 0;
				mario.back = pixels[mario.y][mario.x - level_pos];
				pixels[mario.y][mario.x - level_pos] = mario.color;
			}
			else if(move_x_check <= -MOVE_X_LIMIT && mario.x > level_pos && (BarrierLevelData[mario.x-1] & (0x80 >> mario.y)) == 0 && mario.x)
			{
				pixels[mario.y][mario.x - level_pos] = mario.back;
				mario.x -= 1, move_x_check = 0;
				mario.back = pixels[mario.y][mario.x - level_pos];
				pixels[mario.y][mario.x - level_pos] = mario.color;
			}
			if(move_x_check < -MOVE_X_LIMIT)
				move_x_check = -MOVE_X_LIMIT;
			if(move_x_check > MOVE_X_LIMIT)
				move_x_check = 20;
			if(mario.x - level_pos >= 4)
				AdvanceLevel();
}

int main(void)
{	
	initSongs();
	taskInit(LED_M,1,LED_Matrix);
	taskInit(AUDIO,1,audioTick);
	taskInit(SNES,100,SNES_controller_tick);
	taskInit(GAME,100,gameTick);
	taskInit(LCDI,10,LI_Tick);
	taskInit(LCDT,100,LT_Tick);
	//@ 16M Hz, 16 000 000 / 64 = 250 000
	//count to 125 / 5 = 25.  This is 1 / 10 000 th of a second
	//count to 100 is 1/100th of a second
	
	for(i = 0; i < sizeof(vals)/2; i++)
	vals[i] = i;
	for(i = sizeof(vals)/2; i < sizeof(vals); i++)
	vals[i] = sizeof(vals) - i;

	DDRA = 0xFF; PORT_EQ(PORTA, 0x00);
	DDRB = 0xFE; PORT_EQ(PORTB, 0x01); //1111 1101
	DDRC = 0xFF; PORT_EQ(PORTC, 0x00);
	DDRD = 0xFF; PORT_EQ(PORTD, 0x00);
	
	uchar i,j;
	
//#define setr(row,col,val)(pixels[row][col].r = val)
//#define setb(row,col,val)(pixels[row][col].b = val)
//#define setg(row,col,val)(pixels[row][col].g = val)
	
	for(i = 0; i < 8; i++) //initialize pixels
	{
		for(j = 0; j < 8; j++)
		{
			PIX_EQ(pixels[i][j],0,0,0);
		}
	}
	
	long tick = 0;
	
	
	TimerSet(1);
	TimerOn();
	
    while(1)
	{
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