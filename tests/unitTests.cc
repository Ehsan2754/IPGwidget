#include <gtest/gtest.h>
#include "IPGwidgetAppConfig.hpp"
#include "IPGStreamThread.hpp"
#include <thread>
#include <chrono>


namespace 
{
  TEST(IPGStreamThreadTest, addToQueueTest)
  {
    IPGStreamThread streamThread;
    streamThread.addToQueue("TEST");

    // Wait for the thread to process the added value
    std::this_thread::sleep_for(std::chrono::seconds(PERIOD));

    // Check if the value was processed and written to the file
    std::ifstream file(STREAM_PATH);
    std::string value;
    file >> value;
    EXPECT_TRUE(value == "TEST");
    file.close();
  }

  TEST(IPGStreamThreadTest, addToQueueMultipleValuesTest)
  {
    IPGStreamThread streamThread;
    streamThread.addToQueue("TEST10");
    streamThread.addToQueue("TEST20");
    streamThread.addToQueue("TEST30");

    // Wait for the thread to process the added values
    std::this_thread::sleep_for(std::chrono::seconds(PERIOD));

    // Check if the values were processed and written to the file in order
    std::ifstream file(STREAM_PATH);
    std::string value;
    file >> value;
    EXPECT_TRUE(value == "TEST10");
    file >> value;
    EXPECT_TRUE(value == "TEST20");
    file >> value;
    EXPECT_TRUE(value == "TEST30");
    file.close();
  }

  TEST(IPGStreamThreadTest, addToQueueWhileStoppedTest)
  {
    IPGStreamThread streamThread;
    streamThread.addToQueue("TEST10");

    // Wait for the thread to process the added values
    std::this_thread::sleep_for(std::chrono::seconds(PERIOD));
    // Add a value to the queue while the thread is sleeping
    streamThread.addToQueue("TEST20");
    streamThread.addToQueue("TEST30");

    // Check if the value was not processed and written to the file
    std::ifstream file(STREAM_PATH);
    std::string value;
    file >> value;
    EXPECT_TRUE(value == "TEST10");
    file.close();
  }
}
