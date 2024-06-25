#!/bin/bash

clang -g -o dgemm main.c -I./mylib -L./mylib -la -lb
export LD_LIBRARY_PATH=./mylib 
maqao OV -R1 external_libraries=mylib/libb.so -- ./dgemm 500 20