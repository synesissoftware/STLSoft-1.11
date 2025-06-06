
# ################################################
# X_CMAKE_C_FULLSTANDARD

set(X_CMAKE_C_FULLSTANDARD 0)

if(FALSE)
elseif(CMAKE_C_STANDARD EQUAL 99)

       set(X_CMAKE_C_FULLSTANDARD 1999)
elseif(CMAKE_C_STANDARD EQUAL 90)

       set(X_CMAKE_C_FULLSTANDARD 1990)
elseif(CMAKE_C_STANDARD GREATER_EQUAL 23)

       set(X_CMAKE_C_FULLSTANDARD 2023)
elseif(CMAKE_C_STANDARD GREATER_EQUAL 17)

       set(X_CMAKE_C_FULLSTANDARD 2017)
elseif(CMAKE_C_STANDARD GREATER_EQUAL 11)

       set(X_CMAKE_C_FULLSTANDARD 2011)
else()

       message(FATAL_ERROR "mechanism for discriminating X_CMAKE_C_FULLSTANDARD has failed")
endif()


# ################################################
# X_CMAKE_CXX_FULLSTANDARD

set(X_CMAKE_CXX_FULLSTANDARD 0)

if(FALSE)
elseif(CMAKE_CXX_STANDARD EQUAL 98)

	set(X_CMAKE_CXX_FULLSTANDARD 1998)
elseif(CMAKE_CXX_STANDARD GREATER_EQUAL 26)

	set(X_CMAKE_CXX_FULLSTANDARD 2026)
elseif(CMAKE_CXX_STANDARD GREATER_EQUAL 23)

	set(X_CMAKE_CXX_FULLSTANDARD 2023)
elseif(CMAKE_CXX_STANDARD GREATER_EQUAL 20)

	set(X_CMAKE_CXX_FULLSTANDARD 2020)
elseif(CMAKE_CXX_STANDARD GREATER_EQUAL 17)

	set(X_CMAKE_CXX_FULLSTANDARD 2017)
elseif(CMAKE_CXX_STANDARD GREATER_EQUAL 14)

	set(X_CMAKE_CXX_FULLSTANDARD 2014)
elseif(CMAKE_CXX_STANDARD GREATER_EQUAL 11)

	set(X_CMAKE_CXX_FULLSTANDARD 2011)
else()

	message(FATAL_ERROR "mechanism for discriminating X_CMAKE_CXX_FULLSTANDARD has failed")
endif()


# ############################## end of file ############################# #

