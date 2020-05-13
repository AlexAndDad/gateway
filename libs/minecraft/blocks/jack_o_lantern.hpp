#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jack_o_lantern
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
return 4006;
case facing_type::south:
return 4007;
case facing_type::west:
return 4008;
case facing_type::east:
return 4009;
}
}
constexpr static jack_o_lantern from_id(block_id_type id)
{
switch (id)
{
case 4006:
return {.facing = facing_type::north};
case 4007:
return {.facing = facing_type::south};
case 4008:
return {.facing = facing_type::west};
case 4009:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:jack_o_lantern:north";
case facing_type::south:
return "minecraft:jack_o_lantern:south";
case facing_type::west:
return "minecraft:jack_o_lantern:west";
case facing_type::east:
return "minecraft:jack_o_lantern:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
