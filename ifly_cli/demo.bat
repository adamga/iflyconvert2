@echo off
REM iFly CLI Demo Script
REM This script demonstrates various capabilities of the iFly CLI tool

echo ============================================
echo iFly 737 MAX 8 CLI Demonstration
echo ============================================
echo.

REM Check if CLI tool exists
if not exist "ifly_cli.exe" (
    echo Error: ifly_cli.exe not found!
    echo Please build the tool first using build.bat
    pause
    exit /b 1
)

echo 1. Testing connection to iFly 737 MAX 8...
ifly_cli.exe connect
echo.

echo 2. Listing available commands...
ifly_cli.exe list
echo.

echo 3. Getting help for a specific command...
ifly_cli.exe help landing_light_1
echo.

echo 4. Demonstrating lighting controls...
echo Setting landing lights to ON...
ifly_cli.exe set landing_light_1 on
ifly_cli.exe set landing_light_2 on

echo Setting taxi light to ON...
ifly_cli.exe set taxi_light on

echo Setting logo light to ON...
ifly_cli.exe set logo_light on

echo Setting anti-collision light to ON...
ifly_cli.exe set anti_collision_light on

echo.
echo 5. Checking current light states...
ifly_cli.exe get landing_light_1
ifly_cli.exe get landing_light_2
ifly_cli.exe get taxi_light

echo.
echo 6. Demonstrating air system controls...
echo Setting engine bleeds to ON...
ifly_cli.exe set engine_1_bleed on
ifly_cli.exe set engine_2_bleed on

echo Setting packs to AUTO...
ifly_cli.exe set pack_1 auto
ifly_cli.exe set pack_2 auto

echo.
echo 7. Demonstrating anti-ice controls...
echo Setting wing anti-ice to ON...
ifly_cli.exe set wing_anti_ice on

echo Setting engine anti-ice to ON...
ifly_cli.exe set engine_1_anti_ice on
ifly_cli.exe set engine_2_anti_ice on

echo.
echo 8. Turning off all lights (cleanup)...
ifly_cli.exe set landing_light_1 off
ifly_cli.exe set landing_light_2 off
ifly_cli.exe set taxi_light off
ifly_cli.exe set logo_light off
ifly_cli.exe set anti_collision_light off

echo.
echo ============================================
echo Demo completed!
echo ============================================
echo.
echo The iFly CLI tool has demonstrated:
echo - Connection testing
echo - Command listing
echo - Help system
echo - Light controls
echo - Air system controls  
echo - Anti-ice controls
echo - State querying
echo.
echo Try running individual commands:
echo   ifly_cli.exe help
echo   ifly_cli.exe list
echo   ifly_cli.exe set landing_light_1 on
echo   ifly_cli.exe get landing_light_1
echo.
pause
