//
// Created by rhodges on 07/05/2020.
//

#include "integral_array.hpp"

namespace minecraft::nbt
{
    template struct integral_array<tag_type::Byte>;
    template struct integral_array<tag_type::Int>;
    template struct integral_array<tag_type::Long>;
}