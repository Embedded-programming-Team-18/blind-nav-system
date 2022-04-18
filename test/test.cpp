#include <gtest/gtest.h>
#include "pwm.h"

// Demonstrate some basic assertions.
TEST(TestSuiteSample, TestSample) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}


imt main(int argc, char **argv){
    testting::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS;
}