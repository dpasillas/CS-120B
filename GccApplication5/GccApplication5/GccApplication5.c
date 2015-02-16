/* dpasi001_lab5_part4.c ? JAN 17, 2013
 * Name & E-mail: Daniel Pasillas - dpasi001@ucr.edu
 * CS Login: dpasi001
 * Partner(s) Name & E-mail: Cynthia Kwok - ckwok004@ucr.edu
 * Lab Section: 23
 * Assignment: Lab # 5 Exercise # 4
 * Exercise Description:
 *
 * I acknowledge all content contained herein, excluding template or example

 * code, is my own original work.
 */


 #include <avr/io.h>

 enum State{SM_init, SM_waiting, SM_pressed, SM_guess, SM_check, SM_reset} state;
 unsigned char count, num, win_state;

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

 void smTick(unsigned char input)
 {
   switch(state)
   {
      case (unsigned char)(-1): //move to initial state
         state = SM_init;
         break;
	  case SM_init:
	     win_state = 0;
	     num = rand() % 10;
		 count = 0;
		 state = SM_waiting;
		 Write7Seg(0);
		 break;
      case SM_waiting: //initial state, and only state
         {
            switch(input)
            {
               case 0:
                  break;
               case 1: //P0
                  if(count != 9)
                     ++count;
					 state = SM_pressed;
                  break;
               case 2: //P1
                  if(count != 0)
                     --count;
					 state = SM_pressed;
                  break;
               case 128:
			      state = SM_guess;
                  break;
		       default:
			      break;
            }
            Write7Seg(count);//PORTC = count;
         }
         break;
      case SM_pressed:
         if(input == 3)
             count = 0;
         if(!input)
             state = SM_waiting;
	     break;
      case SM_guess:
	      //PORTB = 2;
	      if(!input)
		      state = SM_check;
	      break;
	  case SM_check:
	      if(count < num)
		      win_state = 2;
		  else if(count > num)
		      win_state = 1;
		  else
		  {
		      win_state = 3;
			  if(input == 0x80)	
			      state = SM_reset;
			  break;
		  }
		  
		  		  
		  state = SM_waiting;
		  break;			  			  
	  case SM_reset:
	      if(!input)
		      state = SM_init;
      default:
         //PORTB = state;
         ;//error!
   }
   PORTB = win_state;
 }

 int main(void)
 {
   DDRA = 0x00; PORTA = 0xFF;
   DDRB = 0xFF; PORTB = 0x00;
   DDRC = 0xFF; PORTC = 0x00;
   state = -1;
   while(1)
   {
      //PORTB = 3;
      smTick (~PINA & 0x83);
 
   }
 }