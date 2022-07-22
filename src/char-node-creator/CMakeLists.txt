# TODO: out of tree build

set(KERNEL_SOURCES
    char-node-creator.c
    control-node.c
    )

set(KERNEL_HEADER
    control-node.h
    globals.h
    )

set(MODULENAME "char_node_creator")
foreach(file ${KERNEL_SOURCES})
    string(REPLACE ".c" ".o" _file "${file}")
    set(KSOURCEFILES "${KSOURCEFILES} ${_file}")
endforeach()
configure_file(kmakefile.in kmakefile @ONLY)

add_custom_target(cnc-kernelmodule ALL
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

# make library find module
set(CNC_KMOD "${CMAKE_CURRENT_SOURCE_DIR}/${MODULENAME}.ko")
configure_file(kmodulelocation.h.in kmodulelocation.h @ONLY)

# ---------------------------------------------------------------------
# the following is not supposed to build - just IDE comfort
add_library(char-node-creator-dummylib STATIC EXCLUDE_FROM_ALL
    ${KERNEL_HEADER}
    ${KERNEL_SOURCES}
    )

execute_process(
    COMMAND uname -r
    OUTPUT_VARIABLE uname_r
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )

set(KERNEL_SRC_DIR "/usr/src/kernels/${uname_r}")
set(KERNEL_ARCH_INCDIR "${KERNEL_SRC_DIR}/arch/x86/include")
set(KERNEL_ARCH_GENERATED_INCDIR "${KERNEL_ARCH_INCDIR}/generated")

target_include_directories(char-node-creator-dummylib
    PUBLIC
    ${KERNEL_SRC_DIR}/include
    ${KERNEL_ARCH_INCDIR}
    ${KERNEL_ARCH_GENERATED_INCDIR}
    )

target_compile_definitions(char-node-creator-dummylib
    PUBLIC
    __KERNEL__
    )

set_target_properties(char-node-creator-dummylib
    PROPERTIES
    LANGUAGE C
    C_STANDARD 99
    C_STANDARD_REQUIRED ON
    )
