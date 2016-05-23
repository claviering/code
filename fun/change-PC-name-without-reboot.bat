echo off
color a
set /p dd=input you PC name: 
set pcname=%dd%
::修改主机名
echo.

set regpth1=HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\ComputerName\ComputerName
set regpth2=HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters
set regpth3=HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\ComputerName\ActiveComputerName
reg add %regpth1% /v ComputerName /d %pcname% /f>nul
reg add %regpth2% /v "NV Hostname" /d %pcname% /f>nul
reg add %regpth2% /v Hostname /d %pcname% /f>nul
reg add %regpth3% /v ComputerName /d %pcname% /f>nul

echo set regpth1=HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\ComputerName\ComputerName
echo set regpth2=HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters
echo set regpth3=HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\ComputerName\ActiveComputerName
echo "reg add %regpth1% /v ComputerName /d %pcname% /f>nul"
echo "reg add %regpth2% /v "NV Hostname" /d %pcname% /f>nul"
echo "reg add %regpth2% /v Hostname /d %pcname% /f>nul"
echo "reg add %regpth3% /v ComputerName /d %pcname% /f>nul"

echo. 

echo you pc name is
hostname

echo.

pause