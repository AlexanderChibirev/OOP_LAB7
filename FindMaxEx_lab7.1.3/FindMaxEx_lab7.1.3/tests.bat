rem echo off
SET program="%1"

echo incorrect growth
%program% "input1.txt" > result1.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b result1.txt standard/result1.txt
IF ERRORLEVEL 1 GOTO testFailed

echo incorrect weight
%program% "input2.txt" > result2.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b result2.txt standard/result2.txt
if ERRORLEVEL 1 goto testFailed

echo  incorrect input file
%program% "input3.txt" > result3.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b result3.txt standard/result3.txt
if ERRORLEVEL 1 goto testFailed

echo correct file
%program% "input4.txt" > result4.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b result3.txt standard/result4.txt
if ERRORLEVEL 1 goto testFailed

echo OK
pause 
exit /B

:testFailed
ECHO Testing failed
pause
exit /B

pause