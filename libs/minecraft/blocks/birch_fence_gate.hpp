#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct birch_fence_gate
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
return 7914;
case false:
return 7915;
}
case false:
switch (powered)
{
case true:
return 7916;
case false:
return 7917;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7918;
case false:
return 7919;
}
case false:
switch (powered)
{
case true:
return 7920;
case false:
return 7921;
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
return 7922;
case false:
return 7923;
}
case false:
switch (powered)
{
case true:
return 7924;
case false:
return 7925;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7926;
case false:
return 7927;
}
case false:
switch (powered)
{
case true:
return 7928;
case false:
return 7929;
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
return 7930;
case false:
return 7931;
}
case false:
switch (powered)
{
case true:
return 7932;
case false:
return 7933;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7934;
case false:
return 7935;
}
case false:
switch (powered)
{
case true:
return 7936;
case false:
return 7937;
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
return 7938;
case false:
return 7939;
}
case false:
switch (powered)
{
case true:
return 7940;
case false:
return 7941;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7942;
case false:
return 7943;
}
case false:
switch (powered)
{
case true:
return 7944;
case false:
return 7945;
}
}
}
}
}
constexpr static birch_fence_gate from_id(block_id_type id)
{
switch (id)
{
case 7914:
return {.facing = facing_type::north, .in_wall = true, .open = true, .powered = true};
case 7915:
return {.facing = facing_type::north, .in_wall = true, .open = true, .powered = false};
case 7916:
return {.facing = facing_type::north, .in_wall = true, .open = false, .powered = true};
case 7917:
return {.facing = facing_type::north, .in_wall = true, .open = false, .powered = false};
case 7918:
return {.facing = facing_type::north, .in_wall = false, .open = true, .powered = true};
case 7919:
return {.facing = facing_type::north, .in_wall = false, .open = true, .powered = false};
case 7920:
return {.facing = facing_type::north, .in_wall = false, .open = false, .powered = true};
case 7921:
return {.facing = facing_type::north, .in_wall = false, .open = false, .powered = false};
case 7922:
return {.facing = facing_type::south, .in_wall = true, .open = true, .powered = true};
case 7923:
return {.facing = facing_type::south, .in_wall = true, .open = true, .powered = false};
case 7924:
return {.facing = facing_type::south, .in_wall = true, .open = false, .powered = true};
case 7925:
return {.facing = facing_type::south, .in_wall = true, .open = false, .powered = false};
case 7926:
return {.facing = facing_type::south, .in_wall = false, .open = true, .powered = true};
case 7927:
return {.facing = facing_type::south, .in_wall = false, .open = true, .powered = false};
case 7928:
return {.facing = facing_type::south, .in_wall = false, .open = false, .powered = true};
case 7929:
return {.facing = facing_type::south, .in_wall = false, .open = false, .powered = false};
case 7930:
return {.facing = facing_type::west, .in_wall = true, .open = true, .powered = true};
case 7931:
return {.facing = facing_type::west, .in_wall = true, .open = true, .powered = false};
case 7932:
return {.facing = facing_type::west, .in_wall = true, .open = false, .powered = true};
case 7933:
return {.facing = facing_type::west, .in_wall = true, .open = false, .powered = false};
case 7934:
return {.facing = facing_type::west, .in_wall = false, .open = true, .powered = true};
case 7935:
return {.facing = facing_type::west, .in_wall = false, .open = true, .powered = false};
case 7936:
return {.facing = facing_type::west, .in_wall = false, .open = false, .powered = true};
case 7937:
return {.facing = facing_type::west, .in_wall = false, .open = false, .powered = false};
case 7938:
return {.facing = facing_type::east, .in_wall = true, .open = true, .powered = true};
case 7939:
return {.facing = facing_type::east, .in_wall = true, .open = true, .powered = false};
case 7940:
return {.facing = facing_type::east, .in_wall = true, .open = false, .powered = true};
case 7941:
return {.facing = facing_type::east, .in_wall = true, .open = false, .powered = false};
case 7942:
return {.facing = facing_type::east, .in_wall = false, .open = true, .powered = true};
case 7943:
return {.facing = facing_type::east, .in_wall = false, .open = true, .powered = false};
case 7944:
return {.facing = facing_type::east, .in_wall = false, .open = false, .powered = true};
case 7945:
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
return "minecraft:birch_fence_gate:north:true:true:true";
case false:
return "minecraft:birch_fence_gate:north:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_fence_gate:north:true:false:true";
case false:
return "minecraft:birch_fence_gate:north:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_fence_gate:north:false:true:true";
case false:
return "minecraft:birch_fence_gate:north:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_fence_gate:north:false:false:true";
case false:
return "minecraft:birch_fence_gate:north:false:false:false";
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
return "minecraft:birch_fence_gate:south:true:true:true";
case false:
return "minecraft:birch_fence_gate:south:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_fence_gate:south:true:false:true";
case false:
return "minecraft:birch_fence_gate:south:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_fence_gate:south:false:true:true";
case false:
return "minecraft:birch_fence_gate:south:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_fence_gate:south:false:false:true";
case false:
return "minecraft:birch_fence_gate:south:false:false:false";
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
return "minecraft:birch_fence_gate:west:true:true:true";
case false:
return "minecraft:birch_fence_gate:west:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_fence_gate:west:true:false:true";
case false:
return "minecraft:birch_fence_gate:west:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_fence_gate:west:false:true:true";
case false:
return "minecraft:birch_fence_gate:west:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_fence_gate:west:false:false:true";
case false:
return "minecraft:birch_fence_gate:west:false:false:false";
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
return "minecraft:birch_fence_gate:east:true:true:true";
case false:
return "minecraft:birch_fence_gate:east:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_fence_gate:east:true:false:true";
case false:
return "minecraft:birch_fence_gate:east:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:birch_fence_gate:east:false:true:true";
case false:
return "minecraft:birch_fence_gate:east:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:birch_fence_gate:east:false:false:true";
case false:
return "minecraft:birch_fence_gate:east:false:false:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
