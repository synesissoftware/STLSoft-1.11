@ECHO OFF

SETLOCAL ENABLEDELAYEDEXPANSION ENABLEEXTENSIONS

SET ScriptPath=%~n0[%~x0]
SET ScriptDir="%~dp0"

SET TestVerbosityDefault=3

SET TestVerbosity=%TEST_VERBOSITY%

IF {%TestVerbosity%} == {} (
    SET TestVerbosity=%TestVerbosityDefault%
)


:: #########################################################
:: command-line handling

FOR %%a IN (%*) DO (
  IF {%%a} == {--help} (
    ECHO ^
STLSoft is a suite of libraries that provide STL extensions and facades over operating-system and technology-specific APIs^

Copyright ^(c^) 2019-2024, Matthew Wilson and Synesis Information Systems^

Copyright ^(c^) 2002-2019, Matthew Wilson and Synesis Software^

Runs all ^(matching^) unit-test ^& component-test programs^

^

%ScriptPath% ^[ ... flags/options ... ^]^

^

Flags/options:^

^

    standard flags:^

^

    --help^

^

        displays this help and terminates^


    EXIT /B 0
  ) ELSE (
    ECHO "%ScriptPath%: unrecognised argument '%1'; use --help for usage" 1>&2

    EXIT /B 1
  )
)


:: #########################################################
:: main()

FOR /F "usebackq delims==" %%p IN (`dir %ScriptDir%\*.exe /b /s ^| FINDSTR /I TEST.UNIT.*\.EXE`) DO CALL %%p --verbosity=%TestVerbosity%


:: ############################# end of file ############################ ::

