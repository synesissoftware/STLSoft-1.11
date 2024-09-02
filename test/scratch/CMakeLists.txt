
add_subdirectory(platformstl)
if(UNIX)
	add_subdirectory(unixstl)
endif(UNIX)
add_subdirectory(versions)
if(WIN32)
	add_subdirectory(winstl)
endif(WIN32)


# ############################## end of file ############################# #

