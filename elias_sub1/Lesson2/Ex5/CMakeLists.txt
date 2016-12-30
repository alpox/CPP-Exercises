cmake_minimum_required(VERSION 3.6)
project(Ex5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES pvector.h main.cpp fraction.h)
add_executable(Ex5 ${SOURCE_FILES})