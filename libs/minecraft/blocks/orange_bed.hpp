#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct orange_bed
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
return 1064;
case part_type::foot:
return 1065;
}
case false:
switch (part)
{
case part_type::head:
return 1066;
case part_type::foot:
return 1067;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1068;
case part_type::foot:
return 1069;
}
case false:
switch (part)
{
case part_type::head:
return 1070;
case part_type::foot:
return 1071;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1072;
case part_type::foot:
return 1073;
}
case false:
switch (part)
{
case part_type::head:
return 1074;
case part_type::foot:
return 1075;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1076;
case part_type::foot:
return 1077;
}
case false:
switch (part)
{
case part_type::head:
return 1078;
case part_type::foot:
return 1079;
}
}
}
}
constexpr static orange_bed from_id(block_id_type id)
{
switch (id)
{
case 1064:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1065:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1066:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1067:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1068:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1069:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1070:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1071:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1072:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1073:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1074:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1075:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1076:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1077:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1078:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1079:
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
return "minecraft:orange_bed:north:true:head";
case part_type::foot:
return "minecraft:orange_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:orange_bed:north:false:head";
case part_type::foot:
return "minecraft:orange_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:orange_bed:south:true:head";
case part_type::foot:
return "minecraft:orange_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:orange_bed:south:false:head";
case part_type::foot:
return "minecraft:orange_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:orange_bed:west:true:head";
case part_type::foot:
return "minecraft:orange_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:orange_bed:west:false:head";
case part_type::foot:
return "minecraft:orange_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:orange_bed:east:true:head";
case part_type::foot:
return "minecraft:orange_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:orange_bed:east:false:head";
case part_type::foot:
return "minecraft:orange_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
