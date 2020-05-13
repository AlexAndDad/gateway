#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct stone_brick_stairs
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
return 4916;
case false:
return 4917;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 4918;
case false:
return 4919;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 4920;
case false:
return 4921;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 4922;
case false:
return 4923;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 4924;
case false:
return 4925;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 4926;
case false:
return 4927;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 4928;
case false:
return 4929;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 4930;
case false:
return 4931;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 4932;
case false:
return 4933;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 4934;
case false:
return 4935;
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
return 4936;
case false:
return 4937;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 4938;
case false:
return 4939;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 4940;
case false:
return 4941;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 4942;
case false:
return 4943;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 4944;
case false:
return 4945;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 4946;
case false:
return 4947;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 4948;
case false:
return 4949;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 4950;
case false:
return 4951;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 4952;
case false:
return 4953;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 4954;
case false:
return 4955;
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
return 4956;
case false:
return 4957;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 4958;
case false:
return 4959;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 4960;
case false:
return 4961;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 4962;
case false:
return 4963;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 4964;
case false:
return 4965;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 4966;
case false:
return 4967;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 4968;
case false:
return 4969;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 4970;
case false:
return 4971;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 4972;
case false:
return 4973;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 4974;
case false:
return 4975;
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
return 4976;
case false:
return 4977;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 4978;
case false:
return 4979;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 4980;
case false:
return 4981;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 4982;
case false:
return 4983;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 4984;
case false:
return 4985;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 4986;
case false:
return 4987;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 4988;
case false:
return 4989;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 4990;
case false:
return 4991;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 4992;
case false:
return 4993;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 4994;
case false:
return 4995;
}
}
}
}
}
constexpr static stone_brick_stairs from_id(block_id_type id)
{
switch (id)
{
case 4916:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 4917:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 4918:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 4919:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 4920:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 4921:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 4922:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 4923:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 4924:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 4925:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 4926:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 4927:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 4928:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 4929:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 4930:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 4931:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 4932:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 4933:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 4934:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 4935:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 4936:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 4937:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 4938:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 4939:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 4940:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 4941:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 4942:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 4943:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 4944:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 4945:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 4946:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 4947:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 4948:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 4949:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 4950:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 4951:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 4952:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 4953:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 4954:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 4955:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 4956:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 4957:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 4958:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 4959:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 4960:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 4961:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 4962:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 4963:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 4964:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 4965:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 4966:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 4967:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 4968:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 4969:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 4970:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 4971:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 4972:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 4973:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 4974:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 4975:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 4976:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 4977:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 4978:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 4979:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 4980:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 4981:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 4982:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 4983:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 4984:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 4985:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 4986:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 4987:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 4988:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 4989:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 4990:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 4991:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 4992:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 4993:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 4994:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 4995:
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
return "minecraft:stone_brick_stairs:north:top:straight:true";
case false:
return "minecraft:stone_brick_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:north:top:inner_left:true";
case false:
return "minecraft:stone_brick_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:north:top:inner_right:true";
case false:
return "minecraft:stone_brick_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:north:top:outer_left:true";
case false:
return "minecraft:stone_brick_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:north:top:outer_right:true";
case false:
return "minecraft:stone_brick_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:north:bottom:straight:true";
case false:
return "minecraft:stone_brick_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:stone_brick_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:stone_brick_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:stone_brick_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:stone_brick_stairs:north:bottom:outer_right:false";
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
return "minecraft:stone_brick_stairs:south:top:straight:true";
case false:
return "minecraft:stone_brick_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:south:top:inner_left:true";
case false:
return "minecraft:stone_brick_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:south:top:inner_right:true";
case false:
return "minecraft:stone_brick_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:south:top:outer_left:true";
case false:
return "minecraft:stone_brick_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:south:top:outer_right:true";
case false:
return "minecraft:stone_brick_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:south:bottom:straight:true";
case false:
return "minecraft:stone_brick_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:stone_brick_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:stone_brick_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:stone_brick_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:stone_brick_stairs:south:bottom:outer_right:false";
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
return "minecraft:stone_brick_stairs:west:top:straight:true";
case false:
return "minecraft:stone_brick_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:west:top:inner_left:true";
case false:
return "minecraft:stone_brick_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:west:top:inner_right:true";
case false:
return "minecraft:stone_brick_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:west:top:outer_left:true";
case false:
return "minecraft:stone_brick_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:west:top:outer_right:true";
case false:
return "minecraft:stone_brick_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:west:bottom:straight:true";
case false:
return "minecraft:stone_brick_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:stone_brick_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:stone_brick_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:stone_brick_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:stone_brick_stairs:west:bottom:outer_right:false";
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
return "minecraft:stone_brick_stairs:east:top:straight:true";
case false:
return "minecraft:stone_brick_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:east:top:inner_left:true";
case false:
return "minecraft:stone_brick_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:east:top:inner_right:true";
case false:
return "minecraft:stone_brick_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:east:top:outer_left:true";
case false:
return "minecraft:stone_brick_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:east:top:outer_right:true";
case false:
return "minecraft:stone_brick_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:east:bottom:straight:true";
case false:
return "minecraft:stone_brick_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:stone_brick_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:stone_brick_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:stone_brick_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:stone_brick_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:stone_brick_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
