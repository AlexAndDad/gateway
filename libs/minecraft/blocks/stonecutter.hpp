#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct stonecutter
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
return 11194;
case facing_type::south:
return 11195;
case facing_type::west:
return 11196;
case facing_type::east:
return 11197;
}
}
constexpr static stonecutter from_id(block_id_type id)
{
switch (id)
{
case 11194:
return {.facing = facing_type::north};
case 11195:
return {.facing = facing_type::south};
case 11196:
return {.facing = facing_type::west};
case 11197:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:stonecutter:north";
case facing_type::south:
return "minecraft:stonecutter:south";
case facing_type::west:
return "minecraft:stonecutter:west";
case facing_type::east:
return "minecraft:stonecutter:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
