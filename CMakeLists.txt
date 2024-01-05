cmake_minimum_required(VERSION 3.27)
project(AVL_local)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
include_directories(include)

add_executable(AVL_local
        libsrc/Nodo.cpp
        libsrc/AVL.cpp
        include/Nodo.h
        include/AVL.h)
