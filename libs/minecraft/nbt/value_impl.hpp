#pragma once

#include "minecraft/nbt/fundamental.hpp"
#include "minecraft/nbt/parse_context.hpp"
#include "minecraft/print.hpp"
#include "minecraft/types/buffer.hpp"
#include "minecraft/variant.hpp"

namespace minecraft::nbt
{
    using value_impl_variant = variant<empty, nvp>;

    struct value_impl
    {
        value_impl_variant var;
    };

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, value_impl &value, parse_context &ctx);

    void pretty_print(std::string &os, value_impl const &vi, const_buffer_iterator storage, std::size_t depth = 0);

}   // namespace minecraft::nbt