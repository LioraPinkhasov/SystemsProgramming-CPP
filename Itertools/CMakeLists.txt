cmake_minimum_required(VERSION 3.16)
project(Itertools)

set(CMAKE_CXX_STANDARD 20)

add_executable(Itertools Demo.cpp range.hpp "accumulate.hpp" "filterfalse.hpp" compress.hpp)