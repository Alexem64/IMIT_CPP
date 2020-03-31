cmake_minimum_required(VERSION 3.14)
project(cpp0Class)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp0Class
        main.cpp
        unitBox.cpp
        unitBox.h
        unitContainer.cpp
        unitContainer.h)
