
add_executable(example.winstl.filesystem.findfile_sequence
    main.cpp
)

target_compile_options(example.winstl.filesystem.findfile_sequence PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-declarations

        ${GCC_WARN_NO_cxx11_long_long}
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

