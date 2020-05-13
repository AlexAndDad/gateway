#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dark_oak_fence_gate
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
return 8010;
case false:
return 8011;
}
case false:
switch (powered)
{
case true:
return 8012;
case false:
return 8013;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8014;
case false:
return 8015;
}
case false:
switch (powered)
{
case true:
return 8016;
case false:
return 8017;
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
return 8018;
case false:
return 8019;
}
case false:
switch (powered)
{
case true:
return 8020;
case false:
return 8021;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8022;
case false:
return 8023;
}
case false:
switch (powered)
{
case true:
return 8024;
case false:
return 8025;
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
return 8026;
case false:
return 8027;
}
case false:
switch (powered)
{
case true:
return 8028;
case false:
return 8029;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8030;
case false:
return 8031;
}
case false:
switch (powered)
{
case true:
return 8032;
case false:
return 8033;
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
return 8034;
case false:
return 8035;
}
case false:
switch (powered)
{
case true:
return 8036;
case false:
return 8037;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8038;
case false:
return 8039;
}
case false:
switch (powered)
{
case true:
return 8040;
case false:
return 8041;
}
}
}
}
}
constexpr static dark_oak_fence_gate from_id(block_id_type id)
{
switch (id)
{
case 8010:
return {.facing = facing_type::north, .in_wall = true, .open = true, .powered = true};
case 8011:
return {.facing = facing_type::north, .in_wall = true, .open = true, .powered = false};
case 8012:
return {.facing = facing_type::north, .in_wall = true, .open = false, .powered = true};
case 8013:
return {.facing = facing_type::north, .in_wall = true, .open = false, .powered = false};
case 8014:
return {.facing = facing_type::north, .in_wall = false, .open = true, .powered = true};
case 8015:
return {.facing = facing_type::north, .in_wall = false, .open = true, .powered = false};
case 8016:
return {.facing = facing_type::north, .in_wall = false, .open = false, .powered = true};
case 8017:
return {.facing = facing_type::north, .in_wall = false, .open = false, .powered = false};
case 8018:
return {.facing = facing_type::south, .in_wall = true, .open = true, .powered = true};
case 8019:
return {.facing = facing_type::south, .in_wall = true, .open = true, .powered = false};
case 8020:
return {.facing = facing_type::south, .in_wall = true, .open = false, .powered = true};
case 8021:
return {.facing = facing_type::south, .in_wall = true, .open = false, .powered = false};
case 8022:
return {.facing = facing_type::south, .in_wall = false, .open = true, .powered = true};
case 8023:
return {.facing = facing_type::south, .in_wall = false, .open = true, .powered = false};
case 8024:
return {.facing = facing_type::south, .in_wall = false, .open = false, .powered = true};
case 8025:
return {.facing = facing_type::south, .in_wall = false, .open = false, .powered = false};
case 8026:
return {.facing = facing_type::west, .in_wall = true, .open = true, .powered = true};
case 8027:
return {.facing = facing_type::west, .in_wall = true, .open = true, .powered = false};
case 8028:
return {.facing = facing_type::west, .in_wall = true, .open = false, .powered = true};
case 8029:
return {.facing = facing_type::west, .in_wall = true, .open = false, .powered = false};
case 8030:
return {.facing = facing_type::west, .in_wall = false, .open = true, .powered = true};
case 8031:
return {.facing = facing_type::west, .in_wall = false, .open = true, .powered = false};
case 8032:
return {.facing = facing_type::west, .in_wall = false, .open = false, .powered = true};
case 8033:
return {.facing = facing_type::west, .in_wall = false, .open = false, .powered = false};
case 8034:
return {.facing = facing_type::east, .in_wall = true, .open = true, .powered = true};
case 8035:
return {.facing = facing_type::east, .in_wall = true, .open = true, .powered = false};
case 8036:
return {.facing = facing_type::east, .in_wall = true, .open = false, .powered = true};
case 8037:
return {.facing = facing_type::east, .in_wall = true, .open = false, .powered = false};
case 8038:
return {.facing = facing_type::east, .in_wall = false, .open = true, .powered = true};
case 8039:
return {.facing = facing_type::east, .in_wall = false, .open = true, .powered = false};
case 8040:
return {.facing = facing_type::east, .in_wall = false, .open = false, .powered = true};
case 8041:
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
return "minecraft:dark_oak_fence_gate:north:true:true:true";
case false:
return "minecraft:dark_oak_fence_gate:north:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_fence_gate:north:true:false:true";
case false:
return "minecraft:dark_oak_fence_gate:north:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:dark_oak_fence_gate:north:false:true:true";
case false:
return "minecraft:dark_oak_fence_gate:north:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_fence_gate:north:false:false:true";
case false:
return "minecraft:dark_oak_fence_gate:north:false:false:false";
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
return "minecraft:dark_oak_fence_gate:south:true:true:true";
case false:
return "minecraft:dark_oak_fence_gate:south:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_fence_gate:south:true:false:true";
case false:
return "minecraft:dark_oak_fence_gate:south:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:dark_oak_fence_gate:south:false:true:true";
case false:
return "minecraft:dark_oak_fence_gate:south:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_fence_gate:south:false:false:true";
case false:
return "minecraft:dark_oak_fence_gate:south:false:false:false";
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
return "minecraft:dark_oak_fence_gate:west:true:true:true";
case false:
return "minecraft:dark_oak_fence_gate:west:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_fence_gate:west:true:false:true";
case false:
return "minecraft:dark_oak_fence_gate:west:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:dark_oak_fence_gate:west:false:true:true";
case false:
return "minecraft:dark_oak_fence_gate:west:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_fence_gate:west:false:false:true";
case false:
return "minecraft:dark_oak_fence_gate:west:false:false:false";
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
return "minecraft:dark_oak_fence_gate:east:true:true:true";
case false:
return "minecraft:dark_oak_fence_gate:east:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_fence_gate:east:true:false:true";
case false:
return "minecraft:dark_oak_fence_gate:east:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:dark_oak_fence_gate:east:false:true:true";
case false:
return "minecraft:dark_oak_fence_gate:east:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_fence_gate:east:false:false:true";
case false:
return "minecraft:dark_oak_fence_gate:east:false:false:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
