#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct smooth_sandstone_stairs
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
return 9693;
case false:
return 9694;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9695;
case false:
return 9696;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9697;
case false:
return 9698;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9699;
case false:
return 9700;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9701;
case false:
return 9702;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9703;
case false:
return 9704;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9705;
case false:
return 9706;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9707;
case false:
return 9708;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9709;
case false:
return 9710;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9711;
case false:
return 9712;
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
return 9713;
case false:
return 9714;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9715;
case false:
return 9716;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9717;
case false:
return 9718;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9719;
case false:
return 9720;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9721;
case false:
return 9722;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9723;
case false:
return 9724;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9725;
case false:
return 9726;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9727;
case false:
return 9728;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9729;
case false:
return 9730;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9731;
case false:
return 9732;
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
return 9733;
case false:
return 9734;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9735;
case false:
return 9736;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9737;
case false:
return 9738;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9739;
case false:
return 9740;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9741;
case false:
return 9742;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9743;
case false:
return 9744;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9745;
case false:
return 9746;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9747;
case false:
return 9748;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9749;
case false:
return 9750;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9751;
case false:
return 9752;
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
return 9753;
case false:
return 9754;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9755;
case false:
return 9756;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9757;
case false:
return 9758;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9759;
case false:
return 9760;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9761;
case false:
return 9762;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 9763;
case false:
return 9764;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 9765;
case false:
return 9766;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 9767;
case false:
return 9768;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 9769;
case false:
return 9770;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 9771;
case false:
return 9772;
}
}
}
}
}
constexpr static smooth_sandstone_stairs from_id(block_id_type id)
{
switch (id)
{
case 9693:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9694:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9695:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9696:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9697:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9698:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9699:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9700:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9701:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9702:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9703:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9704:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9705:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9706:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9707:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9708:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9709:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9710:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9711:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9712:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9713:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9714:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9715:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9716:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9717:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9718:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9719:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9720:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9721:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9722:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9723:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9724:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9725:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9726:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9727:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9728:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9729:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9730:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9731:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9732:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9733:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9734:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9735:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9736:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9737:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9738:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9739:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9740:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9741:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9742:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9743:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9744:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9745:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9746:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9747:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9748:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9749:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9750:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9751:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9752:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 9753:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 9754:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 9755:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 9756:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 9757:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 9758:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 9759:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 9760:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 9761:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 9762:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 9763:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 9764:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 9765:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 9766:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 9767:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 9768:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 9769:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 9770:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 9771:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 9772:
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
return "minecraft:smooth_sandstone_stairs:north:top:straight:true";
case false:
return "minecraft:smooth_sandstone_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:north:top:inner_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:north:top:inner_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:north:top:outer_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:north:top:outer_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:north:bottom:straight:true";
case false:
return "minecraft:smooth_sandstone_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:north:bottom:outer_right:false";
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
return "minecraft:smooth_sandstone_stairs:south:top:straight:true";
case false:
return "minecraft:smooth_sandstone_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:south:top:inner_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:south:top:inner_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:south:top:outer_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:south:top:outer_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:south:bottom:straight:true";
case false:
return "minecraft:smooth_sandstone_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:south:bottom:outer_right:false";
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
return "minecraft:smooth_sandstone_stairs:west:top:straight:true";
case false:
return "minecraft:smooth_sandstone_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:west:top:inner_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:west:top:inner_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:west:top:outer_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:west:top:outer_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:west:bottom:straight:true";
case false:
return "minecraft:smooth_sandstone_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:west:bottom:outer_right:false";
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
return "minecraft:smooth_sandstone_stairs:east:top:straight:true";
case false:
return "minecraft:smooth_sandstone_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:east:top:inner_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:east:top:inner_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:east:top:outer_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:east:top:outer_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:east:bottom:straight:true";
case false:
return "minecraft:smooth_sandstone_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:smooth_sandstone_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:smooth_sandstone_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:smooth_sandstone_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
