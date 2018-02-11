@echo off
mkdir build
del /s /q build
cd build
"C:\Program Files\CMake\bin\cmake.exe" -G  "Visual Studio 14 2015 Win64"  ..

msbuild Alloy.sln /p:Configuration=Release


