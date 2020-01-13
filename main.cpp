#include <iostream>

#include "includes/scalar.hpp"

int main()
{
    static_assert(!numerics::is_nan(1, 2, 3, 4, 5));
    static_assert(numerics::approximately_equal(numerics::sqrt(4.0), 2.0));

    return 0;
}
