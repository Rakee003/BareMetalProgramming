/*
 * main.c
 *
 * Created: 5/18/2022 5:26:53 PM
 *  Author: Rakesh
 */ 

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xFF; //Makes PORTC as Output
    while(1)
    {
        //TODO:: Please write your application code
		PORTC = 0xFF; //Turns ON All LEDs
		_delay_ms(1000); //1 second delay
		PORTC= 0x00; //Turns OFF All LEDs
		_delay_ms(1000); //1 second delay 
    }
}