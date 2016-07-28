REM x64dbg Plugin SDK for JWasm64
REM Copies the *.lib files to \JWasm\Lib\x64 and *.inc files to \JWasm\Include folder
REM
@ECHO OFF
ECHO x64dbg Plugin SDK for JWasm64
ECHO.
ECHO Installing files...

Copy ..\pluginsdk\*.lib \JWasm\lib\x64\ /Y > NUL
Copy ..\pluginsdk\*.inc \JWasm\Include\ /Y > NUL
ECHO Finished.
PAUSE
EXIT