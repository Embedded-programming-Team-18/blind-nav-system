#include <iostream>
#include "lidar.h"
#include "pwm.h"

using namespace std;

class DataInterface : public Lidar::DataInterface {
    private:
        int size=5;
        int minDist[5];
        Pwm pwm4Leds;
        int getArrayMin(int *distance, int n){
            int temp = distance[0];
            for(int i=0; i<n; i++) {
                if(temp>distance[i]) {
                    temp=distance[i];
                }
            }
            return temp;
        }
    public:
        void newScanAvail(int (&data)[Lidar::nDistance]) {
            int splitLength = Lidar::nDistance/size;
            int minValue = data[0];
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
                minDist[i]=minValue;
            }
            // Send pwm to the 5 LED here
            pwm4Leds.sendPwm(minDist);
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