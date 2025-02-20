
if(WIN32)

	add_subdirectory(comstl)
endif(WIN32)
if(UNIX OR WIN32)

	add_subdirectory(inetstl)
endif(UNIX OR WIN32)
if(HAS_MFC)

	add_subdirectory(mfcstl)
endif(HAS_MFC)
add_subdirectory(platformstl)
add_subdirectory(stlsoft)
if(UNIX)
	add_subdirectory(unixstl)
endif(UNIX)
if(WIN32)
	add_subdirectory(winstl)
endif(WIN32)


# ############################## end of file ############################# #

