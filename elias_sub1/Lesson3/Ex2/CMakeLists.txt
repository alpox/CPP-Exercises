cmake_minimum_required(VERSION 3.6)
project(Ex2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp pvector.h pset.h persistence_traits.h)
add_executable(Ex2 ${SOURCE_FILES})