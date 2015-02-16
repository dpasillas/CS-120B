#define F_CPU 16000000UL // 8MHz
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

// number of timer0 overflows/sec
#define INT_PER_SEC 31250

// Frequencies (in Hz) of notes
#define F_FSH_4 370
#define F_A_4 440
#define F_B_4 494
#define F_E_4 330
#define F_CSH_5 554
#define F_D_5 587
#define F_FSH_5 740
#define F_CSH_4 277
#define F_GSH_4 415

// number of timer0 overflows for notes
#define REST -1 // special case
#define FSH_4 INT_PER_SEC/F_FSH_4
#define A_4 INT_PER_SEC/F_A_4
#define B_4 INT_PER_SEC/F_B_4
#define E_4 INT_PER_SEC/F_E_4
#define CSH_5 INT_PER_SEC/F_CSH_5
#define D_5 INT_PER_SEC/F_D_5
#define FSH_5 INT_PER_SEC/F_FSH_5
#define CSH_4 INT_PER_SEC/F_CSH_4
#define GSH_4 INT_PER_SEC/F_GSH_4

#define SEMIQUAVER_TIME 60  // ms
#define BREATH_TIME 20      // ms

volatile uint32_t intrs = 0;
volatile int32_t curNote = REST;

// TIMER0 overflow
ISR(TIMER0_OVF_vect)
{
    if (curNote == REST)
        intrs = 0;
    else
    {
        intrs++;
        if (intrs >= curNote)
        {
            PORTA ^= 1;//_BV(PD4);
            intrs = 0;
        }
    }
}


void play(int32_t note, uint32_t len)
{
    int i;
    curNote = note;
    for (i = 0; i< len; i++)
	{
        _delay_ms(SEMIQUAVER_TIME);
	}		
    curNote = REST;
    _delay_ms(BREATH_TIME);
}

int main(void)
{
    /* setup clock divider. Timer0 overflows on counting to 256.
     * 8Mhz / 1 (CS0=1) = 16000000 increments/sec. Overflows every 256, so 31250
     * overflow interrupts/sec */
    TCCR0 |= _BV(CS00);

    // enable overflow interrupts
    TIMSK |= _BV(TOIE0);

    // PD4 as output
    DDRA = 0xFF;//_BV(PD4);

    TCNT0 = 0;
    intrs = 0;

    curNote = REST;

    // enable interrupts
    sei();

    while (1)
    {
        // Axel F
		//loop();
        play(FSH_4, 2);
        play(REST, 2);
        play(A_4, 3);
        play(FSH_4, 2);
        play(FSH_4, 1);
        play(B_4, 2);
        play(FSH_4, 2);
        play(E_4, 2);
        play(FSH_4, 2);
        play(REST, 2);
        play(CSH_5, 3);
        play(FSH_4, 2);
        play(FSH_4, 1);
        play(D_5, 2);
        play(CSH_5, 2);
        play(A_4, 2);
        play(FSH_4, 2);
        play(CSH_5, 2);
        play(FSH_5, 2);
        play(FSH_4, 1);
        play(E_4, 2);
        play(E_4, 1);
        play(CSH_4, 2);
        play(GSH_4, 2);
        play(FSH_4, 6);
        play(REST, 12);
    }
}

