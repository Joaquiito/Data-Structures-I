# cmake_minimum_required(VERSION <specify CMake version here>)
project(P1_Grupo3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(P1_Grupo3
        LSO.h
        LSOBT.h
        main.c
        Vendedor.h)
