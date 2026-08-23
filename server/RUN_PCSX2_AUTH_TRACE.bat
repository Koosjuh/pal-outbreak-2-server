@echo off
setlocal

set "PCSX2=C:\dnas\PCSX2\pcsx2-qt.exe"
set "REPORT=C:\dnas\active\tools\collect_pcsx2_run.js"

if not exist "%PCSX2%" (
  echo Missing PCSX2 executable: %PCSX2%
  pause
  exit /b 1
)

powershell -NoProfile -ExecutionPolicy Bypass -Command "$iso = 'C:\dnas\iso\original\Resident Evil - Outbreak - File #2 (Europe) (En,Fr,De,Es,It).iso'; if (-not (Test-Path -LiteralPath $iso)) { exit 2 }"
if errorlevel 2 (
  echo Missing ISO: C:\dnas\iso\original\Resident Evil - Outbreak - File #2 ^(Europe^) ^(En,Fr,De,Es,It^).iso
  pause
  exit /b 1
)

echo.
echo ============================================================
echo  PAL Outbreak File 2 auth trace run
echo ============================================================
echo  Keep START_SERVERS.bat running as Administrator first.
echo  This launches PCSX2 with the PAL ISO and writes the normal
echo  PCSX2 DEV9 log to Documents\PCSX2\logs\emulog.txt.
echo.
echo  After PCSX2 closes, a run report is generated from:
echo    - PCSX2 DEV9/TCP log
echo    - HTTP captures
echo    - SN@P trace logs
echo ============================================================
echo.

powershell -NoProfile -ExecutionPolicy Bypass -Command "$pcsx2 = 'C:\dnas\PCSX2\pcsx2-qt.exe'; $iso = 'C:\dnas\iso\original\Resident Evil - Outbreak - File #2 (Europe) (En,Fr,De,Es,It).iso'; Start-Process -FilePath $pcsx2 -ArgumentList @('-fastboot','--',$iso) -Wait"

echo.
echo Generating run report...
node "%REPORT%" 240
echo.
pause
