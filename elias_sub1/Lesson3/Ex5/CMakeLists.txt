cmake_minimum_required(VERSION 3.6)
project(Ex5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp playfield.h player.h)
add_executable(Ex5 ${SOURCE_FILES})