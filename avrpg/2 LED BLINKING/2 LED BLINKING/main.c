/*
 * 2 LED BLINKING.c
 *
 * Created: 11/16/2025 7:33:49 PM
 * Author : Admin
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>

int main(void)

{
	DDRD|=(1<<DDD2)|(1<<DDD3);//initializing pin D2 AND D3 AS OUTPUT
    /* Replace with your application code */
    while (1) 
    {
		//PD2 ON PD3 OFF DELAY 5SEC
		PORTD|=(1<<PD2); 
		PORTD&=~(1<<PD3);
		_delay_ms(5000);
		
		
		//PD2 AND PD3 OFF DELAY 3 SEC
		PORTD&=~(1<<PD2);
		PORTD&=~(1<<PD3);
		_delay_ms(3000);
	     
		 //PD3 ON PD2 OFF DELAY 5 SEC
		 	
		PORTD|=(1<<PD3);
		PORTD&=~(1<<PD2);
		_delay_ms(5000);
		
    }
}

