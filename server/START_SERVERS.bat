@echo off
:: PAL Outbreak File #2 — one-click server launcher
:: Requires Administrator (ports 53, 80, 443).

:: Self-elevate if not already admin
net session >nul 2>&1
if %errorLevel% NEQ 0 (
    echo Requesting Administrator...
    powershell -Command "Start-Process '%~f0' -Verb RunAs"
    exit /b
)

title Outbreak PAL Server Stack
color 17

cd /d "%~dp0server"

echo.
echo ============================================================
echo   RESIDENT EVIL OUTBREAK FILE #2  --  PAL SERVER STACK
echo ============================================================
echo.

where node >nul 2>&1
if %errorLevel% NEQ 0 (
    echo ERROR: Node.js not found. Install Node.js and try again.
    pause
    exit /b 1
)

:: 2026-06-04: Real-PS2 regression test — disable all 2026-06-03 defaults-on features.
:: If real PS2 now renders lobby, one of these was the regression.
set SNAP_PINE_AUTO_ADVANCE=0
set SNAP_POST_LOBBY_PUSH=0
set SNAP_POST_OP48_PUSH=0
set SNAP_LOBBY_ENTRY_DUMP=0
set SNAP_AUTO_INSPECT=0
:: Send word0=0 in named-slot-query reply (was 0xFFFF default — suspected D901 cause)
set SNAP_NAMEDSLOT_WORD0=0
node start_all.js

echo.
echo Server exited. Press any key to close.
pause >nul
