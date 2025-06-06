

function(define_automated_test_program program_name entry_point_source_name)

	add_executable(${program_name}
		${entry_point_source_name}
	)

	target_link_libraries(${program_name}
		$<$<BOOL:${cstring_FOUND}>:cstring::core>
		$<$<BOOL:${shwild_FOUND}>:shwild::core>
		$<$<BOOL:${UNIXem_FOUND}>:UNIXem::UNIXem>
		$<$<BOOL:${xTests_FOUND}>:xTests::core>
	)

	if(WIN32)

		target_link_libraries(${program_name}
			ws2_32
			wsock32
		)
	endif()

	set(X_GCC_CUSTOM_WARNINGS_ "")

	if(X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED)
		foreach(warning ${X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED})

			list(APPEND X_GCC_CUSTOM_WARNINGS_ "-Wno-${warning}")
		endforeach()
	endif()

	set(X_MSVC_CUSTOM_WARNINGS_ "")

	if(X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED)
			foreach(warning ${X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED})

					list(APPEND X_MSVC_CUSTOM_WARNINGS_ "/wd${warning}")
			endforeach()
	endif()

	target_compile_options(${program_name}
		PRIVATE
			$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
				-Werror -Wall -Wextra -pedantic

				${GCC_WARN_NO_cxx11_long_long}
				${X_GCC_CUSTOM_WARNINGS_}
			>
			$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
				-Wno-unused-lambda-capture
			>
			$<$<CXX_COMPILER_ID:MSVC>:
				/WX /W4

				${X_MSVC_CUSTOM_WARNINGS_}
			>
	)
endfunction(define_automated_test_program)


function(define_example_program program_name entry_point_source_name)

	add_executable(${program_name}
		${entry_point_source_name}
	)

	target_link_libraries(${program_name}
		$<$<BOOL:${shwild_FOUND}>:shwild::core>
		$<$<BOOL:${cstring_FOUND}>:cstring::core>
		$<$<BOOL:${UNIXem_FOUND}>:UNIXem::UNIXem>
	)

	if(WIN32)

		target_link_libraries(${program_name}
			ws2_32
			wsock32
		)
	endif()

	set(X_GCC_CUSTOM_WARNINGS_ "")

	if(X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED)
		foreach(warning ${X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED})

			list(APPEND X_GCC_CUSTOM_WARNINGS_ "-Wno-${warning}")
		endforeach()
	endif()

	set(X_MSVC_CUSTOM_WARNINGS_ "")

	if(X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED)
			foreach(warning ${X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED})

					list(APPEND X_MSVC_CUSTOM_WARNINGS_ "/wd${warning}")
			endforeach()
	endif()

	target_compile_options(${program_name}
		PRIVATE
			$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
				-Werror -Wall -Wextra -pedantic

				${GCC_WARN_NO_cxx11_long_long}
				${X_GCC_CUSTOM_WARNINGS_}
			>
			$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
				-Wno-unused-lambda-capture
			>
			$<$<CXX_COMPILER_ID:MSVC>:
				/WX /W4

				${X_MSVC_CUSTOM_WARNINGS_}
			>
	)
endfunction(define_example_program)



# ############################## end of file ############################# #

