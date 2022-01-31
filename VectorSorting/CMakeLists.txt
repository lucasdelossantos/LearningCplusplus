cmake_minimum_required(VERSION 3.21)
project(VectorSorting)

set(CMAKE_CXX_STANDARD 14)

add_executable(VectorSorting src/VectorSorting.cpp
        src/CSVparser.cpp
        src/CSVparser.hpp)
