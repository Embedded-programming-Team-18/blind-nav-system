#include "pwm.h"

    void Pwm::sendPwm(int *minDist){
        if (gpioInitialise() < 0)
        {
        // pigpio initialisation failed.
        std::cout<<"Intialize gpio failes"<< std::endl;
        }
        else
        {
            int pinPWM = 0;
            for(int i=0; i<5; i++){
                pinPWM = (maxDist-minDist[i])*255/maxDist;
                gpioPWM(LED[i],pinPWM);
            }
        }    
    }