#ifndef TONE_H
#define TONE_H

#include <ucr/timer.h>

#define TICKS_PER_SEC (TICKS_PER_MS * F_CPU / (256 * INTS_PER_MS))

#define N_1 (N_2 * 2)		//whole note
#define N_2 (N_4 * 4)		//half note
#define N_2_5 (N_2 + N_4)	//half note and a half
#define N_4 (N_8 * 2)		//quarter note
#define N_4_5 (N_4 + N_8)	//quarter note and a half
#define N_6 4				//sixth note
#define N_8 3				//eighth note

#define A_4_440

#ifdef A_4_440
#define F_C_8 4186
#define F_B_7 3951
#define F_BFT_7 3729
#define F_ASH_7 3729
#define F_A_7 3520
#define F_AFT_7 3322
#define F_GSH_7 3322
#define F_G_7 3136
#define F_GFT_7 2960
#define F_FSH_7 2960
#define F_F_7 2794
#define F_E_7 2637
#define F_EFT_7 2489
#define F_DSH_7 2489
#define F_D_7 2349
#define F_DFT_7 2217
#define F_CSH_7 2217
#define F_C_7 2093
#define F_B_6 1976
#define F_BFT_6 1865
#define F_ASH_6 1865
#define F_A_6 1760
#define F_AFT_6 1661
#define F_GSH_6 1661
#define F_G_6 1568
#define F_GFT_6 1480
#define F_FSH_6 1480
#define F_F_6 1397
#define F_E_6 1319
#define F_EFT_6 1245
#define F_DSH_6 1245
#define F_D_6 1175
#define F_DFT_6 1109
#define F_CSH_6 1109
#define F_C_6 1047
#define F_B_5 988
#define F_BFT_5 932
#define F_ASH_5 932
#define F_A_5 880
#define F_AFT_5 831
#define F_GSH_5 831
#define F_G_5 784
#define F_GFT_5 740
#define F_FSH_5 740
#define F_F_5 698
#define F_E_5 659
#define F_EFT_5 622
#define F_DSH_5 622
#define F_D_5 587
#define F_DFT_5 554
#define F_CSH_5 554
#define F_C_5 523
#define F_B_4 494
#define F_BFT_4 466
#define F_ASH_4 466
#define F_A_4 440
#define F_AFT_4 415
#define F_GSH_4 415
#define F_G_4 392
#define F_GFT_4 370
#define F_FSH_4 370
#define F_F_4 349
#define F_E_4 330
#define F_EFT_4 311
#define F_DSH_4 311
#define F_D_4 294
#define F_DFT_4 277
#define F_CSH_4 277
#define F_C_4 262
#define F_B_3 247
#define F_BFT_3 233
#define F_ASH_3 233
#define F_A_3 220
#define F_AFT_3 208
#define F_GSH_3 208
#define F_G_3 196
#define F_GFT_3 185
#define F_FSH_3 185
#define F_F_3 175
#define F_E_3 165
#define F_EFT_3 156
#define F_DSH_3 156
#define F_D_3 147
#define F_DFT_3 139
#define F_CSH_3 139
#define F_C_3 131
#define F_B_2 123
#define F_BFT_2 117
#define F_ASH_2 117
#define F_A_2 110
#define F_AFT_2 104
#define F_GSH_2 104
#define F_G_2 98
#define F_GFT_2 92
#define F_FSH_2 92
#define F_F_2 87
#define F_E_2 82
#define F_EFT_2 78
#define F_DSH_2 78
#define F_D_2 73
#define F_DFT_2 69
#define F_CSH_2 69
#define F_C_2 65
#define F_B_1 62
#define F_BFT_1 58
#define F_ASH_1 58
#define F_A_1 55
#define F_AFT_1 52
#define F_GSH_1 52
#define F_G_1 49
#define F_GFT_1 46
#define F_FSH_1 46
#define F_F_1 44
#define F_E_1 41
#define F_EFT_1 39
#define F_DSH_1 39
#define F_D_1 37
#define F_DFT_1 35
#define F_CSH_1 35
#define F_C_1 33
#define F_B_0 31
#define F_BFT_0 29
#define F_ASH_0 29
#define F_A_0 28
#endif

