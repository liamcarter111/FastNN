cmake_minimum_required(VERSION 3.0.0)

add_library(
    Activations
    LeakyReLU.cpp
    Linear.cpp
    ReLU.cpp
    Sigmoid.cpp
    Tanh.cpp
)

target_include_directories(Activations INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")