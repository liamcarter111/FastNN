cmake_minimum_required(VERSION 3.0.0)

SET(SRC_LIST 
    main.cpp
)

SET(HEADER_FILES 
)

add_executable(
    App 
    ${SRC_LIST}
    ${HEADER_FILES}
)

target_link_libraries(
    App PRIVATE 
    Core
    Math
    Activations
)