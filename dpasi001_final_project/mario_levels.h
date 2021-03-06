#ifndef MARIO_MAPS
#define MARIO_MAPS

void loadLevel1(uchar col)
{
	switch(col)
	{
		case 0: RedLevelData[0] = 0x00; GreenLevelData[0] = 0x01; BlueLevelData[0] = 0x00; BarrierLevelData[0] = 0x01; break;
		case 1: RedLevelData[1] = 0x00; GreenLevelData[1] = 0x01; BlueLevelData[1] = 0x00; BarrierLevelData[1] = 0x01; break;
		case 2: RedLevelData[2] = 0x40; GreenLevelData[2] = 0x41; BlueLevelData[2] = 0x40; BarrierLevelData[2] = 0x01; break;
		case 3: RedLevelData[3] = 0xC0; GreenLevelData[3] = 0xC1; BlueLevelData[3] = 0xC0; BarrierLevelData[3] = 0x01; break;
		case 4: RedLevelData[4] = 0x40; GreenLevelData[4] = 0x41; BlueLevelData[4] = 0x40; BarrierLevelData[4] = 0x01; break;
		case 5: RedLevelData[5] = 0x00; GreenLevelData[5] = 0x01; BlueLevelData[5] = 0x00; BarrierLevelData[5] = 0x01; break;
		case 6: RedLevelData[6] = 0x00; GreenLevelData[6] = 0x01; BlueLevelData[6] = 0x00; BarrierLevelData[6] = 0x01; break;
		case 7: RedLevelData[7] = 0x08; GreenLevelData[7] = 0x09; BlueLevelData[7] = 0x00; BarrierLevelData[7] = 0x09; break;
		case 8: RedLevelData[8] = 0x00; GreenLevelData[8] = 0x01; BlueLevelData[8] = 0x00; BarrierLevelData[8] = 0x01; break;
		case 9: RedLevelData[9] = 0x08; GreenLevelData[9] = 0x09; BlueLevelData[9] = 0x00; BarrierLevelData[9] = 0x09; break;
		case 10: RedLevelData[10] = 0x28; GreenLevelData[10] = 0x29; BlueLevelData[10] = 0x00; BarrierLevelData[10] = 0x29; break;
		case 11: RedLevelData[11] = 0x08; GreenLevelData[11] = 0x09; BlueLevelData[11] = 0x00; BarrierLevelData[11] = 0x09; break;
		case 12: RedLevelData[12] = 0x00; GreenLevelData[12] = 0x01; BlueLevelData[12] = 0x00; BarrierLevelData[12] = 0x01; break;
		case 13: RedLevelData[13] = 0x00; GreenLevelData[13] = 0x01; BlueLevelData[13] = 0x00; BarrierLevelData[13] = 0x01; break;
		case 14: RedLevelData[14] = 0x00; GreenLevelData[14] = 0x01; BlueLevelData[14] = 0x00; BarrierLevelData[14] = 0x01; break;
		case 15: RedLevelData[15] = 0x00; GreenLevelData[15] = 0x01; BlueLevelData[15] = 0x00; BarrierLevelData[15] = 0x01; break;
		case 16: RedLevelData[16] = 0x80; GreenLevelData[16] = 0x87; BlueLevelData[16] = 0x80; BarrierLevelData[16] = 0x07; break;
		case 17: RedLevelData[17] = 0xC0; GreenLevelData[17] = 0xC7; BlueLevelData[17] = 0xC0; BarrierLevelData[17] = 0x07; break;
		case 18: RedLevelData[18] = 0x40; GreenLevelData[18] = 0x41; BlueLevelData[18] = 0x40; BarrierLevelData[18] = 0x01; break;
		case 19: RedLevelData[19] = 0x00; GreenLevelData[19] = 0x01; BlueLevelData[19] = 0x00; BarrierLevelData[19] = 0x01; break;
		case 20: RedLevelData[20] = 0x00; GreenLevelData[20] = 0x01; BlueLevelData[20] = 0x00; BarrierLevelData[20] = 0x01; break;
		case 21: RedLevelData[21] = 0x00; GreenLevelData[21] = 0x0F; BlueLevelData[21] = 0x00; BarrierLevelData[21] = 0x0F; break;
		case 22: RedLevelData[22] = 0x00; GreenLevelData[22] = 0x0F; BlueLevelData[22] = 0x00; BarrierLevelData[22] = 0x0F; break;
		case 23: RedLevelData[23] = 0x00; GreenLevelData[23] = 0x01; BlueLevelData[23] = 0x00; BarrierLevelData[23] = 0x01; break;
		case 24: RedLevelData[24] = 0x00; GreenLevelData[24] = 0x01; BlueLevelData[24] = 0x00; BarrierLevelData[24] = 0x01; break;
		case 25: RedLevelData[25] = 0x00; GreenLevelData[25] = 0x0F; BlueLevelData[25] = 0x00; BarrierLevelData[25] = 0x0F; break;
		case 26: RedLevelData[26] = 0x00; GreenLevelData[26] = 0x0F; BlueLevelData[26] = 0x00; BarrierLevelData[26] = 0x0F; break;
		case 27: RedLevelData[27] = 0x00; GreenLevelData[27] = 0x01; BlueLevelData[27] = 0x00; BarrierLevelData[27] = 0x01; break;
		case 28: RedLevelData[28] = 0x00; GreenLevelData[28] = 0x01; BlueLevelData[28] = 0x00; BarrierLevelData[28] = 0x01; break;
		case 29: RedLevelData[29] = 0x00; GreenLevelData[29] = 0x0F; BlueLevelData[29] = 0x00; BarrierLevelData[29] = 0x0F; break;
		case 30: RedLevelData[30] = 0x00; GreenLevelData[30] = 0x0F; BlueLevelData[30] = 0x00; BarrierLevelData[30] = 0x0F; break;
		case 31: RedLevelData[31] = 0x00; GreenLevelData[31] = 0x01; BlueLevelData[31] = 0x00; BarrierLevelData[31] = 0x01; break;
		case 32: RedLevelData[32] = 0x00; GreenLevelData[32] = 0x01; BlueLevelData[32] = 0x00; BarrierLevelData[32] = 0x01; break;
		case 33: RedLevelData[33] = 0x08; GreenLevelData[33] = 0x09; BlueLevelData[33] = 0x00; BarrierLevelData[33] = 0x09; break;
		case 34: RedLevelData[34] = 0x00; GreenLevelData[34] = 0x01; BlueLevelData[34] = 0x00; BarrierLevelData[34] = 0x01; break;
		case 35: RedLevelData[35] = 0x00; GreenLevelData[35] = 0x01; BlueLevelData[35] = 0x00; BarrierLevelData[35] = 0x01; break;
		case 36: RedLevelData[36] = 0x40; GreenLevelData[36] = 0x41; BlueLevelData[36] = 0x40; BarrierLevelData[36] = 0x01; break;
		case 37: RedLevelData[37] = 0xC0; GreenLevelData[37] = 0xC1; BlueLevelData[37] = 0xC0; BarrierLevelData[37] = 0x01; break;
		case 38: RedLevelData[38] = 0xE0; GreenLevelData[38] = 0xE0; BlueLevelData[38] = 0xE0; BarrierLevelData[38] = 0x00; break;
		case 39: RedLevelData[39] = 0x40; GreenLevelData[39] = 0x40; BlueLevelData[39] = 0x40; BarrierLevelData[39] = 0x00; break;
		case 40: RedLevelData[40] = 0x00; GreenLevelData[40] = 0x01; BlueLevelData[40] = 0x00; BarrierLevelData[40] = 0x01; break;
		case 41: RedLevelData[41] = 0x04; GreenLevelData[41] = 0x05; BlueLevelData[41] = 0x00; BarrierLevelData[41] = 0x05; break;
		case 42: RedLevelData[42] = 0x04; GreenLevelData[42] = 0x05; BlueLevelData[42] = 0x00; BarrierLevelData[42] = 0x05; break;
		case 43: RedLevelData[43] = 0x10; GreenLevelData[43] = 0x11; BlueLevelData[43] = 0x00; BarrierLevelData[43] = 0x11; break;
		case 44: RedLevelData[44] = 0x10; GreenLevelData[44] = 0x11; BlueLevelData[44] = 0x00; BarrierLevelData[44] = 0x11; break;
		case 45: RedLevelData[45] = 0x10; GreenLevelData[45] = 0x11; BlueLevelData[45] = 0x00; BarrierLevelData[45] = 0x11; break;
		case 46: RedLevelData[46] = 0x10; GreenLevelData[46] = 0x11; BlueLevelData[46] = 0x00; BarrierLevelData[46] = 0x11; break;
		case 47: RedLevelData[47] = 0x00; GreenLevelData[47] = 0x01; BlueLevelData[47] = 0x00; BarrierLevelData[47] = 0x01; break;
		case 48: RedLevelData[48] = 0x00; GreenLevelData[48] = 0x01; BlueLevelData[48] = 0x00; BarrierLevelData[48] = 0x01; break;
		case 49: RedLevelData[49] = 0x00; GreenLevelData[49] = 0x00; BlueLevelData[49] = 0x00; BarrierLevelData[49] = 0x00; break;
		case 50: RedLevelData[50] = 0x00; GreenLevelData[50] = 0x00; BlueLevelData[50] = 0x00; BarrierLevelData[50] = 0x00; break;
		case 51: RedLevelData[51] = 0x00; GreenLevelData[51] = 0x00; BlueLevelData[51] = 0x00; BarrierLevelData[51] = 0x00; break;
		case 52: RedLevelData[52] = 0x10; GreenLevelData[52] = 0x11; BlueLevelData[52] = 0x00; BarrierLevelData[52] = 0x11; break;
		case 53: RedLevelData[53] = 0x14; GreenLevelData[53] = 0x15; BlueLevelData[53] = 0x00; BarrierLevelData[53] = 0x15; break;
		case 54: RedLevelData[54] = 0x00; GreenLevelData[54] = 0x01; BlueLevelData[54] = 0x00; BarrierLevelData[54] = 0x01; break;
		case 55: RedLevelData[55] = 0x00; GreenLevelData[55] = 0x01; BlueLevelData[55] = 0x00; BarrierLevelData[55] = 0x01; break;
		case 56: RedLevelData[56] = 0x48; GreenLevelData[56] = 0x49; BlueLevelData[56] = 0x40; BarrierLevelData[56] = 0x09; break;
		case 57: RedLevelData[57] = 0xC8; GreenLevelData[57] = 0xC9; BlueLevelData[57] = 0xC0; BarrierLevelData[57] = 0x09; break;
		case 58: RedLevelData[58] = 0xC0; GreenLevelData[58] = 0xC1; BlueLevelData[58] = 0xC0; BarrierLevelData[58] = 0x01; break;
		case 59: RedLevelData[59] = 0x80; GreenLevelData[59] = 0x81; BlueLevelData[59] = 0x80; BarrierLevelData[59] = 0x01; break;
		case 60: RedLevelData[60] = 0x08; GreenLevelData[60] = 0x09; BlueLevelData[60] = 0x00; BarrierLevelData[60] = 0x09; break;
		case 61: RedLevelData[61] = 0x00; GreenLevelData[61] = 0x01; BlueLevelData[61] = 0x00; BarrierLevelData[61] = 0x01; break;
		case 62: RedLevelData[62] = 0x28; GreenLevelData[62] = 0x29; BlueLevelData[62] = 0x00; BarrierLevelData[62] = 0x29; break;
		case 63: RedLevelData[63] = 0x00; GreenLevelData[63] = 0x01; BlueLevelData[63] = 0x00; BarrierLevelData[63] = 0x01; break;
		case 64: RedLevelData[64] = 0x08; GreenLevelData[64] = 0x09; BlueLevelData[64] = 0x00; BarrierLevelData[64] = 0x09; break;
		case 65: RedLevelData[65] = 0x00; GreenLevelData[65] = 0x01; BlueLevelData[65] = 0x00; BarrierLevelData[65] = 0x01; break;
		case 66: RedLevelData[66] = 0x00; GreenLevelData[66] = 0x01; BlueLevelData[66] = 0x00; BarrierLevelData[66] = 0x01; break;
		case 67: RedLevelData[67] = 0x20; GreenLevelData[67] = 0x21; BlueLevelData[67] = 0x00; BarrierLevelData[67] = 0x21; break;
		case 68: RedLevelData[68] = 0x20; GreenLevelData[68] = 0x21; BlueLevelData[68] = 0x00; BarrierLevelData[68] = 0x21; break;
		case 69: RedLevelData[69] = 0x00; GreenLevelData[69] = 0x01; BlueLevelData[69] = 0x00; BarrierLevelData[69] = 0x01; break;
		case 70: RedLevelData[70] = 0x00; GreenLevelData[70] = 0x01; BlueLevelData[70] = 0x00; BarrierLevelData[70] = 0x01; break;
		case 71: RedLevelData[71] = 0x28; GreenLevelData[71] = 0x29; BlueLevelData[71] = 0x00; BarrierLevelData[71] = 0x29; break;
		case 72: RedLevelData[72] = 0x20; GreenLevelData[72] = 0x21; BlueLevelData[72] = 0x00; BarrierLevelData[72] = 0x21; break;
		case 73: RedLevelData[73] = 0x00; GreenLevelData[73] = 0x01; BlueLevelData[73] = 0x00; BarrierLevelData[73] = 0x01; break;
		case 74: RedLevelData[74] = 0x00; GreenLevelData[74] = 0x01; BlueLevelData[74] = 0x00; BarrierLevelData[74] = 0x01; break;
		case 75: RedLevelData[75] = 0x02; GreenLevelData[75] = 0x03; BlueLevelData[75] = 0x00; BarrierLevelData[75] = 0x03; break;
		case 76: RedLevelData[76] = 0x06; GreenLevelData[76] = 0x07; BlueLevelData[76] = 0x00; BarrierLevelData[76] = 0x07; break;
		case 77: RedLevelData[77] = 0x0E; GreenLevelData[77] = 0x0F; BlueLevelData[77] = 0x00; BarrierLevelData[77] = 0x0F; break;
		case 78: RedLevelData[78] = 0x00; GreenLevelData[78] = 0x01; BlueLevelData[78] = 0x00; BarrierLevelData[78] = 0x01; break;
		case 79: RedLevelData[79] = 0x0E; GreenLevelData[79] = 0x0F; BlueLevelData[79] = 0x00; BarrierLevelData[79] = 0x0F; break;
		case 80: RedLevelData[80] = 0x06; GreenLevelData[80] = 0x07; BlueLevelData[80] = 0x00; BarrierLevelData[80] = 0x07; break;
		case 81: RedLevelData[81] = 0x42; GreenLevelData[81] = 0x43; BlueLevelData[81] = 0x40; BarrierLevelData[81] = 0x03; break;
		case 82: RedLevelData[82] = 0xC0; GreenLevelData[82] = 0xC1; BlueLevelData[82] = 0xC0; BarrierLevelData[82] = 0x01; break;
		case 83: RedLevelData[83] = 0x40; GreenLevelData[83] = 0x41; BlueLevelData[83] = 0x40; BarrierLevelData[83] = 0x01; break;
		case 84: RedLevelData[84] = 0x02; GreenLevelData[84] = 0x03; BlueLevelData[84] = 0x00; BarrierLevelData[84] = 0x03; break;
		case 85: RedLevelData[85] = 0x06; GreenLevelData[85] = 0x07; BlueLevelData[85] = 0x00; BarrierLevelData[85] = 0x07; break;
		case 86: RedLevelData[86] = 0x0E; GreenLevelData[86] = 0x0F; BlueLevelData[86] = 0x00; BarrierLevelData[86] = 0x0F; break;
		case 87: RedLevelData[87] = 0x0E; GreenLevelData[87] = 0x0F; BlueLevelData[87] = 0x00; BarrierLevelData[87] = 0x0F; break;
		case 88: RedLevelData[88] = 0x00; GreenLevelData[88] = 0x00; BlueLevelData[88] = 0x00; BarrierLevelData[88] = 0x00; break;
		case 89: RedLevelData[89] = 0x0E; GreenLevelData[89] = 0x0F; BlueLevelData[89] = 0x00; BarrierLevelData[89] = 0x0F; break;
		case 90: RedLevelData[90] = 0x06; GreenLevelData[90] = 0x07; BlueLevelData[90] = 0x00; BarrierLevelData[90] = 0x07; break;
		case 91: RedLevelData[91] = 0x02; GreenLevelData[91] = 0x03; BlueLevelData[91] = 0x00; BarrierLevelData[91] = 0x03; break;
		case 92: RedLevelData[92] = 0x00; GreenLevelData[92] = 0x01; BlueLevelData[92] = 0x00; BarrierLevelData[92] = 0x01; break;
		case 93: RedLevelData[93] = 0x00; GreenLevelData[93] = 0x07; BlueLevelData[93] = 0x00; BarrierLevelData[93] = 0x07; break;
		case 94: RedLevelData[94] = 0x00; GreenLevelData[94] = 0x07; BlueLevelData[94] = 0x00; BarrierLevelData[94] = 0x07; break;
		case 95: RedLevelData[95] = 0x00; GreenLevelData[95] = 0x01; BlueLevelData[95] = 0x00; BarrierLevelData[95] = 0x01; break;
		case 96: RedLevelData[96] = 0x00; GreenLevelData[96] = 0x01; BlueLevelData[96] = 0x00; BarrierLevelData[96] = 0x01; break;
		case 97: RedLevelData[97] = 0x08; GreenLevelData[97] = 0x09; BlueLevelData[97] = 0x00; BarrierLevelData[97] = 0x09; break;
		case 98: RedLevelData[98] = 0x08; GreenLevelData[98] = 0x09; BlueLevelData[98] = 0x00; BarrierLevelData[98] = 0x09; break;
		case 99: RedLevelData[99] = 0x00; GreenLevelData[99] = 0x01; BlueLevelData[99] = 0x00; BarrierLevelData[99] = 0x01; break;
		case 100: RedLevelData[100] = 0x00; GreenLevelData[100] = 0x01; BlueLevelData[100] = 0x00; BarrierLevelData[100] = 0x01; break;
		case 101: RedLevelData[101] = 0x02; GreenLevelData[101] = 0x03; BlueLevelData[101] = 0x00; BarrierLevelData[101] = 0x03; break;
		case 102: RedLevelData[102] = 0x06; GreenLevelData[102] = 0x07; BlueLevelData[102] = 0x00; BarrierLevelData[102] = 0x07; break;
		case 103: RedLevelData[103] = 0x0E; GreenLevelData[103] = 0x0F; BlueLevelData[103] = 0x00; BarrierLevelData[103] = 0x0F; break;
		case 104: RedLevelData[104] = 0x1E; GreenLevelData[104] = 0x1F; BlueLevelData[104] = 0x00; BarrierLevelData[104] = 0x1F; break;
		case 105: RedLevelData[105] = 0x00; GreenLevelData[105] = 0x01; BlueLevelData[105] = 0x00; BarrierLevelData[105] = 0x01; break;
		case 106: RedLevelData[106] = 0x00; GreenLevelData[106] = 0x01; BlueLevelData[106] = 0x00; BarrierLevelData[106] = 0x01; break;
		case 107: RedLevelData[107] = 0x00; GreenLevelData[107] = 0x01; BlueLevelData[107] = 0x00; BarrierLevelData[107] = 0x01; break;
		case 108: RedLevelData[108] = 0x00; GreenLevelData[108] = 0x01; BlueLevelData[108] = 0x00; BarrierLevelData[108] = 0x01; break;
		case 109: RedLevelData[109] = 0x00; GreenLevelData[109] = 0x01; BlueLevelData[109] = 0x00; BarrierLevelData[109] = 0x01; break;
		case 110: RedLevelData[110] = 0x40; GreenLevelData[110] = 0x41; BlueLevelData[110] = 0x40; BarrierLevelData[110] = 0x01; break;
		case 111: RedLevelData[111] = 0xE0; GreenLevelData[111] = 0xE1; BlueLevelData[111] = 0xE0; BarrierLevelData[111] = 0x01; break;
		case 112: RedLevelData[112] = 0xE0; GreenLevelData[112] = 0xE1; BlueLevelData[112] = 0xE0; BarrierLevelData[112] = 0x01; break;
		case 113: RedLevelData[113] = 0x4E; GreenLevelData[113] = 0x4F; BlueLevelData[113] = 0x40; BarrierLevelData[113] = 0x09; break;
		case 114: RedLevelData[114] = 0x1E; GreenLevelData[114] = 0x1F; BlueLevelData[114] = 0x00; BarrierLevelData[114] = 0x19; break;
		case 115: RedLevelData[115] = 0x18; GreenLevelData[115] = 0x19; BlueLevelData[115] = 0x00; BarrierLevelData[115] = 0x19; break;
		case 116: RedLevelData[116] = 0x1E; GreenLevelData[116] = 0x1F; BlueLevelData[116] = 0x00; BarrierLevelData[116] = 0x1F; break;
		case 117: RedLevelData[117] = 0x0E; GreenLevelData[117] = 0x0F; BlueLevelData[117] = 0x00; BarrierLevelData[117] = 0x0F; break;
		case 118: RedLevelData[118] = 0x00; GreenLevelData[118] = 0x01; BlueLevelData[118] = 0x00; BarrierLevelData[118] = 0x01; break;
		case 119: RedLevelData[119] = 0x00; GreenLevelData[119] = 0x00; BlueLevelData[119] = 0xFF; BarrierLevelData[119] = 0xFF; break;
		default: break;
	}
}


#endif