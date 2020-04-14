#pragma once

#include "boost/operators.hpp"
#include "minecraft/encode.hpp"
#include "minecraft/nbt/tags.hpp"
#include "minecraft/parse.hpp"

namespace minecraft::nbt
{
    struct nbt_end : boost::equality_comparable< nbt_end >
    {
        static constexpr auto id() { return nbt::nbt_tag::TAG_end; }

        constexpr auto operator==(nbt_end const &) const { return true; }

        friend std::ostream& operator<<(std::ostream& os, nbt_end const& arg)
        {
            os << wise_enum::to_string(arg.id());
            return os;
        }
    };

    template < class Iter >
    Iter encode(nbt_end const &arg, Iter iter)
    {
        using minecraft::encode;
        return encode(arg.id(), iter);
    }

    template < class Iter >
    Iter parse(Iter first, Iter last, nbt_end &arg, error_code &ec)
    {
        ec.clear();
        return first;
    }

}   // namespace minecraft::nbt
