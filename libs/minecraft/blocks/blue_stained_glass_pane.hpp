#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct blue_stained_glass_pane
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
return 6679;
case false:
return 6680;
}
case false:
switch (west)
{
case true:
return 6681;
case false:
return 6682;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6683;
case false:
return 6684;
}
case false:
switch (west)
{
case true:
return 6685;
case false:
return 6686;
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
return 6687;
case false:
return 6688;
}
case false:
switch (west)
{
case true:
return 6689;
case false:
return 6690;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6691;
case false:
return 6692;
}
case false:
switch (west)
{
case true:
return 6693;
case false:
return 6694;
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
return 6695;
case false:
return 6696;
}
case false:
switch (west)
{
case true:
return 6697;
case false:
return 6698;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6699;
case false:
return 6700;
}
case false:
switch (west)
{
case true:
return 6701;
case false:
return 6702;
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
return 6703;
case false:
return 6704;
}
case false:
switch (west)
{
case true:
return 6705;
case false:
return 6706;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 6707;
case false:
return 6708;
}
case false:
switch (west)
{
case true:
return 6709;
case false:
return 6710;
}
}
}
}
}
}
constexpr static blue_stained_glass_pane from_id(block_id_type id)
{
switch (id)
{
case 6679:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 6680:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 6681:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 6682:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 6683:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 6684:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 6685:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 6686:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 6687:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 6688:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 6689:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 6690:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 6691:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 6692:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 6693:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 6694:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 6695:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 6696:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 6697:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 6698:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 6699:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 6700:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 6701:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 6702:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 6703:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 6704:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 6705:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 6706:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 6707:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 6708:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 6709:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 6710:
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
return "minecraft:blue_stained_glass_pane:true:true:true:true:true";
case false:
return "minecraft:blue_stained_glass_pane:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:blue_stained_glass_pane:true:true:true:false:true";
case false:
return "minecraft:blue_stained_glass_pane:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:blue_stained_glass_pane:true:true:false:true:true";
case false:
return "minecraft:blue_stained_glass_pane:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:blue_stained_glass_pane:true:true:false:false:true";
case false:
return "minecraft:blue_stained_glass_pane:true:true:false:false:false";
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
return "minecraft:blue_stained_glass_pane:true:false:true:true:true";
case false:
return "minecraft:blue_stained_glass_pane:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:blue_stained_glass_pane:true:false:true:false:true";
case false:
return "minecraft:blue_stained_glass_pane:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:blue_stained_glass_pane:true:false:false:true:true";
case false:
return "minecraft:blue_stained_glass_pane:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:blue_stained_glass_pane:true:false:false:false:true";
case false:
return "minecraft:blue_stained_glass_pane:true:false:false:false:false";
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
return "minecraft:blue_stained_glass_pane:false:true:true:true:true";
case false:
return "minecraft:blue_stained_glass_pane:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:blue_stained_glass_pane:false:true:true:false:true";
case false:
return "minecraft:blue_stained_glass_pane:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:blue_stained_glass_pane:false:true:false:true:true";
case false:
return "minecraft:blue_stained_glass_pane:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:blue_stained_glass_pane:false:true:false:false:true";
case false:
return "minecraft:blue_stained_glass_pane:false:true:false:false:false";
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
return "minecraft:blue_stained_glass_pane:false:false:true:true:true";
case false:
return "minecraft:blue_stained_glass_pane:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:blue_stained_glass_pane:false:false:true:false:true";
case false:
return "minecraft:blue_stained_glass_pane:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:blue_stained_glass_pane:false:false:false:true:true";
case false:
return "minecraft:blue_stained_glass_pane:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:blue_stained_glass_pane:false:false:false:false:true";
case false:
return "minecraft:blue_stained_glass_pane:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
