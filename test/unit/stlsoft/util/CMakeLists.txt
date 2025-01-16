# SIS:AUTO_GENERATED: Remove this line if you edit the file, otherwise it will be overwritten
add_subdirectory(test.unit.stlsoft.util.bit_functions)
add_subdirectory(test.unit.stlsoft.util.count_decimal_digits)
add_subdirectory(test.unit.stlsoft.util.count_hexadecimal_digits)
if(X_CMAKE_CXX_FULLSTANDARD GREATER_EQUAL 2011)

	add_subdirectory(test.unit.stlsoft.util.string_insertion)
endif()
add_subdirectory(test.unit.stlsoft.util.string_switch)
add_subdirectory(test.unit.stlsoft.util.true_typedef)
