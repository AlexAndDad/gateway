#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct brown_shulker_box
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
return 8814;
case facing_type::east:
return 8815;
case facing_type::south:
return 8816;
case facing_type::west:
return 8817;
case facing_type::up:
return 8818;
case facing_type::down:
return 8819;
}
}
constexpr static brown_shulker_box from_id(block_id_type id)
{
switch (id)
{
case 8814:
return {.facing = facing_type::north};
case 8815:
return {.facing = facing_type::east};
case 8816:
return {.facing = facing_type::south};
case 8817:
return {.facing = facing_type::west};
case 8818:
return {.facing = facing_type::up};
case 8819:
return {.facing = facing_type::down};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:brown_shulker_box:north";
case facing_type::east:
return "minecraft:brown_shulker_box:east";
case facing_type::south:
return "minecraft:brown_shulker_box:south";
case facing_type::west:
return "minecraft:brown_shulker_box:west";
case facing_type::up:
return "minecraft:brown_shulker_box:up";
case facing_type::down:
return "minecraft:brown_shulker_box:down";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
