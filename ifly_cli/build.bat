@echo off
echo Building iFly CLI Tool...

REM Check if Visual Studio Build Tools are available
where cl >nul 2>nul
if %errorlevel% neq 0 (
    echo Error: Visual Studio Build Tools not found.
    echo Please run this from a Visual Studio Developer Command Prompt or install Visual Studio Build Tools.
    pause
    exit /b 1
)

REM Build the CLI tool
echo Compiling...
cl /std:c++17 /EHsc /W3 /DWIN32_LEAN_AND_MEAN /DNOMINMAX /I"." /I"../737MAX_SDK" /I"../737MAX_SDK/sdk" main.cpp /Feifly_cli.exe /link user32.lib kernel32.lib

if %errorlevel% neq 0 (
    echo Build failed!
    pause
    exit /b 1
)

REM Copy to parent directory for easier access
echo Copying to parent directory...
copy ifly_cli.exe ..

REM Cleanup object files
del *.obj 2>nul

echo.
echo Build successful! 
echo The ifly_cli.exe has been created and copied to the parent directory.
echo.
echo Usage examples:
echo   ifly_cli.exe help
echo   ifly_cli.exe list
echo   ifly_cli.exe connect
echo   ifly_cli.exe set landing_light_1 on
echo.
pause
