#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct acacia_fence_gate
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
return 7978;
case false:
return 7979;
}
case false:
switch (powered)
{
case true:
return 7980;
case false:
return 7981;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7982;
case false:
return 7983;
}
case false:
switch (powered)
{
case true:
return 7984;
case false:
return 7985;
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
return 7986;
case false:
return 7987;
}
case false:
switch (powered)
{
case true:
return 7988;
case false:
return 7989;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7990;
case false:
return 7991;
}
case false:
switch (powered)
{
case true:
return 7992;
case false:
return 7993;
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
return 7994;
case false:
return 7995;
}
case false:
switch (powered)
{
case true:
return 7996;
case false:
return 7997;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7998;
case false:
return 7999;
}
case false:
switch (powered)
{
case true:
return 8000;
case false:
return 8001;
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
return 8002;
case false:
return 8003;
}
case false:
switch (powered)
{
case true:
return 8004;
case false:
return 8005;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8006;
case false:
return 8007;
}
case false:
switch (powered)
{
case true:
return 8008;
case false:
return 8009;
}
}
}
}
}
constexpr static acacia_fence_gate from_id(block_id_type id)
{
switch (id)
{
case 7978:
return {.facing = facing_type::north, .in_wall = true, .open = true, .powered = true};
case 7979:
return {.facing = facing_type::north, .in_wall = true, .open = true, .powered = false};
case 7980:
return {.facing = facing_type::north, .in_wall = true, .open = false, .powered = true};
case 7981:
return {.facing = facing_type::north, .in_wall = true, .open = false, .powered = false};
case 7982:
return {.facing = facing_type::north, .in_wall = false, .open = true, .powered = true};
case 7983:
return {.facing = facing_type::north, .in_wall = false, .open = true, .powered = false};
case 7984:
return {.facing = facing_type::north, .in_wall = false, .open = false, .powered = true};
case 7985:
return {.facing = facing_type::north, .in_wall = false, .open = false, .powered = false};
case 7986:
return {.facing = facing_type::south, .in_wall = true, .open = true, .powered = true};
case 7987:
return {.facing = facing_type::south, .in_wall = true, .open = true, .powered = false};
case 7988:
return {.facing = facing_type::south, .in_wall = true, .open = false, .powered = true};
case 7989:
return {.facing = facing_type::south, .in_wall = true, .open = false, .powered = false};
case 7990:
return {.facing = facing_type::south, .in_wall = false, .open = true, .powered = true};
case 7991:
return {.facing = facing_type::south, .in_wall = false, .open = true, .powered = false};
case 7992:
return {.facing = facing_type::south, .in_wall = false, .open = false, .powered = true};
case 7993:
return {.facing = facing_type::south, .in_wall = false, .open = false, .powered = false};
case 7994:
return {.facing = facing_type::west, .in_wall = true, .open = true, .powered = true};
case 7995:
return {.facing = facing_type::west, .in_wall = true, .open = true, .powered = false};
case 7996:
return {.facing = facing_type::west, .in_wall = true, .open = false, .powered = true};
case 7997:
return {.facing = facing_type::west, .in_wall = true, .open = false, .powered = false};
case 7998:
return {.facing = facing_type::west, .in_wall = false, .open = true, .powered = true};
case 7999:
return {.facing = facing_type::west, .in_wall = false, .open = true, .powered = false};
case 8000:
return {.facing = facing_type::west, .in_wall = false, .open = false, .powered = true};
case 8001:
return {.facing = facing_type::west, .in_wall = false, .open = false, .powered = false};
case 8002:
return {.facing = facing_type::east, .in_wall = true, .open = true, .powered = true};
case 8003:
return {.facing = facing_type::east, .in_wall = true, .open = true, .powered = false};
case 8004:
return {.facing = facing_type::east, .in_wall = true, .open = false, .powered = true};
case 8005:
return {.facing = facing_type::east, .in_wall = true, .open = false, .powered = false};
case 8006:
return {.facing = facing_type::east, .in_wall = false, .open = true, .powered = true};
case 8007:
return {.facing = facing_type::east, .in_wall = false, .open = true, .powered = false};
case 8008:
return {.facing = facing_type::east, .in_wall = false, .open = false, .powered = true};
case 8009:
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
return "minecraft:acacia_fence_gate:north:true:true:true";
case false:
return "minecraft:acacia_fence_gate:north:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_fence_gate:north:true:false:true";
case false:
return "minecraft:acacia_fence_gate:north:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:acacia_fence_gate:north:false:true:true";
case false:
return "minecraft:acacia_fence_gate:north:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_fence_gate:north:false:false:true";
case false:
return "minecraft:acacia_fence_gate:north:false:false:false";
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
return "minecraft:acacia_fence_gate:south:true:true:true";
case false:
return "minecraft:acacia_fence_gate:south:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_fence_gate:south:true:false:true";
case false:
return "minecraft:acacia_fence_gate:south:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:acacia_fence_gate:south:false:true:true";
case false:
return "minecraft:acacia_fence_gate:south:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_fence_gate:south:false:false:true";
case false:
return "minecraft:acacia_fence_gate:south:false:false:false";
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
return "minecraft:acacia_fence_gate:west:true:true:true";
case false:
return "minecraft:acacia_fence_gate:west:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_fence_gate:west:true:false:true";
case false:
return "minecraft:acacia_fence_gate:west:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:acacia_fence_gate:west:false:true:true";
case false:
return "minecraft:acacia_fence_gate:west:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_fence_gate:west:false:false:true";
case false:
return "minecraft:acacia_fence_gate:west:false:false:false";
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
return "minecraft:acacia_fence_gate:east:true:true:true";
case false:
return "minecraft:acacia_fence_gate:east:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_fence_gate:east:true:false:true";
case false:
return "minecraft:acacia_fence_gate:east:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:acacia_fence_gate:east:false:true:true";
case false:
return "minecraft:acacia_fence_gate:east:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_fence_gate:east:false:false:true";
case false:
return "minecraft:acacia_fence_gate:east:false:false:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
