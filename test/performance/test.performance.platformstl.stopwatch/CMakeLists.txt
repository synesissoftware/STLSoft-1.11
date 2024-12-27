define_example_program(test.performance.platformstl.stopwatch main.cpp)

if(WIN32)
	target_link_libraries(test.performance.platformstl.stopwatch
		ws2_32
		wsock32
	)
endif()
