@echo off
set PROGRAM="%~1"

rem проверяем одинаковые файлы
%PROGRAM% equal_files_1.txt equal_files_2.txt
if NOT ERRORLEVEL 1 goto err

rem проверяем файл с малым количеством строк с большим
%PROGRAM% lines_less.txt lines_more.txt
if NOT ERRORLEVEL 1 goto err

rem проверяем файл с большим количеством строк с малым
%PROGRAM% lines_more.txt lines_less.txt
if NOT ERRORLEVEL 1 goto err

rem проверяем одинаковые файлы с ошибкой в одной из строк
%PROGRAM% equal_with_mistake_1.txt equal_with_mistake_2.txt
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1