#ifdef A_4_420
#define F_C_8 4000
#define F_B_7 3775
#define F_BFT_7 3564
#define F_ASH_7 3564
#define F_A_7 3364
#define F_AFT_7 3175
#define F_GSH_7 3175
#define F_G_7 2997
#define F_GFT_7 2828
#define F_FSH_7 2828
#define F_F_7 2670
#define F_E_7 2520
#define F_EFT_7 2378
#define F_DSH_7 2378
#define F_D_7 2245
#define F_DFT_7 2119
#define F_CSH_7 2119
#define F_C_7 2000
#define F_B_6 1888
#define F_BFT_6 1782
#define F_ASH_6 1782
#define F_A_6 1682
#define F_AFT_6 1587
#define F_GSH_6 1587
#define F_G_6 1498
#define F_GFT_6 1414
#define F_FSH_6 1414
#define F_F_6 1335
#define F_E_6 1260
#define F_EFT_6 1189
#define F_DSH_6 1189
#define F_D_6 1122
#define F_DFT_6 1059
#define F_CSH_6 1059
#define F_C_6 1000
#define F_B_5 944
#define F_BFT_5 891
#define F_ASH_5 891
#define F_A_5 841
#define F_AFT_5 794
#define F_GSH_5 794
#define F_G_5 749
#define F_GFT_5 707
#define F_FSH_5 707
#define F_F_5 667
#define F_E_5 630
#define F_EFT_5 595
#define F_DSH_5 595
#define F_D_5 561
#define F_DFT_5 530
#define F_CSH_5 530
#define F_C_5 500
#define F_B_4 472
#define F_BFT_4 445
#define F_ASH_4 445
#define F_A_4 420
#define F_AFT_4 397
#define F_GSH_4 397
#define F_G_4 375
#define F_GFT_4 354
#define F_FSH_4 354
#define F_F_4 334
#define F_E_4 315
#define F_EFT_4 297
#define F_DSH_4 297
#define F_D_4 281
#define F_DFT_4 265
#define F_CSH_4 265
#define F_C_4 250
#define F_B_3 236
#define F_BFT_3 223
#define F_ASH_3 223
#define F_A_3 210
#define F_AFT_3 198
#define F_GSH_3 198
#define F_G_3 187
#define F_GFT_3 177
#define F_FSH_3 177
#define F_F_3 167
#define F_E_3 157
#define F_EFT_3 149
#define F_DSH_3 149
#define F_D_3 140
#define F_DFT_3 132
#define F_CSH_3 132
#define F_C_3 125
#define F_B_2 118
#define F_BFT_2 111
#define F_ASH_2 111
#define F_A_2 105
#define F_AFT_2 99
#define F_GSH_2 99
#define F_G_2 94
#define F_GFT_2 88
#define F_FSH_2 88
#define F_F_2 83
#define F_E_2 79
#define F_EFT_2 74
#define F_DSH_2 74
#define F_D_2 70
#define F_DFT_2 66
#define F_CSH_2 66
#define F_C_2 63
#define F_B_1 59
#define F_BFT_1 56
#define F_ASH_1 56
#define F_A_1 53
#define F_AFT_1 50
#define F_GSH_1 50
#define F_G_1 47
#define F_GFT_1 44
#define F_FSH_1 44
#define F_F_1 42
#define F_E_1 39
#define F_EFT_1 37
#define F_DSH_1 37
#define F_D_1 35
#define F_DFT_1 33
#define F_CSH_1 33
#define F_C_1 31
#define F_B_0 29
#define F_BFT_0 28
#define F_ASH_0 28
#define F_A_0 26
#endif

