if(X_CMAKE_CXX_FULLSTANDARD GREATER_EQUAL 2011)

	if(UNIX)

		add_subdirectory(test.scratch.unixstl.synch.semaphore)
	endif(UNIX)
endif()
