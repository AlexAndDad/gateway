#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct purple_bed
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
return 1208;
case part_type::foot:
return 1209;
}
case false:
switch (part)
{
case part_type::head:
return 1210;
case part_type::foot:
return 1211;
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1212;
case part_type::foot:
return 1213;
}
case false:
switch (part)
{
case part_type::head:
return 1214;
case part_type::foot:
return 1215;
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1216;
case part_type::foot:
return 1217;
}
case false:
switch (part)
{
case part_type::head:
return 1218;
case part_type::foot:
return 1219;
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return 1220;
case part_type::foot:
return 1221;
}
case false:
switch (part)
{
case part_type::head:
return 1222;
case part_type::foot:
return 1223;
}
}
}
}
constexpr static purple_bed from_id(block_id_type id)
{
switch (id)
{
case 1208:
return {.facing = facing_type::north, .occupied = true, .part = part_type::head};
case 1209:
return {.facing = facing_type::north, .occupied = true, .part = part_type::foot};
case 1210:
return {.facing = facing_type::north, .occupied = false, .part = part_type::head};
case 1211:
return {.facing = facing_type::north, .occupied = false, .part = part_type::foot};
case 1212:
return {.facing = facing_type::south, .occupied = true, .part = part_type::head};
case 1213:
return {.facing = facing_type::south, .occupied = true, .part = part_type::foot};
case 1214:
return {.facing = facing_type::south, .occupied = false, .part = part_type::head};
case 1215:
return {.facing = facing_type::south, .occupied = false, .part = part_type::foot};
case 1216:
return {.facing = facing_type::west, .occupied = true, .part = part_type::head};
case 1217:
return {.facing = facing_type::west, .occupied = true, .part = part_type::foot};
case 1218:
return {.facing = facing_type::west, .occupied = false, .part = part_type::head};
case 1219:
return {.facing = facing_type::west, .occupied = false, .part = part_type::foot};
case 1220:
return {.facing = facing_type::east, .occupied = true, .part = part_type::head};
case 1221:
return {.facing = facing_type::east, .occupied = true, .part = part_type::foot};
case 1222:
return {.facing = facing_type::east, .occupied = false, .part = part_type::head};
case 1223:
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
return "minecraft:purple_bed:north:true:head";
case part_type::foot:
return "minecraft:purple_bed:north:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:purple_bed:north:false:head";
case part_type::foot:
return "minecraft:purple_bed:north:false:foot";
}
}
case facing_type::south:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:purple_bed:south:true:head";
case part_type::foot:
return "minecraft:purple_bed:south:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:purple_bed:south:false:head";
case part_type::foot:
return "minecraft:purple_bed:south:false:foot";
}
}
case facing_type::west:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:purple_bed:west:true:head";
case part_type::foot:
return "minecraft:purple_bed:west:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:purple_bed:west:false:head";
case part_type::foot:
return "minecraft:purple_bed:west:false:foot";
}
}
case facing_type::east:
switch (occupied)
{
case true:
switch (part)
{
case part_type::head:
return "minecraft:purple_bed:east:true:head";
case part_type::foot:
return "minecraft:purple_bed:east:true:foot";
}
case false:
switch (part)
{
case part_type::head:
return "minecraft:purple_bed:east:false:head";
case part_type::foot:
return "minecraft:purple_bed:east:false:foot";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
