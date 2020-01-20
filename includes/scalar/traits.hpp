#pragma once

namespace numerics
{
    template <typename T> requires (sizeof(T) <= 4 && Integral<T>)
    inline constexpr float make_float(T) noexcept;

    template <typename T> requires (sizeof(T) >= 8 && Integral<T>)
    inline constexpr double make_float() noexcept;

    template <FloatingPoint T>
    inline constexpr T make_float(T) noexcept;

    template <SignedIntegral N>
    inline constexpr auto make_unsigned(N n) noexcept
    {
        return static_cast<std::make_unsigned_t<N>>(n);
    }

    template <UnsignedIntegral N>
    inline constexpr auto make_signed(N n) noexcept
    {
        return static_cast<std::make_signed_t<N>>(n);
    }
}