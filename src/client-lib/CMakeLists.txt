add_library(client-lib STATIC
    kmodulehelpers.cpp
    kmodulehelpers.h
    )

target_link_libraries(client-lib
    PUBLIC
    )

target_include_directories(client-lib
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/../char-node-creator>
    $<BUILD_INTERFACE:${KERNEL_MODULE_SOURCE_DIR}>
    ${CMAKE_CURRENT_SOURCE_DIR}
    )
