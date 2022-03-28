#include "pwm.h"

void Pwm::turnLedsOff(){
    for(int i=0; i<5; i++){
        gpioPWM(LED[i],0);
    }
}

void Pwm::sendPwm(int *minDist){
    int pinPWM = 0;
    for(int i=0; i<5; i++){
        pinPWM = (maxDist-minDist[i])*255/maxDist;
        gpioPWM(LED[i],pinPWM);
    }   
}