//TICKS_PER_SEC/FREQ results in an effective frequency of 220 for A_4
//	This lowers the pitch by about one octave.  This is fine since
//  ~5000 ticks per second isn't enough to precisely represent higher frequency sounds
#define REST 0xFF // special case
#define C_8 TICKS_PER_SEC/F_B_7
#define B_7 TICKS_PER_SEC/F_B_7
#define BFT_7 TICKS_PER_SEC/F_BFT_7
#define ASH_7 TICKS_PER_SEC/F_ASH_7
#define A_7 TICKS_PER_SEC/F_A_7
#define AFT_7 TICKS_PER_SEC/F_AFT_7
#define GSH_7 TICKS_PER_SEC/F_GSH_7
#define G_7 TICKS_PER_SEC/F_G_7
#define GFT_7 TICKS_PER_SEC/F_GFT_7
#define FSH_7 TICKS_PER_SEC/F_FSH_7
#define F_7 TICKS_PER_SEC/F_F_7
#define E_7 TICKS_PER_SEC/F_E_7
#define EFT_7 TICKS_PER_SEC/F_EFT_7
#define DSH_7 TICKS_PER_SEC/F_DSH_7
#define D_7 TICKS_PER_SEC/F_D_7
#define DFT_7 TICKS_PER_SEC/F_DFT_7
#define CSH_7 TICKS_PER_SEC/F_CSH_7
#define C_7 TICKS_PER_SEC/F_C_7
#define B_6 TICKS_PER_SEC/F_B_6
#define BFT_6 TICKS_PER_SEC/F_BFT_6
#define ASH_6 TICKS_PER_SEC/F_ASH_6
#define A_6 TICKS_PER_SEC/F_A_6
#define AFT_6 TICKS_PER_SEC/F_AFT_6
#define GSH_6 TICKS_PER_SEC/F_GSH_6
#define G_6 TICKS_PER_SEC/F_G_6
#define GFT_6 TICKS_PER_SEC/F_GFT_6
#define FSH_6 TICKS_PER_SEC/F_FSH_6
#define F_6 TICKS_PER_SEC/F_F_6
#define E_6 TICKS_PER_SEC/F_E_6
#define EFT_6 TICKS_PER_SEC/F_EFT_6
#define DSH_6 TICKS_PER_SEC/F_DSH_6
#define D_6 TICKS_PER_SEC/F_D_6
#define DFT_6 TICKS_PER_SEC/F_DFT_6
#define CSH_6 TICKS_PER_SEC/F_CSH_6
#define C_6 TICKS_PER_SEC/F_C_6
#define B_5 TICKS_PER_SEC/F_B_5
#define BFT_5 TICKS_PER_SEC/F_BFT_5
#define ASH_5 TICKS_PER_SEC/F_ASH_5
#define A_5 TICKS_PER_SEC/F_A_5
#define AFT_5 TICKS_PER_SEC/F_AFT_5
#define GSH_5 TICKS_PER_SEC/F_GSH_5
#define G_5 TICKS_PER_SEC/F_G_5
#define GFT_5 TICKS_PER_SEC/F_GFT_5
#define FSH_5 TICKS_PER_SEC/F_FSH_5
#define F_5 TICKS_PER_SEC/F_F_5
#define E_5 TICKS_PER_SEC/F_E_5
#define EFT_5 TICKS_PER_SEC/F_EFT_5
#define DSH_5 TICKS_PER_SEC/F_DSH_5
#define D_5 TICKS_PER_SEC/F_D_5
#define DFT_5 TICKS_PER_SEC/F_DFT_5
#define CSH_5 TICKS_PER_SEC/F_CSH_5
#define C_5 TICKS_PER_SEC/F_C_5
#define B_4 TICKS_PER_SEC/F_B_4
#define BFT_4 TICKS_PER_SEC/F_BFT_4
#define ASH_4 TICKS_PER_SEC/F_ASH_4
#define A_4 TICKS_PER_SEC/F_A_4
#define AFT_4 TICKS_PER_SEC/F_AFT_4
#define GSH_4 TICKS_PER_SEC/F_GSH_4
#define G_4 TICKS_PER_SEC/F_G_4
#define GFT_4 TICKS_PER_SEC/F_GFT_4
#define FSH_4 TICKS_PER_SEC/F_FSH_4
#define F_4 TICKS_PER_SEC/F_F_4
#define E_4 TICKS_PER_SEC/F_E_4
#define EFT_4 TICKS_PER_SEC/F_EFT_4
#define DSH_4 TICKS_PER_SEC/F_DSH_4
#define D_4 TICKS_PER_SEC/F_D_4
#define DFT_4 TICKS_PER_SEC/F_DFT_4
#define CSH_4 TICKS_PER_SEC/F_CSH_4
#define C_4 TICKS_PER_SEC/F_C_4
#define B_3 TICKS_PER_SEC/F_B_3
#define BFT_3 TICKS_PER_SEC/F_BFT_3
#define ASH_3 TICKS_PER_SEC/F_ASH_3
#define A_3 TICKS_PER_SEC/F_A_3
#define AFT_3 TICKS_PER_SEC/F_AFT_3
#define GSH_3 TICKS_PER_SEC/F_GSH_3
#define G_3 TICKS_PER_SEC/F_G_3
#define GFT_3 TICKS_PER_SEC/F_GFT_3
#define FSH_3 TICKS_PER_SEC/F_FSH_3
#define F_3 TICKS_PER_SEC/F_F_3
#define E_3 TICKS_PER_SEC/F_E_3
#define EFT_3 TICKS_PER_SEC/F_EFT_3
#define DSH_3 TICKS_PER_SEC/F_DSH_3
#define D_3 TICKS_PER_SEC/F_D_3
#define DFT_3 TICKS_PER_SEC/F_DFT_3
#define CSH_3 TICKS_PER_SEC/F_CSH_3
#define C_3 TICKS_PER_SEC/F_C_3
#define B_2 TICKS_PER_SEC/F_B_2
#define BFT_2 TICKS_PER_SEC/F_BFT_2
#define ASH_2 TICKS_PER_SEC/F_ASH_2
#define A_2 TICKS_PER_SEC/F_A_2
#define AFT_2 TICKS_PER_SEC/F_AFT_2
#define GSH_2 TICKS_PER_SEC/F_GSH_2
#define G_2 TICKS_PER_SEC/F_G_2
#define GFT_2 TICKS_PER_SEC/F_GFT_2
#define FSH_2 TICKS_PER_SEC/F_FSH_2
#define F_2 TICKS_PER_SEC/F_F_2
#define E_2 TICKS_PER_SEC/F_E_2
#define EFT_2 TICKS_PER_SEC/F_EFT_2
#define DSH_2 TICKS_PER_SEC/F_DSH_2
#define D_2 TICKS_PER_SEC/F_D_2
#define DFT_2 TICKS_PER_SEC/F_DFT_2
#define CSH_2 TICKS_PER_SEC/F_CSH_2
#define C_2 TICKS_PER_SEC/F_C_2
#define B_1 TICKS_PER_SEC/F_B_1
#define BFT_1 TICKS_PER_SEC/F_BFT_1
#define ASH_1 TICKS_PER_SEC/F_ASH_1
#define A_1 TICKS_PER_SEC/F_A_1
#define AFT_1 TICKS_PER_SEC/F_AFT_1
#define GSH_1 TICKS_PER_SEC/F_GSH_1
#define G_1 TICKS_PER_SEC/F_G_1
#define GFT_1 TICKS_PER_SEC/F_GFT_1
#define FSH_1 TICKS_PER_SEC/F_FSH_1
#define F_1 TICKS_PER_SEC/F_F_1
#define E_1 TICKS_PER_SEC/F_E_1
#define EFT_1 TICKS_PER_SEC/F_EFT_1
#define DSH_1 TICKS_PER_SEC/F_DSH_1
#define D_1 TICKS_PER_SEC/F_D_1
#define DFT_1 TICKS_PER_SEC/F_DFT_1
#define CSH_1 TICKS_PER_SEC/F_CSH_1
#define C_1 TICKS_PER_SEC/F_C_1
#define B_0 TICKS_PER_SEC/F_B_0
#define BFT_0 TICKS_PER_SEC/F_BFT_0
#define ASH_0 TICKS_PER_SEC/F_ASH_0
#define A_0 TICKS_PER_SEC/F_A_0
#define A_0 TICKS_PER_SEC/F_A_0

