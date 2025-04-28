
if(_BUILD_AS_WIN32)

	add_subdirectory(comstl)
endif(_BUILD_AS_WIN32)
if(_BUILD_AS_UNIX OR _BUILD_AS_WIN32)

	add_subdirectory(inetstl)
endif(_BUILD_AS_UNIX OR _BUILD_AS_WIN32)
if(HAS_MFC)

	add_subdirectory(mfcstl)
endif(HAS_MFC)
add_subdirectory(platformstl)
add_subdirectory(stlsoft)
if(_BUILD_AS_UNIX)
	add_subdirectory(unixstl)
endif(_BUILD_AS_UNIX)
if(_BUILD_AS_WIN32)
	add_subdirectory(winstl)
endif(_BUILD_AS_WIN32)


# ############################## end of file ############################# #

