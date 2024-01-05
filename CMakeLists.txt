cmake_minimum_required(VERSION 3.27)
project(AVL_local)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(AVL_testapp
        main.cpp
        include/AVL.h
)
add_library(Nodo libsrc/Nodo.cpp include/Nodo.h)
add_library(AVL libsrc/AVL.cpp include/AVL.h)

target_link_libraries(AVL Nodo)
target_link_libraries(AVL_testapp AVL)
