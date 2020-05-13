#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dark_oak_stairs
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
enum class half_type : std::uint8_t
{
top,
bottom
} half = half_type::bottom;
enum class shape_type : std::uint8_t
{
straight,
inner_left,
inner_right,
outer_left,
outer_right
} shape = shape_type::straight;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6919;
case false:
return 6920;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6921;
case false:
return 6922;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6923;
case false:
return 6924;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6925;
case false:
return 6926;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6927;
case false:
return 6928;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6929;
case false:
return 6930;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6931;
case false:
return 6932;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6933;
case false:
return 6934;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6935;
case false:
return 6936;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6937;
case false:
return 6938;
}
}
}
case facing_type::south:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6939;
case false:
return 6940;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6941;
case false:
return 6942;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6943;
case false:
return 6944;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6945;
case false:
return 6946;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6947;
case false:
return 6948;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6949;
case false:
return 6950;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6951;
case false:
return 6952;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6953;
case false:
return 6954;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6955;
case false:
return 6956;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6957;
case false:
return 6958;
}
}
}
case facing_type::west:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6959;
case false:
return 6960;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6961;
case false:
return 6962;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6963;
case false:
return 6964;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6965;
case false:
return 6966;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6967;
case false:
return 6968;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6969;
case false:
return 6970;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6971;
case false:
return 6972;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6973;
case false:
return 6974;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6975;
case false:
return 6976;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6977;
case false:
return 6978;
}
}
}
case facing_type::east:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6979;
case false:
return 6980;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6981;
case false:
return 6982;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6983;
case false:
return 6984;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6985;
case false:
return 6986;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6987;
case false:
return 6988;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6989;
case false:
return 6990;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6991;
case false:
return 6992;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6993;
case false:
return 6994;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6995;
case false:
return 6996;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6997;
case false:
return 6998;
}
}
}
}
}
constexpr static dark_oak_stairs from_id(block_id_type id)
{
switch (id)
{
case 6919:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 6920:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 6921:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 6922:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 6923:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 6924:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 6925:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 6926:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 6927:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 6928:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 6929:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 6930:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 6931:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 6932:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 6933:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 6934:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 6935:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 6936:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 6937:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 6938:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 6939:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 6940:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 6941:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 6942:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 6943:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 6944:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 6945:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 6946:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 6947:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 6948:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 6949:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 6950:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 6951:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 6952:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 6953:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 6954:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 6955:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 6956:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 6957:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 6958:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 6959:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 6960:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 6961:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 6962:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 6963:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 6964:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 6965:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 6966:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 6967:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 6968:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 6969:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 6970:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 6971:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 6972:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 6973:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 6974:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 6975:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 6976:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 6977:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 6978:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 6979:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 6980:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 6981:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 6982:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 6983:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 6984:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 6985:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 6986:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 6987:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 6988:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 6989:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 6990:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 6991:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 6992:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 6993:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 6994:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 6995:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 6996:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 6997:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 6998:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:north:top:straight:true";
case false:
return "minecraft:dark_oak_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:north:top:inner_left:true";
case false:
return "minecraft:dark_oak_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:north:top:inner_right:true";
case false:
return "minecraft:dark_oak_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:north:top:outer_left:true";
case false:
return "minecraft:dark_oak_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:north:top:outer_right:true";
case false:
return "minecraft:dark_oak_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:north:bottom:straight:true";
case false:
return "minecraft:dark_oak_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:dark_oak_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:dark_oak_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:dark_oak_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:dark_oak_stairs:north:bottom:outer_right:false";
}
}
}
case facing_type::south:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:south:top:straight:true";
case false:
return "minecraft:dark_oak_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:south:top:inner_left:true";
case false:
return "minecraft:dark_oak_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:south:top:inner_right:true";
case false:
return "minecraft:dark_oak_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:south:top:outer_left:true";
case false:
return "minecraft:dark_oak_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:south:top:outer_right:true";
case false:
return "minecraft:dark_oak_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:south:bottom:straight:true";
case false:
return "minecraft:dark_oak_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:dark_oak_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:dark_oak_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:dark_oak_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:dark_oak_stairs:south:bottom:outer_right:false";
}
}
}
case facing_type::west:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:west:top:straight:true";
case false:
return "minecraft:dark_oak_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:west:top:inner_left:true";
case false:
return "minecraft:dark_oak_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:west:top:inner_right:true";
case false:
return "minecraft:dark_oak_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:west:top:outer_left:true";
case false:
return "minecraft:dark_oak_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:west:top:outer_right:true";
case false:
return "minecraft:dark_oak_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:west:bottom:straight:true";
case false:
return "minecraft:dark_oak_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:dark_oak_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:dark_oak_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:dark_oak_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:dark_oak_stairs:west:bottom:outer_right:false";
}
}
}
case facing_type::east:
switch (half)
{
case half_type::top:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:east:top:straight:true";
case false:
return "minecraft:dark_oak_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:east:top:inner_left:true";
case false:
return "minecraft:dark_oak_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:east:top:inner_right:true";
case false:
return "minecraft:dark_oak_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:east:top:outer_left:true";
case false:
return "minecraft:dark_oak_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:east:top:outer_right:true";
case false:
return "minecraft:dark_oak_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:east:bottom:straight:true";
case false:
return "minecraft:dark_oak_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:dark_oak_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:dark_oak_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:dark_oak_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:dark_oak_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
