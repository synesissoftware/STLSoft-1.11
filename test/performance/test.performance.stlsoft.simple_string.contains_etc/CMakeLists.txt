
add_executable(test.performance.stlsoft.simple_string.contains_etc
    main.cpp
)

target_compile_options(test.performance.stlsoft.simple_string.contains_etc PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-declarations
        -Wno-unused-parameter

        ${GCC_WARN_NO_cxx11_long_long}
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

