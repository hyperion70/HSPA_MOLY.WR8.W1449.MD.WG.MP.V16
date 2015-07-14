:: 
::  MT6572_MultiCore_Debug.bat
:: 

@echo off

:SHOW_COMMAND

cls

echo [MT6572 Multi-Core Debugging]
echo [A]ttach only
echo [R]eset and go
echo [M]odem attach only (Default) 

set /p choice=">"

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

goto MODEM_ATTACH_ONLY

:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:: Reset-Go procedure
:: :::::::::::::::::::::::::::::::::::::::::::::: ::

:RESET_GO
echo Reset and go.

echo Starting AP ^(Cortex-A7^) debugger...
start CVD.exe -Multi -Master -CORE=1 MT6572_MultiCore_AP.csf

:: ping 3 s
ping 127.0.0.1 -n 3 -w 1000 > nul

echo [Step 1] Press any key to start MD1 ^(Cortex-R4^) debugger...
start CVD.exe -Multi -Slave -CORE=2 MT6572_MultiCore_MD.csf

goto END

:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:: Attach only procedure
:: :::::::::::::::::::::::::::::::::::::::::::::: ::

:ATTACH_ONLY
echo Attach only.


echo Starting AP ^(Cortex-A7^) debugger...
start CVD.exe -Multi -Master -CORE=1 MT6572_MultiCore_AP_Attach.csf

:: ping 3 s
ping 127.0.0.1 -n 3 -w 1000 > nul

echo Start MD ^(Cortex-R4^) debugger...
start CVD.exe -Multi -Slave -CORE=3 MT6572_MultiCore_MD_Attach.csf

goto END

:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:: Modem attach only procedure
:: :::::::::::::::::::::::::::::::::::::::::::::: ::

:MODEM_ATTACH_ONLY
echo Modem attach only.

echo start MD ^(Cortex-R4^) debugger...
start CVD.exe MT6572_MultiCore_MD.cmm

goto END
    
:END
echo ************************
echo Press any key to start a new debug session...
pause
goto SHOW_COMMAND
