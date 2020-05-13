#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct oak_fence_gate
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
bool in_wall = false;
bool open = false;
bool powered = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (in_wall)
{
case true:
switch (open)
{
case true:
switch (powered)
{
case true:
return 4804;
case false:
return 4805;
}
case false:
switch (powered)
{
case true:
return 4806;
case false:
return 4807;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 4808;
case false:
return 4809;
}
case false:
switch (powered)
{
case true:
return 4810;
case false:
return 4811;
}
}
}
case facing_type::south:
switch (in_wall)
{
case true:
switch (open)
{
case true:
switch (powered)
{
case true:
return 4812;
case false:
return 4813;
}
case false:
switch (powered)
{
case true:
return 4814;
case false:
return 4815;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 4816;
case false:
return 4817;
}
case false:
switch (powered)
{
case true:
return 4818;
case false:
return 4819;
}
}
}
case facing_type::west:
switch (in_wall)
{
case true:
switch (open)
{
case true:
switch (powered)
{
case true:
return 4820;
case false:
return 4821;
}
case false:
switch (powered)
{
case true:
return 4822;
case false:
return 4823;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 4824;
case false:
return 4825;
}
case false:
switch (powered)
{
case true:
return 4826;
case false:
return 4827;
}
}
}
case facing_type::east:
switch (in_wall)
{
case true:
switch (open)
{
case true:
switch (powered)
{
case true:
return 4828;
case false:
return 4829;
}
case false:
switch (powered)
{
case true:
return 4830;
case false:
return 4831;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 4832;
case false:
return 4833;
}
case false:
switch (powered)
{
case true:
return 4834;
case false:
return 4835;
}
}
}
}
}
constexpr static oak_fence_gate from_id(block_id_type id)
{
switch (id)
{
case 4804:
return {.facing = facing_type::north, .in_wall = true, .open = true, .powered = true};
case 4805:
return {.facing = facing_type::north, .in_wall = true, .open = true, .powered = false};
case 4806:
return {.facing = facing_type::north, .in_wall = true, .open = false, .powered = true};
case 4807:
return {.facing = facing_type::north, .in_wall = true, .open = false, .powered = false};
case 4808:
return {.facing = facing_type::north, .in_wall = false, .open = true, .powered = true};
case 4809:
return {.facing = facing_type::north, .in_wall = false, .open = true, .powered = false};
case 4810:
return {.facing = facing_type::north, .in_wall = false, .open = false, .powered = true};
case 4811:
return {.facing = facing_type::north, .in_wall = false, .open = false, .powered = false};
case 4812:
return {.facing = facing_type::south, .in_wall = true, .open = true, .powered = true};
case 4813:
return {.facing = facing_type::south, .in_wall = true, .open = true, .powered = false};
case 4814:
return {.facing = facing_type::south, .in_wall = true, .open = false, .powered = true};
case 4815:
return {.facing = facing_type::south, .in_wall = true, .open = false, .powered = false};
case 4816:
return {.facing = facing_type::south, .in_wall = false, .open = true, .powered = true};
case 4817:
return {.facing = facing_type::south, .in_wall = false, .open = true, .powered = false};
case 4818:
return {.facing = facing_type::south, .in_wall = false, .open = false, .powered = true};
case 4819:
return {.facing = facing_type::south, .in_wall = false, .open = false, .powered = false};
case 4820:
return {.facing = facing_type::west, .in_wall = true, .open = true, .powered = true};
case 4821:
return {.facing = facing_type::west, .in_wall = true, .open = true, .powered = false};
case 4822:
return {.facing = facing_type::west, .in_wall = true, .open = false, .powered = true};
case 4823:
return {.facing = facing_type::west, .in_wall = true, .open = false, .powered = false};
case 4824:
return {.facing = facing_type::west, .in_wall = false, .open = true, .powered = true};
case 4825:
return {.facing = facing_type::west, .in_wall = false, .open = true, .powered = false};
case 4826:
return {.facing = facing_type::west, .in_wall = false, .open = false, .powered = true};
case 4827:
return {.facing = facing_type::west, .in_wall = false, .open = false, .powered = false};
case 4828:
return {.facing = facing_type::east, .in_wall = true, .open = true, .powered = true};
case 4829:
return {.facing = facing_type::east, .in_wall = true, .open = true, .powered = false};
case 4830:
return {.facing = facing_type::east, .in_wall = true, .open = false, .powered = true};
case 4831:
return {.facing = facing_type::east, .in_wall = true, .open = false, .powered = false};
case 4832:
return {.facing = facing_type::east, .in_wall = false, .open = true, .powered = true};
case 4833:
return {.facing = facing_type::east, .in_wall = false, .open = true, .powered = false};
case 4834:
return {.facing = facing_type::east, .in_wall = false, .open = false, .powered = true};
case 4835:
return {.facing = facing_type::east, .in_wall = false, .open = false, .powered = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (in_wall)
{
case true:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:north:true:true:true";
case false:
return "minecraft:oak_fence_gate:north:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:north:true:false:true";
case false:
return "minecraft:oak_fence_gate:north:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:north:false:true:true";
case false:
return "minecraft:oak_fence_gate:north:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:north:false:false:true";
case false:
return "minecraft:oak_fence_gate:north:false:false:false";
}
}
}
case facing_type::south:
switch (in_wall)
{
case true:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:south:true:true:true";
case false:
return "minecraft:oak_fence_gate:south:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:south:true:false:true";
case false:
return "minecraft:oak_fence_gate:south:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:south:false:true:true";
case false:
return "minecraft:oak_fence_gate:south:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:south:false:false:true";
case false:
return "minecraft:oak_fence_gate:south:false:false:false";
}
}
}
case facing_type::west:
switch (in_wall)
{
case true:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:west:true:true:true";
case false:
return "minecraft:oak_fence_gate:west:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:west:true:false:true";
case false:
return "minecraft:oak_fence_gate:west:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:west:false:true:true";
case false:
return "minecraft:oak_fence_gate:west:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:west:false:false:true";
case false:
return "minecraft:oak_fence_gate:west:false:false:false";
}
}
}
case facing_type::east:
switch (in_wall)
{
case true:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:east:true:true:true";
case false:
return "minecraft:oak_fence_gate:east:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:east:true:false:true";
case false:
return "minecraft:oak_fence_gate:east:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:east:false:true:true";
case false:
return "minecraft:oak_fence_gate:east:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_fence_gate:east:false:false:true";
case false:
return "minecraft:oak_fence_gate:east:false:false:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
