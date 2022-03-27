#ifndef PWM_H
#define PWM_H

#include <pigpio.h>
#include <iostream>

#include <unistd.h>


class Pwm{
    private:
        const int LED [5]={27,22,6,13,19};
        const int RX=15;
        const int TX=14;
        const int maxDist = 420;

    public:
        void sendPwm(int *minDist);
};

#endif