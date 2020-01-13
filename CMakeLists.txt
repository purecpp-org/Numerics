cmake_minimum_required(VERSION 3.15)
project(Numerics)

set(CMAKE_CXX_STANDARD 20)

add_executable(Numerics main.cpp includes/scalar/operand.hpp includes/scalar/operator.hpp includes/scalar.hpp includes/scalar/concepts.hpp)