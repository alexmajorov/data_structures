#!/bin/bash

clang++ -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -O0 -g --coverage -c main.cpp
clang++ -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -O0 -g --coverage -c hash_table_chaining.cpp
clang++ -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -O0 -g --coverage -c hash_table_double_hashing.cpp
clang++ -o app.exe --coverage main.o hash_table_chaining.o hash_table_double_hashing.o