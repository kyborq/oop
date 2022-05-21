@echo off

set PROGRAM="%~1"

set OUT="%TEMP%\output.txt"
set TEST=Tests\

:: Тест №1
%PROGRAM% %TEST%\Valid.txt %TEST%\Valid-output.txt > %OUT% || goto err
fc %OUT% ".\Tests\Valid-output.txt" || goto err

:: Тест №2
rem %PROGRAM% < input.txt > %OUT% || goto err
rem fc %OUT% output.txt || goto err


echo Testing OK
exit /B 0

:err
echo Program testing failed
exit /B 1