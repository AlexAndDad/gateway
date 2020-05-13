#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct brown_bed
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
return 1240;
case part_type::foot:
return 1241;
}
case false:
switch (part)
{
case part_type::head:
return 1242;
case part_type::foot:
return 1243;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1244;
case part_type::foot:
return 1245;
}
case false:
switch (part)
{
case part_type::head:
return 1246;
case part_type::foot:
return 1247;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1248;
case part_type::foot:
return 1249;
}
case false:
switch (part)
{
case part_type::head:
return 1250;
case part_type::foot:
return 1251;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1252;
case part_type::foot:
return 1253;
}
case false:
switch (part)
{
case part_type::head:
return 1254;
case part_type::foot:
return 1255;
}
}
}
}
constexpr static brown_bed from_id(block_id_type id)
{
switch (id)
{
case 1240:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1241:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1242:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1243:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1244:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1245:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1246:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1247:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1248:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1249:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1250:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1251:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1252:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1253:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1254:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1255:
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
return "minecraft:brown_bed:north:true:head";
case part_type::foot:
return "minecraft:brown_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:brown_bed:north:false:head";
case part_type::foot:
return "minecraft:brown_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:brown_bed:south:true:head";
case part_type::foot:
return "minecraft:brown_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:brown_bed:south:false:head";
case part_type::foot:
return "minecraft:brown_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:brown_bed:west:true:head";
case part_type::foot:
return "minecraft:brown_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:brown_bed:west:false:head";
case part_type::foot:
return "minecraft:brown_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:brown_bed:east:true:head";
case part_type::foot:
return "minecraft:brown_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:brown_bed:east:false:head";
case part_type::foot:
return "minecraft:brown_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
