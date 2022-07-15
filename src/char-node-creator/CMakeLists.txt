# TODO: out of tree build
add_custom_target(cnc-kernelmodule ALL
    SOURCES ${SOURCE_DEVINFO}
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

# make library find module
set(CNC_KMOD "${CMAKE_CURRENT_SOURCE_DIR}/char_node_creator.ko")
configure_file(kmodulelocation.h.in kmodulelocation.h @ONLY)

# ---------------------------------------------------------------------
# the following is not supposed to build - just IDE comfort
add_library(char-node-creator-dummylib STATIC EXCLUDE_FROM_ALL
    char-node-creator.c
    control-node.c
    control-node.h
    Makefile
    )

execute_process(
    COMMAND uname -r
    OUTPUT_VARIABLE uname_r
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )

set(kernelsrcdir "/usr/src/kernels/${uname_r}")
set(archkernelincdir "${kernelsrcdir}/arch/x86/include")

target_include_directories(char-node-creator-dummylib
    PUBLIC
    ${kernelsrcdir}/include
    ${archkernelincdir}
    )

set_target_properties(char-node-creator-dummylib
    PROPERTIES
    LANGUAGE C
    C_STANDARD 99
    C_STANDARD_REQUIRED ON
    )
