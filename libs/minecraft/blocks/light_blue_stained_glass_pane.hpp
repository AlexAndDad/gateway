#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct light_blue_stained_glass_pane
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
return 6423;
case false:
return 6424;
}
case false:
switch (west)
{
case true:
return 6425;
case false:
return 6426;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6427;
case false:
return 6428;
}
case false:
switch (west)
{
case true:
return 6429;
case false:
return 6430;
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
return 6431;
case false:
return 6432;
}
case false:
switch (west)
{
case true:
return 6433;
case false:
return 6434;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6435;
case false:
return 6436;
}
case false:
switch (west)
{
case true:
return 6437;
case false:
return 6438;
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
return 6439;
case false:
return 6440;
}
case false:
switch (west)
{
case true:
return 6441;
case false:
return 6442;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6443;
case false:
return 6444;
}
case false:
switch (west)
{
case true:
return 6445;
case false:
return 6446;
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
return 6447;
case false:
return 6448;
}
case false:
switch (west)
{
case true:
return 6449;
case false:
return 6450;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6451;
case false:
return 6452;
}
case false:
switch (west)
{
case true:
return 6453;
case false:
return 6454;
}
}
}
}
}
}
constexpr static light_blue_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6423:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6424:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6425:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6426:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6427:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6428:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6429:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6430:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6431:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6432:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6433:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6434:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6435:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6436:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6437:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6438:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6439:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6440:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6441:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6442:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6443:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6444:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6445:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6446:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6447:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6448:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6449:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6450:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6451:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6452:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6453:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6454:
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
return "minecraft:light_blue_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:light_blue_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_blue_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:light_blue_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:light_blue_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:light_blue_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_blue_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:light_blue_stained_glass_pane:true:true:false:false:false";
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
return "minecraft:light_blue_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:light_blue_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_blue_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:light_blue_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:light_blue_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:light_blue_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_blue_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:light_blue_stained_glass_pane:true:false:false:false:false";
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
return "minecraft:light_blue_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:light_blue_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_blue_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:light_blue_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:light_blue_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:light_blue_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_blue_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:light_blue_stained_glass_pane:false:true:false:false:false";
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
return "minecraft:light_blue_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:light_blue_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_blue_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:light_blue_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:light_blue_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:light_blue_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_blue_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:light_blue_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
