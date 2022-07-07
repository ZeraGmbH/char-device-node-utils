add_executable(cuse-example-server
    ${CMAKE_CURRENT_SOURCE_DIR}/ioctl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/cuse.c
)

target_include_directories(cuse-example-server
    PUBLIC
    ${FUSE_INCLUDE_DIRS}
    )

target_link_libraries(cuse-example-server
    PUBLIC
    fuse3
)


add_executable(cuse-example-client
    ${CMAKE_CURRENT_SOURCE_DIR}/ioctl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/cuse_client.c
)

target_include_directories(cuse-example-client
    PUBLIC
    ${FUSE_INCLUDE_DIRS}
    )

target_link_libraries(cuse-example-client
    PUBLIC
    fuse3
    )
