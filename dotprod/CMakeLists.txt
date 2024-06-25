cmake_minimum_required(VERSION 3.16)
project(maqao LANGUAGES C DESCRIPTION "dotprod")
add_compile_options(-g -O3 -march=native -funroll-loops -fopenmp)

set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CMAKE_C_STANDARD 17)

find_package(MPI REQUIRED)
find_package(OpenMP REQUIRED)

add_executable(dotprod src/main.c src/dotprod.c)
target_include_directories(dotprod PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(dotprod PUBLIC MPI::MPI_C OpenMP::OpenMP_C)