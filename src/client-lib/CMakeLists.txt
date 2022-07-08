add_library(client-lib STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/kmodulehelpers.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kmodulehelpers.h
    )

target_link_libraries(client-lib
    PUBLIC
    )

target_include_directories(client-lib
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/../char-node-creator>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    ${CMAKE_CURRENT_SOURCE_DIR}
    )
