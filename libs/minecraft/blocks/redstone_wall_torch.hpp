#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct redstone_wall_torch
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
bool lit = true;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (lit)
{
case true:
return 3887;
case false:
return 3888;
}
case facing_type::south:
switch (lit)
{
case true:
return 3889;
case false:
return 3890;
}
case facing_type::west:
switch (lit)
{
case true:
return 3891;
case false:
return 3892;
}
case facing_type::east:
switch (lit)
{
case true:
return 3893;
case false:
return 3894;
}
}
}
constexpr static redstone_wall_torch from_id(block_id_type id)
{
switch (id)
{
case 3887:
return {.facing = facing_type::north, .lit = true};
case 3888:
return {.facing = facing_type::north, .lit = false};
case 3889:
return {.facing = facing_type::south, .lit = true};
case 3890:
return {.facing = facing_type::south, .lit = false};
case 3891:
return {.facing = facing_type::west, .lit = true};
case 3892:
return {.facing = facing_type::west, .lit = false};
case 3893:
return {.facing = facing_type::east, .lit = true};
case 3894:
return {.facing = facing_type::east, .lit = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (lit)
{
case true:
return "minecraft:redstone_wall_torch:north:true";
case false:
return "minecraft:redstone_wall_torch:north:false";
}
case facing_type::south:
switch (lit)
{
case true:
return "minecraft:redstone_wall_torch:south:true";
case false:
return "minecraft:redstone_wall_torch:south:false";
}
case facing_type::west:
switch (lit)
{
case true:
return "minecraft:redstone_wall_torch:west:true";
case false:
return "minecraft:redstone_wall_torch:west:false";
}
case facing_type::east:
switch (lit)
{
case true:
return "minecraft:redstone_wall_torch:east:true";
case false:
return "minecraft:redstone_wall_torch:east:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
