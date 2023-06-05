cmake_minimum_required(VERSION 3.5)
project(json)

set(CMAKE_CXX_FLAGS "-Wno-psabi")  #gcc版本大于7.1
set(CMAKE_CXX_STANDARD 14)

SET(use_arm 1)  #是否使用x86_arm交叉编译

SET(CROSS_COMPILE_PATH "/home/qigao/arm-linux-gnueabihf-8.3")

if(use_arm)
     #set(CMAKE_CXX_COMPILER ${CROSS_COMPILE_PATH}/bin/arm-linux-gnueabihf-g++)
     #set(LD_LIBRARY_PATH ${CROSS_COMPILE_PATH}/bin/arm-linux-gnueabihf-ld)
     set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
elseif(NOT<use_arm>)
     set(CMAKE_CXX_COMPILER /usr/bin/x86_64-linux-gnu-g++)
endif()

include_directories(               #指定包含的头文件目录
              ./
              ./include
)

add_library(jsoncpp STATIC                                #STATIC静态库   
            json_reader.cpp
            json_value.cpp
            json_writer.cpp)
target_link_libraries(
               jsoncpp
               pthread
)  #添加链接库
