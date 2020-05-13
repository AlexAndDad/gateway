#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct player_wall_head
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
return 6030;
case facing_type::south:
return 6031;
case facing_type::west:
return 6032;
case facing_type::east:
return 6033;
}
}
constexpr static player_wall_head from_id(block_id_type id)
{
switch (id)
{
case 6030:
return {.facing = facing_type::north};
case 6031:
return {.facing = facing_type::south};
case 6032:
return {.facing = facing_type::west};
case 6033:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:player_wall_head:north";
case facing_type::south:
return "minecraft:player_wall_head:south";
case facing_type::west:
return "minecraft:player_wall_head:west";
case facing_type::east:
return "minecraft:player_wall_head:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
