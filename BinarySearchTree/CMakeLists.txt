cmake_minimum_required(VERSION 3.21)
project(BinarySearchTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(BinarySearchTree src/BinarySearchTree.cpp
        src/CSVparser.hpp
        src/CSVparser.cpp)
