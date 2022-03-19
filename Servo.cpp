#include "servo.h"

class Servo{
    public:
        void Servo::start(int startAngle, int endAngle){
            this::startAngle=startAngle;
            this::angle=startAngle;
            this::endAngle=endAngle;
        }
        int Servo::move(){
            // This function controls how the servo moves forward or backward
            if(flag==1000){
                if(angle>endAngle){
                    angle=startAngle;
                    flag=2000;
                }
                //To move forward
                gpioServo(12,1000+(step*angle));
                ++angle;
                usleep(5000);
            }else if(flag=2000){
                if(angle>endAngle){
                    angle=startAngle;
                    flag=1000;
                }
                // To move backward
                gpioServo(12,2000-(step*angle));
                ++angle;
                usleep(5000);
            }
        }
}
