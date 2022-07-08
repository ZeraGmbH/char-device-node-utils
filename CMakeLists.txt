cmake_minimum_required(VERSION 3.5)

project(char-device-node-utils LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FeatureSummary)
include(GNUInstallDirs)
include(FindPkgConfig)

find_package(GTest)
pkg_check_modules(FUSE fuse3 REQUIRED)

set(CNC_KMOD "${PROJECT_SOURCE_DIR}/src/char-node-creator/char_node_creator.ko")

add_subdirectory(src)
add_subdirectory(tests)
