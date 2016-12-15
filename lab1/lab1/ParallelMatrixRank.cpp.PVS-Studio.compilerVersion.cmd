@ECHO OFF
set PATH=%PATH%;C:\WINDOWS\system32
@call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\vcvars32.bat" > nul
@ECHO ON
@call cl.exe