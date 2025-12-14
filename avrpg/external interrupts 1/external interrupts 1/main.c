/*
 * external interrupts 1.c
 *
 * Created: 12/14/2025 7:19:26 PM
 * Author : Admin
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect)//interrupt service routine for external interrupt 0
{
	PORTB|=(1<<PB5);//toggle led FOR 
	_delay_ms(3000);
}
int main(void)
{
   sei();//enable global interrupt
   EIFR|=(1<<INTF0);// ******IMPORTANT *****INITIALIZE EIFR FLAG AS  0
   DDRD&=~(1<<DDD2);
   DDRB|=(1<<DDB5)|(1<<DDB4);//make pb5 as output
   EIMSK|=(1<<INT0);//***IMPO***enable external interrupt 0
   EICRA|=(1<<ISC01);//***IMPO**
   EICRA&=~(1<<ISC00);// ****IMPO****config interrupt for FALLING edge 
    while (1) 
    {
		PORTB&=~(1<<PB5);//PB5 OFF NORMALLY
		PORTB^=(1<<PB4);//PB4 BLINKING WITH 1 SEC DELAY
		_delay_ms(1000);
    }
}

