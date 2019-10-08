cmake_minimum_required(VERSION 3.0.0)

SET(SRC_LIST 
    LeakyReLU.cpp
    Linear.cpp
    ReLU.cpp
    Sigmoid.cpp
    Tanh.cpp
)

SET(HEADER_FILES 
    LeakyReLU.h
    Linear.h
    ReLU.h
    Sigmoid.h
    Tanh.h
)

add_library(
    Activations
    ${SRC_LIST}
    ${HEADER_FILES}
)

target_include_directories(Activations INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")