#define K_C_8 88
#define K_B_7 87
#define K_BFT_7 86
#define K_ASH_7 86
#define K_A_7 85
#define K_AFT_7 84
#define K_GSH_7 84
#define K_G_7 83
#define K_GFT_7 82
#define K_FSH_7 82
#define K_F_7 81
#define K_E_7 80
#define K_EFT_7 79
#define K_DSH_7 79
#define K_D_7 78
#define K_DFT_7 77
#define K_CSH_7 77
#define K_C_7 76
#define K_B_6 75
#define K_BFT_6 74
#define K_ASH_6 74
#define K_A_6 73
#define K_AFT_6 72
#define K_GSH_6 72
#define K_G_6 71
#define K_GFT_6 70
#define K_FSH_6 70
#define K_F_6 69
#define K_E_6 68
#define K_EFT_6 67
#define K_DSH_6 67
#define K_D_6 66
#define K_DFT_6 65
#define K_CSH_6 65
#define K_C_6 64
#define K_B_5 63
#define K_BFT_5 62
#define K_ASH_5 62
#define K_A_5 61
#define K_AFT_5 60
#define K_GSH_5 60
#define K_G_5 59
#define K_GFT_5 58
#define K_FSH_5 58
#define K_F_5 57
#define K_E_5 56
#define K_EFT_5 55
#define K_DSH_5 55
#define K_D_5 54
#define K_DFT_5 53
#define K_CSH_5 53
#define K_C_5 52
#define K_B_4 51
#define K_BFT_4 50
#define K_ASH_4 50
#define K_A_4 49
#define K_AFT_4 48
#define K_GSH_4 48
#define K_G_4 47
#define K_GFT_4 46
#define K_FSH_4 46
#define K_F_4 45
#define K_E_4 44
#define K_EFT_4 43
#define K_DSH_4 43
#define K_D_4 42
#define K_DFT_4 41
#define K_CSH_4 41
#define K_C_4 40
#define K_B_3 39
#define K_BFT_3 38
#define K_ASH_3 38
#define K_A_3 37
#define K_AFT_3 36
#define K_GSH_3 36
#define K_G_3 35
#define K_GFT_3 34
#define K_FSH_3 34
#define K_F_3 33
#define K_E_3 32
#define K_EFT_3 31
#define K_DSH_3 31
#define K_D_3 30
#define K_DFT_3 29
#define K_CSH_3 29
#define K_C_3 28
#define K_B_2 27
#define K_BFT_2 26
#define K_ASH_2 26
#define K_A_2 25
#define K_AFT_2 24
#define K_GSH_2 24
#define K_G_2 23
#define K_GFT_2 22
#define K_FSH_2 22
#define K_F_2 21
#define K_E_2 20
#define K_EFT_2 19
#define K_DSH_2 19
#define K_D_2 18
#define K_DFT_2 17
#define K_CSH_2 17
#define K_C_2 16
#define K_B_1 15
#define K_BFT_1 14
#define K_ASH_1 14
#define K_A_1 13
#define K_AFT_1 12
#define K_GSH_1 12
#define K_G_1 11
#define K_GFT_1 10
#define K_FSH_1 10
#define K_F_1 9
#define K_E_1 8
#define K_EFT_1 7
#define K_DSH_1 7
#define K_D_1 6
#define K_DFT_1 5
#define K_CSH_1 5
#define K_C_1 4
#define K_B_0 3
#define K_BFT_0 2
#define K_ASH_0 2
#define K_A_0 1
#define K_REST 0

