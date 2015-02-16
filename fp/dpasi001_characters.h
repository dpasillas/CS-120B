/* dpasi001_characters.h - 3/15/2013
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

#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <dpasi001_pixel.h>

typedef struct Character{
	char x, y;
	Pixel color, back;
} Character;

Character objs[10]; // for mario, enemies, and other mobile/interactive objects.

#define mario objs[0]

#endif