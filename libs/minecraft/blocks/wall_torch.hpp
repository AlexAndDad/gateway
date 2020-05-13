#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct wall_torch
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
return 1435;
case facing_type::south:
return 1436;
case facing_type::west:
return 1437;
case facing_type::east:
return 1438;
}
}
constexpr static wall_torch from_id(block_id_type id)
{
switch (id)
{
case 1435:
return {.facing = facing_type::north};
case 1436:
return {.facing = facing_type::south};
case 1437:
return {.facing = facing_type::west};
case 1438:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:wall_torch:north";
case facing_type::south:
return "minecraft:wall_torch:south";
case facing_type::west:
return "minecraft:wall_torch:west";
case facing_type::east:
return "minecraft:wall_torch:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
