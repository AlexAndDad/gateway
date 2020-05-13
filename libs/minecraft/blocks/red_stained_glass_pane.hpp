#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct red_stained_glass_pane
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
return 6775;
case false:
return 6776;
}
case false:
switch (west)
{
case true:
return 6777;
case false:
return 6778;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6779;
case false:
return 6780;
}
case false:
switch (west)
{
case true:
return 6781;
case false:
return 6782;
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
return 6783;
case false:
return 6784;
}
case false:
switch (west)
{
case true:
return 6785;
case false:
return 6786;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6787;
case false:
return 6788;
}
case false:
switch (west)
{
case true:
return 6789;
case false:
return 6790;
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
return 6791;
case false:
return 6792;
}
case false:
switch (west)
{
case true:
return 6793;
case false:
return 6794;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6795;
case false:
return 6796;
}
case false:
switch (west)
{
case true:
return 6797;
case false:
return 6798;
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
return 6799;
case false:
return 6800;
}
case false:
switch (west)
{
case true:
return 6801;
case false:
return 6802;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6803;
case false:
return 6804;
}
case false:
switch (west)
{
case true:
return 6805;
case false:
return 6806;
}
}
}
}
}
}
constexpr static red_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6775:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6776:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6777:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6778:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6779:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6780:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6781:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6782:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6783:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6784:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6785:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6786:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6787:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6788:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6789:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6790:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6791:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6792:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6793:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6794:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6795:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6796:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6797:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6798:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6799:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6800:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6801:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6802:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6803:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6804:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6805:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6806:
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
return "minecraft:red_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:red_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:red_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:red_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:red_stained_glass_pane:true:true:false:false:false";
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
return "minecraft:red_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:red_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:red_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:red_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:red_stained_glass_pane:true:false:false:false:false";
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
return "minecraft:red_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:red_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:red_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:red_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:red_stained_glass_pane:false:true:false:false:false";
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
return "minecraft:red_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:red_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:red_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:red_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:red_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
