/*
 * GccApplication1.c
 *
 * Created: 06-06-2022 9.25.58 PM
 * Author : Rakesh
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>  //interrupt library 
volatile uint8_t overflow_tot;  //global variable


void time_init()
{
	TCCR0B=0x02; // makes it CSO2 i.e prescaling it into 256
	TCNT0=0; //enable counter
	TIMSK0=0x01; // enable overflow interrupt
	sei(); //enables global interrupt
	overflow_tot=0;
}

ISR(TIMER0_OVF_vect) // TIMER0 overflow interrupt service routine called whenever TCNT0 overflows
{
	overflow_tot++;  //keep tracks of number of overflow
}
int main(void)
{
	 DDRC = 0x0F; //Makes PORTC as Output also can be written as 0b00001111    
	 time_init();
	 int count;
	 
    while (1) 
    {
		
		if (overflow_tot>=12)
		{
			if (TCNT0>=53)
			{
				count++;
				TCNT0=0;
				overflow_tot=0;
			}
			if (count==1000)
			{
				PORTC = 0x01;
				count=0;
			}
		}
    }
}

