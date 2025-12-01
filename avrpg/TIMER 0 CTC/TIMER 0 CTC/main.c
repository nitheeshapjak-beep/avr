/*
 * TIMER 0 CTC.c
 *
 * Created: 11/27/2025 9:13:05 PM
 * Author : Admin
 */ 
#define	F_CPU 16000000UL		
#include <avr/io.h>
 
 void delay_1s(void)
 {
	 for(int i=0;i<100;i++)
	 {
		 while(!(TIFR0&(1<<OCF0A)));//WAIT UNTIL OCF0A FLAG SET (TCNT0=0CR0A)
		 TIFR0|=(1<<OCF0A);//RESET OCF0A FLAG
	 }
 }


int main(void)
{
	TCNT0=0;
	OCR0A=0X9C;
    TCCR0A|=(1<<WGM01);
	TCCR0A&=~(1<<WGM00);
	TCCR0B|=(1<<CS02|1<<CS00);
	TCCR0B&=~(1<<CS01);
	DDRB|=(1<<DDB5);
    while (1) 
    {
		PORTB^=(1<<PB5);
		delay_1s();
    }
}

