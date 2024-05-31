cmake_minimum_required(VERSION 3.16)
project(maqao LANGUAGES C DESCRIPTION "LU Decomposition")

set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-g -fopenmp")

find_package(LAPACK REQUIRED)
find_package(BLAS REQUIRED)
find_library(LAPACKE_LIBRARY lapacke REQUIRED)

add_executable(main src/main.c src/lu.c)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(main PRIVATE ${LAPACKE_LIBRARY} ${LAPACK_LIBRARIES} ${BLAS_LIBRARIES} m)
