#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct yellow_stained_glass_pane
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
return 6455;
case false:
return 6456;
}
case false:
switch (west)
{
case true:
return 6457;
case false:
return 6458;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6459;
case false:
return 6460;
}
case false:
switch (west)
{
case true:
return 6461;
case false:
return 6462;
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
return 6463;
case false:
return 6464;
}
case false:
switch (west)
{
case true:
return 6465;
case false:
return 6466;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6467;
case false:
return 6468;
}
case false:
switch (west)
{
case true:
return 6469;
case false:
return 6470;
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
return 6471;
case false:
return 6472;
}
case false:
switch (west)
{
case true:
return 6473;
case false:
return 6474;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6475;
case false:
return 6476;
}
case false:
switch (west)
{
case true:
return 6477;
case false:
return 6478;
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
return 6479;
case false:
return 6480;
}
case false:
switch (west)
{
case true:
return 6481;
case false:
return 6482;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6483;
case false:
return 6484;
}
case false:
switch (west)
{
case true:
return 6485;
case false:
return 6486;
}
}
}
}
}
}
constexpr static yellow_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6455:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6456:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6457:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6458:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6459:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6460:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6461:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6462:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6463:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6464:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6465:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6466:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6467:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6468:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6469:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6470:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6471:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6472:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6473:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6474:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6475:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6476:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6477:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6478:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6479:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6480:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6481:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6482:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6483:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6484:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6485:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6486:
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
return "minecraft:yellow_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:yellow_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:yellow_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:yellow_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:yellow_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:yellow_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:yellow_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:yellow_stained_glass_pane:true:true:false:false:false";
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
return "minecraft:yellow_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:yellow_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:yellow_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:yellow_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:yellow_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:yellow_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:yellow_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:yellow_stained_glass_pane:true:false:false:false:false";
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
return "minecraft:yellow_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:yellow_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:yellow_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:yellow_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:yellow_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:yellow_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:yellow_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:yellow_stained_glass_pane:false:true:false:false:false";
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
return "minecraft:yellow_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:yellow_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:yellow_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:yellow_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:yellow_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:yellow_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:yellow_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:yellow_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
