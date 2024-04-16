#!/bin/bash

clang++ -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wno-unused-result -O2 -c main.cpp
clang++ -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wno-unused-result -O2 -c hash_table_chaining.cpp
clang++ -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wno-unused-result -O2 -c hash_table_double_hashing.cpp
clang++ -o app.exe main.o hash_table_chaining.o hash_table_double_hashing.o