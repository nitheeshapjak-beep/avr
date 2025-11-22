/*
 * internal pullup.c
 *
 * Created: 11/22/2025 8:47:55 PM
 * Author : Admin
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)

{
	DDRB|=(1<<DDB5);//MAKING PIN B5 AS OUTPUT
	PORTB|=(1<<PB6);//MAKING PIN B6 INTERNALLY PULLED UP
	DDRB&=~(1<<DDB6);//MAKING PIN B6 AS INPUT
    /* Replace with your application code */
    while (1) 
    {
		if (!(PINB&(1<<PB6)))// CHECK PB6 PIN IS LOW
		
{
	PORTB|=(1<<PB5);//MAKE PB5 HIGH
    }
	
	else
	
	{
		PORTB&=~(1<<PB5);//MAKE PB5 LOW
	}
	}
	
}

