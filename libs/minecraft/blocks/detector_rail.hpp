#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct detector_rail
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
return 1316;
case shape_type::east_west:
return 1317;
case shape_type::ascending_east:
return 1318;
case shape_type::ascending_west:
return 1319;
case shape_type::ascending_north:
return 1320;
case shape_type::ascending_south:
return 1321;
}
case false:
switch (shape)
{
case shape_type::north_south:
return 1322;
case shape_type::east_west:
return 1323;
case shape_type::ascending_east:
return 1324;
case shape_type::ascending_west:
return 1325;
case shape_type::ascending_north:
return 1326;
case shape_type::ascending_south:
return 1327;
}
}
}
constexpr static detector_rail from_id(block_id_type id)
{
switch (id)
{
case 1316:
return {.powered = true, .shape = shape_type::north_south};
case 1317:
return {.powered = true, .shape = shape_type::east_west};
case 1318:
return {.powered = true, .shape = shape_type::ascending_east};
case 1319:
return {.powered = true, .shape = shape_type::ascending_west};
case 1320:
return {.powered = true, .shape = shape_type::ascending_north};
case 1321:
return {.powered = true, .shape = shape_type::ascending_south};
case 1322:
return {.powered = false, .shape = shape_type::north_south};
case 1323:
return {.powered = false, .shape = shape_type::east_west};
case 1324:
return {.powered = false, .shape = shape_type::ascending_east};
case 1325:
return {.powered = false, .shape = shape_type::ascending_west};
case 1326:
return {.powered = false, .shape = shape_type::ascending_north};
case 1327:
return {.powered = false, .shape = shape_type::ascending_south};
}}
constexpr std::string_view to_string() const
{switch (powered)
{
case true:
switch (shape)
{
case shape_type::north_south:
return "minecraft:detector_rail:true:north_south";
case shape_type::east_west:
return "minecraft:detector_rail:true:east_west";
case shape_type::ascending_east:
return "minecraft:detector_rail:true:ascending_east";
case shape_type::ascending_west:
return "minecraft:detector_rail:true:ascending_west";
case shape_type::ascending_north:
return "minecraft:detector_rail:true:ascending_north";
case shape_type::ascending_south:
return "minecraft:detector_rail:true:ascending_south";
}
case false:
switch (shape)
{
case shape_type::north_south:
return "minecraft:detector_rail:false:north_south";
case shape_type::east_west:
return "minecraft:detector_rail:false:east_west";
case shape_type::ascending_east:
return "minecraft:detector_rail:false:ascending_east";
case shape_type::ascending_west:
return "minecraft:detector_rail:false:ascending_west";
case shape_type::ascending_north:
return "minecraft:detector_rail:false:ascending_north";
case shape_type::ascending_south:
return "minecraft:detector_rail:false:ascending_south";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
