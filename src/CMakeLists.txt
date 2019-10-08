cmake_minimum_required(VERSION 3.0.0)

add_subdirectory(Core)
add_subdirectory(Math)
add_subdirectory(Activations)
add_subdirectory(App)

add_library(
    FastNN OBJECT SHARED
    Core
    Math
    Activations
)
set_target_properties(FastNN PROPERTIES LINKER_LANGUAGE CXX)
SET_TARGET_PROPERTIES(FastNN PROPERTIES PREFIX "")
target_include_directories(FastNN INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")