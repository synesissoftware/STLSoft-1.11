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
    IF EXIST "%~dp0.sis\script_info_lines.txt" (
      type "%~dp0.sis\script_info_lines.txt"
    )
    ECHO ^

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

