
if(X_CMAKE_CXX_FULLSTANDARD GREATER_EQUAL 2011)

	add_subdirectory(test.performance.platformstl.stopwatch)

	add_subdirectory(test.performance.stlsoft.count_digits)
	add_subdirectory(test.performance.stlsoft.doomgram)
	add_subdirectory(test.performance.stlsoft.frequency_map)
	add_subdirectory(test.performance.stlsoft.simple_string.compare)
	add_subdirectory(test.performance.stlsoft.simple_string.op_eq)
endif()


# ############################## end of file ############################# #

