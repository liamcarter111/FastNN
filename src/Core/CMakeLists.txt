cmake_minimum_required(VERSION 3.0.0)

SET(THIS Core)

SET(SRC_LIST 
    Layer.cpp
)

SET(HEADER_FILES 
    Activation.h
    Layer.h
    Network.h
)

add_library(
    ${THIS}
    ${SRC_LIST}
    ${HEADER_FILES}
)

target_link_libraries(
    ${THIS} PRIVATE 
    Math
)

target_include_directories(${THIS} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})