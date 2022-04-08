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
        const int thresholdMaxDist = 450;
        const int thresholdMinDist = 90; 
        std::thread* pwmWorker = nullptr;
        int* minDist;
        bool doInit = true;
        bool running = true;
    public:
        Pwm(bool _doInit = true) {
		    doInit = _doInit;
	    }

         ~Pwm() {
		    gpioTerminate();
	    }

        void start(int *minDist);
        static void sendPwm(Pwm* Pwm);
};

#endif