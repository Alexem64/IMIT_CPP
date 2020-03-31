cmake_minimum_required(VERSION 3.14)
project(cpp1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp1
        DynamicArrayOfInt.cpp
        DynamicArrayOfInt.h
        main.cpp)
