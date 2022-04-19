#include <iostream>
#include "lidar.h"
#include "pwm.h"
#include <mutex>

/** @mainpage A Brief Introduction to Blind Navigation System
* @section intro_sec Introduction
*
* This work contains a LiDAR driver for obstacle detection.
* The driver is implemented to guide a user through vibratic signals sent as pwm to gpio pins.
* 
* 
* Find out more about the work on the following social media platforms:
* - [Twitter](https://twitter.com/BlindNav)
* - [Instagram](https://www.instagram.com/blindnavsystem/)
* - [Youtube](https://www.youtube.com/channel/UC3s1xHjyCuRFFpUrwtq7xhg)
*
* @section Usage How to use
* The following steps serve as a guide for installation after Pi image is installed and hardware is built/coupled.
*
*   1. To use this Library, the following needs to be installed on your Pi.
*
*        * PIGPIO
*        * CMake
*
*    2. Enable Serioal port for `UART` on your Pi.
*    3. To compile and build the code after downloading from GitHub,
*    ```
*       * Cmake .
*        * Make
*    ```
*    4. ./blind-nav executable will be created.
*/

/**
* 
* @section DESCRIPTION
* This class represents the data interface that is required to retrieve data from the Lidar Driver. 
*/ 
/**
* @brief A data interface class that implements the new newScanAvail(...) of the Lidar driver
*
* This class accesses the data read by the lidar after a full scan and sends pwm to the appropriate 
* gpio pin
*/
class DataInterface : public Lidar::DataInterface {
    private:
        int size=6;
        const int LED [6]={16,27,22,6,13,19};
        const int thresholdMaxDist = 300;
        const int thresholdMinDist = 0;
        std::mutex dataoutMtx;
        int gpioFlag = true;
        Pwm pwmObj;
    public:
        /**
        * Callback method implemented in the data interface class
        * @param data int array
        */
        void newScanAvail(int (&data)[Lidar::nDistance]) {
            if(gpioFlag){
                for(int i=0; i<5; i++){
                    gpioSetMode(LED[i],PI_OUTPUT);
                }
                gpioFlag =0;    
            }
            int splitLength = Lidar::nDistance/size;
            int minValue=0;
            int splitStart=0;
            dataoutMtx.lock();
            for(int i=0; i<size;i++){
                splitStart = i*splitLength;
                minValue = data[splitStart];
                // This inner loop iterate through each split to find the minValue
                for(int j=1; j<splitLength; j++){
                    if(minValue>data[splitStart + j]) {
                        minValue=data[splitStart + j];
                    }
                }
                pwmObj.sendPwm(LED[i],minValue);
                dataoutMtx.unlock();
            }
            
        }
};

int main(int, char **){
    Lidar lidar;
    DataInterface dataInterface;
    lidar.registerInterface(&dataInterface);
    lidar.start();
    
    do{

    }while(!getchar());
    
    lidar.stop();
}