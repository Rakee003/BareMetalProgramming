# Timers CTC Mode 

The need of checking the set point everytime is reduced in this mode. The CTC mode works the same method but it implements it in hardware. Which means that we no longer need to worry about comparing the process value with the set point every time. Once the process value becomes equal to set point a flag in the status register is set and the timer is reset automatically.

The [program](https://github.com/Rakee003/BareMetalProgramming/blob/main/AVR_Timers/TIMERS_CTC_Mode/TIMERS_CTC_Mode/main.c) explains the Timers CTC mode in atmega328p microcontroller with timer1.
* F_CPU - 16MHz
* Prescaling - 64
