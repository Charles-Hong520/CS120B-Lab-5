/*	Author: Charles Hong
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #3
 *	Exercise Description: Cool Lights
 *	Link: 
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
#define A (~PINA&0xFF)
enum State {start, on, off} state;
unsigned char tmpA = 0x00;

int main(void) {
    DDRA = 0x00; PORTA = 0xFF; //input
    DDRB = 0xFF; PORTB = 0x00; //output
    state = start;
    unsigned char cnt = 0;
    while(1) {
        switch(state) {
            case start:
            state = off;
            break;
            case on:
            if(A==0x00) {
                state = off;
            } else {
                state = on;
            }
            break;
            case off:
            if(A==0x00) {
                state = off;
            } else {
                state = on;
                cnt = (cnt+1)%11;
                if(cnt==0) PORTB = 0x00;
                else if(cnt==1) PORTB = 0x01;
                else if(cnt==2) PORTB = 0x05;
                else if(cnt==3) PORTB = 0x15;
                else if(cnt==4) PORTB = 0x17;
                else if(cnt==5) PORTB = 0x1F;
                else if(cnt==6) PORTB = 0x3F;
                else if(cnt==7) PORTB = 0x00;
                else if(cnt==8) PORTB = 0x3F;
                else if(cnt==9) PORTB = 0x00;
                else if(cnt==10) PORTB = 0x3F;
             }
            break;
        }
    }
    return 1;
}