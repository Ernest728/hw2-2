# hw2-2
 (1) how to setup and run your program 
 For convenience and as the requirement said, I use three Threads to implement this part.
Thread1 is for PWM, Thread2 is for ADC, Thread3 is for print.
Thread1 is exactly as same as problem1.
In Thread2, I capture the AO with a ADC input A0 at one sample every 1ms. ->wait_us(1000);

 (2) what are the results
 A light sensor can sense the lightness by LED.
