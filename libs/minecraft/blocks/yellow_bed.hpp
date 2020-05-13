#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct yellow_bed
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
return 1112;
case part_type::foot:
return 1113;
}
case false:
switch (part)
{
case part_type::head:
return 1114;
case part_type::foot:
return 1115;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1116;
case part_type::foot:
return 1117;
}
case false:
switch (part)
{
case part_type::head:
return 1118;
case part_type::foot:
return 1119;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1120;
case part_type::foot:
return 1121;
}
case false:
switch (part)
{
case part_type::head:
return 1122;
case part_type::foot:
return 1123;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1124;
case part_type::foot:
return 1125;
}
case false:
switch (part)
{
case part_type::head:
return 1126;
case part_type::foot:
return 1127;
}
}
}
}
constexpr static yellow_bed from_id(block_id_type id)
{
switch (id)
{
case 1112:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1113:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1114:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1115:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1116:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1117:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1118:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1119:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1120:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1121:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1122:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1123:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1124:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1125:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1126:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1127:
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
return "minecraft:yellow_bed:north:true:head";
case part_type::foot:
return "minecraft:yellow_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:yellow_bed:north:false:head";
case part_type::foot:
return "minecraft:yellow_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:yellow_bed:south:true:head";
case part_type::foot:
return "minecraft:yellow_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:yellow_bed:south:false:head";
case part_type::foot:
return "minecraft:yellow_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:yellow_bed:west:true:head";
case part_type::foot:
return "minecraft:yellow_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:yellow_bed:west:false:head";
case part_type::foot:
return "minecraft:yellow_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:yellow_bed:east:true:head";
case part_type::foot:
return "minecraft:yellow_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:yellow_bed:east:false:head";
case part_type::foot:
return "minecraft:yellow_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
