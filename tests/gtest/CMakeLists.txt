enable_testing()

add_test(NAME    kernelmodule-test
         COMMAND kernelmodule-test)

add_executable(kernelmodule-test
    fixtures.h
    testkmodhelpers.cpp
    testcontroldevnode.cpp
)
# constexpr / EXPECT_EQ -> linker problems for c++ < 17
set_property(TARGET kernelmodule-test PROPERTY CXX_STANDARD 17)

target_include_directories(kernelmodule-test
    PRIVATE
    ${KERNEL_MODULE_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

target_link_libraries(kernelmodule-test
    PUBLIC
    gtest
    gtest_main
    client-lib
)

