@echo off

set currentPath=%cd%
set demoIncludeDir=demo\libraries\include
set demoLibDir=demo\libraries\lib
set lib4gIncludeDir=lib4g\src
set lib4gLibDir=lib4g\x64\Release
set includeFile=lib4g.hpp
set libFile=lib4g.lib

:: Remove old files library inside demo project
del "%currentPath%\%demoIncludeDir%\%includeFile%"
del "%currentPath%\%demoLibDir%\%libFile%"

:: Copy new files library to demo project
xcopy /Y "%currentPath%\%lib4gIncludeDir%\%includeFile%" "%currentPath%\%demoIncludeDir%"
xcopy /Y "%currentPath%\%lib4gLibDir%\%libFile%" "%currentPath%\%demoLibDir%"