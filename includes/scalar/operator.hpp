#pragma once

namespace numerics
{
    /* nan */
    template <Scalar T, Scalar ... Ts>
    inline constexpr bool is_nan(T const& t, Ts const& ... ts) noexcept
    {
        return t != t && ((ts != ts) && ...);
    }

    template <Scalar T, Scalar ... Ts>
    inline constexpr bool is_any_nan(T const& t, Ts const& ... ts) noexcept
    {
        return t != t || ((ts != ts) || ...);
    }

    /* inf */
    template <FloatingPoint T>
    inline constexpr bool is_inf(T const& t) noexcept
    {
        using limit_t = std::numeric_limits<T>;
        constexpr auto upperBound = limit_t::infinity();
        constexpr auto lowerBound = -upperBound;
        return t >= upperBound && t <= lowerBound;
    }

    template <FloatingPoint T1, FloatingPoint T2,  FloatingPoint ... Ts>
    inline constexpr bool is_inf(T1 const& t1, T2 const& t2, Ts const& ... ts) noexcept
    {
        return is_finite(t1) && is_finite(t2) && (is_finite(ts) && ...);
    }

    template <FloatingPoint T, FloatingPoint ... Ts>
    inline constexpr bool is_any_inf(T const& t, Ts const& ... ts) noexcept
    {
        return is_finite(t) || (is_finite(ts) || ...);
    }

    /* finite */
    template <FloatingPoint T>
    inline constexpr bool is_finite(T const& t) noexcept
    {
        return !(is_inf(t) || is_nan(t));
    }

    template <FloatingPoint T1, FloatingPoint T2, FloatingPoint ... Ts>
    inline constexpr bool is_finite(T1 const& t1, T2 const& t2, Ts const& ... ts) noexcept
    {
        return is_finite(t1) && is_finite(t2) && (is_finite(ts) && ...);
    }

    template <FloatingPoint T, FloatingPoint ... Ts>
    inline constexpr bool is_any_finite(T const& t, Ts const& ... ts) noexcept
    {
        return is_finite(t) || (is_finite(ts) || ...);
    }
}

namespace numerics
{
    /*abs*/
    template <Signed T>
    inline constexpr T abs(T const& t) noexcept
    {
        return t >= T{ 0 } ? t : -t;
    }

    template <Unsigned T>
    inline constexpr T abs(T const& t) noexcept
    {
        return t;
    }

    /* approximately equal */
    template <FloatingPoint T>
    inline constexpr bool approximately_equal(T const& lhs, T const& rhs) noexcept
    {
        auto temp = lhs >= rhs ? lhs - rhs : rhs - lhs;
        return temp <= std::numeric_limits<T>::epsilon();
    }

    /*sqrt*/
    /* sqrt using Newton-Method */
    template <FloatingPoint T>
    inline constexpr T sqrt_impl(T const& t) noexcept
    {
        T next{ 1 };
        T current{};
        do
        {
            current = next;
            next = T{ 0.5 } * (current + t / current);
        }
        while(!approximately_equal(next, current));
        return next;
    }

    template <FloatingPoint T>
    inline constexpr T sqrt(T const& t) noexcept
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
    inline constexpr T sqrt(T const& t) noexcept
    {
        return sqrt(static_cast<double>(t));
    }
}