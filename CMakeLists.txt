cmake_minimum_required(VERSION 3.21)
project(sem2_hw6)

add_subdirectory(testing)
add_subdirectory(lib)
set(CMAKE_CXX_STANDARD 14)

add_executable(sem2_hw6 main.cpp lib/polynomial.h)
target_include_directories(sem2_hw6 PUBLIC lib)
target_include_directories(testing PUBLIC lib)
