#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct mossy_cobblestone_wall
{bool east = false;
bool north = false;
bool south = false;
bool up = true;
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
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5705;
case false:
return 5706;
}
case false:
switch (west)
{
case true:
return 5707;
case false:
return 5708;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5709;
case false:
return 5710;
}
case false:
switch (west)
{
case true:
return 5711;
case false:
return 5712;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5713;
case false:
return 5714;
}
case false:
switch (west)
{
case true:
return 5715;
case false:
return 5716;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5717;
case false:
return 5718;
}
case false:
switch (west)
{
case true:
return 5719;
case false:
return 5720;
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5721;
case false:
return 5722;
}
case false:
switch (west)
{
case true:
return 5723;
case false:
return 5724;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5725;
case false:
return 5726;
}
case false:
switch (west)
{
case true:
return 5727;
case false:
return 5728;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5729;
case false:
return 5730;
}
case false:
switch (west)
{
case true:
return 5731;
case false:
return 5732;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5733;
case false:
return 5734;
}
case false:
switch (west)
{
case true:
return 5735;
case false:
return 5736;
}
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
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5737;
case false:
return 5738;
}
case false:
switch (west)
{
case true:
return 5739;
case false:
return 5740;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5741;
case false:
return 5742;
}
case false:
switch (west)
{
case true:
return 5743;
case false:
return 5744;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5745;
case false:
return 5746;
}
case false:
switch (west)
{
case true:
return 5747;
case false:
return 5748;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5749;
case false:
return 5750;
}
case false:
switch (west)
{
case true:
return 5751;
case false:
return 5752;
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5753;
case false:
return 5754;
}
case false:
switch (west)
{
case true:
return 5755;
case false:
return 5756;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5757;
case false:
return 5758;
}
case false:
switch (west)
{
case true:
return 5759;
case false:
return 5760;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5761;
case false:
return 5762;
}
case false:
switch (west)
{
case true:
return 5763;
case false:
return 5764;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 5765;
case false:
return 5766;
}
case false:
switch (west)
{
case true:
return 5767;
case false:
return 5768;
}
}
}
}
}
}
}
constexpr static mossy_cobblestone_wall from_id(block_id_type id)
{
switch (id)
{
case 5705:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 5706:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 5707:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 5708:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 5709:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 5710:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 5711:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 5712:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 5713:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 5714:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 5715:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 5716:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 5717:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 5718:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 5719:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 5720:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 5721:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 5722:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 5723:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 5724:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 5725:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 5726:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 5727:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 5728:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 5729:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 5730:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 5731:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 5732:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 5733:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 5734:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 5735:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 5736:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
case 5737:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 5738:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 5739:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 5740:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 5741:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 5742:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 5743:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 5744:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 5745:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 5746:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 5747:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 5748:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 5749:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 5750:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 5751:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 5752:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 5753:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 5754:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 5755:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 5756:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 5757:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 5758:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 5759:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 5760:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 5761:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 5762:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 5763:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 5764:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 5765:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 5766:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 5767:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 5768:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
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
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:true:true:true:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:true:true:true:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:true:true:false:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:true:true:false:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:true:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:true:false:true:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:true:false:true:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:true:false:false:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:true:false:false:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:true:false:false:false:false";
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:false:true:true:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:false:true:true:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:false:true:false:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:false:true:false:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:false:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:false:false:true:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:false:false:true:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:false:false:false:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:true:false:false:false:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:true:false:false:false:false:false";
}
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
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:true:true:true:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:true:true:true:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:true:true:false:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:true:true:false:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:true:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:true:false:true:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:true:false:true:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:true:false:false:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:true:false:false:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:true:false:false:false:false";
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:false:true:true:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:false:true:true:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:false:true:false:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:false:true:false:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:false:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:false:false:true:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:false:false:true:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:false:false:false:true:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:mossy_cobblestone_wall:false:false:false:false:false:true";
case false:
return "minecraft:mossy_cobblestone_wall:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
