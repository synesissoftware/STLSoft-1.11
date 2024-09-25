
if(X_CMAKE_CXX_FULLSTANDARD GREATER_EQUAL 2011)

	add_subdirectory(test.performance.platformstl.stopwatch)
endif()

if(X_CMAKE_CXX_FULLSTANDARD GREATER_EQUAL 2014)

	add_subdirectory(test.performance.stlsoft.auto_buffer)
endif()

if(X_CMAKE_CXX_FULLSTANDARD GREATER_EQUAL 2011)
	add_subdirectory(test.performance.stlsoft.simple_string.compare)
	add_subdirectory(test.performance.stlsoft.simple_string.op_eq)
endif()


# ############################## end of file ############################# #

