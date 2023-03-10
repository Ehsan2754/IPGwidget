# IPGwidget ![build](https://github.com/Ehsan2754/IPGwidget/actions/workflows/build.yml/badge.svg)   ![unittest](https://github.com/Ehsan2754/ShinyAllocator/actions/workflows/unittest.yml/badge.svg) [![docs](https://github.com/Ehsan2754/IPGwidget/actions/workflows/docs.yml/badge.svg)](https://ehsan2754.github.io/IPGwidget) 

A QtWidget based on Qt5 of ordered by IPG photonics. 
# Demo and Memory Profiling 
[![Demo](https://img.youtube.com/vi/E-RvJ02C3ww/0.jpg)](https://youtu.be/E-RvJ02C3ww)

# Download and Run
```
    wget https://github.com/Ehsan2754/IPGwidget/releases/latest/download/IPGwidgetApp;
    chmod +x IPGwidgetApp; 
    ./IPGwidgetApp;
``` 
# Features / Acceptance Criteria
1. Implemented using Qt version 5 library and QtWidgets for the graphical interface
2. The appearance of the window must match the given figure
    | Figure                                                                      | Application                                |
    | --------------------------------------------------------------------------- | ------------------------------------------ |
    | ![Sample](https://i.ibb.co/smCSV2P/Screenshot-from-2023-02-03-16-10-23.png) | ![img](https://i.ibb.co/frbZ4nD/image.png) |
3. The "SEND" button changes color to #619bd5 when pressed
4. When "SEND" button is clicked, the message from the input field is sent to the second thread of the application and the input field is cleared
5. The second thread writes all received messages to the text file "messages.txt" in UTF-8 encoding every 5 seconds
6. The text file "messages.txt" is located in the working directory of the program
7. Desirable to use classes from the Qt library
8. Source code is placed in a local git repository and submitted as an archive in response to the assignment.

# Environment Setup
* Install profiling, testing, documenting and building packages:
    ```
        sudo apt-get update && sudo apt-get upgrade
        sudo apt-get install make cmake doxygen graphviz valgrind kcachegrind  libgtest-dev
        cd /usr/src/gtest
        sudo cmake CMakeLists.txt
        sudo make
        sudo cp ./lib/*.a /usr/lib
             ```
* build and install Qt5 from [sources](https://wiki.qt.io/Building_Qt_5_from_Git#Getting_the_source_code).