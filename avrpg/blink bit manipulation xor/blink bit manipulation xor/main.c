/*
 * blink bit manipulation xor.c
 *
 * Created: 11/16/2025 7:19:17 PM
 * Author : Admin
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>

int main(void)
{
	DDRD|=(1<<DDD2);
    /* Replace with your application code */
    while (1) 
    {
		PORTD^=(1<<PD2);
		_delay_ms(3000);
		PORTD&=~(1<<PD2);
		_delay_ms(3000);
    }
}

