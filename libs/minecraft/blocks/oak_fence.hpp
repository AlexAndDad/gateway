#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct oak_fence
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
return 3964;
case false:
return 3965;
}
case false:
switch (west)
{
case true:
return 3966;
case false:
return 3967;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 3968;
case false:
return 3969;
}
case false:
switch (west)
{
case true:
return 3970;
case false:
return 3971;
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
return 3972;
case false:
return 3973;
}
case false:
switch (west)
{
case true:
return 3974;
case false:
return 3975;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 3976;
case false:
return 3977;
}
case false:
switch (west)
{
case true:
return 3978;
case false:
return 3979;
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
return 3980;
case false:
return 3981;
}
case false:
switch (west)
{
case true:
return 3982;
case false:
return 3983;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 3984;
case false:
return 3985;
}
case false:
switch (west)
{
case true:
return 3986;
case false:
return 3987;
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
return 3988;
case false:
return 3989;
}
case false:
switch (west)
{
case true:
return 3990;
case false:
return 3991;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 3992;
case false:
return 3993;
}
case false:
switch (west)
{
case true:
return 3994;
case false:
return 3995;
}
}
}
}
}
}
constexpr static oak_fence from_id(block_id_type id)
{
switch (id)
{
case 3964:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = true};
case 3965:
return {.east = true, .north = true, .south = true, .waterlogged = true, .west = false};
case 3966:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = true};
case 3967:
return {.east = true, .north = true, .south = true, .waterlogged = false, .west = false};
case 3968:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = true};
case 3969:
return {.east = true, .north = true, .south = false, .waterlogged = true, .west = false};
case 3970:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = true};
case 3971:
return {.east = true, .north = true, .south = false, .waterlogged = false, .west = false};
case 3972:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = true};
case 3973:
return {.east = true, .north = false, .south = true, .waterlogged = true, .west = false};
case 3974:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = true};
case 3975:
return {.east = true, .north = false, .south = true, .waterlogged = false, .west = false};
case 3976:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = true};
case 3977:
return {.east = true, .north = false, .south = false, .waterlogged = true, .west = false};
case 3978:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = true};
case 3979:
return {.east = true, .north = false, .south = false, .waterlogged = false, .west = false};
case 3980:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = true};
case 3981:
return {.east = false, .north = true, .south = true, .waterlogged = true, .west = false};
case 3982:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = true};
case 3983:
return {.east = false, .north = true, .south = true, .waterlogged = false, .west = false};
case 3984:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = true};
case 3985:
return {.east = false, .north = true, .south = false, .waterlogged = true, .west = false};
case 3986:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = true};
case 3987:
return {.east = false, .north = true, .south = false, .waterlogged = false, .west = false};
case 3988:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = true};
case 3989:
return {.east = false, .north = false, .south = true, .waterlogged = true, .west = false};
case 3990:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = true};
case 3991:
return {.east = false, .north = false, .south = true, .waterlogged = false, .west = false};
case 3992:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = true};
case 3993:
return {.east = false, .north = false, .south = false, .waterlogged = true, .west = false};
case 3994:
return {.east = false, .north = false, .south = false, .waterlogged = false, .west = true};
case 3995:
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
return "minecraft:oak_fence:true:true:true:true:true";
case false:
return "minecraft:oak_fence:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:oak_fence:true:true:true:false:true";
case false:
return "minecraft:oak_fence:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:oak_fence:true:true:false:true:true";
case false:
return "minecraft:oak_fence:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:oak_fence:true:true:false:false:true";
case false:
return "minecraft:oak_fence:true:true:false:false:false";
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
return "minecraft:oak_fence:true:false:true:true:true";
case false:
return "minecraft:oak_fence:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:oak_fence:true:false:true:false:true";
case false:
return "minecraft:oak_fence:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:oak_fence:true:false:false:true:true";
case false:
return "minecraft:oak_fence:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:oak_fence:true:false:false:false:true";
case false:
return "minecraft:oak_fence:true:false:false:false:false";
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
return "minecraft:oak_fence:false:true:true:true:true";
case false:
return "minecraft:oak_fence:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:oak_fence:false:true:true:false:true";
case false:
return "minecraft:oak_fence:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:oak_fence:false:true:false:true:true";
case false:
return "minecraft:oak_fence:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:oak_fence:false:true:false:false:true";
case false:
return "minecraft:oak_fence:false:true:false:false:false";
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
return "minecraft:oak_fence:false:false:true:true:true";
case false:
return "minecraft:oak_fence:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:oak_fence:false:false:true:false:true";
case false:
return "minecraft:oak_fence:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:oak_fence:false:false:false:true:true";
case false:
return "minecraft:oak_fence:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:oak_fence:false:false:false:false:true";
case false:
return "minecraft:oak_fence:false:false:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
