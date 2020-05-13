#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct red_sandstone_stairs
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
return 7684;
case false:
return 7685;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7686;
case false:
return 7687;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7688;
case false:
return 7689;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7690;
case false:
return 7691;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7692;
case false:
return 7693;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7694;
case false:
return 7695;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7696;
case false:
return 7697;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7698;
case false:
return 7699;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7700;
case false:
return 7701;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7702;
case false:
return 7703;
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
return 7704;
case false:
return 7705;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7706;
case false:
return 7707;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7708;
case false:
return 7709;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7710;
case false:
return 7711;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7712;
case false:
return 7713;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7714;
case false:
return 7715;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7716;
case false:
return 7717;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7718;
case false:
return 7719;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7720;
case false:
return 7721;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7722;
case false:
return 7723;
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
return 7724;
case false:
return 7725;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7726;
case false:
return 7727;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7728;
case false:
return 7729;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7730;
case false:
return 7731;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7732;
case false:
return 7733;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7734;
case false:
return 7735;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7736;
case false:
return 7737;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7738;
case false:
return 7739;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7740;
case false:
return 7741;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7742;
case false:
return 7743;
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
return 7744;
case false:
return 7745;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7746;
case false:
return 7747;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7748;
case false:
return 7749;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7750;
case false:
return 7751;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7752;
case false:
return 7753;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 7754;
case false:
return 7755;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 7756;
case false:
return 7757;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 7758;
case false:
return 7759;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 7760;
case false:
return 7761;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 7762;
case false:
return 7763;
}
}
}
}
}
constexpr static red_sandstone_stairs from_id(block_id_type id)
{
switch (id)
{
case 7684:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7685:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7686:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7687:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7688:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7689:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7690:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7691:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7692:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7693:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7694:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7695:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7696:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7697:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7698:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7699:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7700:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7701:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7702:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7703:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 7704:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7705:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7706:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7707:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7708:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7709:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7710:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7711:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7712:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7713:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7714:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7715:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7716:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7717:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7718:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7719:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7720:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7721:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7722:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7723:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 7724:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7725:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7726:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7727:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7728:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7729:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7730:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7731:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7732:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7733:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7734:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7735:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7736:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7737:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7738:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7739:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7740:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7741:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7742:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7743:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 7744:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 7745:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 7746:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 7747:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 7748:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 7749:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 7750:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 7751:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 7752:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 7753:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 7754:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 7755:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 7756:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 7757:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 7758:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 7759:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 7760:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 7761:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 7762:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 7763:
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
return "minecraft:red_sandstone_stairs:north:top:straight:true";
case false:
return "minecraft:red_sandstone_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:north:top:inner_left:true";
case false:
return "minecraft:red_sandstone_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:north:top:inner_right:true";
case false:
return "minecraft:red_sandstone_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:north:top:outer_left:true";
case false:
return "minecraft:red_sandstone_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:north:top:outer_right:true";
case false:
return "minecraft:red_sandstone_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:north:bottom:straight:true";
case false:
return "minecraft:red_sandstone_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:red_sandstone_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:red_sandstone_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:red_sandstone_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:red_sandstone_stairs:north:bottom:outer_right:false";
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
return "minecraft:red_sandstone_stairs:south:top:straight:true";
case false:
return "minecraft:red_sandstone_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:south:top:inner_left:true";
case false:
return "minecraft:red_sandstone_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:south:top:inner_right:true";
case false:
return "minecraft:red_sandstone_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:south:top:outer_left:true";
case false:
return "minecraft:red_sandstone_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:south:top:outer_right:true";
case false:
return "minecraft:red_sandstone_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:south:bottom:straight:true";
case false:
return "minecraft:red_sandstone_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:red_sandstone_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:red_sandstone_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:red_sandstone_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:red_sandstone_stairs:south:bottom:outer_right:false";
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
return "minecraft:red_sandstone_stairs:west:top:straight:true";
case false:
return "minecraft:red_sandstone_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:west:top:inner_left:true";
case false:
return "minecraft:red_sandstone_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:west:top:inner_right:true";
case false:
return "minecraft:red_sandstone_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:west:top:outer_left:true";
case false:
return "minecraft:red_sandstone_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:west:top:outer_right:true";
case false:
return "minecraft:red_sandstone_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:west:bottom:straight:true";
case false:
return "minecraft:red_sandstone_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:red_sandstone_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:red_sandstone_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:red_sandstone_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:red_sandstone_stairs:west:bottom:outer_right:false";
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
return "minecraft:red_sandstone_stairs:east:top:straight:true";
case false:
return "minecraft:red_sandstone_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:east:top:inner_left:true";
case false:
return "minecraft:red_sandstone_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:east:top:inner_right:true";
case false:
return "minecraft:red_sandstone_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:east:top:outer_left:true";
case false:
return "minecraft:red_sandstone_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:east:top:outer_right:true";
case false:
return "minecraft:red_sandstone_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:east:bottom:straight:true";
case false:
return "minecraft:red_sandstone_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:red_sandstone_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:red_sandstone_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:red_sandstone_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:red_sandstone_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:red_sandstone_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
