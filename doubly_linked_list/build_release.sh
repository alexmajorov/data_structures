#!/bin/bash

clang++ -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wno-unused-result -O2 -c main.cpp
clang++ -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wno-unused-result -O2 -c linked_list.cpp
clang++ -o app.exe main.o linked_list.o