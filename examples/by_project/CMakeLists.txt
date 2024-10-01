
if(WIN32)
	add_subdirectory(comstl)
endif(WIN32)

if(UNIX)
	add_subdirectory(unixstl)
endif(UNIX)

if(WIN32)
	add_subdirectory(winstl)
endif(WIN32)


# ############################## end of file ############################# #

