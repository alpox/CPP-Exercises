cmake_minimum_required(VERSION 3.6)
project(Ex1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp pvector.h)
add_executable(Ex1 ${SOURCE_FILES})