const unsigned short k[] = { //store key frequencies in an array, makes it easier to change scale
	REST,
	A_0,
	ASH_0,
	B_0,
	C_1,
	CSH_1,
	D_1,
	DSH_1,
	E_1,
	F_1,
	FSH_1,
	G_1,
	GSH_1,
	A_1,
	ASH_1,
	B_1,
	C_2,
	CSH_2,
	D_2,
	DSH_2,
	E_2,
	F_2,
	FSH_2,
	G_2,
	GSH_2,
	A_2,
	ASH_2,
	B_2,
	C_3,
	CSH_3,
	D_3,
	DSH_3,
	E_3,
	F_3,
	FSH_3,
	G_3,
	GSH_3,
	A_3,
	ASH_3,
	B_3,
	C_4,
	CSH_4,
	D_4,
	DSH_4,
	E_4,
	F_4,
	FSH_4,
	G_4,
	GSH_4,
	A_4,
	ASH_4,
	B_4,
	C_5,
	CSH_5,
	D_5,
	DSH_5,
	E_5,
	F_5,
	FSH_5,
	G_5,
	GSH_5,
	A_5,
	ASH_5,
	B_5,
	C_6,
	CSH_6,
	D_6,
	DSH_6,
	E_6,
	F_6,
	FSH_6,
	G_6,
	GSH_6,
	A_6,
	ASH_6,
	B_6,
	C_7,
	CSH_7,
	D_7,
	DSH_7,
	E_7,
	F_7,
	FSH_7,
	G_7,
	GSH_7,
	A_7,
	ASH_7,
	B_7,
	C_8,};



