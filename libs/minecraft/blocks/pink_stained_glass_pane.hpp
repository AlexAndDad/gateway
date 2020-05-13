#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct pink_stained_glass_pane
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
return 6519;
case false:
return 6520;
}
case false:
switch (west)
{
case true:
return 6521;
case false:
return 6522;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6523;
case false:
return 6524;
}
case false:
switch (west)
{
case true:
return 6525;
case false:
return 6526;
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
return 6527;
case false:
return 6528;
}
case false:
switch (west)
{
case true:
return 6529;
case false:
return 6530;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6531;
case false:
return 6532;
}
case false:
switch (west)
{
case true:
return 6533;
case false:
return 6534;
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
return 6535;
case false:
return 6536;
}
case false:
switch (west)
{
case true:
return 6537;
case false:
return 6538;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6539;
case false:
return 6540;
}
case false:
switch (west)
{
case true:
return 6541;
case false:
return 6542;
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
return 6543;
case false:
return 6544;
}
case false:
switch (west)
{
case true:
return 6545;
case false:
return 6546;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6547;
case false:
return 6548;
}
case false:
switch (west)
{
case true:
return 6549;
case false:
return 6550;
}
}
}
}
}
}
constexpr static pink_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6519:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6520:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6521:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6522:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6523:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6524:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6525:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6526:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6527:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6528:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6529:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6530:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6531:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6532:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6533:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6534:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6535:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6536:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6537:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6538:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6539:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6540:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6541:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6542:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6543:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6544:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6545:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6546:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6547:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6548:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6549:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6550:
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
return "minecraft:pink_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:pink_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:pink_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:pink_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:pink_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:pink_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:pink_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:pink_stained_glass_pane:true:true:false:false:false";
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
return "minecraft:pink_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:pink_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:pink_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:pink_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:pink_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:pink_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:pink_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:pink_stained_glass_pane:true:false:false:false:false";
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
return "minecraft:pink_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:pink_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:pink_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:pink_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:pink_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:pink_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:pink_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:pink_stained_glass_pane:false:true:false:false:false";
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
return "minecraft:pink_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:pink_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:pink_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:pink_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:pink_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:pink_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:pink_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:pink_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
