#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct light_gray_bed
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
return 1176;
case part_type::foot:
return 1177;
}
case false:
switch (part)
{
case part_type::head:
return 1178;
case part_type::foot:
return 1179;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1180;
case part_type::foot:
return 1181;
}
case false:
switch (part)
{
case part_type::head:
return 1182;
case part_type::foot:
return 1183;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1184;
case part_type::foot:
return 1185;
}
case false:
switch (part)
{
case part_type::head:
return 1186;
case part_type::foot:
return 1187;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1188;
case part_type::foot:
return 1189;
}
case false:
switch (part)
{
case part_type::head:
return 1190;
case part_type::foot:
return 1191;
}
}
}
}
constexpr static light_gray_bed from_id(block_id_type id)
{
switch (id)
{
case 1176:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1177:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1178:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1179:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1180:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1181:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1182:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1183:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1184:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1185:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1186:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1187:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1188:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1189:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1190:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1191:
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
return "minecraft:light_gray_bed:north:true:head";
case part_type::foot:
return "minecraft:light_gray_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:light_gray_bed:north:false:head";
case part_type::foot:
return "minecraft:light_gray_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:light_gray_bed:south:true:head";
case part_type::foot:
return "minecraft:light_gray_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:light_gray_bed:south:false:head";
case part_type::foot:
return "minecraft:light_gray_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:light_gray_bed:west:true:head";
case part_type::foot:
return "minecraft:light_gray_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:light_gray_bed:west:false:head";
case part_type::foot:
return "minecraft:light_gray_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:light_gray_bed:east:true:head";
case part_type::foot:
return "minecraft:light_gray_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:light_gray_bed:east:false:head";
case part_type::foot:
return "minecraft:light_gray_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
