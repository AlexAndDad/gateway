#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jungle_wall_sign
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
return 3765;
case false:
return 3766;
}
case facing_type::south:
switch (waterlogged)
{
case true:
return 3767;
case false:
return 3768;
}
case facing_type::west:
switch (waterlogged)
{
case true:
return 3769;
case false:
return 3770;
}
case facing_type::east:
switch (waterlogged)
{
case true:
return 3771;
case false:
return 3772;
}
}
}
constexpr static jungle_wall_sign from_id(block_id_type id)
{
switch (id)
{
case 3765:
return {.facing = facing_type::north, .waterlogged = true};
case 3766:
return {.facing = facing_type::north, .waterlogged = false};
case 3767:
return {.facing = facing_type::south, .waterlogged = true};
case 3768:
return {.facing = facing_type::south, .waterlogged = false};
case 3769:
return {.facing = facing_type::west, .waterlogged = true};
case 3770:
return {.facing = facing_type::west, .waterlogged = false};
case 3771:
return {.facing = facing_type::east, .waterlogged = true};
case 3772:
return {.facing = facing_type::east, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (waterlogged)
{
case true:
return "minecraft:jungle_wall_sign:north:true";
case false:
return "minecraft:jungle_wall_sign:north:false";
}
case facing_type::south:
switch (waterlogged)
{
case true:
return "minecraft:jungle_wall_sign:south:true";
case false:
return "minecraft:jungle_wall_sign:south:false";
}
case facing_type::west:
switch (waterlogged)
{
case true:
return "minecraft:jungle_wall_sign:west:true";
case false:
return "minecraft:jungle_wall_sign:west:false";
}
case facing_type::east:
switch (waterlogged)
{
case true:
return "minecraft:jungle_wall_sign:east:true";
case false:
return "minecraft:jungle_wall_sign:east:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
