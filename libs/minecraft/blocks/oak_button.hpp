#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct oak_button
{enum class face_type : std::uint8_t
{
floor,
wall,
ceiling
} face = face_type::wall;
enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
bool powered = false;
constexpr block_id_type to_id() const {
switch (face)
{
case face_type::floor:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5810;
case false:
return 5811;
}
case facing_type::south:
switch (powered)
{
case true:
return 5812;
case false:
return 5813;
}
case facing_type::west:
switch (powered)
{
case true:
return 5814;
case false:
return 5815;
}
case facing_type::east:
switch (powered)
{
case true:
return 5816;
case false:
return 5817;
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5818;
case false:
return 5819;
}
case facing_type::south:
switch (powered)
{
case true:
return 5820;
case false:
return 5821;
}
case facing_type::west:
switch (powered)
{
case true:
return 5822;
case false:
return 5823;
}
case facing_type::east:
switch (powered)
{
case true:
return 5824;
case false:
return 5825;
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5826;
case false:
return 5827;
}
case facing_type::south:
switch (powered)
{
case true:
return 5828;
case false:
return 5829;
}
case facing_type::west:
switch (powered)
{
case true:
return 5830;
case false:
return 5831;
}
case facing_type::east:
switch (powered)
{
case true:
return 5832;
case false:
return 5833;
}
}
}
}
constexpr static oak_button from_id(block_id_type id)
{
switch (id)
{
case 5810:
return {.face = face_type::floor, .facing = facing_type::north, .powered = true};
case 5811:
return {.face = face_type::floor, .facing = facing_type::north, .powered = false};
case 5812:
return {.face = face_type::floor, .facing = facing_type::south, .powered = true};
case 5813:
return {.face = face_type::floor, .facing = facing_type::south, .powered = false};
case 5814:
return {.face = face_type::floor, .facing = facing_type::west, .powered = true};
case 5815:
return {.face = face_type::floor, .facing = facing_type::west, .powered = false};
case 5816:
return {.face = face_type::floor, .facing = facing_type::east, .powered = true};
case 5817:
return {.face = face_type::floor, .facing = facing_type::east, .powered = false};
case 5818:
return {.face = face_type::wall, .facing = facing_type::north, .powered = true};
case 5819:
return {.face = face_type::wall, .facing = facing_type::north, .powered = false};
case 5820:
return {.face = face_type::wall, .facing = facing_type::south, .powered = true};
case 5821:
return {.face = face_type::wall, .facing = facing_type::south, .powered = false};
case 5822:
return {.face = face_type::wall, .facing = facing_type::west, .powered = true};
case 5823:
return {.face = face_type::wall, .facing = facing_type::west, .powered = false};
case 5824:
return {.face = face_type::wall, .facing = facing_type::east, .powered = true};
case 5825:
return {.face = face_type::wall, .facing = facing_type::east, .powered = false};
case 5826:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = true};
case 5827:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = false};
case 5828:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = true};
case 5829:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = false};
case 5830:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = true};
case 5831:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = false};
case 5832:
return {.face = face_type::ceiling, .facing = facing_type::east, .powered = true};
case 5833:
return {.face = face_type::ceiling, .facing = facing_type::east, .powered = false};
}}
constexpr std::string_view to_string() const
{switch (face)
{
case face_type::floor:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:oak_button:floor:north:true";
case false:
return "minecraft:oak_button:floor:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:oak_button:floor:south:true";
case false:
return "minecraft:oak_button:floor:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:oak_button:floor:west:true";
case false:
return "minecraft:oak_button:floor:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:oak_button:floor:east:true";
case false:
return "minecraft:oak_button:floor:east:false";
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:oak_button:wall:north:true";
case false:
return "minecraft:oak_button:wall:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:oak_button:wall:south:true";
case false:
return "minecraft:oak_button:wall:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:oak_button:wall:west:true";
case false:
return "minecraft:oak_button:wall:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:oak_button:wall:east:true";
case false:
return "minecraft:oak_button:wall:east:false";
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:oak_button:ceiling:north:true";
case false:
return "minecraft:oak_button:ceiling:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:oak_button:ceiling:south:true";
case false:
return "minecraft:oak_button:ceiling:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:oak_button:ceiling:west:true";
case false:
return "minecraft:oak_button:ceiling:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:oak_button:ceiling:east:true";
case false:
return "minecraft:oak_button:ceiling:east:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
