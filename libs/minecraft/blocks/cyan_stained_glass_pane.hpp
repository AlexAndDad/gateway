#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct cyan_stained_glass_pane
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
return 6615;
case false:
return 6616;
}
case false:
switch (west)
{
case true:
return 6617;
case false:
return 6618;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6619;
case false:
return 6620;
}
case false:
switch (west)
{
case true:
return 6621;
case false:
return 6622;
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
return 6623;
case false:
return 6624;
}
case false:
switch (west)
{
case true:
return 6625;
case false:
return 6626;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6627;
case false:
return 6628;
}
case false:
switch (west)
{
case true:
return 6629;
case false:
return 6630;
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
return 6631;
case false:
return 6632;
}
case false:
switch (west)
{
case true:
return 6633;
case false:
return 6634;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6635;
case false:
return 6636;
}
case false:
switch (west)
{
case true:
return 6637;
case false:
return 6638;
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
return 6639;
case false:
return 6640;
}
case false:
switch (west)
{
case true:
return 6641;
case false:
return 6642;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6643;
case false:
return 6644;
}
case false:
switch (west)
{
case true:
return 6645;
case false:
return 6646;
}
}
}
}
}
}
constexpr static cyan_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6615:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6616:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6617:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6618:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6619:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6620:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6621:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6622:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6623:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6624:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6625:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6626:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6627:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6628:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6629:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6630:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6631:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6632:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6633:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6634:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6635:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6636:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6637:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6638:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6639:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6640:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6641:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6642:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6643:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6644:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6645:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6646:
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
return "minecraft:cyan_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:cyan_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cyan_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:cyan_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:cyan_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:cyan_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cyan_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:cyan_stained_glass_pane:true:true:false:false:false";
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
return "minecraft:cyan_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:cyan_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cyan_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:cyan_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:cyan_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:cyan_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cyan_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:cyan_stained_glass_pane:true:false:false:false:false";
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
return "minecraft:cyan_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:cyan_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cyan_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:cyan_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:cyan_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:cyan_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cyan_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:cyan_stained_glass_pane:false:true:false:false:false";
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
return "minecraft:cyan_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:cyan_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cyan_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:cyan_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:cyan_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:cyan_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:cyan_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:cyan_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
