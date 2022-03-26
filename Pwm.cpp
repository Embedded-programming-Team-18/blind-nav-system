#include "pwm.h"

class Pwm{
    public:
        void sendPwm(int minDist){
            if (gpioInitialise() < 0)
            {
            // pigpio initialisation failed.
            cout<<"Intialize gpio failes"<<endl;
            }
            else
            {
                for(int i=0; i<5; i++){
                    pinPWM = (maxDist-minDist[i])*255/maxDist;
                    gpioPWM(led[i],pinPWM);
                }
            }    
        }
}