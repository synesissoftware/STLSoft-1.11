if(X_CMAKE_CXX_FULLSTANDARD GREATER_EQUAL 2011)

	if(UNIX)

		add_subdirectory(test.component.unixstl.dl.dl_call)
	endif(UNIX)
endif()
