#pragma once

namespace numerics
{
    /*sqrt*/
    /* sqrt using Newton-Method */
    template <FloatingPoint T>
    inline constexpr T sqrt_impl(T const t) noexcept
    {
        constexpr T a_half{ 0.5 };
        T next{ 1 };
        T current{};
        do
        {
            current = next;
            next = a_half * (current + t / current);
        }
        while(!approximately_equal(next, current));
        return next;
    }

    template <FloatingPoint T>
    inline constexpr T sqrt(T const t) noexcept
    {
        using limit_t = std::numeric_limits<T>;
        if(t < 0 || is_nan(t))
            return limit_t::quiet_NaN();
        else if(is_inf(t))
            return limit_t::infinity();
        else if(approximately_equal(t, T{ 1 }) || approximately_equal(t, T{ 0 }))
            return t;
        else
            return sqrt_impl(t);
    }

    template <Integral T>
    inline constexpr T sqrt(T const t) noexcept
    {
        return sqrt(static_cast<double>(t));
    }
}