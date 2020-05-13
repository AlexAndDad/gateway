#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct pink_bed
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
return 1144;
case part_type::foot:
return 1145;
}
case false:
switch (part)
{
case part_type::head:
return 1146;
case part_type::foot:
return 1147;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1148;
case part_type::foot:
return 1149;
}
case false:
switch (part)
{
case part_type::head:
return 1150;
case part_type::foot:
return 1151;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1152;
case part_type::foot:
return 1153;
}
case false:
switch (part)
{
case part_type::head:
return 1154;
case part_type::foot:
return 1155;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1156;
case part_type::foot:
return 1157;
}
case false:
switch (part)
{
case part_type::head:
return 1158;
case part_type::foot:
return 1159;
}
}
}
}
constexpr static pink_bed from_id(block_id_type id)
{
switch (id)
{
case 1144:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1145:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1146:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1147:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1148:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1149:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1150:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1151:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1152:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1153:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1154:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1155:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1156:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1157:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1158:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1159:
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
return "minecraft:pink_bed:north:true:head";
case part_type::foot:
return "minecraft:pink_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:pink_bed:north:false:head";
case part_type::foot:
return "minecraft:pink_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:pink_bed:south:true:head";
case part_type::foot:
return "minecraft:pink_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:pink_bed:south:false:head";
case part_type::foot:
return "minecraft:pink_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:pink_bed:west:true:head";
case part_type::foot:
return "minecraft:pink_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:pink_bed:west:false:head";
case part_type::foot:
return "minecraft:pink_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:pink_bed:east:true:head";
case part_type::foot:
return "minecraft:pink_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:pink_bed:east:false:head";
case part_type::foot:
return "minecraft:pink_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
