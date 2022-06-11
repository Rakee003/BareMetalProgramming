/*
 * AVR_Timer_SimpleProgram.c
 *
 * Created: 11-06-2022 4.44.58 PM
 * Author : Rakesh
 */ 

#include <avr/io.h>
void timer_init();

int main(void)
{
    /* Replace with your application code */
	// connect led to pin PC0
	DDRC = 0x01; // 0000 0001
	
	// initialize timer
	timer_init();
	
    while (1) 
    {
		// check if the timer count reaches 124
		if (TCNT0 >= 124)
		{
			PORTC = 0x01;    // toggles the led
			TCNT0 = 0;            // reset counter
		}
    }
}

void timer_init()
{
	// set up timer with prescaler = 1024
	TCCR0B |= (1 << CS02)|(1 << CS00);
	
	// initialize counter
	TCNT0 = 0;
}


