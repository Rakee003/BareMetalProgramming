# Timers
 In AVR, timers are of two types: 8-bit and 16-bit timers
 
 This means that the 8-bit timer is capable of counting 2^8=256 steps from 0 to 255 as demonstrated below.Similarly a 16 bit timer is capable of counting 2^16=65536 steps from 0 to 65535. 
 
In ATMEGA328p, we have three different kinds of timers:

    TIMER0 – 8-bit timer
    TIMER1 – 16-bit timer
    TIMER2 – 8-bit timer
    
Time period is the time taken for going from one clock step to another. For example from 0 to 1.

    Time Period = 1/Frequency


AVR microcontrollers typically are 16MHz.

To calculate the timer count,

    TimerCount = (Required Delay / Clock Time Period) - 1

We can Increase the clock time period by decreasing the F_CPU value. It is called prescaling. The actual F_CPU remains the same, we derive a frequency from it to run the timer. There will be a trade of between resolution and duration when dealing with prescalars.

### Choosing Prescalars
AVR offers us following prescalar values to choose from 
* 8
* 64
* 256
* 1024

## Registers for Timers
* TCNTx Register ---> Timer/Counter Register (Data Register)
* TCCRx Register ---> Timer/Counter Control Register 
* TIMSK Register ---> Timer/Counter Interrupt Mask 
* TIFR Register  ---> Timer/Counter Interrupt Flag Register

### TCNTx Register

![image](https://user-images.githubusercontent.com/58605350/173190245-67aaf67d-5dcd-4682-8f26-e2e6b1d3af85.png)

![image](https://user-images.githubusercontent.com/58605350/173190276-b4b012b9-1a82-4539-8624-30461ddf5421.png)

![image](https://user-images.githubusercontent.com/58605350/173190294-c03f40c1-3e25-4020-8af4-fd2341f61257.png)


### TIFR Register

![image](https://user-images.githubusercontent.com/58605350/173190302-89a96560-d81f-44a7-aa8c-d2232dbb9cad.png)


