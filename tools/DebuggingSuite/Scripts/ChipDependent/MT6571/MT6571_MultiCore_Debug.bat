:: 
::  MT6571_MultiCore_Debug.bat
:: 

@echo off

::SET CVDPath=C:\JnDTech\CVI\CVD\Bin\
SET CVDPath=
:SHOW_COMMAND

cls

echo [MT6571 Multi-Core Debugging]
echo [A]ttach only
echo [R]eset and go
echo [M]odem attach only (Default) 
echo [C]hange CVD.exe path
ECHO [E]xit

set /p choice=">"

IF '%choice%'=='e' (
    GOTO EXIT
)
IF '%choice%'=='E' (
    GOTO EXIT
)
IF '%choice%'=='x' (
    GOTO EXIT
)
IF '%choice%'=='X' (
    GOTO EXIT
)

echo kill all CVD.exe ...
taskkill /IM CVD.exe /F

IF '%choice%'=='a' (
    goto ATTACH_ONLY
)
IF '%choice%'=='A' (
    goto ATTACH_ONLY
)

IF '%choice%'=='r' (
    goto RESET_GO
)
IF '%choice%'=='R' (
    goto RESET_GO
)

IF '%choice%'=='c' (
    goto CHANGE_PATH
)
IF '%choice%'=='C' (
    goto CHANGE_PATH
)

goto MODEM_ATTACH_ONLY

:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:: change CVD.exe path
:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:CHANGE_PATH
echo please input CVD.exe path. For example: "C:\JnDTech\CVI\CVD\Bin\"
set /p CVDPath=">"
echo CVD.exe path have changed to %CVDPath%
goto END

:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:: Reset-Go procedure
:: :::::::::::::::::::::::::::::::::::::::::::::: ::

:RESET_GO
echo Reset and go.

echo Starting AP ^(Cortex-A7^) debugger...
start %CVDPath%CVD.exe -Multi -Master -CORE=1 MT6571_MultiCore_AP.csf

:: ping 3 s
ping 127.0.0.1 -n 3 -w 1000 > nul

echo [Step 1] Press any key to start MD1 ^(Cortex-R4^) debugger...
start %CVDPath%CVD.exe -Multi -Slave -CORE=2 MT6571_MultiCore_MD.csf

goto END

:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:: Attach only procedure
:: :::::::::::::::::::::::::::::::::::::::::::::: ::

:ATTACH_ONLY
echo Attach only.


echo Starting AP ^(Cortex-A7^) debugger...
start %CVDPath%CVD.exe -Multi -Master -CORE=1 MT6571_MultiCore_AP_Attach.csf

:: ping 3 s
ping 127.0.0.1 -n 3 -w 1000 > nul

echo Start MD ^(Cortex-R4^) debugger...
start %CVDPath%CVD.exe -Multi -Slave -CORE=3 MT6571_MultiCore_MD_Attach.csf

goto END

:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:: Modem attach only procedure
:: :::::::::::::::::::::::::::::::::::::::::::::: ::

:MODEM_ATTACH_ONLY
echo Modem attach only.

echo start MD ^(Cortex-R4^) debugger...
start %CVDPath%CVD.exe MT6571_MultiCore_MD.cmm

goto END
    
:END
ECHO ************************
ECHO Press any key to start a new debug session...
PAUSE
SET choice=
GOTO SHOW_COMMAND
:EXIT
ECHO ************************
ECHO Bye~
PAUSE
