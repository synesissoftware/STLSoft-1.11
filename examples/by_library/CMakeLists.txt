if(_BUILD_AS_WIN32)
	add_subdirectory(com_utility)
endif(_BUILD_AS_WIN32)
add_subdirectory(containers)
add_subdirectory(conversion)
add_subdirectory(diagnostics)
add_subdirectory(memory)
add_subdirectory(synch)
if(_BUILD_AS_WIN32)
	add_subdirectory(windows_clipboard)
	add_subdirectory(windows_control_panel)
	add_subdirectory(windows_registry)
	add_subdirectory(windows_shell)
	add_subdirectory(windows_toolhelp)
endif(_BUILD_AS_WIN32)


# ############################## end of file ############################# #

