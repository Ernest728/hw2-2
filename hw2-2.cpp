#include "mbed.h"
PwmOut PWM1(D6);
AnalogIn Ain(A0);
AnalogOut Aout(D7);
EventQueue queue(32 * EVENTS_EVENT_SIZE);
Thread thread1, thread2, thread3;
void print()
{
    printf("%f\n", Aout.read());
}
void PWM_thread()
{
    PWM1.period_ms(50);
    float R[20];
    int Re[20];
    int i = 0;
    R[i++] = 0;
    for (; i < 5; i++)
        R[i] = i/5.0;
    for (;i < 10; i++)
        R[i] = 1.0;
    for (;i < 15; i++)
        R[i] = 1.0 - (i-10)/5.0;
    for (;i < 20; i++)
        R[i] = 0.0;
    for (i = 0; i < 20; i++)
        Re[i] = int(R[i]*50000);
    while (true) {
        for (int j = 0; j < 20; j++) {
            PWM1.pulsewidth_us(Re[j]);
            wait_us(46500);
        }
    }
}

void Light_sense()
{
    
    while(true) {

            Aout = Ain;
            queue.call(print);
            wait_us(1000);
    }
}

int main()
{
    thread1.start(PWM_thread);
    thread2.start(Light_sense);
    thread3.start(callback(&queue, &EventQueue::dispatch_forever));
}

