set PROGRAM="%~1"

rem проверяем одинаковые файлы
%PROGRAM% equal_files_1.txt equal_files_2.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1