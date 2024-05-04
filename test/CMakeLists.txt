
include_directories(${CMAKE_SOURCE_DIR}/include)

if(APPLE)

	message("adding '/usr/local/include' to include-directories for 'test'")

	include_directories("/usr/local/include")
endif(APPLE)


if(UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)
endif(UNIX)

if(WIN32)

	# message(FATAL_ERROR "Use of CMake on Windows not currently supported")
endif(WIN32)


set(GCC_WARN_NO_cxx11_long_long "")
if("${CMAKE_CXX_STANDARD}" STREQUAL "98")

	set(GCC_WARN_NO_cxx11_long_long -Wno-c++11-long-long)
endif()


add_subdirectory(performance)
add_subdirectory(scratch)
add_subdirectory(unit)


# ############################## end of file ############################# #

