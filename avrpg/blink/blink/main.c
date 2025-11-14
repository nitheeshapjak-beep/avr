/*
 * blink.c
 *
 * Created: 11/13/2025 8:46:02 PM
 * Author : Admin
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>


int main(void)
{
  DDRB=0b00100000;
    while (1) 
    {
		PORTB=0b00100000;
		_delay_ms(1000);
		PORTB=0b00000000;
		_delay_ms(1000);
		
    }
}

