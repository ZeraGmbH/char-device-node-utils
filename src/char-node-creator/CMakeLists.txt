# this is not supposed to build cleanly

set(kerneldir "" CACHE STRING "Path to the kernel build directory")
execute_process(
    COMMAND uname -r
    OUTPUT_VARIABLE uname_r
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )
set(kerneldir "/lib/modules/${uname_r}/build")
message("kerneldir: ${kerneldir}")
set(kernelincdir "/usr/src/kernels/${uname_r}/include")
message("kernelincdir: ${kernelincdir}")

add_library(char-node-creator-dummylib STATIC EXCLUDE_FROM_ALL
    char-node-creator.c
    control-node.c
    control-node.h
    )
get_target_property(module_sources char-node-creator-dummylib SOURCES)
list(APPEND module_sources module.c)

target_include_directories(char-node-creator-dummylib
    PUBLIC
    ${kernelincdir}
    )

set_target_properties(char-node-creator-dummylib
    PROPERTIES
    LANGUAGE C
    C_STANDARD 99
    )

set(CNC_KMOD "${CMAKE_CURRENT_SOURCE_DIR}/char_node_creator.ko")
configure_file(kmodulelocation.h.in kmodulelocation.h @ONLY)
