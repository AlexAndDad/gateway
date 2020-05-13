#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct cobblestone_stairs
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
return 3653;
case false:
return 3654;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 3655;
case false:
return 3656;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 3657;
case false:
return 3658;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 3659;
case false:
return 3660;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 3661;
case false:
return 3662;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 3663;
case false:
return 3664;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 3665;
case false:
return 3666;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 3667;
case false:
return 3668;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 3669;
case false:
return 3670;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 3671;
case false:
return 3672;
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
return 3673;
case false:
return 3674;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 3675;
case false:
return 3676;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 3677;
case false:
return 3678;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 3679;
case false:
return 3680;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 3681;
case false:
return 3682;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 3683;
case false:
return 3684;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 3685;
case false:
return 3686;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 3687;
case false:
return 3688;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 3689;
case false:
return 3690;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 3691;
case false:
return 3692;
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
return 3693;
case false:
return 3694;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 3695;
case false:
return 3696;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 3697;
case false:
return 3698;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 3699;
case false:
return 3700;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 3701;
case false:
return 3702;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 3703;
case false:
return 3704;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 3705;
case false:
return 3706;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 3707;
case false:
return 3708;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 3709;
case false:
return 3710;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 3711;
case false:
return 3712;
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
return 3713;
case false:
return 3714;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 3715;
case false:
return 3716;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 3717;
case false:
return 3718;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 3719;
case false:
return 3720;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 3721;
case false:
return 3722;
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return 3723;
case false:
return 3724;
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return 3725;
case false:
return 3726;
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return 3727;
case false:
return 3728;
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return 3729;
case false:
return 3730;
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return 3731;
case false:
return 3732;
}
}
}
}
}
constexpr static cobblestone_stairs from_id(block_id_type id)
{
switch (id)
{
case 3653:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 3654:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 3655:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 3656:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 3657:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 3658:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 3659:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 3660:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 3661:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 3662:
return {.facing = facing_type::north, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 3663:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 3664:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 3665:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 3666:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 3667:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 3668:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 3669:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 3670:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 3671:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 3672:
return {.facing = facing_type::north, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 3673:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 3674:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 3675:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 3676:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 3677:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 3678:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 3679:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 3680:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 3681:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 3682:
return {.facing = facing_type::south, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 3683:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 3684:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 3685:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 3686:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 3687:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 3688:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 3689:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 3690:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 3691:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 3692:
return {.facing = facing_type::south, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 3693:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 3694:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 3695:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 3696:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 3697:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 3698:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 3699:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 3700:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 3701:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 3702:
return {.facing = facing_type::west, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 3703:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 3704:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 3705:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 3706:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 3707:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 3708:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 3709:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 3710:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 3711:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 3712:
return {.facing = facing_type::west, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = false};
case 3713:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = true};
case 3714:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::straight, .waterlogged = false};
case 3715:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = true};
case 3716:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_left, .waterlogged = false};
case 3717:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = true};
case 3718:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::inner_right, .waterlogged = false};
case 3719:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = true};
case 3720:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_left, .waterlogged = false};
case 3721:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = true};
case 3722:
return {.facing = facing_type::east, .half = half_type::top, .shape = shape_type::outer_right, .waterlogged = false};
case 3723:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = true};
case 3724:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::straight, .waterlogged = false};
case 3725:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = true};
case 3726:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_left, .waterlogged = false};
case 3727:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = true};
case 3728:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::inner_right, .waterlogged = false};
case 3729:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = true};
case 3730:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_left, .waterlogged = false};
case 3731:
return {.facing = facing_type::east, .half = half_type::bottom, .shape = shape_type::outer_right, .waterlogged = true};
case 3732:
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
return "minecraft:cobblestone_stairs:north:top:straight:true";
case false:
return "minecraft:cobblestone_stairs:north:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:north:top:inner_left:true";
case false:
return "minecraft:cobblestone_stairs:north:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:north:top:inner_right:true";
case false:
return "minecraft:cobblestone_stairs:north:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:north:top:outer_left:true";
case false:
return "minecraft:cobblestone_stairs:north:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:north:top:outer_right:true";
case false:
return "minecraft:cobblestone_stairs:north:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:north:bottom:straight:true";
case false:
return "minecraft:cobblestone_stairs:north:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:north:bottom:inner_left:true";
case false:
return "minecraft:cobblestone_stairs:north:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:north:bottom:inner_right:true";
case false:
return "minecraft:cobblestone_stairs:north:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:north:bottom:outer_left:true";
case false:
return "minecraft:cobblestone_stairs:north:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:north:bottom:outer_right:true";
case false:
return "minecraft:cobblestone_stairs:north:bottom:outer_right:false";
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
return "minecraft:cobblestone_stairs:south:top:straight:true";
case false:
return "minecraft:cobblestone_stairs:south:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:south:top:inner_left:true";
case false:
return "minecraft:cobblestone_stairs:south:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:south:top:inner_right:true";
case false:
return "minecraft:cobblestone_stairs:south:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:south:top:outer_left:true";
case false:
return "minecraft:cobblestone_stairs:south:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:south:top:outer_right:true";
case false:
return "minecraft:cobblestone_stairs:south:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:south:bottom:straight:true";
case false:
return "minecraft:cobblestone_stairs:south:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:south:bottom:inner_left:true";
case false:
return "minecraft:cobblestone_stairs:south:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:south:bottom:inner_right:true";
case false:
return "minecraft:cobblestone_stairs:south:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:south:bottom:outer_left:true";
case false:
return "minecraft:cobblestone_stairs:south:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:south:bottom:outer_right:true";
case false:
return "minecraft:cobblestone_stairs:south:bottom:outer_right:false";
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
return "minecraft:cobblestone_stairs:west:top:straight:true";
case false:
return "minecraft:cobblestone_stairs:west:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:west:top:inner_left:true";
case false:
return "minecraft:cobblestone_stairs:west:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:west:top:inner_right:true";
case false:
return "minecraft:cobblestone_stairs:west:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:west:top:outer_left:true";
case false:
return "minecraft:cobblestone_stairs:west:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:west:top:outer_right:true";
case false:
return "minecraft:cobblestone_stairs:west:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:west:bottom:straight:true";
case false:
return "minecraft:cobblestone_stairs:west:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:west:bottom:inner_left:true";
case false:
return "minecraft:cobblestone_stairs:west:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:west:bottom:inner_right:true";
case false:
return "minecraft:cobblestone_stairs:west:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:west:bottom:outer_left:true";
case false:
return "minecraft:cobblestone_stairs:west:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:west:bottom:outer_right:true";
case false:
return "minecraft:cobblestone_stairs:west:bottom:outer_right:false";
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
return "minecraft:cobblestone_stairs:east:top:straight:true";
case false:
return "minecraft:cobblestone_stairs:east:top:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:east:top:inner_left:true";
case false:
return "minecraft:cobblestone_stairs:east:top:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:east:top:inner_right:true";
case false:
return "minecraft:cobblestone_stairs:east:top:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:east:top:outer_left:true";
case false:
return "minecraft:cobblestone_stairs:east:top:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:east:top:outer_right:true";
case false:
return "minecraft:cobblestone_stairs:east:top:outer_right:false";
}
}
case half_type::bottom:
switch (shape)
{
case shape_type::straight:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:east:bottom:straight:true";
case false:
return "minecraft:cobblestone_stairs:east:bottom:straight:false";
}
case shape_type::inner_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:east:bottom:inner_left:true";
case false:
return "minecraft:cobblestone_stairs:east:bottom:inner_left:false";
}
case shape_type::inner_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:east:bottom:inner_right:true";
case false:
return "minecraft:cobblestone_stairs:east:bottom:inner_right:false";
}
case shape_type::outer_left:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:east:bottom:outer_left:true";
case false:
return "minecraft:cobblestone_stairs:east:bottom:outer_left:false";
}
case shape_type::outer_right:
switch (waterlogged)
{
case true:
return "minecraft:cobblestone_stairs:east:bottom:outer_right:true";
case false:
return "minecraft:cobblestone_stairs:east:bottom:outer_right:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
