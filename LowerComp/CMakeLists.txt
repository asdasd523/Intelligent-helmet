cmake_minimum_required(VERSION 3.5)
project(Lower_App)

add_subdirectory(lib)

set(CMAKE_CXX_STANDARD 14)

SET(use_arm 1)  #是否使用x86_arm交叉编译

SET(CROSS_COMPILE_PATH "/home/qigao/arm-linux-gnueabihf-8.3")

if(use_arm)
     # set(CMAKE_CXX_COMPILER ${CROSS_COMPILE_PATH}/bin/arm-linux-gnueabihf-g++)
     # set(LD_LIBRARY_PATH ${CROSS_COMPILE_PATH}/bin/arm-linux-gnueabihf-ld)
     set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
elseif(NOT<use_arm>)
     set(CMAKE_CXX_COMPILER /usr/bin/x86_64-linux-gnu-g++)
endif()

file(GLOB_RECURSE sources
     "./src/*.cpp"
     "./src/common/*.cpp"
     "./src/Message/*.cpp"
     "./src/hardware/*.cpp"
     )
include_directories(               # 指定包含的头文件目录
               ./lib/jsoncpp/include
               ./lib/nmealib/include
               ./include
 )
link_directories(                  # 指定动态库目录位置
               /usr/lib
)
add_executable(Lower_App ${sources})                # 指定生成目标
# SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}) # 指定可执行文件的输出路径到当下目录
target_link_libraries(
               Lower_App
               pthread
               rt
               jsoncpp
               nmea
               m
)                                                   # 添加链接库
