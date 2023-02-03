#include <gtest/gtest.h>
// #include "IPGwidgetAppConfig.hpp"
// #include "IPGStreamThread.hpp"
// #include <thread>
// #include <chrono>
#include <math.h>
 
double squareRoot(const double a) {
    double b = sqrt(a);
    if(b != b) { // nan check
        return -1.0;
    }else{
        return sqrt(a);
    }
} 
TEST(SquareRootTest, PositiveNos) { 
    ASSERT_EQ(6, squareRoot(36.0));
    ASSERT_EQ(18.0, squareRoot(324.0));
    ASSERT_EQ(25.4, squareRoot(645.16));
    ASSERT_EQ(0, squareRoot(0.0));
}
 
TEST(SquareRootTest, NegativeNos) {
    ASSERT_EQ(-1.0, squareRoot(-15.0));
    ASSERT_EQ(-1.0, squareRoot(-0.2));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// namespace 
// {
//   TEST(IPGStreamThreadTest, addToQueueTest)
//   {
//     IPGStreamThread streamThread;
//     streamThread.addToQueue("TEST");

//     // Wait for the thread to process the added value
//     std::this_thread::sleep_for(std::chrono::seconds(PERIOD));

//     // Check if the value was processed and written to the file
//     std::ifstream file(STREAM_PATH);
//     std::string value;
//     file >> value;
//     EXPECT_TRUE(value == "TEST");
//     file.close();
//   }

//   TEST(IPGStreamThreadTest, addToQueueMultipleValuesTest)
//   {
//     IPGStreamThread streamThread;
//     streamThread.addToQueue("TEST10");
//     streamThread.addToQueue("TEST20");
//     streamThread.addToQueue("TEST30");

//     // Wait for the thread to process the added values
//     std::this_thread::sleep_for(std::chrono::seconds(PERIOD));

//     // Check if the values were processed and written to the file in order
//     std::ifstream file(STREAM_PATH);
//     std::string value;
//     file >> value;
//     EXPECT_TRUE(value == "TEST10");
//     file >> value;
//     EXPECT_TRUE(value == "TEST20");
//     file >> value;
//     EXPECT_TRUE(value == "TEST30");
//     file.close();
//   }

//   TEST(IPGStreamThreadTest, addToQueueWhileStoppedTest)
//   {
//     IPGStreamThread streamThread;
//     streamThread.addToQueue("TEST10");
//     streamThread.addToQueue("TEST20");

//     // Wait for the thread to process the added values
//     std::this_thread::sleep_for(std::chrono::seconds(1));

//     // Stop the thread
//     streamThread.~IPGStreamThread();

//     // Add a value to the queue while the thread is stopped
//     streamThread.addToQueue("TEST30");

//     // Wait for some time
//     std::this_thread::sleep_for(std::chrono::seconds(PERIOD));

//     // Check if the value was not processed and written to the file
//     std::ifstream file(STREAM_PATH);
//     std::string value;
//     file >> value;
//     EXPECT_TRUE(value == "TEST10");
//     file >> value;
//     EXPECT_TRUE(value == "TEST20");
//     file.close();
//   }
// }
