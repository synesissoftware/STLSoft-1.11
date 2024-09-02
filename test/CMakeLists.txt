
include_directories(${CMAKE_SOURCE_DIR}/include)

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


set(GCC_WARN_NO_cxx11_long_long "")
if(X_CMAKE_CXX_FULLSTANDARD LESS 2011)

	set(GCC_WARN_NO_cxx11_long_long -Wno-c++11-long-long)
endif()


add_subdirectory(performance)
add_subdirectory(scratch)
add_subdirectory(unit)


# ############################## end of file ############################# #

