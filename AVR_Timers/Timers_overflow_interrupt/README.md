# Timer Overflow Interupts
When the required delay is greater than the maximum possible delay, obviously the timer will overflow. And whenever the timer overflows, an interrupt is fired. So by calculating how many times the itterupt should be fired, the delay time can be achieved.



The [program](https://github.com/Rakee003/BareMetalProgramming/blob/main/AVR_Timers/Timers_overflow_interrupt/Timers_overflow_interrupt/main.c) uses TIMER 0 with overflow interrupt in atmega328p.
* F_CPU - 16MHz
* PreScaling - 256
* Delay Time - 50ms

