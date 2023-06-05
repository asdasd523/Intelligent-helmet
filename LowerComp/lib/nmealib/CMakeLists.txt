cmake_minimum_required(VERSION 3.5)
project(nmealib)

set(CMAKE_C_FLAGS "-Wno-psabi")  #gcc版本大于7.1

SET(CROSS_COMPILE_PATH "/home/qigao/arm-linux-gnueabihf-8.3")


set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)

include_directories(               #指定包含的头文件目录
            ./include/
)

add_library(nmea STATIC                                #STATIC静态库   
            ./src/context.c
            ./src/generate.c
            ./src/generator.c
            ./src/gmath.c
            ./src/info.c
            ./src/parse.c
            ./src/parser.c
            ./src/sentence.c
            ./src/time.c
            ./src/tok.c
            )

target_link_libraries(
            nmea
)