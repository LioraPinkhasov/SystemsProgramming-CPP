cmake_minimum_required(VERSION 3.16)
project(Solver)

set(CMAKE_CXX_STANDARD 20)

add_executable(Solver Demo.cpp solver.hpp solver.cpp )