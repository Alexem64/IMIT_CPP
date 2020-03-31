cmake_minimum_required(VERSION 3.14)
project(cpp2_ringBuffer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp2_ringBuffer
        ringBuffer.cpp
        ringBuffer.h)
