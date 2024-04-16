@echo off

call "D:\Programs\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
cl -Zi main.cpp hash_table_chaining.cpp hash_table_double_hashing.cpp 
devenv main.exe