cmake_minimum_required(VERSION 3.0.0)

add_executable(
    App 
    main.cpp
)

target_link_libraries(
    App PRIVATE 
    Core
    Math
    Activations
)