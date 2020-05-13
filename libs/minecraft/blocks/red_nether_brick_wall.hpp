#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct red_nether_brick_wall
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
return 10843;
case false:
return 10844;
}
case false:
switch (west)
{
case true:
return 10845;
case false:
return 10846;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10847;
case false:
return 10848;
}
case false:
switch (west)
{
case true:
return 10849;
case false:
return 10850;
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
return 10851;
case false:
return 10852;
}
case false:
switch (west)
{
case true:
return 10853;
case false:
return 10854;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10855;
case false:
return 10856;
}
case false:
switch (west)
{
case true:
return 10857;
case false:
return 10858;
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
return 10859;
case false:
return 10860;
}
case false:
switch (west)
{
case true:
return 10861;
case false:
return 10862;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10863;
case false:
return 10864;
}
case false:
switch (west)
{
case true:
return 10865;
case false:
return 10866;
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
return 10867;
case false:
return 10868;
}
case false:
switch (west)
{
case true:
return 10869;
case false:
return 10870;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10871;
case false:
return 10872;
}
case false:
switch (west)
{
case true:
return 10873;
case false:
return 10874;
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
return 10875;
case false:
return 10876;
}
case false:
switch (west)
{
case true:
return 10877;
case false:
return 10878;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10879;
case false:
return 10880;
}
case false:
switch (west)
{
case true:
return 10881;
case false:
return 10882;
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
return 10883;
case false:
return 10884;
}
case false:
switch (west)
{
case true:
return 10885;
case false:
return 10886;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10887;
case false:
return 10888;
}
case false:
switch (west)
{
case true:
return 10889;
case false:
return 10890;
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
return 10891;
case false:
return 10892;
}
case false:
switch (west)
{
case true:
return 10893;
case false:
return 10894;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10895;
case false:
return 10896;
}
case false:
switch (west)
{
case true:
return 10897;
case false:
return 10898;
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
return 10899;
case false:
return 10900;
}
case false:
switch (west)
{
case true:
return 10901;
case false:
return 10902;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10903;
case false:
return 10904;
}
case false:
switch (west)
{
case true:
return 10905;
case false:
return 10906;
}
}
}
}
}
}
}
constexpr static red_nether_brick_wall from_id(block_id_type id)
{
switch (id)
{
case 10843:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10844:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10845:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10846:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10847:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10848:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10849:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10850:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10851:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10852:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10853:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10854:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10855:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10856:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10857:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10858:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10859:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10860:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10861:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10862:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10863:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10864:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10865:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10866:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10867:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10868:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10869:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10870:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10871:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10872:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10873:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10874:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
case 10875:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10876:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10877:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10878:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10879:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10880:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10881:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10882:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10883:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10884:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10885:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10886:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10887:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10888:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10889:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10890:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10891:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10892:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10893:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10894:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10895:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10896:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10897:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10898:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10899:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10900:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10901:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10902:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10903:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10904:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10905:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10906:
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
return "minecraft:red_nether_brick_wall:true:true:true:true:true:true";
case false:
return "minecraft:red_nether_brick_wall:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:true:true:true:true:false:true";
case false:
return "minecraft:red_nether_brick_wall:true:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:true:true:true:false:true:true";
case false:
return "minecraft:red_nether_brick_wall:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:true:true:true:false:false:true";
case false:
return "minecraft:red_nether_brick_wall:true:true:true:false:false:false";
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
return "minecraft:red_nether_brick_wall:true:true:false:true:true:true";
case false:
return "minecraft:red_nether_brick_wall:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:true:true:false:true:false:true";
case false:
return "minecraft:red_nether_brick_wall:true:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:true:true:false:false:true:true";
case false:
return "minecraft:red_nether_brick_wall:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:true:true:false:false:false:true";
case false:
return "minecraft:red_nether_brick_wall:true:true:false:false:false:false";
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
return "minecraft:red_nether_brick_wall:true:false:true:true:true:true";
case false:
return "minecraft:red_nether_brick_wall:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:true:false:true:true:false:true";
case false:
return "minecraft:red_nether_brick_wall:true:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:true:false:true:false:true:true";
case false:
return "minecraft:red_nether_brick_wall:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:true:false:true:false:false:true";
case false:
return "minecraft:red_nether_brick_wall:true:false:true:false:false:false";
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
return "minecraft:red_nether_brick_wall:true:false:false:true:true:true";
case false:
return "minecraft:red_nether_brick_wall:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:true:false:false:true:false:true";
case false:
return "minecraft:red_nether_brick_wall:true:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:true:false:false:false:true:true";
case false:
return "minecraft:red_nether_brick_wall:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:true:false:false:false:false:true";
case false:
return "minecraft:red_nether_brick_wall:true:false:false:false:false:false";
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
return "minecraft:red_nether_brick_wall:false:true:true:true:true:true";
case false:
return "minecraft:red_nether_brick_wall:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:false:true:true:true:false:true";
case false:
return "minecraft:red_nether_brick_wall:false:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:false:true:true:false:true:true";
case false:
return "minecraft:red_nether_brick_wall:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:false:true:true:false:false:true";
case false:
return "minecraft:red_nether_brick_wall:false:true:true:false:false:false";
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
return "minecraft:red_nether_brick_wall:false:true:false:true:true:true";
case false:
return "minecraft:red_nether_brick_wall:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:false:true:false:true:false:true";
case false:
return "minecraft:red_nether_brick_wall:false:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:false:true:false:false:true:true";
case false:
return "minecraft:red_nether_brick_wall:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:false:true:false:false:false:true";
case false:
return "minecraft:red_nether_brick_wall:false:true:false:false:false:false";
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
return "minecraft:red_nether_brick_wall:false:false:true:true:true:true";
case false:
return "minecraft:red_nether_brick_wall:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:false:false:true:true:false:true";
case false:
return "minecraft:red_nether_brick_wall:false:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:false:false:true:false:true:true";
case false:
return "minecraft:red_nether_brick_wall:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:false:false:true:false:false:true";
case false:
return "minecraft:red_nether_brick_wall:false:false:true:false:false:false";
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
return "minecraft:red_nether_brick_wall:false:false:false:true:true:true";
case false:
return "minecraft:red_nether_brick_wall:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:false:false:false:true:false:true";
case false:
return "minecraft:red_nether_brick_wall:false:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:false:false:false:false:true:true";
case false:
return "minecraft:red_nether_brick_wall:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_nether_brick_wall:false:false:false:false:false:true";
case false:
return "minecraft:red_nether_brick_wall:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
