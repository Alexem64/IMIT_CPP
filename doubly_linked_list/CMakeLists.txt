cmake_minimum_required(VERSION 3.14)
project(doubly_linked_list)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(doubly_linked_list
        abstractDoublyLinkedList.h
        main.cpp doublyLinkedList.cpp doublyLinkedList.h)
