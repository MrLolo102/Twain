# Twain rabbitmq client

##### Implement rabbitmq for communicate with Twain server

# How to build?
##### 1. Install package dependencies: sudo apt-get install build-essential git cmake clang 
##### 2. Clone repository to your computer
##### 3. Run command: cd twain-rabbitmq-client && git submodule update --init --recursive && mkdir build && cd build && cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ && make -j12
##### 4. To run the build: ./twain with args: get_device_id to get device id and set_up to set up device
#### Note:
##### - In the step 3 you can change the command to change C/C++ compiler with gcc and build type Debug
##### - In the step 4, change last param for auto script path on your computer
##### - In project folder, I added an auto script file, you can use it. Don't forget add execute permission for it: sudo chmod +x <file_name.sh>

# Open source license
##### - rabbitmq-c by alanxz https://github.com/alanxz/rabbitmq-c
##### - libcpprestsdk by microsoft https://github.com/microsoft/cpprestsdk

# About
##### Copyright by VMODEV JSC 2020