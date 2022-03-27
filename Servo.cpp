#include "servo.h"

int Servo::steps=0;
int Servo::step=1000/90;
int Servo::angle=0;
int Servo::flag=1000;
int Servo::startAngle=0;
int Servo::endAngle=0;

void Servo::start(){
        steps=0;
        step=1000/90;
        angle=0;
        flag=1000;
        // set servo angles
        startAngle=0;
        endAngle=0;
}

int Servo::move(){
    // This function controls how the servo moves forward or backward
    if(flag==1000){
        if(angle>=endAngle){
            angle=startAngle;
            flag=2000;
        }
        //To move forward
        gpioServo(12,1000+(step*angle));
        ++angle;
        usleep(5000);
    }else if(flag==2000){
        if(angle>=endAngle){
            angle=startAngle;
            flag=1000;
        }
        // To move backward
        gpioServo(12,2000-(step*angle));
        ++angle;
        usleep(5000);
    }
    return angle;
}

