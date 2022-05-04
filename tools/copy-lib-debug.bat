@echo off

cd ../
set currentPath=%cd%

set demoIncludeDir=demo\libs\include
set demoLibDir=demo\libs\lib

set lib4gIncludeDir=lib4g\src
set lib4gLibDir=lib4g\x64\Debug

set includeFile=lib4g.hpp
set libFile=lib4g.lib

:: Remove old files library inside demo project
del "%currentPath%\%demoIncludeDir%\%includeFile%"
del "%currentPath%\%demoLibDir%\%libFile%"

:: Copy new files library to demo project
xcopy /Y "%currentPath%\%lib4gIncludeDir%\%includeFile%" "%currentPath%\%demoIncludeDir%"
xcopy /Y "%currentPath%\%lib4gLibDir%\%libFile%" "%currentPath%\%demoLibDir%"
