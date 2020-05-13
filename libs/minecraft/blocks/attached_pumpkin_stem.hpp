#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct attached_pumpkin_stem
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
return 4748;
case facing_type::south:
return 4749;
case facing_type::west:
return 4750;
case facing_type::east:
return 4751;
}
}
constexpr static attached_pumpkin_stem from_id(block_id_type id)
{
switch (id)
{
case 4748:
return {.facing = facing_type::north};
case 4749:
return {.facing = facing_type::south};
case 4750:
return {.facing = facing_type::west};
case 4751:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:attached_pumpkin_stem:north";
case facing_type::south:
return "minecraft:attached_pumpkin_stem:south";
case facing_type::west:
return "minecraft:attached_pumpkin_stem:west";
case facing_type::east:
return "minecraft:attached_pumpkin_stem:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
