#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct brown_stained_glass_pane
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
return 6711;
case false:
return 6712;
}
case false:
switch (west)
{
case true:
return 6713;
case false:
return 6714;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6715;
case false:
return 6716;
}
case false:
switch (west)
{
case true:
return 6717;
case false:
return 6718;
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
return 6719;
case false:
return 6720;
}
case false:
switch (west)
{
case true:
return 6721;
case false:
return 6722;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6723;
case false:
return 6724;
}
case false:
switch (west)
{
case true:
return 6725;
case false:
return 6726;
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
return 6727;
case false:
return 6728;
}
case false:
switch (west)
{
case true:
return 6729;
case false:
return 6730;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6731;
case false:
return 6732;
}
case false:
switch (west)
{
case true:
return 6733;
case false:
return 6734;
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
return 6735;
case false:
return 6736;
}
case false:
switch (west)
{
case true:
return 6737;
case false:
return 6738;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6739;
case false:
return 6740;
}
case false:
switch (west)
{
case true:
return 6741;
case false:
return 6742;
}
}
}
}
}
}
constexpr static brown_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6711:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6712:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6713:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6714:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6715:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6716:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6717:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6718:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6719:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6720:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6721:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6722:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6723:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6724:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6725:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6726:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6727:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6728:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6729:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6730:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6731:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6732:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6733:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6734:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6735:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6736:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6737:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6738:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6739:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6740:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6741:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6742:
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
return "minecraft:brown_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:brown_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:brown_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brown_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:brown_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:brown_stained_glass_pane:true:true:false:false:false";
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
return "minecraft:brown_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:brown_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:brown_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brown_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:brown_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:brown_stained_glass_pane:true:false:false:false:false";
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
return "minecraft:brown_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:brown_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:brown_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brown_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:brown_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:brown_stained_glass_pane:false:true:false:false:false";
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
return "minecraft:brown_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:brown_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:brown_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brown_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:brown_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:brown_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
