#include <iostream>
#include "lidar.h"

using namespace std;

// class DataInterface : public Lidar::DataInterface {
//     private:
//         int size=5;
//         int minDist[size];
//         int getArrayMin(int[] distance, int n){
//             int temp = distance[0];
//             for(int i=0; i<n; i++) {
//                 if(temp>distance[i]) {
//                     temp=distance[i];
//                 }
//             }
//             return temp;
//         }
//     public:
//         void newScanAvail(int (&data)[Lidar::nDistance]) {
//             int splitLength = nDistance/size;
//             int minValue = distance[0];
//             for(i=0; i<size;i++){
//                 minValue = distance[i*splitLength];
//                 for(j=0; j<splitLength; j++){
//                     k=i*splitLength + j;
//                     if(minValue>distance[k]) {
//                         minValue=distance[k];
//                     }
//                 }
//                 minDist[i]=minValue;
//             }
//         }
// };

int main(){
    Lidar lidar;
    //DataInterface dataInterface;
    //lidar.registerInterface(&dataInterface);
    lidar.start();
    
    do{

    }while(!getchar());
    
    lidar.stop();
}