#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct black_stained_glass_pane
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
return 6807;
case false:
return 6808;
}
case false:
switch (west)
{
case true:
return 6809;
case false:
return 6810;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6811;
case false:
return 6812;
}
case false:
switch (west)
{
case true:
return 6813;
case false:
return 6814;
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
return 6815;
case false:
return 6816;
}
case false:
switch (west)
{
case true:
return 6817;
case false:
return 6818;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6819;
case false:
return 6820;
}
case false:
switch (west)
{
case true:
return 6821;
case false:
return 6822;
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
return 6823;
case false:
return 6824;
}
case false:
switch (west)
{
case true:
return 6825;
case false:
return 6826;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6827;
case false:
return 6828;
}
case false:
switch (west)
{
case true:
return 6829;
case false:
return 6830;
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
return 6831;
case false:
return 6832;
}
case false:
switch (west)
{
case true:
return 6833;
case false:
return 6834;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6835;
case false:
return 6836;
}
case false:
switch (west)
{
case true:
return 6837;
case false:
return 6838;
}
}
}
}
}
}
constexpr static black_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6807:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6808:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6809:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6810:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6811:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6812:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6813:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6814:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6815:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6816:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6817:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6818:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6819:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6820:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6821:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6822:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6823:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6824:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6825:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6826:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6827:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6828:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6829:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6830:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6831:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6832:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6833:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6834:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6835:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6836:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6837:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6838:
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
return "minecraft:black_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:black_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:black_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:black_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:black_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:black_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:black_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:black_stained_glass_pane:true:true:false:false:false";
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
return "minecraft:black_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:black_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:black_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:black_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:black_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:black_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:black_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:black_stained_glass_pane:true:false:false:false:false";
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
return "minecraft:black_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:black_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:black_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:black_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:black_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:black_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:black_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:black_stained_glass_pane:false:true:false:false:false";
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
return "minecraft:black_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:black_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:black_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:black_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:black_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:black_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:black_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:black_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
