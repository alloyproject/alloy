@echo off

mkdir build
del /s /q build
cd build

if "%1"=="dyn" goto :dyn
echo Static Build
cmake.exe -G  "Visual Studio 14 2015 Win64"  ..
msbuild Alloy.sln /p:Configuration=Release


EXIT /B 



:dyn
echo Dynamic Build
cmake.exe -G  "Visual Studio 14 2015 Win64"  -DSTATIC=NO  ..
msbuild Alloy.sln /p:Configuration=Release

echo Copying libs
del /s /q \opt\alloy\libs
md \opt\alloy\libs
for /r "\opt\alloy" %%x in (*.lib) do copy "%%x" "\opt\alloy\libs"

 

