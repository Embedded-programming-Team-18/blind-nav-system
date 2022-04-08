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
        endAngle=89;
}

int Servo::move(){
    std::mutex readoutMtx;
    // This function controls how the servo moves forward or backward
    // The forward part
    if(flag==1000){
        // This part reset the start angle
        if(angle<endAngle){
            //To move forward
            gpioServo(12,1000+(step*angle));
            readoutMtx.lock();
                ++angle;
            readoutMtx.unlock();  
         
        }else{
            angle=startAngle;
            flag=2000;
        }
        // std::cout<<"Forward anngle: "<< angle << std::endl;
        return angle;
    }else if(flag==2000){
        // The backward part
        // This part reset the start angle
        if(angle<endAngle){
            // To move backward
            gpioServo(12,2000-(step*angle));
             readoutMtx.lock();
                ++angle;
            readoutMtx.unlock();   
        }else{
            angle=startAngle;
            flag=1000;
        }
       //std::cout<<"Backward anngle: "<< endAngle-angle << std::endl;
       return endAngle-angle;
    }
    
    return angle;
}

