#include <iostream>
#include <IPGwidgetAppConfig.hpp>
#include "IPGStreamThread.hpp"

/**
 * @brief Here is application start point for IPGwidgetApp
 * 
 * @param argc argument count
 * @param argv argument vector
 * @return int application exit code
 */
int main(int argc, char *argv[])
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
    std::cout << value << std::endl;
    file >> value;
    std::cout << value << std::endl;
    file >> value;
    std::cout << value << std::endl;
    file.close();
}