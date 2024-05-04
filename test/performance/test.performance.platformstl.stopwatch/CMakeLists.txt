
add_executable(test.performance.platformstl.stopwatch
    main.cpp
)

target_compile_options(test.performance.platformstl.stopwatch PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-declarations
        -Wno-unused-parameter

        ${GCC_WARN_NO_cxx11_long_long}
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4

          /wd4100
    >
)


# ############################## end of file ############################# #

