#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dragon_wall_head
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
return 6070;
case facing_type::south:
return 6071;
case facing_type::west:
return 6072;
case facing_type::east:
return 6073;
}
}
constexpr static dragon_wall_head from_id(block_id_type id)
{
switch (id)
{
case 6070:
return {.facing = facing_type::north};
case 6071:
return {.facing = facing_type::south};
case 6072:
return {.facing = facing_type::west};
case 6073:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:dragon_wall_head:north";
case facing_type::south:
return "minecraft:dragon_wall_head:south";
case facing_type::west:
return "minecraft:dragon_wall_head:west";
case facing_type::east:
return "minecraft:dragon_wall_head:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
