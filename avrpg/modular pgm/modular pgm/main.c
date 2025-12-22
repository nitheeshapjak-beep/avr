/*
 * modular pgm.c
 *
 * Created: 12/21/2025 2:58:33 PM
 * Author : Admin
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "delay.h" //("" )use for user defined header files


int main(void)
{
	DDRB|=(1<<DDB5);
	timer0_init();//user defined funtn for timer 0 config
    /* Replace with your application code */
    while (1) 
    {
	 PORTB^=(1<<PB5);
	 delay_ms(5000); //user defined function for delay
	 
    }
}

