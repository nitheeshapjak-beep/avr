/*
 * pwm phase correct.c
 *
 * Created: 11/29/2025 9:11:20 PM
 * Author : Admin
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
	DDRD|=(1<<DDD6);//CONFIG PD6 AS OUTPUT
	
	//CONFIGURE FOR PHASE CORRECT MODE
    TCCR0A|=(1<<WGM00);
	TCCR0A&=~(1<<WGM01);
	//CONFIG FOR NON INVERTING PWM
	TCCR0A|=(1<<COM0A1);
	TCCR0B&=~(1<<COM0A0);
	//SELECTING PRESCALAR
	TCCR0B&=~(1<<CS02);
	TCCR0B&=~(1<<CS00);
	TCCR0B|=(1<<CS01);
	
	
	
	 OCR0A=255;
    while (1) 
    {
		
		
    }
}

