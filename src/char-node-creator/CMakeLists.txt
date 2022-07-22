# ---------------------------------------------------------------------
# Build kernel module - inspired by
# https://musteresel.github.io/posts/2020/02/cmake-template-linux-kernel-module.html

set(KERNEL_SOURCES
    char-node-creator.c
    control-node.c
    )

set(KERNEL_HEADER
    control-node.h
    globals.h
    )

set(MODULENAME "char_node_creator")
get_filename_component(MY_PATH ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(MODULE_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/${MY_PATH}")

foreach(file ${KERNEL_SOURCES})
    string(REPLACE ".c" ".o" _file "${file}")
    set(KSOURCEFILES "${KSOURCEFILES} ${_file}")
endforeach()
configure_file(Kbuild.in Kbuild @ONLY)

execute_process(
    COMMAND uname -r
    OUTPUT_VARIABLE UNAME_R
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )
set(KERNEL_SRC_DIR "/lib/modules/${UNAME_R}/build")
set(MODULE_MAKE_CMD make -C ${KERNEL_SRC_DIR} M=${MODULE_BUILD_DIR})

add_custom_command(OUTPUT ${MODULENAME}.ko
    COMMAND cp -rf ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND cp -f ${CMAKE_CURRENT_BINARY_DIR}/Kbuild ${MODULE_BUILD_DIR}
    COMMAND ${MODULE_MAKE_CMD} modules
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${KERNEL_SOURCES} ${KERNEL_HEADER} ${CMAKE_CURRENT_BINARY_DIR}/Kbuild
    VERBATIM
    )

add_custom_target(module ALL DEPENDS ${MODULENAME}.ko)
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${MODULE_BUILD_DIR})


# ---------------------------------------------------------------------
# make library find module
set(CNC_KMODULE_PATH "${MODULE_BUILD_DIR}/${MODULENAME}.ko")
configure_file(kmodulelocation.h.in kmodulelocation.h @ONLY)


# ---------------------------------------------------------------------
# the following is not supposed to build - just IDE comfort
add_library(char-node-creator-ide STATIC EXCLUDE_FROM_ALL
    ${KERNEL_HEADER}
    ${KERNEL_SOURCES}
    )

set(KERNEL_SRC_DIR "/usr/src/kernels/${UNAME_R}")
set(KERNEL_ARCH_INCDIR "${KERNEL_SRC_DIR}/arch/x86/include")
set(KERNEL_ARCH_GENERATED_INCDIR "${KERNEL_ARCH_INCDIR}/generated")

target_include_directories(char-node-creator-ide
    PUBLIC
    ${KERNEL_SRC_DIR}/include
    ${KERNEL_ARCH_INCDIR}
    ${KERNEL_ARCH_GENERATED_INCDIR}
    )

target_compile_definitions(char-node-creator-ide
    PUBLIC
    __KERNEL__
    )

set_target_properties(char-node-creator-ide
    PROPERTIES
    LANGUAGE C
    C_STANDARD 99
    C_STANDARD_REQUIRED ON
    )
