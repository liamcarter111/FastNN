cmake_minimum_required(VERSION 3.0.0)

SET(SRC_LIST 
    NumericFunction.cpp 
    Matrix.cpp
)

SET(HEADER_FILES 
    NumericFunction.h 
    Matrix.h
)

add_library(
    Math
    ${SRC_LIST}
    ${HEADER_FILES}
)

target_include_directories(Math INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")