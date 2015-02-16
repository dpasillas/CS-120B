/* dpasi001_port_assign.h - 3/15/2013
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


#ifndef PORT_ASSIGN_H
#define PORT_ASSIGN_H

unsigned char PORTA_PROXY, PORTB_PROXY, PORTC_PROXY, PORTD_PROXY;

#define PORT_EQ(PORT, val)(PORT##_PROXY = val, PORT = PORT##_PROXY)
#define PORT_OR_EQ(PORT, val)(PORT##_PROXY |= val, PORT = PORT##_PROXY)
#define PORT_AND_EQ(PORT, val)(PORT##_PROXY &= val, PORT = PORT##_PROXY)

#endif