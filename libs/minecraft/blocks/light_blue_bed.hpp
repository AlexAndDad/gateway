#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct light_blue_bed
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
bool occupied = false;
enum class part_type : std::uint8_t
{
head,
foot
} part = part_type::foot;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1096;
case part_type::foot:
return 1097;
}
case false:
switch (part)
{
case part_type::head:
return 1098;
case part_type::foot:
return 1099;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1100;
case part_type::foot:
return 1101;
}
case false:
switch (part)
{
case part_type::head:
return 1102;
case part_type::foot:
return 1103;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1104;
case part_type::foot:
return 1105;
}
case false:
switch (part)
{
case part_type::head:
return 1106;
case part_type::foot:
return 1107;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1108;
case part_type::foot:
return 1109;
}
case false:
switch (part)
{
case part_type::head:
return 1110;
case part_type::foot:
return 1111;
}
}
}
}
constexpr static light_blue_bed from_id(block_id_type id)
{
switch (id)
{
case 1096:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1097:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1098:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1099:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1100:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1101:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1102:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1103:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1104:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1105:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1106:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1107:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1108:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1109:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1110:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1111:
return {.facing = facing_type::east, .occupied = false, .part = part_type::foot};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:light_blue_bed:north:true:head";
case part_type::foot:
return "minecraft:light_blue_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:light_blue_bed:north:false:head";
case part_type::foot:
return "minecraft:light_blue_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:light_blue_bed:south:true:head";
case part_type::foot:
return "minecraft:light_blue_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:light_blue_bed:south:false:head";
case part_type::foot:
return "minecraft:light_blue_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:light_blue_bed:west:true:head";
case part_type::foot:
return "minecraft:light_blue_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:light_blue_bed:west:false:head";
case part_type::foot:
return "minecraft:light_blue_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:light_blue_bed:east:true:head";
case part_type::foot:
return "minecraft:light_blue_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:light_blue_bed:east:false:head";
case part_type::foot:
return "minecraft:light_blue_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
