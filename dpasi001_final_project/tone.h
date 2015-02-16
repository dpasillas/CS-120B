#ifndef TONE_H
#define TONE_H

#define F_FSH_4 370
#define F_A_4 440
#define F_B_4 494
#define F_E_4 330
#define F_CSH_5 554
#define F_D_5 587
#define F_FSH_5 740
#define F_CSH_4 277
#define F_GSH_4 415

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

#define NOTE_DURATION 60;
#define REST_DURATION 20;

typedef struct note{
	short note_freq;
	unsigned char duration;
} note;
note cf[] = {{FSH_4, 2},
        {REST, 2},
        {A_4, 3},
        {FSH_4, 2},
        {FSH_4, 1},
        {B_4, 2},
        {FSH_4, 2},
        {E_4, 2},
        {FSH_4, 2},
        {REST, 2},
        {CSH_5, 3},
        {FSH_4, 2},
        {FSH_4, 1},
        {D_5, 2},
        {CSH_5, 2},
        {A_4, 2},
        {FSH_4, 2},
        {CSH_5, 2},
        {FSH_5, 2},
        {FSH_4, 1},
        {E_4, 2},
        {E_4, 1},
        {CSH_4, 2},
        {GSH_4, 2},
        {FSH_4, 6},
        {REST, 12}};

#endif