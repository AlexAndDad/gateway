#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct green_stained_glass_pane
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
return 6743;
case false:
return 6744;
}
case false:
switch (west)
{
case true:
return 6745;
case false:
return 6746;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6747;
case false:
return 6748;
}
case false:
switch (west)
{
case true:
return 6749;
case false:
return 6750;
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
return 6751;
case false:
return 6752;
}
case false:
switch (west)
{
case true:
return 6753;
case false:
return 6754;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6755;
case false:
return 6756;
}
case false:
switch (west)
{
case true:
return 6757;
case false:
return 6758;
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
return 6759;
case false:
return 6760;
}
case false:
switch (west)
{
case true:
return 6761;
case false:
return 6762;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6763;
case false:
return 6764;
}
case false:
switch (west)
{
case true:
return 6765;
case false:
return 6766;
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
return 6767;
case false:
return 6768;
}
case false:
switch (west)
{
case true:
return 6769;
case false:
return 6770;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6771;
case false:
return 6772;
}
case false:
switch (west)
{
case true:
return 6773;
case false:
return 6774;
}
}
}
}
}
}
constexpr static green_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6743:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6744:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6745:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6746:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6747:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6748:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6749:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6750:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6751:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6752:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6753:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6754:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6755:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6756:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6757:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6758:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6759:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6760:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6761:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6762:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6763:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6764:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6765:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6766:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6767:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6768:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6769:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6770:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6771:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6772:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6773:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6774:
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
return "minecraft:green_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:green_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:green_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:green_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:green_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:green_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:green_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:green_stained_glass_pane:true:true:false:false:false";
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
return "minecraft:green_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:green_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:green_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:green_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:green_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:green_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:green_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:green_stained_glass_pane:true:false:false:false:false";
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
return "minecraft:green_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:green_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:green_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:green_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:green_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:green_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:green_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:green_stained_glass_pane:false:true:false:false:false";
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
return "minecraft:green_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:green_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:green_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:green_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:green_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:green_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:green_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:green_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
