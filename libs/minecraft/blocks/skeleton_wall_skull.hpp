#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct skeleton_wall_skull
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
return 5970;
case facing_type::south:
return 5971;
case facing_type::west:
return 5972;
case facing_type::east:
return 5973;
}
}
constexpr static skeleton_wall_skull from_id(block_id_type id)
{
switch (id)
{
case 5970:
return {.facing = facing_type::north};
case 5971:
return {.facing = facing_type::south};
case 5972:
return {.facing = facing_type::west};
case 5973:
return {.facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
return "minecraft:skeleton_wall_skull:north";
case facing_type::south:
return "minecraft:skeleton_wall_skull:south";
case facing_type::west:
return "minecraft:skeleton_wall_skull:west";
case facing_type::east:
return "minecraft:skeleton_wall_skull:east";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
