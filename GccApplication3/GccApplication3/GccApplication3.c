/* dpasi001_lab3_part2.c ? JAN 17, 2013
 * Name & E?mail: Daniel Pasillas ? dpasi001@ucr.edu
 * CS Login: dpasi001
 * Partner(s) Name & E?mail: Valeed Malik ? vmali001@ucr.edu
 * Lab Section: 23
 * Assignment: Lab # 3  Exercise # 2
 * Exercise Description:
 *             Buttons are connected to PA0 and PA1. Output for PORTC is
 *             initially 0. Pressing PA0 increments PORTC (stopping at 9).
 *             Pressing PA1 decrements PORTC (stopping at 0). If both
 *             buttons are depressed (even if not initially
 *             simultaneously), PORTC resets to 0.
 *
 * I acknowledge all content contained herein, excluding template or example

 * code, is my own original work.
 */


 #include <avr/io.h>

 enum State{s0, s1} state;
 unsigned char count;

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
         state = s0;
         count = 0;
         break;
      case s0: //initial state, and only state
         {
            switch(input)
            {
               case 0:
                  break;
               case 1: //P0
                  if(count != 9)
                     ++count;
                  break;
               case 2: //P1
                  if(count != 0)
                     --count;
                  break;
               case 3: //P0 && P1
                  count = 0;

            }
            Write7Seg(count);//PORTC = count;
            if(input)
               state = s1;
         }
         break;
      case s1:
         if(input == 3)
             count = 0;
         if(!input)
             state = s0;
      default:
         PORTB = state;
         ;//error!
   }
 }

 int main(void)
 {
   DDRA = 0x00; PORTA = 0xFF;
   DDRC = 0xFF; PORTC = 0x00;
   state = -1;
   while(1)
   {

      smTick (~PINA & 0x03);
 
   }
 }