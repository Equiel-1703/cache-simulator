@echo off
cmake -S . -B build
cd build

:: Pega o primeiro arquivo .sln (que é o único que interessa) e compila usando o msbuild
:: [cmake in Windows] https://stackoverflow.com/questions/9878225/using-cmake-on-windows-for-c
:: [% vs %% in batch] https://jeffpar.github.io/kbarchive/kb/075/Q75634/
:: [% vs %% in batch] https://stackoverflow.com/questions/14509652/what-is-the-difference-between-and-in-a-cmd-file

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