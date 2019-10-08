cmake_minimum_required(VERSION 3.0.0)

add_library(
    Core
    Layer.cpp
)

target_include_directories(Core INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")