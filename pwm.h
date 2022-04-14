#ifndef PWM_H
#define PWM_H

#include <pigpio.h>
#include <iostream>
#include <unistd.h>
#include <thread>


class Pwm{
    private:
        const int thresholdMaxDist = 100;
        const int thresholdMinDist = 0; 
    public:
        void sendPwm(int gpioPin,int distance);
};

#endif