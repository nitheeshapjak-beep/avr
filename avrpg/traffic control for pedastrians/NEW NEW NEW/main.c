/*
 * NEW NEW NEW.c
 *
 * Created: 12/15/2025 10:55:24 PM
 * Author : Admin
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


volatile uint8_t pedrqst = 0;

/* Function Prototypes */
void normalmode(void);
void orangeblink(void);
void motorclockwise(void);
void motoranticlockwise(void);
void motorstop(void);





// External Interrupt ISR 
ISR(INT0_vect)
{
	pedrqst = 1;
}

int main(void)
{
	//LED OUTPUT ASSIGN
	DDRD |= (1 <<PD4)|(1 <<PD5)|(1 <<PD6);

	//MOTOR OUT ASSIGN
	DDRB |= (1 << PB0)|(1 << PB1);

	//SWITCH WITH INTERNAL PULL UP
	DDRD &= ~(1 << PD2);
	PORTD|= (1 << PD2);

	//Enable INT0 on falling edge
	EICRA|=(1<< ISC01);
	EICRA&=~(1<<ISC00);
	EIMSK|=(1 <<INT0);

	sei();  // Enable global interrupts

	normalmode();

	while (1)
	{
		if (pedrqst)
		{
			pedrqst = 0;

			// 10 seconds delay before stopping traffic 
			for (uint8_t i = 0; i < 5; i++)
			_delay_ms(1000);

			PORTD &= ~(1 <<PD4);   // Green OFF
			orangeblink();           // Orange blinking

			PORTD|=(1 <<PD6);      // Red ON

			motorclockwise();        // Close crossbar
			for (uint8_t i = 0; i < 10; i++)
			_delay_ms(1000);
			motorstop();

			// Red light ON for 10SEC 
			for (uint8_t i = 0; i < 15; i++)
			_delay_ms(1000);

			motoranticlockwise();    // Open crossbar
			for (uint8_t i = 0; i < 10; i++)
			_delay_ms(1000);
			motorstop();

			PORTD &= ~(1 << PD6);     // Red OFF
			normalmode();            // Back to normal
		}
	}
}
//Functions

void normalmode(void)
{
	PORTD |= (1 <<PD4);
	PORTD &= ~((1 <<PD5) | (1 <<PD6));
}

void orangeblink(void)
{
	for (uint8_t i = 0; i < 5; i++)
	{
		PORTD |= (1 <<PD5);
		_delay_ms(1000);
		PORTD &= ~(1 <<PD5);
		_delay_ms(1000);
	}
}

void motorclockwise(void)
{
	PORTB |= (1 <<PB1);
	PORTB &= ~(1 <<PB0);
}

void motoranticlockwise(void)
{
	PORTB |= (1 <<PB0);
	PORTB &= ~(1 <<PB1);
}

void motorstop(void)
{
	PORTB&=~((1<<PB0)|(1<<PB1));
}