#define NOTE_DURATION 20 //24th of a bar = 20*6 = 120
#define REST_DURATION 7

typedef struct note{
	unsigned char note_per;
	unsigned char duration;
} note;

#define NOTE N_4

note test[] = {{E_5,N_8},
{E_5,N_8},
{REST,N_8},
{E_5,N_8},
{REST,N_8},
{C_5,N_8},
{E_5,N_4},
{G_5,N_4},
{REST,N_4},
{G_4,N_4},
{REST,N_4},
{C_5,N_4_5},
{G_4,N_8},
{REST,N_4},
{E_4,N_4_5},
{A_4,N_4},
{B_4,N_4_5},
{BFT_4,N_8},
{A_4,N_4},
{G_4,N_6},
{E_5,N_6},
{G_5,N_6},
{A_5,N_4},
{F_5,N_4},
{G_5,N_4},
{REST,N_8},
{E_5,N_4},
{C_5,N_8},
{D_5,N_8},
{B_4,N_4},
{REST,N_8},
{C_5,N_4_5},
{G_4,N_8},
{REST,N_4},
{D_4,N_4_5},
{A_4,N_4},
{B_4,N_4},
{BFT_4,N_8},
{A_4,N_4},
{G_4,N_6},
{E_5,N_6},
{G_5,N_6},
{A_5,N_4},
{F_5,N_8},
{G_5,N_8},
{REST,N_8},
{E_5,N_4},
{C_5,N_8},
{D_5,N_8},
{B_4,N_4},
{REST,N_8},
{REST,N_4},
{G_5,N_8},
{GFT_5,N_8},
{F_5,N_8},
{DSH_5,N_4},
{E_5,N_8},
{REST,N_8},
{GSH_4,N_8},
{A_4,N_8},
{C_5,N_8},
{REST,N_8},
{A_4,N_8},
{C_5,N_8},
{D_5,N_8},
{REST,N_4},
{G_5,N_8},
{GFT_5,N_8},
{F_5,N_8},
{DSH_5,N_4},
{E_5,N_8},
{REST,N_8},
{C_6,N_8},
{REST,N_8},
{C_6,N_8},
{C_6,N_4_5},
{REST,N_4_5},
{G_5,N_8},
{GFT_5,N_8},
{F_5,N_8},
{DSH_5,N_4},
{E_5,N_8},
{REST,N_8},
{GSH_4,N_8},
{A_4,N_8},
{C_5,N_8},
{REST,N_8},
{A_4,N_8},
{C_5,N_8},
{D_5,N_8},
{REST,N_4},
{EFT_5,N_4},
{REST,N_8},
{D_5,N_4},
{REST,N_8},
{C_5,N_2},
{REST,N_2},
{REST,N_4},
{G_5,N_8},
{GFT_5,N_8},
{F_5,N_8},
{DSH_5,N_4},
{E_5,N_8},
{REST,N_8},
{GSH_4,N_8},
{A_4,N_8},
{C_5,N_8},
{REST,N_8},
{A_4,N_8},
{C_5,N_8},
{D_5,N_8},
{REST,N_4},
{G_5,N_8},
{GFT_5,N_8},
{F_5,N_8},
{DSH_5,N_4},
{E_5,N_8},
{REST,N_8},
{C_6,N_8},
{REST,N_8},
{C_6,N_8},
{C_6,N_4_5},
{REST,N_4_5},
{G_5,N_8},
{GFT_5,N_8},
{F_5,N_8},
{DSH_5,N_4},
{E_5,N_8},
{REST,N_8},
{GSH_4,N_8},
{A_4,N_8},
{C_5,N_8},
{REST,N_8},
{A_4,N_8},
{C_5,N_8},
{D_5,N_8},
{REST,N_4},
{EFT_5,N_4},
{REST,N_8},
{D_5,N_4},
{REST,N_8},
{C_5,N_2},
{REST,N_2},
	
{REST,NOTE*4}};

