#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct glass_pane
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
return 4715;
case false:
return 4716;
}
case false:
switch (west)
{
case true:
return 4717;
case false:
return 4718;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 4719;
case false:
return 4720;
}
case false:
switch (west)
{
case true:
return 4721;
case false:
return 4722;
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
return 4723;
case false:
return 4724;
}
case false:
switch (west)
{
case true:
return 4725;
case false:
return 4726;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 4727;
case false:
return 4728;
}
case false:
switch (west)
{
case true:
return 4729;
case false:
return 4730;
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
return 4731;
case false:
return 4732;
}
case false:
switch (west)
{
case true:
return 4733;
case false:
return 4734;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 4735;
case false:
return 4736;
}
case false:
switch (west)
{
case true:
return 4737;
case false:
return 4738;
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
return 4739;
case false:
return 4740;
}
case false:
switch (west)
{
case true:
return 4741;
case false:
return 4742;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 4743;
case false:
return 4744;
}
case false:
switch (west)
{
case true:
return 4745;
case false:
return 4746;
}
}
}
}
}
}
constexpr static glass_pane from_id(block_id_type id)
{
switch (id)
{
case 4715:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 4716:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 4717:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 4718:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 4719:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 4720:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 4721:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 4722:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 4723:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 4724:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 4725:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 4726:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 4727:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 4728:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 4729:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 4730:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 4731:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 4732:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 4733:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 4734:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 4735:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 4736:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 4737:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 4738:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 4739:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 4740:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 4741:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 4742:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 4743:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 4744:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 4745:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 4746:
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
return "minecraft:glass_pane:true:true:true:true:true";
case false:
return "minecraft:glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:glass_pane:true:true:true:false:true";
case false:
return "minecraft:glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:glass_pane:true:true:false:true:true";
case false:
return "minecraft:glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:glass_pane:true:true:false:false:true";
case false:
return "minecraft:glass_pane:true:true:false:false:false";
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
return "minecraft:glass_pane:true:false:true:true:true";
case false:
return "minecraft:glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:glass_pane:true:false:true:false:true";
case false:
return "minecraft:glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:glass_pane:true:false:false:true:true";
case false:
return "minecraft:glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:glass_pane:true:false:false:false:true";
case false:
return "minecraft:glass_pane:true:false:false:false:false";
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
return "minecraft:glass_pane:false:true:true:true:true";
case false:
return "minecraft:glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:glass_pane:false:true:true:false:true";
case false:
return "minecraft:glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:glass_pane:false:true:false:true:true";
case false:
return "minecraft:glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:glass_pane:false:true:false:false:true";
case false:
return "minecraft:glass_pane:false:true:false:false:false";
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
return "minecraft:glass_pane:false:false:true:true:true";
case false:
return "minecraft:glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:glass_pane:false:false:true:false:true";
case false:
return "minecraft:glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:glass_pane:false:false:false:true:true";
case false:
return "minecraft:glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:glass_pane:false:false:false:false:true";
case false:
return "minecraft:glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
