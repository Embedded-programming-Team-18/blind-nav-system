#include "pwm.h"
void Pwm::sendPwm(int gpioPin,int distance){
    int pinPWM = 0;
    if(distance>thresholdMaxDist){
        distance = thresholdMaxDist;
    }else if(distance<thresholdMinDist){
        distance=0;
    }
    pinPWM = (thresholdMaxDist-distance)*255/thresholdMaxDist;
    //std::cout<<"Min "<<minValue<<", Pwm "<<i<<": "<<pinPWM<<std::endl;
    gpioPWM(gpioPin,pinPWM);
}