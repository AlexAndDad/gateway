#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct cyan_bed
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
return 1192;
case part_type::foot:
return 1193;
}
case false:
switch (part)
{
case part_type::head:
return 1194;
case part_type::foot:
return 1195;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1196;
case part_type::foot:
return 1197;
}
case false:
switch (part)
{
case part_type::head:
return 1198;
case part_type::foot:
return 1199;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1200;
case part_type::foot:
return 1201;
}
case false:
switch (part)
{
case part_type::head:
return 1202;
case part_type::foot:
return 1203;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1204;
case part_type::foot:
return 1205;
}
case false:
switch (part)
{
case part_type::head:
return 1206;
case part_type::foot:
return 1207;
}
}
}
}
constexpr static cyan_bed from_id(block_id_type id)
{
switch (id)
{
case 1192:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1193:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1194:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1195:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1196:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1197:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1198:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1199:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1200:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1201:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1202:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1203:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1204:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1205:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1206:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1207:
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
return "minecraft:cyan_bed:north:true:head";
case part_type::foot:
return "minecraft:cyan_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:cyan_bed:north:false:head";
case part_type::foot:
return "minecraft:cyan_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:cyan_bed:south:true:head";
case part_type::foot:
return "minecraft:cyan_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:cyan_bed:south:false:head";
case part_type::foot:
return "minecraft:cyan_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:cyan_bed:west:true:head";
case part_type::foot:
return "minecraft:cyan_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:cyan_bed:west:false:head";
case part_type::foot:
return "minecraft:cyan_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:cyan_bed:east:true:head";
case part_type::foot:
return "minecraft:cyan_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:cyan_bed:east:false:head";
case part_type::foot:
return "minecraft:cyan_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
