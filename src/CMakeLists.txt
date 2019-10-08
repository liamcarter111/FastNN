cmake_minimum_required(VERSION 3.0.0)

SET(THIS FastNN)

add_subdirectory(Core)
add_subdirectory(Math)
add_subdirectory(Activations)
add_subdirectory(App)

add_library(
    ${THIS} SHARED
    Core
    Math
    Activations
)
set_target_properties(${THIS} PROPERTIES LINKER_LANGUAGE CXX)
SET_TARGET_PROPERTIES(${THIS} PROPERTIES PREFIX "")
target_include_directories(${THIS} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})