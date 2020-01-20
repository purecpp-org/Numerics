cmake_minimum_required(VERSION 3.15)
project(Numerics)

set(CMAKE_CXX_STANDARD 20)

add_executable(Numerics main.cpp
        includes/scalar/operand.hpp
        includes/scalar/operator.hpp
        includes/scalar/concepts.hpp
        includes/scalar.hpp
        includes/scalar/operator/common.hpp
        includes/scalar/operator/sqrt.hpp
        includes/scalar/operator/exp.hpp
        includes/scalar/traits.hpp)