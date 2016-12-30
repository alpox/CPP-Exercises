cmake_minimum_required(VERSION 3.6)
project(Ex4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Ex4 ${SOURCE_FILES})