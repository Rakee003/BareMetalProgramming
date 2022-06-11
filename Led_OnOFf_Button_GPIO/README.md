# Using GPIO pins in microcontroller
AVR ATmega328p has 28 pins constituting three ports. The ports are listed below :
* PORT B - 8 pins
* PORT C - 7 pins
* PORT D - 8 pins

These pins can be configured as input or output using the three I/O registers for each port.
* Data register - PORTx
* Data direction register - DDRx
* Input pins address register - PINx

The process of using the pins as input/output is demonstrated in the [program](https://github.com/Rakee003/BareMetalProgramming/blob/main/Led_OnOFf_Button_GPIO/Led_OnOff_Button_GPIO.c).

## The schematic of the circuit:

![sdfsdfsf](https://user-images.githubusercontent.com/58605350/173176388-4547b112-aad5-439c-9be3-1820e09675d9.png)



