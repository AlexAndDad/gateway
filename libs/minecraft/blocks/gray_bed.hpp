#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct gray_bed
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
return 1160;
case part_type::foot:
return 1161;
}
case false:
switch (part)
{
case part_type::head:
return 1162;
case part_type::foot:
return 1163;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1164;
case part_type::foot:
return 1165;
}
case false:
switch (part)
{
case part_type::head:
return 1166;
case part_type::foot:
return 1167;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1168;
case part_type::foot:
return 1169;
}
case false:
switch (part)
{
case part_type::head:
return 1170;
case part_type::foot:
return 1171;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1172;
case part_type::foot:
return 1173;
}
case false:
switch (part)
{
case part_type::head:
return 1174;
case part_type::foot:
return 1175;
}
}
}
}
constexpr static gray_bed from_id(block_id_type id)
{
switch (id)
{
case 1160:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1161:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1162:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1163:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1164:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1165:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1166:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1167:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1168:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1169:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1170:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1171:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1172:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1173:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1174:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1175:
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
return "minecraft:gray_bed:north:true:head";
case part_type::foot:
return "minecraft:gray_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:gray_bed:north:false:head";
case part_type::foot:
return "minecraft:gray_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:gray_bed:south:true:head";
case part_type::foot:
return "minecraft:gray_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:gray_bed:south:false:head";
case part_type::foot:
return "minecraft:gray_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:gray_bed:west:true:head";
case part_type::foot:
return "minecraft:gray_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:gray_bed:west:false:head";
case part_type::foot:
return "minecraft:gray_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:gray_bed:east:true:head";
case part_type::foot:
return "minecraft:gray_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:gray_bed:east:false:head";
case part_type::foot:
return "minecraft:gray_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
