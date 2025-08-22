
list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED "uninitialized")
list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED "unused-variable")
define_example_program(union_cast main.cpp)
