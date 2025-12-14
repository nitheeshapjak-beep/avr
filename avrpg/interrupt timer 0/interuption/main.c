/*
 * interuption.c
 *
 * Created: 12/5/2025 11:01:15 PM
 * Author : Admin
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include<avr/interrupt.h>
volatile uint16_t count=0;
ISR(TIMER0_OVF_vect)//interupt service routine

{
	
if (count>977)
{
	PORTB^=(1<<PB5);
	count=0;
}
else
{
	count++;
}
}
int main(void)
{
		DDRB|=(1<<DDB5);
	sei();
	TCNT0=0;
	TCCR0A&=~(1<<WGM00|1<<WGM01);//NORMAL MODE
	TCCR0B|=(1<<CS01|1<<CS00);//PRESCALAR 64
	TCCR0B&=~(1<<CS02);
	TIMSK0|=(1<<TOIE0);// ENABLE TIMER 0 OVERFLOW INTRUPT
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

