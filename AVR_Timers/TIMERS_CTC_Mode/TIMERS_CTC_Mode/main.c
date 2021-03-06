/*
 * TIMERS_CTC_Mode.c
 *
 * Created: 11-06-2022 7.52.37 PM
 * Author : Rakesh
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


void timer_init();
ISR (TIMER1_COMPA_vect);

int main(void)
{
	// connect led to pin PC0
	DDRC |= (1 << 0);
	
	// initialize timer
	timer_init();
	
    while (1) 
    {
		// do nothing
		// whenever a match occurs, ISR is fired
		// toggle the led in the ISR itself
		// no need to keep track of any flag bits here
		// done!
    }
}

// initialize timer, interrupt and variable
void timer_init()
{
	// set up timer with prescaler = 64 and CTC mode
	TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10);
	
	// initialize counter
	TCNT1 = 0;
	
	// initialize compare value
	OCR1A = 24999;
	
	// enable compare interrupt
	TIMSK1 |= (1 << OCIE1A);
	
	// enable global interrupts
	sei();
}

// this ISR is fired whenever a match occurs
// hence, toggle led here itself..
ISR (TIMER1_COMPA_vect)
{
	// toggle led here
	PORTC ^= (1 << 0);
}
		