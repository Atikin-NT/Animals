cmake_minimum_required(VERSION 3.21)
project(Animals)

set(CMAKE_CXX_STANDARD 17)

add_executable(Animals main.cpp Animal.h animal.cpp Zoo.h zoo.cpp IException.cpp IException.h)
