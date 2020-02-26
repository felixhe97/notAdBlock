cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)

project(filters VERSION 0.1)

add_executable(filters main.cpp)
target_sources(filters PRIVATE rangeFilter.cpp)
