#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct green_bed
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
return 1256;
case part_type::foot:
return 1257;
}
case false:
switch (part)
{
case part_type::head:
return 1258;
case part_type::foot:
return 1259;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1260;
case part_type::foot:
return 1261;
}
case false:
switch (part)
{
case part_type::head:
return 1262;
case part_type::foot:
return 1263;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1264;
case part_type::foot:
return 1265;
}
case false:
switch (part)
{
case part_type::head:
return 1266;
case part_type::foot:
return 1267;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1268;
case part_type::foot:
return 1269;
}
case false:
switch (part)
{
case part_type::head:
return 1270;
case part_type::foot:
return 1271;
}
}
}
}
constexpr static green_bed from_id(block_id_type id)
{
switch (id)
{
case 1256:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1257:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1258:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1259:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1260:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1261:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1262:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1263:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1264:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1265:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1266:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1267:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1268:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1269:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1270:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1271:
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
return "minecraft:green_bed:north:true:head";
case part_type::foot:
return "minecraft:green_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:green_bed:north:false:head";
case part_type::foot:
return "minecraft:green_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:green_bed:south:true:head";
case part_type::foot:
return "minecraft:green_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:green_bed:south:false:head";
case part_type::foot:
return "minecraft:green_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:green_bed:west:true:head";
case part_type::foot:
return "minecraft:green_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:green_bed:west:false:head";
case part_type::foot:
return "minecraft:green_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:green_bed:east:true:head";
case part_type::foot:
return "minecraft:green_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:green_bed:east:false:head";
case part_type::foot:
return "minecraft:green_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
