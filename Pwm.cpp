#include "pwm.h"

void Pwm::start(int *dist){
    if (nullptr != pwmWorker) return;
     minDist = dist;

    // pgpio is initialized here
    if (gpioInitialise() < 0) {
        throw "gpioInitialise failed";
    }

    for(int i=0; i<5; i++){
        gpioSetMode(LED[i],PI_OUTPUT);
    }
    // Create the thread which starts running
    pwmWorker = new std::thread(Pwm::sendPwm,this);
}

void Pwm::sendPwm(Pwm* Pwm){
    int pinPWM = 0;
    int distance =0;
    while(Pwm->running){

        for(int i=0; i<5; i++){
            //std::cout<<"Mindist: "<<Pwm->minDist[i]<<" i: "<<i<<std::endl;
            distance = Pwm->minDist[i];
            if(distance>Pwm->thresholdMaxDist){
                distance = Pwm->thresholdMaxDist;
            }else if(distance<Pwm->thresholdMinDist){
                distance=0;
            }
            pinPWM = (Pwm->thresholdMaxDist-distance)*255/Pwm->thresholdMaxDist;
            gpioPWM(Pwm->LED[i],pinPWM);
        }   
    }
    
}