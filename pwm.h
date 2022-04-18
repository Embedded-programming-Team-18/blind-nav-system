#ifndef PWM_H
#define PWM_H

#include <pigpio.h>
#include <iostream>
#include <unistd.h>
#include <thread>


/**
* 
* @section DESCRIPTION
* This class abstracts the function of sending pwm from the data inteface class. 
*/ 
/**
* @brief The pwm class that send pwm to the gpio pins
*
* This class sends pwm to the to the gpio pins sent to it.
* It uses a double threshold: thresholdMinDist,thresholdMaxDist constant integers
* to serve as maximum and minmum distances at which pwm will be sent.  
*/
class Pwm{
    private:
        const int thresholdMaxDist = 100;
        const int thresholdMinDist = 0; 
    public:
        /**
        * This method calculates the pwm from the distance param 
        * and sends it to the gpio pin it receives as argument.
        *
        * @param gpioPin int
        * @param distance int
        */
        void sendPwm(int gpioPin,int distance);

};

#endif