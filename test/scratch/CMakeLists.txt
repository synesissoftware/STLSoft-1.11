
add_subdirectory(platformstl)
if(_BUILD_AS_UNIX)
	add_subdirectory(unixstl)
endif(_BUILD_AS_UNIX)
add_subdirectory(versions)
if(_BUILD_AS_WIN32)
	add_subdirectory(winstl)
endif(_BUILD_AS_WIN32)


# ############################## end of file ############################# #

