#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct powered_rail
{bool powered = false;
enum class shape_type : std::uint8_t
{
north_south,
east_west,
ascending_east,
ascending_west,
ascending_north,
ascending_south
} shape = shape_type::north_south;
constexpr block_id_type to_id() const {
switch (powered)
{
case true:
switch (shape)
{
case shape_type::north_south:
return 1304;
case shape_type::east_west:
return 1305;
case shape_type::ascending_east:
return 1306;
case shape_type::ascending_west:
return 1307;
case shape_type::ascending_north:
return 1308;
case shape_type::ascending_south:
return 1309;
}
case false:
switch (shape)
{
case shape_type::north_south:
return 1310;
case shape_type::east_west:
return 1311;
case shape_type::ascending_east:
return 1312;
case shape_type::ascending_west:
return 1313;
case shape_type::ascending_north:
return 1314;
case shape_type::ascending_south:
return 1315;
}
}
}
constexpr static powered_rail from_id(block_id_type id)
{
switch (id)
{
case 1304:
return {.powered = true, .shape = shape_type::north_south};
case 1305:
return {.powered = true, .shape = shape_type::east_west};
case 1306:
return {.powered = true, .shape = shape_type::ascending_east};
case 1307:
return {.powered = true, .shape = shape_type::ascending_west};
case 1308:
return {.powered = true, .shape = shape_type::ascending_north};
case 1309:
return {.powered = true, .shape = shape_type::ascending_south};
case 1310:
return {.powered = false, .shape = shape_type::north_south};
case 1311:
return {.powered = false, .shape = shape_type::east_west};
case 1312:
return {.powered = false, .shape = shape_type::ascending_east};
case 1313:
return {.powered = false, .shape = shape_type::ascending_west};
case 1314:
return {.powered = false, .shape = shape_type::ascending_north};
case 1315:
return {.powered = false, .shape = shape_type::ascending_south};
}}
constexpr std::string_view to_string() const
{switch (powered)
{
case true:
switch (shape)
{
case shape_type::north_south:
return "minecraft:powered_rail:true:north_south";
case shape_type::east_west:
return "minecraft:powered_rail:true:east_west";
case shape_type::ascending_east:
return "minecraft:powered_rail:true:ascending_east";
case shape_type::ascending_west:
return "minecraft:powered_rail:true:ascending_west";
case shape_type::ascending_north:
return "minecraft:powered_rail:true:ascending_north";
case shape_type::ascending_south:
return "minecraft:powered_rail:true:ascending_south";
}
case false:
switch (shape)
{
case shape_type::north_south:
return "minecraft:powered_rail:false:north_south";
case shape_type::east_west:
return "minecraft:powered_rail:false:east_west";
case shape_type::ascending_east:
return "minecraft:powered_rail:false:ascending_east";
case shape_type::ascending_west:
return "minecraft:powered_rail:false:ascending_west";
case shape_type::ascending_north:
return "minecraft:powered_rail:false:ascending_north";
case shape_type::ascending_south:
return "minecraft:powered_rail:false:ascending_south";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
