#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct light_gray_stained_glass_pane
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
return 6583;
case false:
return 6584;
}
case false:
switch (west)
{
case true:
return 6585;
case false:
return 6586;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6587;
case false:
return 6588;
}
case false:
switch (west)
{
case true:
return 6589;
case false:
return 6590;
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
return 6591;
case false:
return 6592;
}
case false:
switch (west)
{
case true:
return 6593;
case false:
return 6594;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6595;
case false:
return 6596;
}
case false:
switch (west)
{
case true:
return 6597;
case false:
return 6598;
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
return 6599;
case false:
return 6600;
}
case false:
switch (west)
{
case true:
return 6601;
case false:
return 6602;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6603;
case false:
return 6604;
}
case false:
switch (west)
{
case true:
return 6605;
case false:
return 6606;
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
return 6607;
case false:
return 6608;
}
case false:
switch (west)
{
case true:
return 6609;
case false:
return 6610;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6611;
case false:
return 6612;
}
case false:
switch (west)
{
case true:
return 6613;
case false:
return 6614;
}
}
}
}
}
}
constexpr static light_gray_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6583:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6584:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6585:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6586:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6587:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6588:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6589:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6590:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6591:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6592:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6593:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6594:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6595:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6596:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6597:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6598:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6599:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6600:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6601:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6602:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6603:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6604:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6605:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6606:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6607:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6608:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6609:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6610:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6611:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6612:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6613:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6614:
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
return "minecraft:light_gray_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:light_gray_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_gray_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:light_gray_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:light_gray_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:light_gray_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_gray_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:light_gray_stained_glass_pane:true:true:false:false:false";
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
return "minecraft:light_gray_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:light_gray_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_gray_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:light_gray_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:light_gray_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:light_gray_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_gray_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:light_gray_stained_glass_pane:true:false:false:false:false";
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
return "minecraft:light_gray_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:light_gray_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_gray_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:light_gray_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:light_gray_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:light_gray_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_gray_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:light_gray_stained_glass_pane:false:true:false:false:false";
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
return "minecraft:light_gray_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:light_gray_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_gray_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:light_gray_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:light_gray_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:light_gray_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:light_gray_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:light_gray_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
