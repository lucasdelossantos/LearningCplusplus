cmake_minimum_required(VERSION 3.21)
project(LinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinkedList src/LinkedList.cpp
        src/CSVparser.cpp
        src/CSVparser.hpp)
