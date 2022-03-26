#include "servo.h"

class Servo{

    public:
        Servo(){
            this::steps=0;
            this::step=1000/90;
            this::angle=1;
            this::flag=1000;
        }
        void Servo::start(ServoInit init){
            this::startAngle=init.startAngle;
            this::angle=init.startAngle;
            this::endAngle=init.endAngle;
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
            return angle;
        }
};
