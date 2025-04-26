list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED
	format-zero-length
)
list(APPEND X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED
	4996
)
define_automated_test_program(test.unit.stlsoft.util.string.snprintf entry.cpp)
