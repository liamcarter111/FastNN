cmake_minimum_required(VERSION 3.0.0)

SET(THIS Activations)

SET(SRC_LIST 
    LeakyReLU.cpp
    Linear.cpp
    ReLU.cpp
    Sigmoid.cpp
    Tanh.cpp
    Softmax.cpp
)

SET(HEADER_FILES 
    LeakyReLU.h
    Linear.h
    ReLU.h
    Sigmoid.h
    Tanh.h
    Softmax.h
)

add_library(
    ${THIS}
    ${SRC_LIST}
    ${HEADER_FILES}
)

target_link_libraries(
    ${THIS} PRIVATE 
    Math
    Core
)

target_include_directories(${THIS} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})