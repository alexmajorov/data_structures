#!/bin/bash

clang++ -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wno-unused-result -O2 -c main.cpp
clang++ -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wno-unused-result -O2 -c queue.cpp
clang++ -o app.exe main.o queue.o