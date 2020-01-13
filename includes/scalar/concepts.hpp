#pragma once

namespace numerics
{
    // TODO ... complex, polynomial & ...
    template <typename T>
    concept Scalar = std::is_arithmetic_v<T>;

    template <typename T>
    concept Integral = std::is_integral_v<T>;

    template <typename T>
    concept Signed = std::is_signed_v<T>;

    template <typename T>
    concept Unsigned = std::is_unsigned_v<T>;

    template <typename T>
    concept FloatingPoint = std::is_floating_point_v<T>;
}