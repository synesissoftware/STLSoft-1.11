
include_directories(${CMAKE_SOURCE_DIR}/include)

if(APPLE)

	message("adding '/usr/local/include' to include-directories for 'examples'")

	include_directories("/usr/local/include")
endif(APPLE)


if(UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)
endif(UNIX)

if(WIN32)

	if (CMAKE_SIZEOF_VOID_P EQUAL 8)

		message (STATUS "Compiling for 64-bit Windows")

		add_definitions(-DWIN64)
	else()

		message (STATUS "Compiling for 32-bit Windows")

		add_definitions(-DWIN32)
	endif()

	add_definitions(-DNOMINMAX)
endif(WIN32)


if ((MSVC) AND (MSVC_VERSION GREATER_EQUAL 1914))

	add_compile_options("/Zc:__cplusplus")
endif()


if(UNIX)
	add_subdirectory(unixstl)
endif(UNIX)

if(WIN32)
	add_subdirectory(winstl)
endif(WIN32)


# ############################## end of file ############################# #

