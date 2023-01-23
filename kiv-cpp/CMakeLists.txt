cmake_minimum_required(VERSION 3.23)
project(kiv_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(kiv_cpp
        main.cpp Lib.h Lib.cpp)
