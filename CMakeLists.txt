cmake_minimum_required(VERSION 3.3)
project(linked_lists)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp base.hpp single_linked.hpp double_linked.hpp structures.hpp)
add_executable(linked_lists ${SOURCE_FILES})