#pragma once

#include <cstdint>
#include <bitset>

namespace polyfill::bitset_tools
{
    template < std::size_t bits >
    auto signedBS_to_signed32(std::bitset< bits > bitset) -> std::enable_if_t< bits <= 32, std::int32_t >
    {
        auto result = static_cast< std::uint32_t >(bitset.to_ulong());
        if (result & (1 << (bits - 1)))   // Sign extend the result if needed
        {
            std::uint32_t mask = ~0;
            mask <<= bits;
            result |= mask;
        }
        return static_cast<std::int32_t>(result);
    }

}   // namespace polyfill::bitset_tools