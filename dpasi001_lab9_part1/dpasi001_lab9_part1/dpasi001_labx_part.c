/* dpasi001_labx_party.c - [DATE]
 * Name & E-mail: Daniel Pasillas - dpasi001@ucr.edu
 * CS Login: dpasi001
 * Partner(s) Name & E-mail: [NAME] - [E-MAIL]
 * Lab Section: 23
 * Assignment: Lab # 9 Exercise # 3
 * Exercise Description:
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */


#include <avr/io.h>
#include <ucr/timer.h>
#include <ucr/queue.h>
#include <ucr/keypad.h>

typedef unsigned char uchar;

uchar key = 0;

enum {KEY_WAITING, KEY_PRESSED};
uchar keyTick(uchar state)
{
	static uchar pushed = 0;
	switch(state)
	{
	case (uchar)-1: state = KEY_WAITING; break;
	case KEY_WAITING: state = (pushed)?KEY_PRESSED:(KEY_WAITING); break;
	case KEY_PRESSED: state = (pushed)?KEY_PRESSED:(KEY_WAITING); break;
	default: state = KEY_WAITING;
	}
	
	switch(state)
	{
	case KEY_WAITING:
		pushed = key = GetKeypadKey();
		if(key == '*')
		{
			//LCD_write_str ^= 1;
			//LCD_char_pos = ~PINA & 0x0F;
			//key = 0;
		} break;
	case KEY_PRESSED:
	    pushed = GetKeypadKey();
		key = 0;
		break;
	default: break;
	}
	return state;
}

inline void pwm_set(uint16_t x) {
	OCR1B = x;
}
#define DIV 8
#define PWM_MIN 1300 / DIV
#define PWM_MAX 4450 / DIV
#define PWM_START 2765 / DIV
void pwm_init() {
	// setup Timer1 for Fast PWM mode, 16-bit
	// COM1B1 -- for non-inverting output
	// WGM13, WGM12, WGM11, WGM10 -- for Fast PWM with OCR1A as TOP value
	// CS11 -- for CLK/8 prescaling
	
	OCR1A = 36864 / DIV;	// sets PWM to repeat pulse every 20.0ms
	pwm_set(PWM_START);
	TCCR1A = (1<<COM1B1) | (1<<WGM11) | (1<<WGM10);
	TCCR1B = (1<<WGM13) | (1<<WGM12) | (1<<CS11);
	
	// each count is 8/14745600 = 0.5425us.
	// so 1.0ms = 1843.2
	//    1.5ms = 2764.8
	//    2.0ms = 3686.4
	//   20.0ms = 36864
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xF0; PORTC = 0x0F; // PC7..4 outputs init 0s, PC3..0 inputs init 1s
	TimerSetMS(1);
	TimerOn();
	pwm_init();
	uint16_t pos = PWM_START;
    while(1)
    {
		pwm_set(pos);
		keyTick(0);
		if(key=='A') pos = PWM_MIN;//+= 25;
		if(key=='B') pos = PWM_MAX;//-= 25;
		if(key=='0') PORTB &= ~(1<<PB3);
		if(key=='7') PORTB ^= (1<<PB3);
		if(key=='1') PORTB |= (1<<PB3);
        //TODO:: Please write your application code
		//PORTB ^= 1;
		while(!TimerFlag);
		TimerFlag = 0;
    }
}