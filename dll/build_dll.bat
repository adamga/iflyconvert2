@echo off
REM Build script for iflycli_dll.dll

REM Ensure you are running from a Visual Studio Developer Command Prompt

setlocal
set DLL_SRC=iflycli_dll.cpp
set DLL_NAME=iflycli_dll.dll
set CLI_INC=../ifly_cli
set CLI_CMD_INC=../ifly_cli/commands

REM Compile the DLL
cl /LD %DLL_SRC% /I%CLI_INC% /I%CLI_CMD_INC% /Fe:%DLL_NAME% user32.lib kernel32.lib

if %ERRORLEVEL% NEQ 0 (
    echo Build failed!
    exit /b %ERRORLEVEL%
) else (
    echo Build succeeded: %DLL_NAME%
)
endlocal
