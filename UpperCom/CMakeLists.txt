cmake_minimum_required(VERSION 3.5)
project(UpperComp)     #项目名称,引入变量 sim_BINARY_DIR sim_SOURCE_DIR

SET(CMAKE_INCLUDE_CURRENT_DIR ON)   #包含当前目录

#执行子进程，获取qt路径保存在变量CMAKE_PREFIX_PATH_1中
execute_process(COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/find_qt_path.sh OUTPUT_VARIABLE CMAKE_PREFIX_PATH_1)  
SET(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH_1})

if(POLICY CMP0071)
  cmake_policy(SET CMP0071 OLD)
endif()

set(CMAKE_CXX_STANDARD 14)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
set(Qt5Core_DIR    ~/Qt/CMAKE_PREFIX_PATH/gcc_64/lib/cmake/Qt5Core)
set(Qt5Widgets_DIR ~/Qt/CMAKE_PREFIX_PATH/gcc_64/lib/cmake/Qt5Widgets)
set(Qt5Network_DIR ~/Qt/CMAKE_PREFIX_PATH/gcc_64/lib/cmake/Qt5Network)
set(Qt5Charts_DIR  ~/Qt/CMAKE_PREFIX_PATH/gcc_64/lib/cmake/Qt5Charts)
set(Qt5SerialPort_DIR  ~/Qt/CMAKE_PREFIX_PATH/gcc_64/lib/cmake/Qt5SerialPort)
find_package(Qt5Core CONFIG REQUIRED)       #查找CMAKE_PREFIX_PATH    REQUIRED:必须找到,找不到停止全部cmake 
find_package(Qt5Widgets CONFIG REQUIRED)
get_target_property(QtCore_location Qt5::Core LOCATION)
message(STATUS ${QtCore_location})          #显示消息 为QtCore_location的值
find_package(Qt5Gui CONFIG REQUIRED)

set(QOBJECT_HEADERS
       ./MainWindow.h
       ./include/tcpclient.h
       ./include/udpclient.h
       ./include/uartclient.h
       ./include/sendthread.h
       ./include/protocol.h
       ./include/hardwareclient.h
       ./include/gpsinfownd.h
       ./include/thermwnd.h
       ./include/hygrownd.h
)
QT5_WRAP_CPP(tst_hdr_moc ${QOBJECT_HEADERS})   #生成的moc文件放入变量mocfiles中

include_directories("./"
                    "./include")
include_directories(${CMAKE_BINARY_DIR})
file(GLOB sources
          "./*.cpp"
          "./src/*.cpp")   #将源文件组成列表存放在sources中

find_package(Qt5Core COMPONENTS QtCharts REQUIRED QtNetwork REQUIRED QtSerialPort)
find_package(Qt5Charts  REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5SerialPort REQUIRED)

set(OpenGL_GL_PREFERENCE LEGACY)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})   #指定可执行文件的输出路径到当下目录

add_executable(UpperCom ${sources} ${tst_hdr_moc})     #设置可执行文件

#链接动态库
target_link_libraries(UpperCom pthread  Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Charts Qt5::Network Qt5::SerialPort
 ${QT_LIBRARIES} ${OPENGL_LIBRARIES})

if (CMAKE_SYSTEM_NAME MATCHES Linux)
     target_link_libraries(UpperCom pthread rt ${GLUT_glut_LIBRARIES})
     include (CheckIncludeFileCXX)
endif (CMAKE_SYSTEM_NAME MATCHES Linux)


