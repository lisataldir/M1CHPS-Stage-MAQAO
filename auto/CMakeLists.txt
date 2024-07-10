cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_COMPILER "gcc")
project(Initialisation)

set(CMAKE_C_FLAGS "-g -O3 -march=native -grecord-gcc-switches")

add_executable(init src/main.c src/init.c)
target_include_directories(init PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)