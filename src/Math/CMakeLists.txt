cmake_minimum_required(VERSION 3.0.0)

SET(THIS Math)

SET(SRC_LIST 
    Matrix.cpp
    Random.cpp
)

SET(HEADER_FILES 
    Matrix.h
    Random.h
)

add_library(
    ${THIS}
    ${SRC_LIST}
    ${HEADER_FILES}
)

target_include_directories(${THIS} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TARGET ${THIS} PROPERTY CXX_STANDARD 17)