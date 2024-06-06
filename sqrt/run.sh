#!/bin/bash

gcc -o sqrt main.c -I./mylib -L./mylib -la -lb -lm
export LD_LIBRARY_PATH=./mylib 

maqao OV -R1 external_libraries=mylib/libb.so -- ./sqrt 500000000