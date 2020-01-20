#include <iostream>

#include "includes/scalar.hpp"

int main()
{
    static_assert(!numerics::is_nan(1, 2, 3, 4, 5));
    static_assert(numerics::approximately_equal(numerics::sqrt(4.0), 2.0));
    static_assert(std::is_signed_v<float>);
    static_assert(numerics::approximately_equal(numerics::exp(0.1, -2), 100.0, 0.00001));

    return 0;
}
