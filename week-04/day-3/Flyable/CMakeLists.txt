cmake_minimum_required(VERSION 3.13)
project(Flyable)

set(CMAKE_CXX_STANDARD 14)

add_executable(Flyable main.cpp animal.cpp flyable.cpp flyable.h vehicle.cpp vehicle.h helicopter.cpp helicopter.h bird.cpp bird.h)