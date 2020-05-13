#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct nether_brick_wall
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
return 10715;
case false:
return 10716;
}
case false:
switch (west)
{
case true:
return 10717;
case false:
return 10718;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10719;
case false:
return 10720;
}
case false:
switch (west)
{
case true:
return 10721;
case false:
return 10722;
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
return 10723;
case false:
return 10724;
}
case false:
switch (west)
{
case true:
return 10725;
case false:
return 10726;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10727;
case false:
return 10728;
}
case false:
switch (west)
{
case true:
return 10729;
case false:
return 10730;
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
return 10731;
case false:
return 10732;
}
case false:
switch (west)
{
case true:
return 10733;
case false:
return 10734;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10735;
case false:
return 10736;
}
case false:
switch (west)
{
case true:
return 10737;
case false:
return 10738;
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
return 10739;
case false:
return 10740;
}
case false:
switch (west)
{
case true:
return 10741;
case false:
return 10742;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10743;
case false:
return 10744;
}
case false:
switch (west)
{
case true:
return 10745;
case false:
return 10746;
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
return 10747;
case false:
return 10748;
}
case false:
switch (west)
{
case true:
return 10749;
case false:
return 10750;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10751;
case false:
return 10752;
}
case false:
switch (west)
{
case true:
return 10753;
case false:
return 10754;
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
return 10755;
case false:
return 10756;
}
case false:
switch (west)
{
case true:
return 10757;
case false:
return 10758;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10759;
case false:
return 10760;
}
case false:
switch (west)
{
case true:
return 10761;
case false:
return 10762;
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
return 10763;
case false:
return 10764;
}
case false:
switch (west)
{
case true:
return 10765;
case false:
return 10766;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10767;
case false:
return 10768;
}
case false:
switch (west)
{
case true:
return 10769;
case false:
return 10770;
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
return 10771;
case false:
return 10772;
}
case false:
switch (west)
{
case true:
return 10773;
case false:
return 10774;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10775;
case false:
return 10776;
}
case false:
switch (west)
{
case true:
return 10777;
case false:
return 10778;
}
}
}
}
}
}
}
constexpr static nether_brick_wall from_id(block_id_type id)
{
switch (id)
{
case 10715:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10716:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10717:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10718:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10719:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10720:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10721:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10722:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10723:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10724:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10725:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10726:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10727:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10728:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10729:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10730:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10731:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10732:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10733:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10734:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10735:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10736:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10737:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10738:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10739:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10740:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10741:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10742:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10743:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10744:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10745:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10746:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
case 10747:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10748:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10749:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10750:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10751:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10752:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10753:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10754:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10755:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10756:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10757:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10758:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10759:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10760:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10761:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10762:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10763:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10764:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10765:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10766:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10767:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10768:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10769:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10770:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10771:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10772:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10773:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10774:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10775:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10776:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10777:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10778:
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
return "minecraft:nether_brick_wall:true:true:true:true:true:true";
case false:
return "minecraft:nether_brick_wall:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:true:true:true:true:false:true";
case false:
return "minecraft:nether_brick_wall:true:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:true:true:true:false:true:true";
case false:
return "minecraft:nether_brick_wall:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:true:true:true:false:false:true";
case false:
return "minecraft:nether_brick_wall:true:true:true:false:false:false";
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
return "minecraft:nether_brick_wall:true:true:false:true:true:true";
case false:
return "minecraft:nether_brick_wall:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:true:true:false:true:false:true";
case false:
return "minecraft:nether_brick_wall:true:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:true:true:false:false:true:true";
case false:
return "minecraft:nether_brick_wall:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:true:true:false:false:false:true";
case false:
return "minecraft:nether_brick_wall:true:true:false:false:false:false";
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
return "minecraft:nether_brick_wall:true:false:true:true:true:true";
case false:
return "minecraft:nether_brick_wall:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:true:false:true:true:false:true";
case false:
return "minecraft:nether_brick_wall:true:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:true:false:true:false:true:true";
case false:
return "minecraft:nether_brick_wall:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:true:false:true:false:false:true";
case false:
return "minecraft:nether_brick_wall:true:false:true:false:false:false";
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
return "minecraft:nether_brick_wall:true:false:false:true:true:true";
case false:
return "minecraft:nether_brick_wall:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:true:false:false:true:false:true";
case false:
return "minecraft:nether_brick_wall:true:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:true:false:false:false:true:true";
case false:
return "minecraft:nether_brick_wall:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:true:false:false:false:false:true";
case false:
return "minecraft:nether_brick_wall:true:false:false:false:false:false";
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
return "minecraft:nether_brick_wall:false:true:true:true:true:true";
case false:
return "minecraft:nether_brick_wall:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:false:true:true:true:false:true";
case false:
return "minecraft:nether_brick_wall:false:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:false:true:true:false:true:true";
case false:
return "minecraft:nether_brick_wall:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:false:true:true:false:false:true";
case false:
return "minecraft:nether_brick_wall:false:true:true:false:false:false";
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
return "minecraft:nether_brick_wall:false:true:false:true:true:true";
case false:
return "minecraft:nether_brick_wall:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:false:true:false:true:false:true";
case false:
return "minecraft:nether_brick_wall:false:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:false:true:false:false:true:true";
case false:
return "minecraft:nether_brick_wall:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:false:true:false:false:false:true";
case false:
return "minecraft:nether_brick_wall:false:true:false:false:false:false";
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
return "minecraft:nether_brick_wall:false:false:true:true:true:true";
case false:
return "minecraft:nether_brick_wall:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:false:false:true:true:false:true";
case false:
return "minecraft:nether_brick_wall:false:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:false:false:true:false:true:true";
case false:
return "minecraft:nether_brick_wall:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:false:false:true:false:false:true";
case false:
return "minecraft:nether_brick_wall:false:false:true:false:false:false";
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
return "minecraft:nether_brick_wall:false:false:false:true:true:true";
case false:
return "minecraft:nether_brick_wall:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:false:false:false:true:false:true";
case false:
return "minecraft:nether_brick_wall:false:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:false:false:false:false:true:true";
case false:
return "minecraft:nether_brick_wall:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:nether_brick_wall:false:false:false:false:false:true";
case false:
return "minecraft:nether_brick_wall:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
