#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct white_wall_banner
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
return 7617;
case facing_type::south:
return 7618;
case facing_type::west:
return 7619;
case facing_type::east:
return 7620;
}
}
constexpr static white_wall_banner from_id(block_id_type id)
{
switch (id)
{
case 7617:
return {.facing = facing_type::north};
case 7618:
return {.facing = facing_type::south};
case 7619:
return {.facing = facing_type::west};
case 7620:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:white_wall_banner:north";
case facing_type::south:
return "minecraft:white_wall_banner:south";
case facing_type::west:
return "minecraft:white_wall_banner:west";
case facing_type::east:
return "minecraft:white_wall_banner:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
