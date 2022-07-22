cmake_minimum_required(VERSION 3.5)

project(char-device-node-utils LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FeatureSummary)
include(GNUInstallDirs)
include(FindPkgConfig)

set(KERNEL_MODULE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/char-node-creator)

find_package(GTest)

add_subdirectory(src)
add_subdirectory(tests)
