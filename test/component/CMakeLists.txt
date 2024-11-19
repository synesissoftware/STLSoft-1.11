
add_subdirectory(platformstl)
add_subdirectory(stlsoft)
if(UNIX)
	add_subdirectory(unixstl)
endif(UNIX)
if(WIN32)
	add_subdirectory(winstl)
endif(WIN32)


# ############################## end of file ############################# #

