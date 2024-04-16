#!/bin/bash

clang++ -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -O0 -g --coverage -c main.cpp
clang++ -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -O0 -g --coverage -c io.cpp
clang++ -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -O0 -g --coverage -c sorts.cpp
clang++ -o app.exe --coverage main.o sorts.o io.o