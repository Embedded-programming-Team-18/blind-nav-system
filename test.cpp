#include <gtest/gtest.h>
#include <iostream>

using namespace std;

int thresholdMaxDist=100;
int thresholdMinDist=0;
int sendPwmTest(int gpioPin,int distance){
    int pinPwm=0;
    if(distance>thresholdMaxDist){
        distance = thresholdMaxDist;
    }else if(distance<thresholdMinDist){
        distance=0;
    }

    pinPwm = (thresholdMaxDist-distance)*255/thresholdMaxDist;
    return pinPwm;
}

TEST(TestSuiteSample, PwmTestSample) {
  // Expect equality.
  EXPECT_EQ(sendPwmTest(27,0), 255);
  EXPECT_EQ(sendPwmTest(27,-2000), 255);
  EXPECT_EQ(sendPwmTest(27,100), 0);
  EXPECT_EQ(sendPwmTest(27,167), 0);
  EXPECT_EQ(sendPwmTest(27,26550), 0);
}



  int step=1000/90;
  int angle=0;
  int startAngle=0;
  int endAngle=89;
  int servoMove(){
    if(angle<endAngle){
        angle++;
    }else{
        angle=startAngle;
    }
    return angle;
  }


TEST(TestSuiteSample, ServoTestSample) {
  for(int i=0; i<89; i++)
    EXPECT_EQ(servoMove(), i+1);
}  


int main(int argc, char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}