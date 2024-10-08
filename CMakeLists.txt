
# ######################################################################## #
# File:     /CMakeLists.txt
#
# Purpose:  Top-level CMake lists file for STLSoft
#
# Created:  31st March 2021
# Updated:  1st October 2024
#
# ######################################################################## #


# ##########################################################
# CMake

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# require out-of-source builds
file(TO_CMAKE_PATH "${CMAKE_CURRENT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")

	message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

# directory for CMake specific extensions and source files.
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})


# ##########################################################
# project

project(STLSoft
	DESCRIPTION "STLSoft is a suite of libraries that provide STL extensions and facades over operating-system and technology-specific APIs."
	HOMEPAGE_URL "https://github.com/synesissoftware/STLSoft-1.11"
	LANGUAGES C CXX
)

string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)

# handle version number
set(RX_PROJ_TAG "${PROJECT_NAME_UPPER}")
set(RX_WS "[ \t]")
file(READ "${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${PROJECT_NAME_LOWER}.h" _header_file)
string(REGEX MATCH "#${RX_WS}*define${RX_WS}+_?${RX_PROJ_TAG}_VER_MAJOR${RX_WS}+([0-9]+)" MAJOR_DUMMY ${_header_file})
set(_VERSION_MAJOR ${CMAKE_MATCH_1})
string(REGEX MATCH "#${RX_WS}*define${RX_WS}+_?${RX_PROJ_TAG}_VER_MINOR${RX_WS}+([0-9]+)" MINOR_DUMMY ${_header_file})
set(_VERSION_MINOR ${CMAKE_MATCH_1})
string(REGEX MATCH "#${RX_WS}*define${RX_WS}+_?${RX_PROJ_TAG}_VER_REVISION${RX_WS}+([0-9]+)" PATCH_DUMMY ${_header_file})
set(_VERSION_PATCH ${CMAKE_MATCH_1})

# set project version number here
set(PROJECT_VERSION_MAJOR ${_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${_VERSION_MINOR})
set(PROJECT_VERSION_PATCH ${_VERSION_PATCH})
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# adhere strictly to C and C++ standards plus extensions. These are actually
# useless since we do not compile anything; they merely state our intention.
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON) # GNU extensions and POSIX standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# ##########################################################
# install

# provides install directory variables as defined by the GNU Coding Standards.
include(GNUInstallDirs)


# ##########################################################
# build

# load/default `CMAKE_BUILD_TYPE`
include(BuildType)
include(LanguageFullVersion)
include(TargetMacros)

add_library(STLSoft INTERFACE)

target_include_directories(STLSoft INTERFACE
	$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)


# ##########################################################
# examples

option(BUILD_EXAMPLES "Build examples" ON)
if(BUILD_EXAMPLES)

	message("-- enabled building of examples ...")

	add_subdirectory(examples)
else(BUILD_EXAMPLES)

	message("-- disabled building of examples - define BUILD_EXAMPLES to enable")
endif(BUILD_EXAMPLES)


# ##########################################################
# test

include(CTest)

if(BUILD_TESTING)

	message("-- enabled building of tests ...")

	find_package(STLSoft REQUIRED)

	if(NOT STLSoft_FOUND)

		message(FATAL_ERROR "No existing installation of STLSoft was found, which means you are not able to configure CMake with testing enabled, because STLSoft's component/unit tests are implemented in terms of xTests, which itself relies on STLSoft. Instead, you must perform an initial CMake configuration and installation with testing disabled (-DBUILD_TESTING:BOOL=OFF, or passing --disable-testing to prepare_cmake.sh), and then configure and install xTests, whereupon you will be free to (re)configure STLSoft for testing.")
	else()

		message("-- CMake package STLSoft found (version ${STLSoft_VERSION}) - required only to enable xTests package; the current project's header files will be used for all compilation")
	endif()

	set(xTests_REQUIRED_VERSION_ 0.24)

	find_package(xTests ${xTests_REQUIRED_VERSION_} REQUIRED)

	message("-- CMake package xTests found (version ${xTests_VERSION}; ${xTests_REQUIRED_VERSION_} requested)")

	add_subdirectory(test)
else(BUILD_TESTING)

	message("-- disabled building of tests - define BUILD_TESTING to enable")
endif(BUILD_TESTING)


# ##########################################################
# install

# this does not actually install anything...
install(TARGETS STLSoft
	EXPORT project-targets
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# ... and we have to manually copy the header files.
foreach(ITEM
	acestl
	atlstl
	comstl
	inetstl
	mfcstl
	platformstl
	rangelib
	stlsoft
	unixstl
	winstl
	wtlstl
)

	install(
		DIRECTORY ${CMAKE_SOURCE_DIR}/include/${ITEM}/
		DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${ITEM}/
		FILES_MATCHING
		PATTERN "*.h*"
	)
endforeach()


# ##########################################################
# export

include(CMakePackageConfigHelpers)

string(TOLOWER ${PROJECT_NAME} EXPORT_NAME)

configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/cmake/${EXPORT_NAME}-config.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config.cmake
	INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/${EXPORT_NAME}/cmake
)

write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config-version.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY AnyNewerVersion
)

# install stlsoft-targets.cmake => /usr/local/lib/cmake/stlsoft
install(EXPORT project-targets
	NAMESPACE "${PROJECT_NAME}::"
	FILE "${EXPORT_NAME}-targets.cmake"
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${EXPORT_NAME}
)

# install stlsoft-config.cmake & stlsoft-config-version.cmake => /usr/local/lib/cmake/stlsoft
install(FILES
	"${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config.cmake"
	"${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config-version.cmake"
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${EXPORT_NAME}
)


# ##########################################################
# completion

message(NOTICE "Generating CMake build scripts for ${PROJECT_NAME} ${PROJECT_VERSION}, for C${CMAKE_C_STANDARD} C++${CMAKE_CXX_STANDARD}")


# ############################## end of file ############################# #

