#include "pwm.h"
void Pwm::sendPwm(int gpioPin,int distance){
    if(distance>thresholdMaxDist){
        distance = thresholdMaxDist;
    }else if(minValue<thresholdMinDist){
        distance=0;
    }
    pinPWM = (thresholdMaxDist-distance)*255/thresholdMaxDist;
    //std::cout<<"Min "<<minValue<<", Pwm "<<i<<": "<<pinPWM<<std::endl;
    gpioPWM(gpioPin,pinPWM);
}

Pwm::double sqr(double x) { return x*x; }