note oneUp[] = {{REST,N_4},
{E_4,N_8},
{G_4,N_8},
{E_5,N_8},
{C_5,N_8},
{D_5,N_8},
{G_5,N_8},
{REST, N_1*2}};
note mt[] = {{E_5,3},
{E_5,3},
{REST,3},
{E_5,3},
{REST,3},
{C_5,3},
{E_5,6},
{G_5,6},
{REST,6},
{G_4,6},
{REST,6},
{C_5,9},
{G_4,3},
{REST,6},
{E_4,9},
{A_4,6},
{B_4,6},
{ASH_4,3},
{G_4,6},
{E_4,4},
{G_4,4},
{A_5,4},
{F_5,6},
{G_5,3},
{E_5,3},
{REST,3},
{C_5,6},
{D_5,3},
{B_4,12},
{REST,100}}; //super mario theme
	
note mt2[] ={{E_5,3},
{E_5,3},
{REST,3},
{E_5,3},
{REST,3},
{B_4,3},
{E_5,6},
{GFT_5,6},
{REST,6},
{GFT_4,6},
{REST,6},
{B_4,9},
{GFT_4,3},
{REST,6},
{EFT_4,9},
{A_4,6},
{BFT_4,6},
{A_4,3},
{GSH_4,6},
{GFT_4,4},
{E_5,4},
{GFT_5,4},
{GSH_5,6},
{F_5,3},
{GFT_5,3},
{E_5,3},
{C_5,6},
{DFT_5,3},
{BFT_4,12}, {REST,100}
};

