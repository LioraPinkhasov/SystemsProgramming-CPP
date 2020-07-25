cmake_minimum_required(VERSION 3.16)
project(PhoneticSearch)

set(CMAKE_CXX_STANDARD 20)

add_executable(PhoneticSearch Demo.cpp PhoneticFinder.hpp PhoneticFinder.cpp)