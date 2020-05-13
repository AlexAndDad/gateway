#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct ender_chest
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
return 5235;
case false:
return 5236;
}
case facing_type::south:
switch (waterlogged)
{
case true:
return 5237;
case false:
return 5238;
}
case facing_type::west:
switch (waterlogged)
{
case true:
return 5239;
case false:
return 5240;
}
case facing_type::east:
switch (waterlogged)
{
case true:
return 5241;
case false:
return 5242;
}
}
}
constexpr static ender_chest from_id(block_id_type id)
{
switch (id)
{
case 5235:
return {.facing = facing_type::north, .waterlogged = true};
case 5236:
return {.facing = facing_type::north, .waterlogged = false};
case 5237:
return {.facing = facing_type::south, .waterlogged = true};
case 5238:
return {.facing = facing_type::south, .waterlogged = false};
case 5239:
return {.facing = facing_type::west, .waterlogged = true};
case 5240:
return {.facing = facing_type::west, .waterlogged = false};
case 5241:
return {.facing = facing_type::east, .waterlogged = true};
case 5242:
return {.facing = facing_type::east, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (waterlogged)
{
case true:
return "minecraft:ender_chest:north:true";
case false:
return "minecraft:ender_chest:north:false";
}
case facing_type::south:
switch (waterlogged)
{
case true:
return "minecraft:ender_chest:south:true";
case false:
return "minecraft:ender_chest:south:false";
}
case facing_type::west:
switch (waterlogged)
{
case true:
return "minecraft:ender_chest:west:true";
case false:
return "minecraft:ender_chest:west:false";
}
case facing_type::east:
switch (waterlogged)
{
case true:
return "minecraft:ender_chest:east:true";
case false:
return "minecraft:ender_chest:east:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
