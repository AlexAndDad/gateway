#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct spruce_fence_gate
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
return 7882;
case false:
return 7883;
}
case false:
switch (powered)
{
case true:
return 7884;
case false:
return 7885;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7886;
case false:
return 7887;
}
case false:
switch (powered)
{
case true:
return 7888;
case false:
return 7889;
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
return 7890;
case false:
return 7891;
}
case false:
switch (powered)
{
case true:
return 7892;
case false:
return 7893;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7894;
case false:
return 7895;
}
case false:
switch (powered)
{
case true:
return 7896;
case false:
return 7897;
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
return 7898;
case false:
return 7899;
}
case false:
switch (powered)
{
case true:
return 7900;
case false:
return 7901;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7902;
case false:
return 7903;
}
case false:
switch (powered)
{
case true:
return 7904;
case false:
return 7905;
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
return 7906;
case false:
return 7907;
}
case false:
switch (powered)
{
case true:
return 7908;
case false:
return 7909;
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return 7910;
case false:
return 7911;
}
case false:
switch (powered)
{
case true:
return 7912;
case false:
return 7913;
}
}
}
}
}
constexpr static spruce_fence_gate from_id(block_id_type id)
{
switch (id)
{
case 7882:
return {.facing = facing_type::north, .in_wall = true, .open = true, .powered = true};
case 7883:
return {.facing = facing_type::north, .in_wall = true, .open = true, .powered = false};
case 7884:
return {.facing = facing_type::north, .in_wall = true, .open = false, .powered = true};
case 7885:
return {.facing = facing_type::north, .in_wall = true, .open = false, .powered = false};
case 7886:
return {.facing = facing_type::north, .in_wall = false, .open = true, .powered = true};
case 7887:
return {.facing = facing_type::north, .in_wall = false, .open = true, .powered = false};
case 7888:
return {.facing = facing_type::north, .in_wall = false, .open = false, .powered = true};
case 7889:
return {.facing = facing_type::north, .in_wall = false, .open = false, .powered = false};
case 7890:
return {.facing = facing_type::south, .in_wall = true, .open = true, .powered = true};
case 7891:
return {.facing = facing_type::south, .in_wall = true, .open = true, .powered = false};
case 7892:
return {.facing = facing_type::south, .in_wall = true, .open = false, .powered = true};
case 7893:
return {.facing = facing_type::south, .in_wall = true, .open = false, .powered = false};
case 7894:
return {.facing = facing_type::south, .in_wall = false, .open = true, .powered = true};
case 7895:
return {.facing = facing_type::south, .in_wall = false, .open = true, .powered = false};
case 7896:
return {.facing = facing_type::south, .in_wall = false, .open = false, .powered = true};
case 7897:
return {.facing = facing_type::south, .in_wall = false, .open = false, .powered = false};
case 7898:
return {.facing = facing_type::west, .in_wall = true, .open = true, .powered = true};
case 7899:
return {.facing = facing_type::west, .in_wall = true, .open = true, .powered = false};
case 7900:
return {.facing = facing_type::west, .in_wall = true, .open = false, .powered = true};
case 7901:
return {.facing = facing_type::west, .in_wall = true, .open = false, .powered = false};
case 7902:
return {.facing = facing_type::west, .in_wall = false, .open = true, .powered = true};
case 7903:
return {.facing = facing_type::west, .in_wall = false, .open = true, .powered = false};
case 7904:
return {.facing = facing_type::west, .in_wall = false, .open = false, .powered = true};
case 7905:
return {.facing = facing_type::west, .in_wall = false, .open = false, .powered = false};
case 7906:
return {.facing = facing_type::east, .in_wall = true, .open = true, .powered = true};
case 7907:
return {.facing = facing_type::east, .in_wall = true, .open = true, .powered = false};
case 7908:
return {.facing = facing_type::east, .in_wall = true, .open = false, .powered = true};
case 7909:
return {.facing = facing_type::east, .in_wall = true, .open = false, .powered = false};
case 7910:
return {.facing = facing_type::east, .in_wall = false, .open = true, .powered = true};
case 7911:
return {.facing = facing_type::east, .in_wall = false, .open = true, .powered = false};
case 7912:
return {.facing = facing_type::east, .in_wall = false, .open = false, .powered = true};
case 7913:
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
return "minecraft:spruce_fence_gate:north:true:true:true";
case false:
return "minecraft:spruce_fence_gate:north:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_fence_gate:north:true:false:true";
case false:
return "minecraft:spruce_fence_gate:north:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:spruce_fence_gate:north:false:true:true";
case false:
return "minecraft:spruce_fence_gate:north:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_fence_gate:north:false:false:true";
case false:
return "minecraft:spruce_fence_gate:north:false:false:false";
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
return "minecraft:spruce_fence_gate:south:true:true:true";
case false:
return "minecraft:spruce_fence_gate:south:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_fence_gate:south:true:false:true";
case false:
return "minecraft:spruce_fence_gate:south:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:spruce_fence_gate:south:false:true:true";
case false:
return "minecraft:spruce_fence_gate:south:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_fence_gate:south:false:false:true";
case false:
return "minecraft:spruce_fence_gate:south:false:false:false";
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
return "minecraft:spruce_fence_gate:west:true:true:true";
case false:
return "minecraft:spruce_fence_gate:west:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_fence_gate:west:true:false:true";
case false:
return "minecraft:spruce_fence_gate:west:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:spruce_fence_gate:west:false:true:true";
case false:
return "minecraft:spruce_fence_gate:west:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_fence_gate:west:false:false:true";
case false:
return "minecraft:spruce_fence_gate:west:false:false:false";
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
return "minecraft:spruce_fence_gate:east:true:true:true";
case false:
return "minecraft:spruce_fence_gate:east:true:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_fence_gate:east:true:false:true";
case false:
return "minecraft:spruce_fence_gate:east:true:false:false";
}
}
case false:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:spruce_fence_gate:east:false:true:true";
case false:
return "minecraft:spruce_fence_gate:east:false:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:spruce_fence_gate:east:false:false:true";
case false:
return "minecraft:spruce_fence_gate:east:false:false:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
