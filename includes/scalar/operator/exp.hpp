#pragma once


namespace numerics
{

    namespace detail
    {
        template <typename T, UnsignedIntegral N>
        inline constexpr auto basic_exp(T const base, N n) noexcept -> decltype(make_float(n))
        {
            using result_type = decltype(make_float(n));
            result_type x = static_cast<result_type>(base);
            if(n == 0)
            {
                return static_cast<result_type>(1);
            }
            else if(base == T{ 0 } || approximately_equal(x, result_type{ 0 }))
            {
                return result_type{ 0 };
            }
            else
            {
                result_type y = static_cast<result_type>(1);
                result_type x = static_cast<result_type>(base);
                while(n > 1)
                {
                    if(is_even(n))
                    {
                        x *= x;
                        n /= 2;
                    }
                    else
                    {
                        y *= x;
                        x *= x;
                        n = (n - 1) / 2;
                    }
                }

                return x * y;
            }
        }

        template <typename T, SignedIntegral N>
        inline constexpr auto basic_exp(T base, N n) noexcept -> decltype(make_float(base))
        {
            using result_type = decltype(make_float(base));

            if(n < 0)
            {
                constexpr result_type zero{ 0 };
                if(base == zero)
                {
                    return zero;
                }
                else
                {
                    return result_type{ 1.0 } / basic_exp(static_cast<result_type>(base), make_unsigned(-n));
                }
            }
            else
            {
                return basic_exp(base, make_unsigned(n));
            }
        }
    }

    template <typename T, Integral N>
    inline constexpr auto exp(T base, N component)
    {
        return detail::basic_exp(base, component);
    }
}
