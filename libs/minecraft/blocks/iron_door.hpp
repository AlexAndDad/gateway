#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct iron_door
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
enum class half_type : std::uint8_t
{
upper,
lower
} half = half_type::lower;
enum class hinge_type : std::uint8_t
{
left,
right
} hinge = hinge_type::left;
bool open = false;
bool powered = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3807;
case false:
return 3808;
}
case false:
switch (powered)
{
case true:
return 3809;
case false:
return 3810;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3811;
case false:
return 3812;
}
case false:
switch (powered)
{
case true:
return 3813;
case false:
return 3814;
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3815;
case false:
return 3816;
}
case false:
switch (powered)
{
case true:
return 3817;
case false:
return 3818;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3819;
case false:
return 3820;
}
case false:
switch (powered)
{
case true:
return 3821;
case false:
return 3822;
}
}
}
}
case facing_type::south:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3823;
case false:
return 3824;
}
case false:
switch (powered)
{
case true:
return 3825;
case false:
return 3826;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3827;
case false:
return 3828;
}
case false:
switch (powered)
{
case true:
return 3829;
case false:
return 3830;
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3831;
case false:
return 3832;
}
case false:
switch (powered)
{
case true:
return 3833;
case false:
return 3834;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3835;
case false:
return 3836;
}
case false:
switch (powered)
{
case true:
return 3837;
case false:
return 3838;
}
}
}
}
case facing_type::west:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3839;
case false:
return 3840;
}
case false:
switch (powered)
{
case true:
return 3841;
case false:
return 3842;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3843;
case false:
return 3844;
}
case false:
switch (powered)
{
case true:
return 3845;
case false:
return 3846;
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3847;
case false:
return 3848;
}
case false:
switch (powered)
{
case true:
return 3849;
case false:
return 3850;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3851;
case false:
return 3852;
}
case false:
switch (powered)
{
case true:
return 3853;
case false:
return 3854;
}
}
}
}
case facing_type::east:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3855;
case false:
return 3856;
}
case false:
switch (powered)
{
case true:
return 3857;
case false:
return 3858;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3859;
case false:
return 3860;
}
case false:
switch (powered)
{
case true:
return 3861;
case false:
return 3862;
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3863;
case false:
return 3864;
}
case false:
switch (powered)
{
case true:
return 3865;
case false:
return 3866;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3867;
case false:
return 3868;
}
case false:
switch (powered)
{
case true:
return 3869;
case false:
return 3870;
}
}
}
}
}
}
constexpr static iron_door from_id(block_id_type id)
{
switch (id)
{
case 3807:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 3808:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 3809:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 3810:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 3811:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 3812:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 3813:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 3814:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 3815:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 3816:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 3817:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 3818:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 3819:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 3820:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 3821:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 3822:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 3823:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 3824:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 3825:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 3826:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 3827:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 3828:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 3829:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 3830:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 3831:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 3832:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 3833:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 3834:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 3835:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 3836:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 3837:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 3838:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 3839:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 3840:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 3841:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 3842:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 3843:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 3844:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 3845:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 3846:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 3847:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 3848:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 3849:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 3850:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 3851:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 3852:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 3853:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 3854:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 3855:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 3856:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 3857:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 3858:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 3859:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 3860:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 3861:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 3862:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 3863:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 3864:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 3865:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 3866:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 3867:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 3868:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 3869:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 3870:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:north:upper:left:true:true";
case false:
return "minecraft:iron_door:north:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:north:upper:left:false:true";
case false:
return "minecraft:iron_door:north:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:north:upper:right:true:true";
case false:
return "minecraft:iron_door:north:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:north:upper:right:false:true";
case false:
return "minecraft:iron_door:north:upper:right:false:false";
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:north:lower:left:true:true";
case false:
return "minecraft:iron_door:north:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:north:lower:left:false:true";
case false:
return "minecraft:iron_door:north:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:north:lower:right:true:true";
case false:
return "minecraft:iron_door:north:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:north:lower:right:false:true";
case false:
return "minecraft:iron_door:north:lower:right:false:false";
}
}
}
}
case facing_type::south:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:south:upper:left:true:true";
case false:
return "minecraft:iron_door:south:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:south:upper:left:false:true";
case false:
return "minecraft:iron_door:south:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:south:upper:right:true:true";
case false:
return "minecraft:iron_door:south:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:south:upper:right:false:true";
case false:
return "minecraft:iron_door:south:upper:right:false:false";
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:south:lower:left:true:true";
case false:
return "minecraft:iron_door:south:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:south:lower:left:false:true";
case false:
return "minecraft:iron_door:south:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:south:lower:right:true:true";
case false:
return "minecraft:iron_door:south:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:south:lower:right:false:true";
case false:
return "minecraft:iron_door:south:lower:right:false:false";
}
}
}
}
case facing_type::west:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:west:upper:left:true:true";
case false:
return "minecraft:iron_door:west:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:west:upper:left:false:true";
case false:
return "minecraft:iron_door:west:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:west:upper:right:true:true";
case false:
return "minecraft:iron_door:west:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:west:upper:right:false:true";
case false:
return "minecraft:iron_door:west:upper:right:false:false";
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:west:lower:left:true:true";
case false:
return "minecraft:iron_door:west:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:west:lower:left:false:true";
case false:
return "minecraft:iron_door:west:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:west:lower:right:true:true";
case false:
return "minecraft:iron_door:west:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:west:lower:right:false:true";
case false:
return "minecraft:iron_door:west:lower:right:false:false";
}
}
}
}
case facing_type::east:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:east:upper:left:true:true";
case false:
return "minecraft:iron_door:east:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:east:upper:left:false:true";
case false:
return "minecraft:iron_door:east:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:east:upper:right:true:true";
case false:
return "minecraft:iron_door:east:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:east:upper:right:false:true";
case false:
return "minecraft:iron_door:east:upper:right:false:false";
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:east:lower:left:true:true";
case false:
return "minecraft:iron_door:east:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:east:lower:left:false:true";
case false:
return "minecraft:iron_door:east:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:iron_door:east:lower:right:true:true";
case false:
return "minecraft:iron_door:east:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:iron_door:east:lower:right:false:true";
case false:
return "minecraft:iron_door:east:lower:right:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
