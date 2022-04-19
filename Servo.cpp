#include "servo.h"

int Servo::move(){
    if(angle<endAngle){
        //To move forward
        gpioServo(17,1000+(step*angle));
        angle++;
    }else{
        gpioServo(17,1000);
        angle=startAngle;
    }
    return angle;
}

