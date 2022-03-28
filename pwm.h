#ifndef PWM_H
#define PWM_H

#include <pigpio.h>
#include <iostream>
#include <unistd.h>
#include <thread>


class Pwm{
    private:
        const int LED [5]={27,22,6,13,19};
        const int RX=15;
        const int TX=14;
        const int maxDist = 420;
        std::thread* pwmWorker = nullptr;

    public:
        Pwm(){
            for(int i=0; i<5; i++){
                gpioSetMode(LED[i],PI_OUTPUT);
            }
        }
        void sendPwm(int *minDist);
        void turnLedsOff();
};

#endif