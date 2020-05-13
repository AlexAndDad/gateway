#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct birch_button
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
return 5858;
case false:
return 5859;
}
case facing_type::south:
switch (powered)
{
case true:
return 5860;
case false:
return 5861;
}
case facing_type::west:
switch (powered)
{
case true:
return 5862;
case false:
return 5863;
}
case facing_type::east:
switch (powered)
{
case true:
return 5864;
case false:
return 5865;
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5866;
case false:
return 5867;
}
case facing_type::south:
switch (powered)
{
case true:
return 5868;
case false:
return 5869;
}
case facing_type::west:
switch (powered)
{
case true:
return 5870;
case false:
return 5871;
}
case facing_type::east:
switch (powered)
{
case true:
return 5872;
case false:
return 5873;
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5874;
case false:
return 5875;
}
case facing_type::south:
switch (powered)
{
case true:
return 5876;
case false:
return 5877;
}
case facing_type::west:
switch (powered)
{
case true:
return 5878;
case false:
return 5879;
}
case facing_type::east:
switch (powered)
{
case true:
return 5880;
case false:
return 5881;
}
}
}
}
constexpr static birch_button from_id(block_id_type id)
{
switch (id)
{
case 5858:
return {.face = face_type::floor, .facing = facing_type::north, .powered = true};
case 5859:
return {.face = face_type::floor, .facing = facing_type::north, .powered = false};
case 5860:
return {.face = face_type::floor, .facing = facing_type::south, .powered = true};
case 5861:
return {.face = face_type::floor, .facing = facing_type::south, .powered = false};
case 5862:
return {.face = face_type::floor, .facing = facing_type::west, .powered = true};
case 5863:
return {.face = face_type::floor, .facing = facing_type::west, .powered = false};
case 5864:
return {.face = face_type::floor, .facing = facing_type::east, .powered = true};
case 5865:
return {.face = face_type::floor, .facing = facing_type::east, .powered = false};
case 5866:
return {.face = face_type::wall, .facing = facing_type::north, .powered = true};
case 5867:
return {.face = face_type::wall, .facing = facing_type::north, .powered = false};
case 5868:
return {.face = face_type::wall, .facing = facing_type::south, .powered = true};
case 5869:
return {.face = face_type::wall, .facing = facing_type::south, .powered = false};
case 5870:
return {.face = face_type::wall, .facing = facing_type::west, .powered = true};
case 5871:
return {.face = face_type::wall, .facing = facing_type::west, .powered = false};
case 5872:
return {.face = face_type::wall, .facing = facing_type::east, .powered = true};
case 5873:
return {.face = face_type::wall, .facing = facing_type::east, .powered = false};
case 5874:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = true};
case 5875:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = false};
case 5876:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = true};
case 5877:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = false};
case 5878:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = true};
case 5879:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = false};
case 5880:
return {.face = face_type::ceiling, .facing = facing_type::east, .powered = true};
case 5881:
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
return "minecraft:birch_button:floor:north:true";
case false:
return "minecraft:birch_button:floor:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:birch_button:floor:south:true";
case false:
return "minecraft:birch_button:floor:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:birch_button:floor:west:true";
case false:
return "minecraft:birch_button:floor:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:birch_button:floor:east:true";
case false:
return "minecraft:birch_button:floor:east:false";
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:birch_button:wall:north:true";
case false:
return "minecraft:birch_button:wall:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:birch_button:wall:south:true";
case false:
return "minecraft:birch_button:wall:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:birch_button:wall:west:true";
case false:
return "minecraft:birch_button:wall:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:birch_button:wall:east:true";
case false:
return "minecraft:birch_button:wall:east:false";
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:birch_button:ceiling:north:true";
case false:
return "minecraft:birch_button:ceiling:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:birch_button:ceiling:south:true";
case false:
return "minecraft:birch_button:ceiling:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:birch_button:ceiling:west:true";
case false:
return "minecraft:birch_button:ceiling:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:birch_button:ceiling:east:true";
case false:
return "minecraft:birch_button:ceiling:east:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
