cmake_minimum_required(VERSION 3.0.0)

SET(THIS App)

SET(SRC_LIST 
    main.cpp
)

SET(HEADER_FILES 
)

add_executable(
    ${THIS} 
    ${SRC_LIST}
    ${HEADER_FILES}
)

target_link_libraries(
    ${THIS} PRIVATE 
    Core
    Math
    Activations
)