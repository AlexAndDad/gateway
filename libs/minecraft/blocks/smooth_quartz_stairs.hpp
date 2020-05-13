#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct smooth_quartz_stairs
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
return 9773;
case false:
return 9774;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9775;
case false:
return 9776;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9777;
case false:
return 9778;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9779;
case false:
return 9780;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9781;
case false:
return 9782;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9783;
case false:
return 9784;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9785;
case false:
return 9786;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9787;
case false:
return 9788;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9789;
case false:
return 9790;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9791;
case false:
return 9792;
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
return 9793;
case false:
return 9794;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9795;
case false:
return 9796;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9797;
case false:
return 9798;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9799;
case false:
return 9800;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9801;
case false:
return 9802;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9803;
case false:
return 9804;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9805;
case false:
return 9806;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9807;
case false:
return 9808;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9809;
case false:
return 9810;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9811;
case false:
return 9812;
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
return 9813;
case false:
return 9814;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9815;
case false:
return 9816;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9817;
case false:
return 9818;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9819;
case false:
return 9820;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9821;
case false:
return 9822;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9823;
case false:
return 9824;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9825;
case false:
return 9826;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9827;
case false:
return 9828;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9829;
case false:
return 9830;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9831;
case false:
return 9832;
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
return 9833;
case false:
return 9834;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9835;
case false:
return 9836;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9837;
case false:
return 9838;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9839;
case false:
return 9840;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9841;
case false:
return 9842;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9843;
case false:
return 9844;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9845;
case false:
return 9846;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9847;
case false:
return 9848;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9849;
case false:
return 9850;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9851;
case false:
return 9852;
}
}
}
}
}
constexpr static smooth_quartz_stairs from_id(block_id_type id)
{
switch (id)
{
case 9773:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9774:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9775:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9776:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9777:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9778:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9779:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9780:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9781:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9782:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9783:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9784:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9785:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9786:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9787:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9788:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9789:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9790:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9791:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9792:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9793:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9794:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9795:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9796:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9797:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9798:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9799:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9800:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9801:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9802:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9803:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9804:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9805:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9806:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9807:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9808:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9809:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9810:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9811:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9812:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9813:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9814:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9815:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9816:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9817:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9818:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9819:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9820:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9821:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9822:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9823:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9824:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9825:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9826:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9827:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9828:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9829:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9830:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9831:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9832:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9833:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9834:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9835:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9836:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9837:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9838:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9839:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9840:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9841:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9842:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9843:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9844:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9845:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9846:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9847:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9848:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9849:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9850:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9851:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9852:
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
return "minecraft:smooth_quartz_stairs:north:top:straight:true";
case false:
return "minecraft:smooth_quartz_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:north:top:inner_left:true";
case false:
return "minecraft:smooth_quartz_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:north:top:inner_right:true";
case false:
return "minecraft:smooth_quartz_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:north:top:outer_left:true";
case false:
return "minecraft:smooth_quartz_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:north:top:outer_right:true";
case false:
return "minecraft:smooth_quartz_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:north:bottom:straight:true";
case false:
return "minecraft:smooth_quartz_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:smooth_quartz_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:smooth_quartz_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:smooth_quartz_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:smooth_quartz_stairs:north:bottom:outer_right:false";
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
return "minecraft:smooth_quartz_stairs:south:top:straight:true";
case false:
return "minecraft:smooth_quartz_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:south:top:inner_left:true";
case false:
return "minecraft:smooth_quartz_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:south:top:inner_right:true";
case false:
return "minecraft:smooth_quartz_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:south:top:outer_left:true";
case false:
return "minecraft:smooth_quartz_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:south:top:outer_right:true";
case false:
return "minecraft:smooth_quartz_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:south:bottom:straight:true";
case false:
return "minecraft:smooth_quartz_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:smooth_quartz_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:smooth_quartz_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:smooth_quartz_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:smooth_quartz_stairs:south:bottom:outer_right:false";
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
return "minecraft:smooth_quartz_stairs:west:top:straight:true";
case false:
return "minecraft:smooth_quartz_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:west:top:inner_left:true";
case false:
return "minecraft:smooth_quartz_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:west:top:inner_right:true";
case false:
return "minecraft:smooth_quartz_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:west:top:outer_left:true";
case false:
return "minecraft:smooth_quartz_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:west:top:outer_right:true";
case false:
return "minecraft:smooth_quartz_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:west:bottom:straight:true";
case false:
return "minecraft:smooth_quartz_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:smooth_quartz_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:smooth_quartz_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:smooth_quartz_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:smooth_quartz_stairs:west:bottom:outer_right:false";
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
return "minecraft:smooth_quartz_stairs:east:top:straight:true";
case false:
return "minecraft:smooth_quartz_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:east:top:inner_left:true";
case false:
return "minecraft:smooth_quartz_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:east:top:inner_right:true";
case false:
return "minecraft:smooth_quartz_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:east:top:outer_left:true";
case false:
return "minecraft:smooth_quartz_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:east:top:outer_right:true";
case false:
return "minecraft:smooth_quartz_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:east:bottom:straight:true";
case false:
return "minecraft:smooth_quartz_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:smooth_quartz_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:smooth_quartz_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:smooth_quartz_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_quartz_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:smooth_quartz_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
