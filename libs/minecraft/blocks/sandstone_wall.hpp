#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct sandstone_wall
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
return 10907;
case false:
return 10908;
}
case false:
switch (west)
{
case true:
return 10909;
case false:
return 10910;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10911;
case false:
return 10912;
}
case false:
switch (west)
{
case true:
return 10913;
case false:
return 10914;
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
return 10915;
case false:
return 10916;
}
case false:
switch (west)
{
case true:
return 10917;
case false:
return 10918;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10919;
case false:
return 10920;
}
case false:
switch (west)
{
case true:
return 10921;
case false:
return 10922;
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
return 10923;
case false:
return 10924;
}
case false:
switch (west)
{
case true:
return 10925;
case false:
return 10926;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10927;
case false:
return 10928;
}
case false:
switch (west)
{
case true:
return 10929;
case false:
return 10930;
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
return 10931;
case false:
return 10932;
}
case false:
switch (west)
{
case true:
return 10933;
case false:
return 10934;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10935;
case false:
return 10936;
}
case false:
switch (west)
{
case true:
return 10937;
case false:
return 10938;
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
return 10939;
case false:
return 10940;
}
case false:
switch (west)
{
case true:
return 10941;
case false:
return 10942;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10943;
case false:
return 10944;
}
case false:
switch (west)
{
case true:
return 10945;
case false:
return 10946;
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
return 10947;
case false:
return 10948;
}
case false:
switch (west)
{
case true:
return 10949;
case false:
return 10950;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10951;
case false:
return 10952;
}
case false:
switch (west)
{
case true:
return 10953;
case false:
return 10954;
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
return 10955;
case false:
return 10956;
}
case false:
switch (west)
{
case true:
return 10957;
case false:
return 10958;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10959;
case false:
return 10960;
}
case false:
switch (west)
{
case true:
return 10961;
case false:
return 10962;
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
return 10963;
case false:
return 10964;
}
case false:
switch (west)
{
case true:
return 10965;
case false:
return 10966;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10967;
case false:
return 10968;
}
case false:
switch (west)
{
case true:
return 10969;
case false:
return 10970;
}
}
}
}
}
}
}
constexpr static sandstone_wall from_id(block_id_type id)
{
switch (id)
{
case 10907:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10908:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10909:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10910:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10911:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10912:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10913:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10914:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10915:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10916:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10917:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10918:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10919:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10920:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10921:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10922:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10923:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10924:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10925:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10926:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10927:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10928:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10929:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10930:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10931:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10932:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10933:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10934:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10935:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10936:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10937:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10938:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
case 10939:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10940:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10941:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10942:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10943:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10944:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10945:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10946:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10947:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10948:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10949:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10950:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10951:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10952:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10953:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10954:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10955:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10956:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10957:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10958:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10959:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10960:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10961:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10962:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10963:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10964:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10965:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10966:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10967:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10968:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10969:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10970:
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
return "minecraft:sandstone_wall:true:true:true:true:true:true";
case false:
return "minecraft:sandstone_wall:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:true:true:true:true:false:true";
case false:
return "minecraft:sandstone_wall:true:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:sandstone_wall:true:true:true:false:true:true";
case false:
return "minecraft:sandstone_wall:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:true:true:true:false:false:true";
case false:
return "minecraft:sandstone_wall:true:true:true:false:false:false";
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
return "minecraft:sandstone_wall:true:true:false:true:true:true";
case false:
return "minecraft:sandstone_wall:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:true:true:false:true:false:true";
case false:
return "minecraft:sandstone_wall:true:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:sandstone_wall:true:true:false:false:true:true";
case false:
return "minecraft:sandstone_wall:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:true:true:false:false:false:true";
case false:
return "minecraft:sandstone_wall:true:true:false:false:false:false";
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
return "minecraft:sandstone_wall:true:false:true:true:true:true";
case false:
return "minecraft:sandstone_wall:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:true:false:true:true:false:true";
case false:
return "minecraft:sandstone_wall:true:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:sandstone_wall:true:false:true:false:true:true";
case false:
return "minecraft:sandstone_wall:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:true:false:true:false:false:true";
case false:
return "minecraft:sandstone_wall:true:false:true:false:false:false";
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
return "minecraft:sandstone_wall:true:false:false:true:true:true";
case false:
return "minecraft:sandstone_wall:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:true:false:false:true:false:true";
case false:
return "minecraft:sandstone_wall:true:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:sandstone_wall:true:false:false:false:true:true";
case false:
return "minecraft:sandstone_wall:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:true:false:false:false:false:true";
case false:
return "minecraft:sandstone_wall:true:false:false:false:false:false";
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
return "minecraft:sandstone_wall:false:true:true:true:true:true";
case false:
return "minecraft:sandstone_wall:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:false:true:true:true:false:true";
case false:
return "minecraft:sandstone_wall:false:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:sandstone_wall:false:true:true:false:true:true";
case false:
return "minecraft:sandstone_wall:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:false:true:true:false:false:true";
case false:
return "minecraft:sandstone_wall:false:true:true:false:false:false";
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
return "minecraft:sandstone_wall:false:true:false:true:true:true";
case false:
return "minecraft:sandstone_wall:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:false:true:false:true:false:true";
case false:
return "minecraft:sandstone_wall:false:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:sandstone_wall:false:true:false:false:true:true";
case false:
return "minecraft:sandstone_wall:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:false:true:false:false:false:true";
case false:
return "minecraft:sandstone_wall:false:true:false:false:false:false";
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
return "minecraft:sandstone_wall:false:false:true:true:true:true";
case false:
return "minecraft:sandstone_wall:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:false:false:true:true:false:true";
case false:
return "minecraft:sandstone_wall:false:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:sandstone_wall:false:false:true:false:true:true";
case false:
return "minecraft:sandstone_wall:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:false:false:true:false:false:true";
case false:
return "minecraft:sandstone_wall:false:false:true:false:false:false";
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
return "minecraft:sandstone_wall:false:false:false:true:true:true";
case false:
return "minecraft:sandstone_wall:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:false:false:false:true:false:true";
case false:
return "minecraft:sandstone_wall:false:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:sandstone_wall:false:false:false:false:true:true";
case false:
return "minecraft:sandstone_wall:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:sandstone_wall:false:false:false:false:false:true";
case false:
return "minecraft:sandstone_wall:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