#define cf_OFFSET 0
note cf[26]; /*{{FSH_4, N_4}, //crazy frog
        {REST, N_4},
        {A_4, N_4_5},
        {FSH_4, N_4},
        {FSH_4, N_8},
        {B_4, N_4},
        {FSH_4, N_4},
        {E_4, N_4},
        {FSH_4, N_4},
        {REST, N_4},
        {CSH_5, N_4_5},
        {FSH_4, N_4},
        {FSH_4, N_8},
        {D_5, N_4},
        {CSH_5, N_4},
        {A_4, N_4},
        {FSH_4, N_4},
        {CSH_5, N_4},
        {FSH_5, N_4},
        {FSH_4, N_8},
        {E_4, N_4},
        {E_4, N_8},
        {CSH_4, N_4},
        {GSH_4, N_4},
        {FSH_4, N_2*3},
        {REST, N_2_5}};*/


static unsigned char temp, i = 0;
#define S_INIT(song,KEY,DUR)(temp = i++, song[temp].note_per = k[(KEY == REST)?K_REST:(K_##KEY + song##_OFFSET)], song[temp].duration = DUR)

void initSongs()
{
S_INIT(cf,FSH_4, N_4), //crazy frog
S_INIT(cf,REST, N_4),
S_INIT(cf,A_4, N_4_5),
S_INIT(cf,FSH_4, N_4),
S_INIT(cf,FSH_4, N_8),
S_INIT(cf,B_4, N_4),
S_INIT(cf,FSH_4, N_4),
S_INIT(cf,E_4, N_4),
S_INIT(cf,FSH_4, N_4),
S_INIT(cf,REST, N_4),
S_INIT(cf,CSH_5, N_4_5),
S_INIT(cf,FSH_4, N_4),
S_INIT(cf,FSH_4, N_8),
S_INIT(cf,D_5, N_4),
S_INIT(cf,CSH_5, N_4),
S_INIT(cf,A_4, N_4),
S_INIT(cf,FSH_4, N_4),
S_INIT(cf,CSH_5, N_4),
S_INIT(cf,FSH_5, N_4),
S_INIT(cf,FSH_4, N_8),
S_INIT(cf,E_4, N_4),
S_INIT(cf,E_4, N_8),
S_INIT(cf,CSH_4, N_4),
S_INIT(cf,GSH_4, N_4),
S_INIT(cf,FSH_4, N_2*3),
S_INIT(cf,REST, N_2_5);
/*cf[0].note_per = FSH_4,	cf[0].duration = N_4,//crazy frog
cf[1].note_per = REST,	cf[1].duration = N_4,
cf[2].note_per = A_4,	cf[2].duration = N_4_5,
cf[3].note_per = FSH_4,	cf[3].duration = N_4,
cf[4].note_per = FSH_4,	cf[4].duration = N_8,
cf[5].note_per = B_4,	cf[5].duration = N_4,
cf[6].note_per = FSH_4,	cf[6].duration = N_4,
cf[7].note_per = E_4,	cf[7].duration = N_4,
cf[8].note_per = FSH_4,	cf[8].duration = N_4,
cf[9].note_per = REST,	cf[9].duration = N_4,
cf[10].note_per = CSH_5,cf[10].duration = N_4_5,
cf[11].note_per = FSH_4,cf[11].duration = N_4,
cf[12].note_per = FSH_4,cf[12].duration = N_8,
cf[13].note_per = D_5,	cf[13].duration = N_4,
cf[14].note_per = CSH_5,cf[14].duration = N_4,
cf[15].note_per = A_4,	cf[15].duration = N_4,
cf[16].note_per = FSH_4,cf[16].duration = N_4,
cf[17].note_per = CSH_5,cf[17].duration = N_4,
cf[18].note_per = FSH_5,cf[18].duration = N_4,
cf[19].note_per = FSH_4,cf[19].duration = N_8,
cf[20].note_per = E_4,	cf[20].duration = N_4,
cf[21].note_per = E_4,	cf[21].duration = N_8,
cf[22].note_per = CSH_4,cf[22].duration = N_4,
cf[23].note_per = GSH_4,cf[23].duration = N_4,
cf[24].note_per = FSH_4,cf[24].duration = N_2*3,
cf[25].note_per = REST,	cf[25].duration = N_2_5;*/
}

#endif