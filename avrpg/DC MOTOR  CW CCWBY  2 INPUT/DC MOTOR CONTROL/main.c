/*
 * DC MOTOR CONTROL.c
 *
 * Created: 11/20/2025 9:01:29 PM
 * Author : Admin
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
 void CW ()
 {
PORTD|=(1<<PD0);
PORTD&=~(1<<PD1);
 }
 void CCW ()
 {
	 PORTD&=~(1<<PD0);
	 PORTD|=(1<<PD1);
 }
  void STOP ()
  {
	  PORTD&=~(1<<PD0);
	  PORTD&=~(1<<PD1);
  }


int main(void)
{
DDRB&=~((1<<DDB0)|(1<DDB1));//CONFIG PIN B0,B1 AS INPUT 
DDRD|=(1<<DDD0)|(1<DDD1);//CONFG PIN D0,D1  AS OUTPUT


    /* Replace with your application code */
    while (1)    
	 {
		if((PINB&(1<<PB0))&&!(PINB&(1<<PB1)))
		{
			CW();
		}
		else if ((PINB&(1<<PB1))&&!(PINB&(1<<PB0)))
		{
			CCW();
		}
		
		else
		{
			STOP () ;
		}
		}
		
			   }


