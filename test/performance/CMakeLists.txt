
add_subdirectory(test.performance.platformstl.stopwatch)

if((NOT ${CMAKE_CXX_STANDARD} EQUAL "98") OR (NOT ${CMAKE_CXX_STANDARD} EQUAL "03"))

    add_subdirectory(test.performance.stlsoft.simple_string.compare)
    add_subdirectory(test.performance.stlsoft.simple_string.contains_etc)
    add_subdirectory(test.performance.stlsoft.simple_string.op_eq)
endif()


# ############################## end of file ############################# #

