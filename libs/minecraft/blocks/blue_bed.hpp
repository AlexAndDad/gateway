#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct blue_bed
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
return 1224;
case part_type::foot:
return 1225;
}
case false:
switch (part)
{
case part_type::head:
return 1226;
case part_type::foot:
return 1227;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1228;
case part_type::foot:
return 1229;
}
case false:
switch (part)
{
case part_type::head:
return 1230;
case part_type::foot:
return 1231;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1232;
case part_type::foot:
return 1233;
}
case false:
switch (part)
{
case part_type::head:
return 1234;
case part_type::foot:
return 1235;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1236;
case part_type::foot:
return 1237;
}
case false:
switch (part)
{
case part_type::head:
return 1238;
case part_type::foot:
return 1239;
}
}
}
}
constexpr static blue_bed from_id(block_id_type id)
{
switch (id)
{
case 1224:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1225:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1226:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1227:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1228:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1229:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1230:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1231:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1232:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1233:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1234:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1235:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1236:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1237:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1238:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1239:
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
return "minecraft:blue_bed:north:true:head";
case part_type::foot:
return "minecraft:blue_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:blue_bed:north:false:head";
case part_type::foot:
return "minecraft:blue_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:blue_bed:south:true:head";
case part_type::foot:
return "minecraft:blue_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:blue_bed:south:false:head";
case part_type::foot:
return "minecraft:blue_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:blue_bed:west:true:head";
case part_type::foot:
return "minecraft:blue_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:blue_bed:west:false:head";
case part_type::foot:
return "minecraft:blue_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:blue_bed:east:true:head";
case part_type::foot:
return "minecraft:blue_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:blue_bed:east:false:head";
case part_type::foot:
return "minecraft:blue_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
