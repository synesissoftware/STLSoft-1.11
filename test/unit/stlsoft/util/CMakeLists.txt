add_subdirectory(test.unit.stlsoft.util.bit_functions)
add_subdirectory(test.unit.stlsoft.util.count_decimal_digits)
add_subdirectory(test.unit.stlsoft.util.count_hexadecimal_digits)
if(X_CMAKE_CXX_FULLSTANDARD GREATER_EQUAL 2011)

	add_subdirectory(test.unit.stlsoft.util.string_insertion)
endif()
add_subdirectory(test.unit.stlsoft.util.string.snprintf)
add_subdirectory(test.unit.stlsoft.util.string_switch)
add_subdirectory(test.unit.stlsoft.util.true_typedef)

