cmake_minimum_required(VERSION 3.0.0)

SET(SRC_LIST 
    Layer.cpp
)

SET(HEADER_FILES 
    Activation.h
    Layer.h
    Network.h
)

add_library(
    Core
    ${SRC_LIST}
    ${HEADER_FILES}
)

target_include_directories(Core INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")