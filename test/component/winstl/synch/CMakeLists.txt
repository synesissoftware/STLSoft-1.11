
if(X_CMAKE_CXX_FULLSTANDARD GREATER_EQUAL 2011)

	add_subdirectory(test.component.winstl.synch.atomic_functions)
	add_subdirectory(test.component.winstl.synch.spin_mutex)
endif()
