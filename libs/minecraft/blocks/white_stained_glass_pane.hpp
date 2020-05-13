#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct white_stained_glass_pane
{bool east = false;
bool north = false;
bool south = false;
bool waterlogged = false;
bool west = false;
constexpr block_id_type to_id() const {
switch (east)
{
case true:
switch (north)
{
case true:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6327;
case false:
return 6328;
}
case false:
switch (west)
{
case true:
return 6329;
case false:
return 6330;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6331;
case false:
return 6332;
}
case false:
switch (west)
{
case true:
return 6333;
case false:
return 6334;
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6335;
case false:
return 6336;
}
case false:
switch (west)
{
case true:
return 6337;
case false:
return 6338;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6339;
case false:
return 6340;
}
case false:
switch (west)
{
case true:
return 6341;
case false:
return 6342;
}
}
}
}
case false:
switch (north)
{
case true:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6343;
case false:
return 6344;
}
case false:
switch (west)
{
case true:
return 6345;
case false:
return 6346;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6347;
case false:
return 6348;
}
case false:
switch (west)
{
case true:
return 6349;
case false:
return 6350;
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6351;
case false:
return 6352;
}
case false:
switch (west)
{
case true:
return 6353;
case false:
return 6354;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6355;
case false:
return 6356;
}
case false:
switch (west)
{
case true:
return 6357;
case false:
return 6358;
}
}
}
}
}
}
constexpr static white_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6327:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6328:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6329:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6330:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6331:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6332:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6333:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6334:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6335:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6336:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6337:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6338:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6339:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6340:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6341:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6342:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6343:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6344:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6345:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6346:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6347:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6348:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6349:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6350:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6351:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6352:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6353:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6354:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6355:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6356:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6357:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6358:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = false};
}}
constexpr std::string_view to_string() const
{switch (east)
{
case true:
switch (north)
{
case true:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:white_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:white_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:white_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:white_stained_glass_pane:true:true:false:false:false";
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:white_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:white_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:white_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:white_stained_glass_pane:true:false:false:false:false";
}
}
}
}
case false:
switch (north)
{
case true:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:white_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:white_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:white_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:white_stained_glass_pane:false:true:false:false:false";
}
}
}
case false:
switch (south)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:white_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:white_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:white_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:white_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:white_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
