#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct lime_bed
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
return 1128;
case part_type::foot:
return 1129;
}
case false:
switch (part)
{
case part_type::head:
return 1130;
case part_type::foot:
return 1131;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1132;
case part_type::foot:
return 1133;
}
case false:
switch (part)
{
case part_type::head:
return 1134;
case part_type::foot:
return 1135;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1136;
case part_type::foot:
return 1137;
}
case false:
switch (part)
{
case part_type::head:
return 1138;
case part_type::foot:
return 1139;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1140;
case part_type::foot:
return 1141;
}
case false:
switch (part)
{
case part_type::head:
return 1142;
case part_type::foot:
return 1143;
}
}
}
}
constexpr static lime_bed from_id(block_id_type id)
{
switch (id)
{
case 1128:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1129:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1130:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1131:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1132:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1133:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1134:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1135:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1136:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1137:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1138:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1139:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1140:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1141:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1142:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1143:
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
return "minecraft:lime_bed:north:true:head";
case part_type::foot:
return "minecraft:lime_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:lime_bed:north:false:head";
case part_type::foot:
return "minecraft:lime_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:lime_bed:south:true:head";
case part_type::foot:
return "minecraft:lime_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:lime_bed:south:false:head";
case part_type::foot:
return "minecraft:lime_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:lime_bed:west:true:head";
case part_type::foot:
return "minecraft:lime_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:lime_bed:west:false:head";
case part_type::foot:
return "minecraft:lime_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:lime_bed:east:true:head";
case part_type::foot:
return "minecraft:lime_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:lime_bed:east:false:head";
case part_type::foot:
return "minecraft:lime_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
