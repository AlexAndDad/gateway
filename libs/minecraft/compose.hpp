#pragma once

#include<vector>
#include "minecraft/encode.hpp"

namespace minecraft
{
    inline void compose(std::vector< char > const &source, std::vector< char > &target)
    {
        target.reserve(target.size() + source.size() + 5);
        auto len = std::int32_t(source.size());
        encode(variable_length(len), std::back_inserter(target));
        target.insert(target.end(), source.begin(), source.end());
    }

}   // namespace minecraft