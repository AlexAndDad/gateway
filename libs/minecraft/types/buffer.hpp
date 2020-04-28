//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "minecraft/to_json.hpp"
#include <vector>
#include "minecraft/span.hpp"

namespace minecraft
{
    using mutable_buffer_element  = char;
    using mutable_buffer_iterator = mutable_buffer_element *;

    using const_buffer_element  = char const;
    using const_buffer_iterator = const_buffer_element *;

    using compose_buffer = std::vector< mutable_buffer_element >;

    inline auto to_span(compose_buffer const &buf)
    {
        auto first = buf.data();
        auto last  = first + buf.size();
        return const_byte_span(first, last);
    }

};   // namespace minecraft