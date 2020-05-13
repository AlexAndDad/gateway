#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct white_bed
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
return 1048;
case part_type::foot:
return 1049;
}
case false:
switch (part)
{
case part_type::head:
return 1050;
case part_type::foot:
return 1051;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1052;
case part_type::foot:
return 1053;
}
case false:
switch (part)
{
case part_type::head:
return 1054;
case part_type::foot:
return 1055;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1056;
case part_type::foot:
return 1057;
}
case false:
switch (part)
{
case part_type::head:
return 1058;
case part_type::foot:
return 1059;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1060;
case part_type::foot:
return 1061;
}
case false:
switch (part)
{
case part_type::head:
return 1062;
case part_type::foot:
return 1063;
}
}
}
}
constexpr static white_bed from_id(block_id_type id)
{
switch (id)
{
case 1048:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1049:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1050:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1051:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1052:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1053:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1054:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1055:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1056:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1057:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1058:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1059:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1060:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1061:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1062:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1063:
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
return "minecraft:white_bed:north:true:head";
case part_type::foot:
return "minecraft:white_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:white_bed:north:false:head";
case part_type::foot:
return "minecraft:white_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:white_bed:south:true:head";
case part_type::foot:
return "minecraft:white_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:white_bed:south:false:head";
case part_type::foot:
return "minecraft:white_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:white_bed:west:true:head";
case part_type::foot:
return "minecraft:white_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:white_bed:west:false:head";
case part_type::foot:
return "minecraft:white_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:white_bed:east:true:head";
case part_type::foot:
return "minecraft:white_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:white_bed:east:false:head";
case part_type::foot:
return "minecraft:white_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
