add_subdirectory(auto_buffer)
if(_BUILD_AS_WIN32)
	add_subdirectory(heapwalk_sequence)
	add_subdirectory(com_memory_functions)
endif(_BUILD_AS_WIN32)

