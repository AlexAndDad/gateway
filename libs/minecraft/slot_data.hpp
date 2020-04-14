//
// Created by rhodges on 14/04/2020.
//

#pragma once

#include "minecraft/encode.hpp"
#include "minecraft/nbt.hpp"
#include "minecraft/types.hpp"

#include <iostream>
#include <optional>

namespace minecraft
{
    struct slot_data
    {
        var_int      item_id;
        std::uint8_t count;
        nbt::value   nbt_data;

        template < class Self >
        static auto as_tuple(Self &self)
        {
            return std::tie(self.item_id, self.count, self.nbt_data);
        }
    };

    template < class Iter >
    Iter encode(slot_data const &arg, Iter iter)
    {
        iter = encode(arg.item_id, iter);
        iter = encode(arg.count, iter);
        iter = encode(arg.nbt_data, iter);
        return iter;
    }

    template < class Iter >
    Iter parse(Iter first, Iter last, slot_data &arg, error_code &ec)
    {
        return parse(first, last, slot_data::as_tuple(arg), ec);
    }

    using optional_slot_data = std::optional< slot_data >;

}   // namespace minecraft
