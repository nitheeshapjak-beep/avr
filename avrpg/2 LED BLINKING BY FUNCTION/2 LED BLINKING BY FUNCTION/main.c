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

 void CW(void)//
 {
	 PORTD|=(1<<PD2);
	 PORTD&=~(1<<PD3);
	 
 }
 void CCW(void)
 {
	 PORTD|=(1<<PD3);
	 PORTD&=~(1<<PD2);
	 
 }
 void STOP(void)
 {
	 PORTD&=~(1<<PD2);
	 PORTD&=~(1<<PD3);
	 
 }

int main(void)

{
	DDRD|=(1<<DDD2)|(1<<DDD3);//initializing pin D2 AND D3 AS OUTPUT
	
	
    while (1) 
    {
		CW();
		_delay_ms(5000);
		CCW();
		_delay_ms(3000);
		STOP();
		_delay_ms(5000);
		
		
		
		
		
		
    }
}


