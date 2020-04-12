#include "packet_id.hpp"
#include <string>
#include <vector>

namespace minecraft {

    template<class Iter>
    Iter encode(std::int32_t in, Iter first)
    {
        auto value = static_cast<std::uint32_t>(in);
        do
        {
            auto b = static_cast<std::uint8_t>(value & 0x7f);
            value >>= 7;
            if (value != 0)
                b |= 0x80;
            *first++ = b;
        } while(value);
        return first;
    }

    template<class Enum, class Iter>
    auto encode(Enum in, Iter first)
    -> std::enable_if_t<std::is_enum_v<Enum>, Iter>
    {
        return encode(static_cast<std::underlying_type_t <Enum>>(in), first);
    }

    template<class Iter>
    Iter encode(std::string const& in, Iter first)
    {
        auto len = static_cast<std::int32_t>(in.size());
        first = encode(len, first);
        first = std::copy(in.begin(), in.end(), first);
        return first;
    }

    template<class Iter>
    Iter encode(std::vector<std::uint8_t> const& in, Iter first)
    {
        auto len = static_cast<std::int32_t>(in.size());
        first = encode(len, first);
        first = std::copy(in.begin(), in.end(), first);
        return first;
    }

}