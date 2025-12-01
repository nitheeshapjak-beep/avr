/*
 * timer 0 normal mode.c
 *
 * Created: 12/1/2025 9:35:30 PM
 * Author : Admin
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

delay_1s()
{
	TCNT0=0;//LOAD MINIMUM VALUE IN COUNTER
	//SET COUNTER IN  NORMAL MODE 
TCCR0A&=~(1<<WGM00);
TCCR0A&=~(1<<WGM01);
	//SET NO PRESCALING
	TCCR0B&=~(1<<CS02);
	TCCR0B&=~(1<<CS01);
	TCCR0B|=(1<<CS00);
	
	//REPEAT PROCESS 62500 TIMES TO GET 1SEC DELAY
	for(long int i=0;i<62500;i++)
	{
	 while (!(TIFR0&(1<<TOV0)));//CHECKING FLAG
	 TIFR0|=(1<<TOV0);// WRITTING 1 TO MAKE TOV0; ((((((STRANGE RULE)))))))
	}
}

int main(void)
{
   DDRB|=(1<<DDB5);
    while (1) 
    {
		PORTB^=(1<<PB5);
		delay_1s();
    }
}

