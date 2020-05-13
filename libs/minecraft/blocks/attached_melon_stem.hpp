#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct attached_melon_stem
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
return 4752;
case facing_type::south:
return 4753;
case facing_type::west:
return 4754;
case facing_type::east:
return 4755;
}
}
constexpr static attached_melon_stem from_id(block_id_type id)
{
switch (id)
{
case 4752:
return {.facing = facing_type::north};
case 4753:
return {.facing = facing_type::south};
case 4754:
return {.facing = facing_type::west};
case 4755:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:attached_melon_stem:north";
case facing_type::south:
return "minecraft:attached_melon_stem:south";
case facing_type::west:
return "minecraft:attached_melon_stem:west";
case facing_type::east:
return "minecraft:attached_melon_stem:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
