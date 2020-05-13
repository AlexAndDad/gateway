#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct red_bed
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
return 1272;
case part_type::foot:
return 1273;
}
case false:
switch (part)
{
case part_type::head:
return 1274;
case part_type::foot:
return 1275;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1276;
case part_type::foot:
return 1277;
}
case false:
switch (part)
{
case part_type::head:
return 1278;
case part_type::foot:
return 1279;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1280;
case part_type::foot:
return 1281;
}
case false:
switch (part)
{
case part_type::head:
return 1282;
case part_type::foot:
return 1283;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1284;
case part_type::foot:
return 1285;
}
case false:
switch (part)
{
case part_type::head:
return 1286;
case part_type::foot:
return 1287;
}
}
}
}
constexpr static red_bed from_id(block_id_type id)
{
switch (id)
{
case 1272:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1273:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1274:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1275:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1276:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1277:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1278:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1279:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1280:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1281:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1282:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1283:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1284:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1285:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1286:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1287:
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
return "minecraft:red_bed:north:true:head";
case part_type::foot:
return "minecraft:red_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:red_bed:north:false:head";
case part_type::foot:
return "minecraft:red_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:red_bed:south:true:head";
case part_type::foot:
return "minecraft:red_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:red_bed:south:false:head";
case part_type::foot:
return "minecraft:red_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:red_bed:west:true:head";
case part_type::foot:
return "minecraft:red_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:red_bed:west:false:head";
case part_type::foot:
return "minecraft:red_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:red_bed:east:true:head";
case part_type::foot:
return "minecraft:red_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:red_bed:east:false:head";
case part_type::foot:
return "minecraft:red_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
