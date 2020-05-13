#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct lever
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
return 3781;
case false:
return 3782;
}
case facing_type::south:
switch (powered)
{
case true:
return 3783;
case false:
return 3784;
}
case facing_type::west:
switch (powered)
{
case true:
return 3785;
case false:
return 3786;
}
case facing_type::east:
switch (powered)
{
case true:
return 3787;
case false:
return 3788;
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 3789;
case false:
return 3790;
}
case facing_type::south:
switch (powered)
{
case true:
return 3791;
case false:
return 3792;
}
case facing_type::west:
switch (powered)
{
case true:
return 3793;
case false:
return 3794;
}
case facing_type::east:
switch (powered)
{
case true:
return 3795;
case false:
return 3796;
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 3797;
case false:
return 3798;
}
case facing_type::south:
switch (powered)
{
case true:
return 3799;
case false:
return 3800;
}
case facing_type::west:
switch (powered)
{
case true:
return 3801;
case false:
return 3802;
}
case facing_type::east:
switch (powered)
{
case true:
return 3803;
case false:
return 3804;
}
}
}
}
constexpr static lever from_id(block_id_type id)
{
switch (id)
{
case 3781:
return {.face = face_type::floor, .facing = facing_type::north, .powered = true};
case 3782:
return {.face = face_type::floor, .facing = facing_type::north, .powered = false};
case 3783:
return {.face = face_type::floor, .facing = facing_type::south, .powered = true};
case 3784:
return {.face = face_type::floor, .facing = facing_type::south, .powered = false};
case 3785:
return {.face = face_type::floor, .facing = facing_type::west, .powered = true};
case 3786:
return {.face = face_type::floor, .facing = facing_type::west, .powered = false};
case 3787:
return {.face = face_type::floor, .facing = facing_type::east, .powered = true};
case 3788:
return {.face = face_type::floor, .facing = facing_type::east, .powered = false};
case 3789:
return {.face = face_type::wall, .facing = facing_type::north, .powered = true};
case 3790:
return {.face = face_type::wall, .facing = facing_type::north, .powered = false};
case 3791:
return {.face = face_type::wall, .facing = facing_type::south, .powered = true};
case 3792:
return {.face = face_type::wall, .facing = facing_type::south, .powered = false};
case 3793:
return {.face = face_type::wall, .facing = facing_type::west, .powered = true};
case 3794:
return {.face = face_type::wall, .facing = facing_type::west, .powered = false};
case 3795:
return {.face = face_type::wall, .facing = facing_type::east, .powered = true};
case 3796:
return {.face = face_type::wall, .facing = facing_type::east, .powered = false};
case 3797:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = true};
case 3798:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = false};
case 3799:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = true};
case 3800:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = false};
case 3801:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = true};
case 3802:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = false};
case 3803:
return {.face = face_type::ceiling, .facing = facing_type::east, .powered = true};
case 3804:
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
return "minecraft:lever:floor:north:true";
case false:
return "minecraft:lever:floor:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:lever:floor:south:true";
case false:
return "minecraft:lever:floor:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:lever:floor:west:true";
case false:
return "minecraft:lever:floor:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:lever:floor:east:true";
case false:
return "minecraft:lever:floor:east:false";
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:lever:wall:north:true";
case false:
return "minecraft:lever:wall:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:lever:wall:south:true";
case false:
return "minecraft:lever:wall:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:lever:wall:west:true";
case false:
return "minecraft:lever:wall:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:lever:wall:east:true";
case false:
return "minecraft:lever:wall:east:false";
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:lever:ceiling:north:true";
case false:
return "minecraft:lever:ceiling:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:lever:ceiling:south:true";
case false:
return "minecraft:lever:ceiling:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:lever:ceiling:west:true";
case false:
return "minecraft:lever:ceiling:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:lever:ceiling:east:true";
case false:
return "minecraft:lever:ceiling:east:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
