/*
 * Led_OnOff_Button_GPIO.c
 *
 * Created: 02-06-2022 11.08.06 AM
 *  Author: Rakesh
 */ 

 #include <xc.h>
 #include <avr/io.h>
 #include <util/delay.h>

 int main(void)
 {
	 DDRC = 0x0F; //Makes PORTC as Output also can be written as 0b00001111
	 DDRD = 0x00;
	 while(1)
	 {
		 
		 if (PIND & (1<<3))
		 {
			 PORTC = 0x01;//Turns ON All LEDs
			 
		 }
		 else
		 {
			 PORTC= 0x00; //Turns OFF All LEDs
		 }
		 
		 
	 }
 }