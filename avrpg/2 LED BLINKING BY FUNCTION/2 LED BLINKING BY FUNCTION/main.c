/*
 * 2 LED BLINKING BY FUNCTION.c
 *
 * Created: 11/16/2025 7:56:25 PM
 * Author : Admin
 */ 

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
	 CW(PORTD,PD2,PD3)
	 {
		 PORTD|=(1<<PD2);
		 PORTD&=~(1<<PD3);
		 _delay_ms(5000);
	 }
	 CCW(PORTD,PD2,PD3)
	 {
		 PORTD|=(1<<PD3);
		 PORTD&=~(1<<PD2);
		 _delay_ms(5000);
	 }
	  STOP(PORTD,PD2,PD3)
	  {
    PORTD&=~(1<<PD2);
    PORTD&=~(1<<PD3);
    _delay_ms(3000);
	  }
	
    while (1) 
    {
		CW;
		CCW;
		STOP;
		
		
		
		
		
		
    }
}


