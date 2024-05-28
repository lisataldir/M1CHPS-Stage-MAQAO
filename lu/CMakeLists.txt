cmake_minimum_required(VERSION 3.16)
project(maqao LANGUAGES C DESCRIPTION "lu")

set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-g")

add_executable(main src/main.c src/lu.c)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)