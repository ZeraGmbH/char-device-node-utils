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

add_library(char-node-creator-dummylib STATIC char_node_creator.c)
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
