cmake_minimum_required(VERSION 2.8.4)
project(sb)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    kotori.cpp
    kotori.h
    main.cpp)

add_executable(sb ${SOURCE_FILES})