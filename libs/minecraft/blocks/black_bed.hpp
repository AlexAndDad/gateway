#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct black_bed
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
return 1288;
case part_type::foot:
return 1289;
}
case false:
switch (part)
{
case part_type::head:
return 1290;
case part_type::foot:
return 1291;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1292;
case part_type::foot:
return 1293;
}
case false:
switch (part)
{
case part_type::head:
return 1294;
case part_type::foot:
return 1295;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1296;
case part_type::foot:
return 1297;
}
case false:
switch (part)
{
case part_type::head:
return 1298;
case part_type::foot:
return 1299;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1300;
case part_type::foot:
return 1301;
}
case false:
switch (part)
{
case part_type::head:
return 1302;
case part_type::foot:
return 1303;
}
}
}
}
constexpr static black_bed from_id(block_id_type id)
{
switch (id)
{
case 1288:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1289:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1290:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1291:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1292:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1293:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1294:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1295:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1296:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1297:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1298:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1299:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1300:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1301:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1302:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1303:
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
return "minecraft:black_bed:north:true:head";
case part_type::foot:
return "minecraft:black_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:black_bed:north:false:head";
case part_type::foot:
return "minecraft:black_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:black_bed:south:true:head";
case part_type::foot:
return "minecraft:black_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:black_bed:south:false:head";
case part_type::foot:
return "minecraft:black_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:black_bed:west:true:head";
case part_type::foot:
return "minecraft:black_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:black_bed:west:false:head";
case part_type::foot:
return "minecraft:black_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:black_bed:east:true:head";
case part_type::foot:
return "minecraft:black_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:black_bed:east:false:head";
case part_type::foot:
return "minecraft:black_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
