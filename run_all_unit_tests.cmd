@ECHO OFF

SETLOCAL ENABLEDELAYEDEXPANSION ENABLEEXTENSIONS

SET ScriptPath=%~n0[%~x0]
SET ScriptDir=%~dp0

IF DEFINED SIS_CMAKE_BUILD_DIR (

    SET CMakeDir=%SIS_CMAKE_BUILD_DIR%
) ELSE (

    SET CMakeDir=%ScriptDir%_build
)

SET ListOnly=0
SET RunMake=1
SET UnitOnly=0
SET ComponentOnly=0
SET TestVerbosityDefault=3
SET TestVerbosity=%TEST_VERBOSITY%

IF NOT DEFINED TestVerbosity SET TestVerbosity=%TestVerbosityDefault%
IF DEFINED XTESTS_VERBOSITY SET TestVerbosity=%XTESTS_VERBOSITY%

SET BuildConfig=Release
IF DEFINED CMAKE_BUILD_TYPE SET BuildConfig=%CMAKE_BUILD_TYPE%


:: #########################################################
:: command-line handling

:parse_args
IF "%~1"=="" GOTO args_done

IF /I "%~1"=="--help" GOTO show_help
IF /I "%~1"=="-l" (
    SET ListOnly=1
    GOTO next_arg
)
IF /I "%~1"=="--list-only" (
    SET ListOnly=1
    GOTO next_arg
)
IF /I "%~1"=="-M" (
    SET RunMake=0
    GOTO next_arg
)
IF /I "%~1"=="--no-make" (
    SET RunMake=0
    GOTO next_arg
)
IF /I "%~1"=="--unit-only" (
    SET UnitOnly=1
    GOTO next_arg
)
IF /I "%~1"=="--component-only" (
    SET ComponentOnly=1
    GOTO next_arg
)
IF /I "%~1"=="--verbosity" (
    SHIFT
    IF "%~1"=="" (
        ECHO %ScriptPath%: --verbosity requires an argument 1>&2
        EXIT /B 1
    )
    SET TestVerbosity=%~1
    GOTO next_arg
)

ECHO %ScriptPath%: unrecognised argument '%~1'; use --help for usage 1>&2
EXIT /B 1

:next_arg
SHIFT
GOTO parse_args

:args_done

IF %UnitOnly% NEQ 0 IF %ComponentOnly% NEQ 0 (
    ECHO %ScriptPath%: --unit-only and --component-only are mutually exclusive 1>&2
    EXIT /B 1
)

IF %UnitOnly% NEQ 0 (
    SET TestKindDescription=unit test
    SET FindPattern=test[._]unit[._].*\.exe$
) ELSE IF %ComponentOnly% NEQ 0 (
    SET TestKindDescription=component test
    SET FindPattern=test[._]component[._].*\.exe$
) ELSE (
    SET TestKindDescription=component and unit test
    SET FindPattern=test[._]unit[._].*\.exe$ test[._]component[._].*\.exe$
)


:: #########################################################
:: main()

SET status=0

IF %RunMake% NEQ 0 (
    IF %ListOnly% EQU 0 (
        ECHO Executing build and then running all !TestKindDescription! programs
        CALL :do_build
        IF ERRORLEVEL 1 SET status=1
    )
) ELSE (
    IF NOT EXIST "%CMakeDir%\CMakeCache.txt" (
        ECHO %ScriptPath%: cannot run in '--no-make' mode without a previous successful build step 1>&2
        EXIT /B 1
    )
)

IF %status% EQU 0 (
    IF %ListOnly% NEQ 0 (
        ECHO Listing all !TestKindDescription! programs
    ) ELSE (
        ECHO Running all !TestKindDescription! programs
    )

    FOR /F "usebackq delims=" %%f IN (`DIR /A:-D /B /S "%CMakeDir%" 2^>NUL ^| FINDSTR /I /R "%FindPattern%"`) DO (
        IF !ListOnly! NEQ 0 (
            ECHO would execute %%f:
        ) ELSE (
            ECHO.
            ECHO executing %%f:
            CALL "%%f" --verbosity=!TestVerbosity!
            IF ERRORLEVEL 1 (
                SET status=1
                GOTO tests_done
            )
        )
    )
)

:tests_done
IF !status! NEQ 0 (
    ENDLOCAL
    EXIT /B 1
)
ENDLOCAL
EXIT /B 0


:: #########################################################
:: helpers

:do_build
IF DEFINED SIS_CMAKE_MAKE_COMMAND (
    PUSHd "%CMakeDir%"
    CALL %SIS_CMAKE_MAKE_COMMAND%
    SET build_status=!ERRORLEVEL!
    POPD
    EXIT /B !build_status!
)
IF EXIST "%CMakeDir%\Makefile" (
    PUSHd "%CMakeDir%"
    IF DEFINED MSYSTEM (
        mingw32-make.exe
    ) ELSE (
        make
    )
    SET build_status=!ERRORLEVEL!
    POPD
    EXIT /B !build_status!
)
cmake --build "%CMakeDir%" --config %BuildConfig%
EXIT /B %ERRORLEVEL%


:show_help
IF EXIST "%ScriptDir%.sis\script_info_lines.txt" (
    type "%ScriptDir%.sis\script_info_lines.txt"
)
ECHO.
ECHO Runs all (matching) unit-test and/or component-test programs
ECHO.
ECHO %ScriptPath% [ ... flags/options ... ]
ECHO.
ECHO Flags/options:
ECHO.
ECHO     behaviour:
ECHO.
ECHO     -l
ECHO     --list-only
ECHO         lists the target programs but does not execute them
ECHO.
ECHO     -M
ECHO     --no-make
ECHO         does not execute CMake and make before running tests
ECHO.
ECHO     --unit-only
ECHO         runs only unit-test programs (test.unit.* / test_unit*)
ECHO.
ECHO     --component-only
ECHO         runs only component-test programs (test.component.* / test_component*)
ECHO.
ECHO     --verbosity ^<verbosity^>
ECHO         specifies an explicit verbosity for the unit-test(s)
ECHO.
ECHO     standard flags:
ECHO.
ECHO     --help
ECHO         displays this help and terminates
EXIT /B 0


:: ############################# end of file ############################ ::
