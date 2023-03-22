cmake_minimum_required(VERSION 3.24)
project(EDA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(EDA
        Tree/Node.h
        Tree/Tree.cpp
        Tree/Tree.h
        Tree/main.cpp)
