#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct acacia_stairs
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
return 6839;
case false:
return 6840;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6841;
case false:
return 6842;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6843;
case false:
return 6844;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6845;
case false:
return 6846;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6847;
case false:
return 6848;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6849;
case false:
return 6850;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6851;
case false:
return 6852;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6853;
case false:
return 6854;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6855;
case false:
return 6856;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6857;
case false:
return 6858;
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
return 6859;
case false:
return 6860;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6861;
case false:
return 6862;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6863;
case false:
return 6864;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6865;
case false:
return 6866;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6867;
case false:
return 6868;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6869;
case false:
return 6870;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6871;
case false:
return 6872;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6873;
case false:
return 6874;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6875;
case false:
return 6876;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6877;
case false:
return 6878;
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
return 6879;
case false:
return 6880;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6881;
case false:
return 6882;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6883;
case false:
return 6884;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6885;
case false:
return 6886;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6887;
case false:
return 6888;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6889;
case false:
return 6890;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6891;
case false:
return 6892;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6893;
case false:
return 6894;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6895;
case false:
return 6896;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6897;
case false:
return 6898;
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
return 6899;
case false:
return 6900;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6901;
case false:
return 6902;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6903;
case false:
return 6904;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6905;
case false:
return 6906;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6907;
case false:
return 6908;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 6909;
case false:
return 6910;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 6911;
case false:
return 6912;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 6913;
case false:
return 6914;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 6915;
case false:
return 6916;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 6917;
case false:
return 6918;
}
}
}
}
}
constexpr static acacia_stairs from_id(block_id_type id)
{
switch (id)
{
case 6839:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 6840:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 6841:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 6842:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 6843:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 6844:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 6845:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 6846:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 6847:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 6848:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 6849:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 6850:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 6851:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 6852:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 6853:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 6854:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 6855:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 6856:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 6857:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 6858:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 6859:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 6860:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 6861:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 6862:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 6863:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 6864:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 6865:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 6866:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 6867:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 6868:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 6869:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 6870:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 6871:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 6872:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 6873:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 6874:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 6875:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 6876:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 6877:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 6878:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 6879:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 6880:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 6881:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 6882:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 6883:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 6884:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 6885:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 6886:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 6887:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 6888:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 6889:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 6890:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 6891:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 6892:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 6893:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 6894:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 6895:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 6896:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 6897:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 6898:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 6899:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 6900:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 6901:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 6902:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 6903:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 6904:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 6905:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 6906:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 6907:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 6908:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 6909:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 6910:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 6911:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 6912:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 6913:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 6914:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 6915:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 6916:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 6917:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 6918:
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
return "minecraft:acacia_stairs:north:top:straight:true";
case false:
return "minecraft:acacia_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:north:top:inner_left:true";
case false:
return "minecraft:acacia_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:north:top:inner_right:true";
case false:
return "minecraft:acacia_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:north:top:outer_left:true";
case false:
return "minecraft:acacia_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:north:top:outer_right:true";
case false:
return "minecraft:acacia_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:north:bottom:straight:true";
case false:
return "minecraft:acacia_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:acacia_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:acacia_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:acacia_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:acacia_stairs:north:bottom:outer_right:false";
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
return "minecraft:acacia_stairs:south:top:straight:true";
case false:
return "minecraft:acacia_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:south:top:inner_left:true";
case false:
return "minecraft:acacia_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:south:top:inner_right:true";
case false:
return "minecraft:acacia_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:south:top:outer_left:true";
case false:
return "minecraft:acacia_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:south:top:outer_right:true";
case false:
return "minecraft:acacia_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:south:bottom:straight:true";
case false:
return "minecraft:acacia_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:acacia_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:acacia_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:acacia_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:acacia_stairs:south:bottom:outer_right:false";
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
return "minecraft:acacia_stairs:west:top:straight:true";
case false:
return "minecraft:acacia_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:west:top:inner_left:true";
case false:
return "minecraft:acacia_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:west:top:inner_right:true";
case false:
return "minecraft:acacia_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:west:top:outer_left:true";
case false:
return "minecraft:acacia_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:west:top:outer_right:true";
case false:
return "minecraft:acacia_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:west:bottom:straight:true";
case false:
return "minecraft:acacia_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:acacia_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:acacia_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:acacia_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:acacia_stairs:west:bottom:outer_right:false";
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
return "minecraft:acacia_stairs:east:top:straight:true";
case false:
return "minecraft:acacia_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:east:top:inner_left:true";
case false:
return "minecraft:acacia_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:east:top:inner_right:true";
case false:
return "minecraft:acacia_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:east:top:outer_left:true";
case false:
return "minecraft:acacia_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:east:top:outer_right:true";
case false:
return "minecraft:acacia_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:east:bottom:straight:true";
case false:
return "minecraft:acacia_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:acacia_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:acacia_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:acacia_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:acacia_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:acacia_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
