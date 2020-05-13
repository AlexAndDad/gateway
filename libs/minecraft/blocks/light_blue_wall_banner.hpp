#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct light_blue_wall_banner
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
return 7629;
case facing_type::south:
return 7630;
case facing_type::west:
return 7631;
case facing_type::east:
return 7632;
}
}
constexpr static light_blue_wall_banner from_id(block_id_type id)
{
switch (id)
{
case 7629:
return {.facing = facing_type::north};
case 7630:
return {.facing = facing_type::south};
case 7631:
return {.facing = facing_type::west};
case 7632:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:light_blue_wall_banner:north";
case facing_type::south:
return "minecraft:light_blue_wall_banner:south";
case facing_type::west:
return "minecraft:light_blue_wall_banner:west";
case facing_type::east:
return "minecraft:light_blue_wall_banner:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
