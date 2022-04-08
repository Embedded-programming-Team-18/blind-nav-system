#include <iostream>
#include "lidar.h"
#include "pwm.h"
#include <mutex>

using namespace std;

class DataInterface : public Lidar::DataInterface {
    private:
        int size=5;
        int minDist[5];
        bool pwmFlag = false;
        Pwm pwm4Leds;
    public:
        void newScanAvail(int (&data)[Lidar::nDistance]) {
            int splitLength = Lidar::nDistance/size;
            int minValue = data[0];
            std::mutex readoutMtx;
            // This outer loop sets the 5 minDistance that we want.
            for(int i=0; i<size;i++){
                // The min value will start at i*18 which represents the 5 splits
                minValue = data[i*splitLength];
                int k = 0;
                // This inner loop iterate through each split to find the minValue
                for(int j=0; j<splitLength; j++){
                    k=i*splitLength + j;
                    if(minValue>data[k]) {
                        minValue=data[k];
                    }
                }
                readoutMtx.lock();
                 minDist[i]=minValue;
                readoutMtx.unlock();
            }
            //for(int g=0; g<5; g++) std::cout << "MinDist "<<g<<" "<<minDist[g]<<"\n";
            //std::cout<<pwmFlag<<std::endl;
            if(pwmFlag == false){
                // std::cout<<"Call back"<<"\n";
                // Send pwm to the 5 LED here
                pwm4Leds.start(minDist);
                pwmFlag=true;
            
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