cmake_minimum_required(VERSION 3.31)
project(esamelabanas)

set(CMAKE_CXX_STANDARD 20)

add_executable(esamelabanas main.cpp
        Transazione.cpp
        Transazione.h
        ContoCorrente.cpp
        ContoCorrente.h)
add_subdirectory(test)