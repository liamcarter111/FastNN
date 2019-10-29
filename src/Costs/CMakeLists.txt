cmake_minimum_required(VERSION 3.0.0)

SET(THIS Costs)

SET(SRC_LIST 
    MeanSquareError.cpp
    RootMeanSquareError.cpp
)

SET(HEADER_FILES 
    MeanSquareError.h
    RootMeanSquareError.h
)

add_library(
    ${THIS}
    ${SRC_LIST}
    ${HEADER_FILES}
)

target_link_libraries(
    ${THIS} PRIVATE 
    Core
)

target_include_directories(${THIS} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TARGET ${THIS} PROPERTY CXX_STANDARD 17)