void delay(int32_t d)
{
	int32_t i;
	for(i = 0; i < d; i++)
	{
		_delay_us(100);
		_delay_us(100);
		_delay_us(100);
		_delay_us(100);
		_delay_us(100);
		_delay_us(100);
		_delay_us(100);
	}		
}
void loop()
{
	play(INT_PER_SEC/660,100);
	delay(75);play(INT_PER_SEC/660,100);
	delay(150);play(INT_PER_SEC/660,100);
	delay(150);play(INT_PER_SEC/510,100);
	delay(50);play(INT_PER_SEC/660,100);
	delay(150);play(INT_PER_SEC/770,100);
	delay(275);play(INT_PER_SEC/380,100);
	delay(287);play(INT_PER_SEC/510,100);
	delay(225);play(INT_PER_SEC/380,100);
	delay(200);play(INT_PER_SEC/320,100);
	delay(250);play(INT_PER_SEC/440,100);
	delay(150);play(INT_PER_SEC/480,80);
	delay(165);play(INT_PER_SEC/450,100);
	delay(75);play(INT_PER_SEC/430,100);
	delay(150);play(INT_PER_SEC/380,100);
	delay(100);play(INT_PER_SEC/660,80);
	delay(100);play(INT_PER_SEC/760,50);
	delay(75);play(INT_PER_SEC/860,100);
	delay(150);play(INT_PER_SEC/700,80);
	delay(75);play(INT_PER_SEC/760,50);
	delay(175);play(INT_PER_SEC/660,80);
	delay(150);play(INT_PER_SEC/520,80);
	delay(75);play(INT_PER_SEC/580,80);
	delay(75);play(INT_PER_SEC/480,80);
	delay(175);play(INT_PER_SEC/510,100);
	delay(275);play(INT_PER_SEC/380,100);
	delay(200);play(INT_PER_SEC/320,100);
	delay(250);play(INT_PER_SEC/440,100);
	delay(150);play(INT_PER_SEC/480,80);
	delay(165);play(INT_PER_SEC/450,100);
	delay(75);play(INT_PER_SEC/430,100);
	delay(150);play(INT_PER_SEC/380,100);
	delay(100);play(INT_PER_SEC/660,80);
	delay(100);play(INT_PER_SEC/760,50);
	delay(75);play(INT_PER_SEC/860,100);
	delay(150);play(INT_PER_SEC/700,80);
	delay(75);play(INT_PER_SEC/760,50);
	delay(175);play(INT_PER_SEC/660,80);
	delay(150);play(INT_PER_SEC/520,80);
	delay(75);play(INT_PER_SEC/580,80);
	delay(75);play(INT_PER_SEC/480,80);
	delay(250);play(INT_PER_SEC/500,100);
	delay(150);play(INT_PER_SEC/760,100);
	delay(50);play(INT_PER_SEC/720,100);
	delay(75);play(INT_PER_SEC/680,100);
	delay(75);play(INT_PER_SEC/620,150);
	delay(150);play(INT_PER_SEC/650,150);
	delay(150);play(INT_PER_SEC/380,100);
	delay(75);play(INT_PER_SEC/430,100);
	delay(75);play(INT_PER_SEC/500,100);
	delay(150);play(INT_PER_SEC/430,100);
	delay(75);play(INT_PER_SEC/500,100);
	delay(50);play(INT_PER_SEC/570,100);
	delay(110);play(INT_PER_SEC/500,100);
	delay(150);play(INT_PER_SEC/760,100);
	delay(50);play(INT_PER_SEC/720,100);
	delay(75);play(INT_PER_SEC/680,100);
	delay(75);play(INT_PER_SEC/620,150);
	delay(150);play(INT_PER_SEC/650,200);
	delay(150);play(INT_PER_SEC/1020,80);
	delay(150);play(INT_PER_SEC/1020,80);
	delay(75);play(INT_PER_SEC/1020,80);
	delay(150);play(INT_PER_SEC/380,100);
	delay(150);play(INT_PER_SEC/500,100);
	delay(150);play(INT_PER_SEC/760,100);
	delay(50);play(INT_PER_SEC/720,100);
	delay(75);play(INT_PER_SEC/680,100);
	delay(75);play(INT_PER_SEC/620,150);
	delay(150);play(INT_PER_SEC/650,150);
	delay(150);play(INT_PER_SEC/380,100);
	delay(75);play(INT_PER_SEC/430,100);
	delay(75);play(INT_PER_SEC/500,100);
	delay(150);play(INT_PER_SEC/430,100);
	delay(75);play(INT_PER_SEC/500,100);
	delay(50);play(INT_PER_SEC/570,100);
	delay(110);play(INT_PER_SEC/500,100);
	delay(150);play(INT_PER_SEC/760,100);
	delay(50);play(INT_PER_SEC/720,100);
	delay(75);play(INT_PER_SEC/680,100);
	delay(75);play(INT_PER_SEC/620,150);
	delay(150);play(INT_PER_SEC/650,200);
	delay(150);play(INT_PER_SEC/1020,80);
	delay(150);play(INT_PER_SEC/1020,80);
	delay(75);play(INT_PER_SEC/1020,80);
	delay(150);play(INT_PER_SEC/380,100);
	delay(150);play(INT_PER_SEC/500,100);
	delay(150);play(INT_PER_SEC/760,100);
	delay(50);play(INT_PER_SEC/720,100);
	delay(75);play(INT_PER_SEC/680,100);
	delay(75);play(INT_PER_SEC/620,150);
	delay(150);play(INT_PER_SEC/650,150);
	delay(150);play(INT_PER_SEC/380,100);
	delay(75);play(INT_PER_SEC/430,100);
	delay(75);play(INT_PER_SEC/500,100);
	delay(150);play(INT_PER_SEC/430,100);
	delay(75);play(INT_PER_SEC/500,100);
	delay(50);play(INT_PER_SEC/570,100);
	delay(210);play(INT_PER_SEC/585,100);
	delay(275);play(INT_PER_SEC/550,100);
	delay(210);play(INT_PER_SEC/500,100);
	delay(180);play(INT_PER_SEC/380,100);
	delay(150);play(INT_PER_SEC/500,100);
	delay(150);play(INT_PER_SEC/500,100);
	delay(75);play(INT_PER_SEC/500,100);
	delay(150);play(INT_PER_SEC/500,60);
	delay(75);play(INT_PER_SEC/500,80);
	delay(150);play(INT_PER_SEC/500,60);
	delay(175);play(INT_PER_SEC/500,80);
	delay(75);play(INT_PER_SEC/580,80);
	delay(175);play(INT_PER_SEC/660,80);
	delay(75);play(INT_PER_SEC/500,80);
	delay(150);play(INT_PER_SEC/430,80);
	delay(75);play(INT_PER_SEC/380,80);
	delay(300);play(INT_PER_SEC/500,60);
	delay(75);play(INT_PER_SEC/500,80);
	delay(150);play(INT_PER_SEC/500,60);
	delay(175);play(INT_PER_SEC/500,80);
	delay(75);play(INT_PER_SEC/580,80);
	delay(75);play(INT_PER_SEC/660,80);
	delay(225);play(INT_PER_SEC/870,80);
	delay(162);play(INT_PER_SEC/760,80);
	delay(300);play(INT_PER_SEC/500,60);
	delay(75);play(INT_PER_SEC/500,80);
	delay(150);play(INT_PER_SEC/500,60);
	delay(175);play(INT_PER_SEC/500,80);
	delay(75);play(INT_PER_SEC/580,80);
	delay(175);play(INT_PER_SEC/660,80);
	delay(75);play(INT_PER_SEC/500,80);
	delay(150);play(INT_PER_SEC/430,80);
	delay(75);play(INT_PER_SEC/380,80);
	delay(300);play(INT_PER_SEC/660,100);
	delay(75);play(INT_PER_SEC/660,100);
	delay(150);play(INT_PER_SEC/660,100);
	delay(150);play(INT_PER_SEC/510,100);
	delay(50);play(INT_PER_SEC/660,100);
	delay(150);play(INT_PER_SEC/770,100);
	delay(225);play(INT_PER_SEC/380,100);
	//tells the user it is over and delays it a little before going to the top again
	delay(1000);
	play(INT_PER_SEC/440,200);
	delay(200);
	delay(200);
	play(INT_PER_SEC/440,400);
	delay(200);
	delay(200);
	delay(5000);
}	