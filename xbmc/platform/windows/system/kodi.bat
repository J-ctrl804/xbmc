@echo off
REM Start Kodi

REM Check if Kodi is already running
tasklist /FI "IMAGENAME eq kodi.exe" 2>NUL | find /I /N "kodi.exe">NUL
if "%ERRORLEVEL%"=="0" (
    echo Kodi is already running
    exit /b 1
)

REM Start Kodi
start "" "C:\Program Files\Kodi\kodi.exe"
