/*
 * Timers_overflow_interrupt.c
 *
 * Created: 11-06-2022 6.00.56 PM
 * Author : Rakesh
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL        // Speed of the microprocessor, in hertz (16 MHz)

void timer_init();

// global variable to count the number of overflows
volatile uint8_t overflow;
ISR(TIMER0_OVF_vect);

int main(void)
{
	// connect led to pin PC0
	DDRC = 0x01;
	
	// initialize timer
	timer_init();
    while (1) 
    {
		// check if no. of overflows = 12
		if (overflow >= 12)  // NOTE: '>=' is used
		{
			// check if the timer count reaches 53
			if (TCNT0 >= 53)
			{
				PORTC = 0x01;    // toggles the led
				TCNT0 = 0;            // reset counter
				overflow = 0;     // reset overflow counter
			}
		}
	}
}

// initialize timer, interrupt and variable
void timer_init()
{
	// set up timer with prescaler = 256
	TCCR0B |= (1 << CS02);
	
	// initialize counter
	TCNT0 = 0;
	
	// enable overflow interrupt
	TIMSK0 |= (1 << TOIE0);
	
	// enable global interrupts
	sei();
	
	// initialize overflow counter variable
	overflow = 0;
}

// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows
ISR(TIMER0_OVF_vect)
{
	// keep a track of number of overflows
	overflow++;
}
