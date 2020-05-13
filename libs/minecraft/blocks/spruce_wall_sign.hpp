#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct spruce_wall_sign
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (waterlogged)
{
case true:
return 3741;
case false:
return 3742;
}
case facing_type::south:
switch (waterlogged)
{
case true:
return 3743;
case false:
return 3744;
}
case facing_type::west:
switch (waterlogged)
{
case true:
return 3745;
case false:
return 3746;
}
case facing_type::east:
switch (waterlogged)
{
case true:
return 3747;
case false:
return 3748;
}
}
}
constexpr static spruce_wall_sign from_id(block_id_type id)
{
switch (id)
{
case 3741:
return {.facing = facing_type::north, .waterlogged = true};
case 3742:
return {.facing = facing_type::north, .waterlogged = false};
case 3743:
return {.facing = facing_type::south, .waterlogged = true};
case 3744:
return {.facing = facing_type::south, .waterlogged = false};
case 3745:
return {.facing = facing_type::west, .waterlogged = true};
case 3746:
return {.facing = facing_type::west, .waterlogged = false};
case 3747:
return {.facing = facing_type::east, .waterlogged = true};
case 3748:
return {.facing = facing_type::east, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (waterlogged)
{
case true:
return "minecraft:spruce_wall_sign:north:true";
case false:
return "minecraft:spruce_wall_sign:north:false";
}
case facing_type::south:
switch (waterlogged)
{
case true:
return "minecraft:spruce_wall_sign:south:true";
case false:
return "minecraft:spruce_wall_sign:south:false";
}
case facing_type::west:
switch (waterlogged)
{
case true:
return "minecraft:spruce_wall_sign:west:true";
case false:
return "minecraft:spruce_wall_sign:west:false";
}
case facing_type::east:
switch (waterlogged)
{
case true:
return "minecraft:spruce_wall_sign:east:true";
case false:
return "minecraft:spruce_wall_sign:east:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
