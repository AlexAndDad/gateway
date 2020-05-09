//
// Created by rhodges on 07/05/2020.
//

#include "integral_array.hpp"

namespace minecraft::nbt
{
    template struct integral_array<std::int8_t>;
    template struct integral_array<std::int32_t>;
    template struct integral_array<std::int64_t>;
}