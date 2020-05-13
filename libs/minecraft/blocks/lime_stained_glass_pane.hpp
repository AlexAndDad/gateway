#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct lime_stained_glass_pane
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
return 6487;
case false:
return 6488;
}
case false:
switch (west)
{
case true:
return 6489;
case false:
return 6490;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6491;
case false:
return 6492;
}
case false:
switch (west)
{
case true:
return 6493;
case false:
return 6494;
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
return 6495;
case false:
return 6496;
}
case false:
switch (west)
{
case true:
return 6497;
case false:
return 6498;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6499;
case false:
return 6500;
}
case false:
switch (west)
{
case true:
return 6501;
case false:
return 6502;
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
return 6503;
case false:
return 6504;
}
case false:
switch (west)
{
case true:
return 6505;
case false:
return 6506;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6507;
case false:
return 6508;
}
case false:
switch (west)
{
case true:
return 6509;
case false:
return 6510;
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
return 6511;
case false:
return 6512;
}
case false:
switch (west)
{
case true:
return 6513;
case false:
return 6514;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6515;
case false:
return 6516;
}
case false:
switch (west)
{
case true:
return 6517;
case false:
return 6518;
}
}
}
}
}
}
constexpr static lime_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6487:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6488:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6489:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6490:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6491:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6492:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6493:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6494:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6495:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6496:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6497:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6498:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6499:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6500:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6501:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6502:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6503:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6504:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6505:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6506:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6507:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6508:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6509:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6510:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6511:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6512:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6513:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6514:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6515:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6516:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6517:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6518:
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
return "minecraft:lime_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:lime_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:lime_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:lime_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:lime_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:lime_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:lime_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:lime_stained_glass_pane:true:true:false:false:false";
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
return "minecraft:lime_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:lime_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:lime_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:lime_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:lime_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:lime_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:lime_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:lime_stained_glass_pane:true:false:false:false:false";
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
return "minecraft:lime_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:lime_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:lime_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:lime_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:lime_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:lime_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:lime_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:lime_stained_glass_pane:false:true:false:false:false";
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
return "minecraft:lime_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:lime_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:lime_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:lime_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:lime_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:lime_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:lime_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:lime_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
