cmake_minimum_required(VERSION 3.6)
project(Ex1)

SET(ROOT_DIR    "/Users/Elias/CloudStation/UZH/Semester3/C++")
set(CMAKE_SHARED_LINKER_FLAGS "-L${ROOT_DIR}/duma/ -lduma -lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Object.h dumb_pointer.h smart_pointer.cpp smart_pointer.h)
add_executable(Ex1 ${SOURCE_FILES})