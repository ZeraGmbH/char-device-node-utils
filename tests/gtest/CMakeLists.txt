enable_testing()

add_test(NAME    kernelmodule-test
         COMMAND kernelmodule-test)

add_executable(kernelmodule-test
    ${CMAKE_CURRENT_SOURCE_DIR}/kernelmodulehelpers.h
    ${CMAKE_CURRENT_SOURCE_DIR}/kernelmodulehelpers.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/testkmodhelpers.cpp
)
# constexpr / EXPECT_EQ -> linker problems for c++ < 17
set_property(TARGET kernelmodule-test PROPERTY CXX_STANDARD 17)

target_include_directories(kernelmodule-test
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

target_link_libraries(kernelmodule-test
    PUBLIC
    gtest
    gtest_main
)

configure_file(kmodulelocation.h.in kmodulelocation.h @ONLY)
