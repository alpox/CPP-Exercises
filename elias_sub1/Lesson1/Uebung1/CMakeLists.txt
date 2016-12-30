cmake_minimum_required(VERSION 3.6)
project(Uebung1)

# variable CMAKE_CONGIGURATION_TYPES shall be defined prior to other definitions:
set(CMAKE_CONFIGURATION_TYPES "SomeConfig" CACHE STRING "" FORCE) # setting two custom
# configuration types

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Uebung1 ${SOURCE_FILES})