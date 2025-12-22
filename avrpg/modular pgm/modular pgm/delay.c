/*
 * delay.c
 *
 * Created: 12/21/2025 3:04:30 PM
 *  Author: Admin
 */ 
#include<avr/io.h>
#include "delay.h"
void  timer0_init(void)//timer0 fnctn definition 
{
	TCNT0=0;
	OCR0A=249;
	//timer ctc mode
	TCCR0A|=(1<<WGM01);
	TCCR0A&=~(1<<WGM00);
	//prescalar 64
	TCCR0B|=(1<<CS00)|(1<<CS01);
	TCCR0B&=~(1<<CS02);
}
void delay_ms(uint16_t ms)

{
	while (ms--)
	{
while (!(TIFR0&(1<<OCF0A)));//1ms delay
TIFR0|=(1<<OCF0A);
	}
}