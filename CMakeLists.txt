cmake_minimum_required(VERSION 3.8)
project(Vector3R)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Vector3.h Vector3.cpp)
add_executable(Vector3R ${SOURCE_FILES})