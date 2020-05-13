#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct blue_shulker_box
{enum class facing_type : std::uint8_t
{
north,
east,
south,
west,
up,
down
} facing = facing_type::up;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
return 8808;
case facing_type::east:
return 8809;
case facing_type::south:
return 8810;
case facing_type::west:
return 8811;
case facing_type::up:
return 8812;
case facing_type::down:
return 8813;
}
}
constexpr static blue_shulker_box from_id(block_id_type id)
{
switch (id)
{
case 8808:
return {.facing = facing_type::north};
case 8809:
return {.facing = facing_type::east};
case 8810:
return {.facing = facing_type::south};
case 8811:
return {.facing = facing_type::west};
case 8812:
return {.facing = facing_type::up};
case 8813:
return {.facing = facing_type::down};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:blue_shulker_box:north";
case facing_type::east:
return "minecraft:blue_shulker_box:east";
case facing_type::south:
return "minecraft:blue_shulker_box:south";
case facing_type::west:
return "minecraft:blue_shulker_box:west";
case facing_type::up:
return "minecraft:blue_shulker_box:up";
case facing_type::down:
return "minecraft:blue_shulker_box:down";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
