@echo off
cmake -S . -B build
cd build

for %%f in (./*.sln) do (
     if exist %%f (
        echo:
        echo File to build %%f
        echo:
        msbuild %%f -p:Configuration=Debug
        goto :final
     )
)

:final
cd Debug

echo:
echo ---------- Ready to run ----------