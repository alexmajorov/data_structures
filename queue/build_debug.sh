#!/bin/bash

clang++ -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -O0 -g --coverage -c main.cpp
clang++ -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -O0 -g --coverage -c queue.cpp
clang++ -o app.exe --coverage main.o queue.o