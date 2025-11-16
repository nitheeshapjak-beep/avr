/*
 * blink.c
 *
 * Created: 11/13/2025 8:46:02 Pm
 * Author : Admin
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>


int main(void)
{
  DDRB=0b00100000;// dedicating 5 TH PIN OF PORT B AS OUTPUT
    while (1) 
    {
		PORTB=0b00100000; //MAKE OUTPUT HIGH AT 5TH PIN OF PORT B
		_delay_ms(3000);//MAKE DELAY OF 3 SEC
		PORTB=0b00000000;//MAKE OUTPUT LOW AT 5TH PIN OF PORT B
		_delay_ms(3000);//MAKE DELAY OF 3 SEC
		
    }
}

