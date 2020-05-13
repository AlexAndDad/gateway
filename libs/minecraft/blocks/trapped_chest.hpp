#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct trapped_chest
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
enum class type_type : std::uint8_t
{
single,
left,
right
} type = type_type::single;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return 6086;
case false:
return 6087;
}
case type_type::left:
switch (waterlogged)
{
case true:
return 6088;
case false:
return 6089;
}
case type_type::right:
switch (waterlogged)
{
case true:
return 6090;
case false:
return 6091;
}
}
case facing_type::south:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return 6092;
case false:
return 6093;
}
case type_type::left:
switch (waterlogged)
{
case true:
return 6094;
case false:
return 6095;
}
case type_type::right:
switch (waterlogged)
{
case true:
return 6096;
case false:
return 6097;
}
}
case facing_type::west:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return 6098;
case false:
return 6099;
}
case type_type::left:
switch (waterlogged)
{
case true:
return 6100;
case false:
return 6101;
}
case type_type::right:
switch (waterlogged)
{
case true:
return 6102;
case false:
return 6103;
}
}
case facing_type::east:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return 6104;
case false:
return 6105;
}
case type_type::left:
switch (waterlogged)
{
case true:
return 6106;
case false:
return 6107;
}
case type_type::right:
switch (waterlogged)
{
case true:
return 6108;
case false:
return 6109;
}
}
}
}
constexpr static trapped_chest from_id(block_id_type id)
{
switch (id)
{
case 6086:
return {.facing = facing_type::north, .type = type_type::single, .waterlogged = true};
case 6087:
return {.facing = facing_type::north, .type = type_type::single, .waterlogged = false};
case 6088:
return {.facing = facing_type::north, .type = type_type::left, .waterlogged = true};
case 6089:
return {.facing = facing_type::north, .type = type_type::left, .waterlogged = false};
case 6090:
return {.facing = facing_type::north, .type = type_type::right, .waterlogged = true};
case 6091:
return {.facing = facing_type::north, .type = type_type::right, .waterlogged = false};
case 6092:
return {.facing = facing_type::south, .type = type_type::single, .waterlogged = true};
case 6093:
return {.facing = facing_type::south, .type = type_type::single, .waterlogged = false};
case 6094:
return {.facing = facing_type::south, .type = type_type::left, .waterlogged = true};
case 6095:
return {.facing = facing_type::south, .type = type_type::left, .waterlogged = false};
case 6096:
return {.facing = facing_type::south, .type = type_type::right, .waterlogged = true};
case 6097:
return {.facing = facing_type::south, .type = type_type::right, .waterlogged = false};
case 6098:
return {.facing = facing_type::west, .type = type_type::single, .waterlogged = true};
case 6099:
return {.facing = facing_type::west, .type = type_type::single, .waterlogged = false};
case 6100:
return {.facing = facing_type::west, .type = type_type::left, .waterlogged = true};
case 6101:
return {.facing = facing_type::west, .type = type_type::left, .waterlogged = false};
case 6102:
return {.facing = facing_type::west, .type = type_type::right, .waterlogged = true};
case 6103:
return {.facing = facing_type::west, .type = type_type::right, .waterlogged = false};
case 6104:
return {.facing = facing_type::east, .type = type_type::single, .waterlogged = true};
case 6105:
return {.facing = facing_type::east, .type = type_type::single, .waterlogged = false};
case 6106:
return {.facing = facing_type::east, .type = type_type::left, .waterlogged = true};
case 6107:
return {.facing = facing_type::east, .type = type_type::left, .waterlogged = false};
case 6108:
return {.facing = facing_type::east, .type = type_type::right, .waterlogged = true};
case 6109:
return {.facing = facing_type::east, .type = type_type::right, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return "minecraft:trapped_chest:north:single:true";
case false:
return "minecraft:trapped_chest:north:single:false";
}
case type_type::left:
switch (waterlogged)
{
case true:
return "minecraft:trapped_chest:north:left:true";
case false:
return "minecraft:trapped_chest:north:left:false";
}
case type_type::right:
switch (waterlogged)
{
case true:
return "minecraft:trapped_chest:north:right:true";
case false:
return "minecraft:trapped_chest:north:right:false";
}
}
case facing_type::south:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return "minecraft:trapped_chest:south:single:true";
case false:
return "minecraft:trapped_chest:south:single:false";
}
case type_type::left:
switch (waterlogged)
{
case true:
return "minecraft:trapped_chest:south:left:true";
case false:
return "minecraft:trapped_chest:south:left:false";
}
case type_type::right:
switch (waterlogged)
{
case true:
return "minecraft:trapped_chest:south:right:true";
case false:
return "minecraft:trapped_chest:south:right:false";
}
}
case facing_type::west:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return "minecraft:trapped_chest:west:single:true";
case false:
return "minecraft:trapped_chest:west:single:false";
}
case type_type::left:
switch (waterlogged)
{
case true:
return "minecraft:trapped_chest:west:left:true";
case false:
return "minecraft:trapped_chest:west:left:false";
}
case type_type::right:
switch (waterlogged)
{
case true:
return "minecraft:trapped_chest:west:right:true";
case false:
return "minecraft:trapped_chest:west:right:false";
}
}
case facing_type::east:
switch (type)
{
case type_type::single:
switch (waterlogged)
{
case true:
return "minecraft:trapped_chest:east:single:true";
case false:
return "minecraft:trapped_chest:east:single:false";
}
case type_type::left:
switch (waterlogged)
{
case true:
return "minecraft:trapped_chest:east:left:true";
case false:
return "minecraft:trapped_chest:east:left:false";
}
case type_type::right:
switch (waterlogged)
{
case true:
return "minecraft:trapped_chest:east:right:true";
case false:
return "minecraft:trapped_chest:east:right:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
