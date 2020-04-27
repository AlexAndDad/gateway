//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once

#include "minecraft/types.hpp"

#include <algorithm>
#include <array>
#include <bitset>

namespace minecraft::utils
{
    void base64_encode(const_buffer_iterator first, const_buffer_iterator last, compose_buffer &target, char pad = '=');

}   // namespace minecraft::utils
