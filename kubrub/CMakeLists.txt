cmake_minimum_required(VERSION 3.21)
project(kubrub)

set(CMAKE_CXX_STANDARD 17)

add_executable(kubrub main.cpp CubeRubik.h SmallCube.h)
