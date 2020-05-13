#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct zombie_wall_head
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
return 6010;
case facing_type::south:
return 6011;
case facing_type::west:
return 6012;
case facing_type::east:
return 6013;
}
}
constexpr static zombie_wall_head from_id(block_id_type id)
{
switch (id)
{
case 6010:
return {.facing = facing_type::north};
case 6011:
return {.facing = facing_type::south};
case 6012:
return {.facing = facing_type::west};
case 6013:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:zombie_wall_head:north";
case facing_type::south:
return "minecraft:zombie_wall_head:south";
case facing_type::west:
return "minecraft:zombie_wall_head:west";
case facing_type::east:
return "minecraft:zombie_wall_head:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
