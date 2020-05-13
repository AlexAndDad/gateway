#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct magenta_bed
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
return 1080;
case part_type::foot:
return 1081;
}
case false:
switch (part)
{
case part_type::head:
return 1082;
case part_type::foot:
return 1083;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1084;
case part_type::foot:
return 1085;
}
case false:
switch (part)
{
case part_type::head:
return 1086;
case part_type::foot:
return 1087;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1088;
case part_type::foot:
return 1089;
}
case false:
switch (part)
{
case part_type::head:
return 1090;
case part_type::foot:
return 1091;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1092;
case part_type::foot:
return 1093;
}
case false:
switch (part)
{
case part_type::head:
return 1094;
case part_type::foot:
return 1095;
}
}
}
}
constexpr static magenta_bed from_id(block_id_type id)
{
switch (id)
{
case 1080:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1081:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1082:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1083:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1084:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1085:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1086:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1087:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1088:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1089:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1090:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1091:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1092:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1093:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1094:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1095:
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
return "minecraft:magenta_bed:north:true:head";
case part_type::foot:
return "minecraft:magenta_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:magenta_bed:north:false:head";
case part_type::foot:
return "minecraft:magenta_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:magenta_bed:south:true:head";
case part_type::foot:
return "minecraft:magenta_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:magenta_bed:south:false:head";
case part_type::foot:
return "minecraft:magenta_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:magenta_bed:west:true:head";
case part_type::foot:
return "minecraft:magenta_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:magenta_bed:west:false:head";
case part_type::foot:
return "minecraft:magenta_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:magenta_bed:east:true:head";
case part_type::foot:
return "minecraft:magenta_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:magenta_bed:east:false:head";
case part_type::foot:
return "minecraft:magenta_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
