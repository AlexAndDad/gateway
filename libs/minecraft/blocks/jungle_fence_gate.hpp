#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jungle_fence_gate
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
return 7946;
case false:
return 7947;
}
case false:
switch (powered)
{
case true:
return 7948;
case false:
return 7949;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7950;
case false:
return 7951;
}
case false:
switch (powered)
{
case true:
return 7952;
case false:
return 7953;
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
return 7954;
case false:
return 7955;
}
case false:
switch (powered)
{
case true:
return 7956;
case false:
return 7957;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7958;
case false:
return 7959;
}
case false:
switch (powered)
{
case true:
return 7960;
case false:
return 7961;
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
return 7962;
case false:
return 7963;
}
case false:
switch (powered)
{
case true:
return 7964;
case false:
return 7965;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7966;
case false:
return 7967;
}
case false:
switch (powered)
{
case true:
return 7968;
case false:
return 7969;
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
return 7970;
case false:
return 7971;
}
case false:
switch (powered)
{
case true:
return 7972;
case false:
return 7973;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7974;
case false:
return 7975;
}
case false:
switch (powered)
{
case true:
return 7976;
case false:
return 7977;
}
}
}
}
}
constexpr static jungle_fence_gate from_id(block_id_type id)
{
switch (id)
{
case 7946:
return {.facing = facing_type::north, .in_wall = true, .open = true, .powered = true};
case 7947:
return {.facing = facing_type::north, .in_wall = true, .open = true, .powered = false};
case 7948:
return {.facing = facing_type::north, .in_wall = true, .open = false, .powered = true};
case 7949:
return {.facing = facing_type::north, .in_wall = true, .open = false, .powered = false};
case 7950:
return {.facing = facing_type::north, .in_wall = false, .open = true, .powered = true};
case 7951:
return {.facing = facing_type::north, .in_wall = false, .open = true, .powered = false};
case 7952:
return {.facing = facing_type::north, .in_wall = false, .open = false, .powered = true};
case 7953:
return {.facing = facing_type::north, .in_wall = false, .open = false, .powered = false};
case 7954:
return {.facing = facing_type::south, .in_wall = true, .open = true, .powered = true};
case 7955:
return {.facing = facing_type::south, .in_wall = true, .open = true, .powered = false};
case 7956:
return {.facing = facing_type::south, .in_wall = true, .open = false, .powered = true};
case 7957:
return {.facing = facing_type::south, .in_wall = true, .open = false, .powered = false};
case 7958:
return {.facing = facing_type::south, .in_wall = false, .open = true, .powered = true};
case 7959:
return {.facing = facing_type::south, .in_wall = false, .open = true, .powered = false};
case 7960:
return {.facing = facing_type::south, .in_wall = false, .open = false, .powered = true};
case 7961:
return {.facing = facing_type::south, .in_wall = false, .open = false, .powered = false};
case 7962:
return {.facing = facing_type::west, .in_wall = true, .open = true, .powered = true};
case 7963:
return {.facing = facing_type::west, .in_wall = true, .open = true, .powered = false};
case 7964:
return {.facing = facing_type::west, .in_wall = true, .open = false, .powered = true};
case 7965:
return {.facing = facing_type::west, .in_wall = true, .open = false, .powered = false};
case 7966:
return {.facing = facing_type::west, .in_wall = false, .open = true, .powered = true};
case 7967:
return {.facing = facing_type::west, .in_wall = false, .open = true, .powered = false};
case 7968:
return {.facing = facing_type::west, .in_wall = false, .open = false, .powered = true};
case 7969:
return {.facing = facing_type::west, .in_wall = false, .open = false, .powered = false};
case 7970:
return {.facing = facing_type::east, .in_wall = true, .open = true, .powered = true};
case 7971:
return {.facing = facing_type::east, .in_wall = true, .open = true, .powered = false};
case 7972:
return {.facing = facing_type::east, .in_wall = true, .open = false, .powered = true};
case 7973:
return {.facing = facing_type::east, .in_wall = true, .open = false, .powered = false};
case 7974:
return {.facing = facing_type::east, .in_wall = false, .open = true, .powered = true};
case 7975:
return {.facing = facing_type::east, .in_wall = false, .open = true, .powered = false};
case 7976:
return {.facing = facing_type::east, .in_wall = false, .open = false, .powered = true};
case 7977:
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
return "minecraft:jungle_fence_gate:north:true:true:true";
case false:
return "minecraft:jungle_fence_gate:north:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_fence_gate:north:true:false:true";
case false:
return "minecraft:jungle_fence_gate:north:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:jungle_fence_gate:north:false:true:true";
case false:
return "minecraft:jungle_fence_gate:north:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_fence_gate:north:false:false:true";
case false:
return "minecraft:jungle_fence_gate:north:false:false:false";
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
return "minecraft:jungle_fence_gate:south:true:true:true";
case false:
return "minecraft:jungle_fence_gate:south:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_fence_gate:south:true:false:true";
case false:
return "minecraft:jungle_fence_gate:south:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:jungle_fence_gate:south:false:true:true";
case false:
return "minecraft:jungle_fence_gate:south:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_fence_gate:south:false:false:true";
case false:
return "minecraft:jungle_fence_gate:south:false:false:false";
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
return "minecraft:jungle_fence_gate:west:true:true:true";
case false:
return "minecraft:jungle_fence_gate:west:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_fence_gate:west:true:false:true";
case false:
return "minecraft:jungle_fence_gate:west:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:jungle_fence_gate:west:false:true:true";
case false:
return "minecraft:jungle_fence_gate:west:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_fence_gate:west:false:false:true";
case false:
return "minecraft:jungle_fence_gate:west:false:false:false";
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
return "minecraft:jungle_fence_gate:east:true:true:true";
case false:
return "minecraft:jungle_fence_gate:east:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_fence_gate:east:true:false:true";
case false:
return "minecraft:jungle_fence_gate:east:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:jungle_fence_gate:east:false:true:true";
case false:
return "minecraft:jungle_fence_gate:east:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_fence_gate:east:false:false:true";
case false:
return "minecraft:jungle_fence_gate:east:false:false:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
