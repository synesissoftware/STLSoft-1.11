if(_BUILD_AS_WIN32)
	# TODO: sort out 64-bit build of `comstl::interface_cast<>`
	# add_subdirectory(interface_cast)
endif(_BUILD_AS_WIN32)
add_subdirectory(sap_cast)
add_subdirectory(union_cast)
