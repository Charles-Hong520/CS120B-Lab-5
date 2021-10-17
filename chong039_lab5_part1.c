/*	Author: Charles Hong
 *  Partner(s) Name: N/A
 *	Lab Section: 022
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: Car Fuel Sensor from 3.2
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as inputs
	unsigned char tmpA = 0x00; 

	while(1) {
		// 1) Read input
		tmpA = (~PINA & 0x0F);
		unsigned char tmpC = 0x00; 

		// 2) Perform computation
		if(tmpA==0) tmpC=0x00;
		else if(tmpA <= 2) tmpC = 0x20;
		else if(tmpA <= 4) tmpC = 0x30;
		else if(tmpA <= 6) tmpC = 0x38;
		else if(tmpA <= 9) tmpC = 0x3C;
		else if(tmpA <= 12) tmpC = 0x3E;
		else if (tmpA <= 15) tmpC = 0x3F;

		if(tmpA<=4) tmpC += 1<<6;
		// 3) Write output
		PORTC = tmpC;
	}
	return 0;
}