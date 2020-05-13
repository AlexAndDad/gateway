#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct loom
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
return 11131;
case facing_type::south:
return 11132;
case facing_type::west:
return 11133;
case facing_type::east:
return 11134;
}
}
constexpr static loom from_id(block_id_type id)
{
switch (id)
{
case 11131:
return {.facing = facing_type::north};
case 11132:
return {.facing = facing_type::south};
case 11133:
return {.facing = facing_type::west};
case 11134:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:loom:north";
case facing_type::south:
return "minecraft:loom:south";
case facing_type::west:
return "minecraft:loom:west";
case facing_type::east:
return "minecraft:loom:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
