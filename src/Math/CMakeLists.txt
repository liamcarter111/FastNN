cmake_minimum_required(VERSION 3.0.0)

add_library(
    Math
    NumericFunction.cpp
    Matrix.cpp
)

target_include_directories(Math INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")