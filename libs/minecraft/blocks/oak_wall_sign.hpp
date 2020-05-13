#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct oak_wall_sign
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
return 3733;
case false:
return 3734;
}
case facing_type::south:
switch (waterlogged)
{
case true:
return 3735;
case false:
return 3736;
}
case facing_type::west:
switch (waterlogged)
{
case true:
return 3737;
case false:
return 3738;
}
case facing_type::east:
switch (waterlogged)
{
case true:
return 3739;
case false:
return 3740;
}
}
}
constexpr static oak_wall_sign from_id(block_id_type id)
{
switch (id)
{
case 3733:
return {.facing = facing_type::north, .waterlogged = true};
case 3734:
return {.facing = facing_type::north, .waterlogged = false};
case 3735:
return {.facing = facing_type::south, .waterlogged = true};
case 3736:
return {.facing = facing_type::south, .waterlogged = false};
case 3737:
return {.facing = facing_type::west, .waterlogged = true};
case 3738:
return {.facing = facing_type::west, .waterlogged = false};
case 3739:
return {.facing = facing_type::east, .waterlogged = true};
case 3740:
return {.facing = facing_type::east, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (waterlogged)
{
case true:
return "minecraft:oak_wall_sign:north:true";
case false:
return "minecraft:oak_wall_sign:north:false";
}
case facing_type::south:
switch (waterlogged)
{
case true:
return "minecraft:oak_wall_sign:south:true";
case false:
return "minecraft:oak_wall_sign:south:false";
}
case facing_type::west:
switch (waterlogged)
{
case true:
return "minecraft:oak_wall_sign:west:true";
case false:
return "minecraft:oak_wall_sign:west:false";
}
case facing_type::east:
switch (waterlogged)
{
case true:
return "minecraft:oak_wall_sign:east:true";
case false:
return "minecraft:oak_wall_sign:east:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
