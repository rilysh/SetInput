@Echo off
mkdir x86
gcc -Os -s -m32 SetInput.c -o SetInput.exe 
Copy SetInput.exe x86\
del SetInput.exe
mkdir x64
gcc -Os -s -m64 SetInput.c -o SetInput.exe 
Copy SetInput.exe x64\
del SetInput.exe
echo Done!
Pause
