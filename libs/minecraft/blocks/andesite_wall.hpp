#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct andesite_wall
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
return 10779;
case false:
return 10780;
}
case false:
switch (west)
{
case true:
return 10781;
case false:
return 10782;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10783;
case false:
return 10784;
}
case false:
switch (west)
{
case true:
return 10785;
case false:
return 10786;
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
return 10787;
case false:
return 10788;
}
case false:
switch (west)
{
case true:
return 10789;
case false:
return 10790;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10791;
case false:
return 10792;
}
case false:
switch (west)
{
case true:
return 10793;
case false:
return 10794;
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
return 10795;
case false:
return 10796;
}
case false:
switch (west)
{
case true:
return 10797;
case false:
return 10798;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10799;
case false:
return 10800;
}
case false:
switch (west)
{
case true:
return 10801;
case false:
return 10802;
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
return 10803;
case false:
return 10804;
}
case false:
switch (west)
{
case true:
return 10805;
case false:
return 10806;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10807;
case false:
return 10808;
}
case false:
switch (west)
{
case true:
return 10809;
case false:
return 10810;
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
return 10811;
case false:
return 10812;
}
case false:
switch (west)
{
case true:
return 10813;
case false:
return 10814;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10815;
case false:
return 10816;
}
case false:
switch (west)
{
case true:
return 10817;
case false:
return 10818;
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
return 10819;
case false:
return 10820;
}
case false:
switch (west)
{
case true:
return 10821;
case false:
return 10822;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10823;
case false:
return 10824;
}
case false:
switch (west)
{
case true:
return 10825;
case false:
return 10826;
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
return 10827;
case false:
return 10828;
}
case false:
switch (west)
{
case true:
return 10829;
case false:
return 10830;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10831;
case false:
return 10832;
}
case false:
switch (west)
{
case true:
return 10833;
case false:
return 10834;
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
return 10835;
case false:
return 10836;
}
case false:
switch (west)
{
case true:
return 10837;
case false:
return 10838;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10839;
case false:
return 10840;
}
case false:
switch (west)
{
case true:
return 10841;
case false:
return 10842;
}
}
}
}
}
}
}
constexpr static andesite_wall from_id(block_id_type id)
{
switch (id)
{
case 10779:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10780:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10781:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10782:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10783:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10784:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10785:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10786:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10787:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10788:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10789:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10790:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10791:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10792:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10793:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10794:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10795:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10796:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10797:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10798:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10799:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10800:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10801:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10802:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10803:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10804:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10805:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10806:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10807:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10808:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10809:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10810:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
case 10811:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10812:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10813:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10814:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10815:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10816:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10817:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10818:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10819:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10820:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10821:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10822:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10823:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10824:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10825:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10826:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10827:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10828:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10829:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10830:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10831:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10832:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10833:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10834:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10835:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10836:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10837:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10838:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10839:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10840:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10841:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10842:
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
return "minecraft:andesite_wall:true:true:true:true:true:true";
case false:
return "minecraft:andesite_wall:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:true:true:true:true:false:true";
case false:
return "minecraft:andesite_wall:true:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:andesite_wall:true:true:true:false:true:true";
case false:
return "minecraft:andesite_wall:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:true:true:true:false:false:true";
case false:
return "minecraft:andesite_wall:true:true:true:false:false:false";
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
return "minecraft:andesite_wall:true:true:false:true:true:true";
case false:
return "minecraft:andesite_wall:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:true:true:false:true:false:true";
case false:
return "minecraft:andesite_wall:true:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:andesite_wall:true:true:false:false:true:true";
case false:
return "minecraft:andesite_wall:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:true:true:false:false:false:true";
case false:
return "minecraft:andesite_wall:true:true:false:false:false:false";
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
return "minecraft:andesite_wall:true:false:true:true:true:true";
case false:
return "minecraft:andesite_wall:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:true:false:true:true:false:true";
case false:
return "minecraft:andesite_wall:true:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:andesite_wall:true:false:true:false:true:true";
case false:
return "minecraft:andesite_wall:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:true:false:true:false:false:true";
case false:
return "minecraft:andesite_wall:true:false:true:false:false:false";
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
return "minecraft:andesite_wall:true:false:false:true:true:true";
case false:
return "minecraft:andesite_wall:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:true:false:false:true:false:true";
case false:
return "minecraft:andesite_wall:true:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:andesite_wall:true:false:false:false:true:true";
case false:
return "minecraft:andesite_wall:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:true:false:false:false:false:true";
case false:
return "minecraft:andesite_wall:true:false:false:false:false:false";
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
return "minecraft:andesite_wall:false:true:true:true:true:true";
case false:
return "minecraft:andesite_wall:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:false:true:true:true:false:true";
case false:
return "minecraft:andesite_wall:false:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:andesite_wall:false:true:true:false:true:true";
case false:
return "minecraft:andesite_wall:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:false:true:true:false:false:true";
case false:
return "minecraft:andesite_wall:false:true:true:false:false:false";
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
return "minecraft:andesite_wall:false:true:false:true:true:true";
case false:
return "minecraft:andesite_wall:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:false:true:false:true:false:true";
case false:
return "minecraft:andesite_wall:false:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:andesite_wall:false:true:false:false:true:true";
case false:
return "minecraft:andesite_wall:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:false:true:false:false:false:true";
case false:
return "minecraft:andesite_wall:false:true:false:false:false:false";
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
return "minecraft:andesite_wall:false:false:true:true:true:true";
case false:
return "minecraft:andesite_wall:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:false:false:true:true:false:true";
case false:
return "minecraft:andesite_wall:false:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:andesite_wall:false:false:true:false:true:true";
case false:
return "minecraft:andesite_wall:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:false:false:true:false:false:true";
case false:
return "minecraft:andesite_wall:false:false:true:false:false:false";
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
return "minecraft:andesite_wall:false:false:false:true:true:true";
case false:
return "minecraft:andesite_wall:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:false:false:false:true:false:true";
case false:
return "minecraft:andesite_wall:false:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:andesite_wall:false:false:false:false:true:true";
case false:
return "minecraft:andesite_wall:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:andesite_wall:false:false:false:false:false:true";
case false:
return "minecraft:andesite_wall:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
