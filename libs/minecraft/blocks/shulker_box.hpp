#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct shulker_box
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
return 8736;
case facing_type::east:
return 8737;
case facing_type::south:
return 8738;
case facing_type::west:
return 8739;
case facing_type::up:
return 8740;
case facing_type::down:
return 8741;
}
}
constexpr static shulker_box from_id(block_id_type id)
{
switch (id)
{
case 8736:
return {.facing = facing_type::north};
case 8737:
return {.facing = facing_type::east};
case 8738:
return {.facing = facing_type::south};
case 8739:
return {.facing = facing_type::west};
case 8740:
return {.facing = facing_type::up};
case 8741:
return {.facing = facing_type::down};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:shulker_box:north";
case facing_type::east:
return "minecraft:shulker_box:east";
case facing_type::south:
return "minecraft:shulker_box:south";
case facing_type::west:
return "minecraft:shulker_box:west";
case facing_type::up:
return "minecraft:shulker_box:up";
case facing_type::down:
return "minecraft:shulker_box:down";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
