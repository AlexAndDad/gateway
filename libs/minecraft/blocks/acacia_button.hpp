#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct acacia_button
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
return 5906;
case false:
return 5907;
}
case facing_type::south:
switch (powered)
{
case true:
return 5908;
case false:
return 5909;
}
case facing_type::west:
switch (powered)
{
case true:
return 5910;
case false:
return 5911;
}
case facing_type::east:
switch (powered)
{
case true:
return 5912;
case false:
return 5913;
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5914;
case false:
return 5915;
}
case facing_type::south:
switch (powered)
{
case true:
return 5916;
case false:
return 5917;
}
case facing_type::west:
switch (powered)
{
case true:
return 5918;
case false:
return 5919;
}
case facing_type::east:
switch (powered)
{
case true:
return 5920;
case false:
return 5921;
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5922;
case false:
return 5923;
}
case facing_type::south:
switch (powered)
{
case true:
return 5924;
case false:
return 5925;
}
case facing_type::west:
switch (powered)
{
case true:
return 5926;
case false:
return 5927;
}
case facing_type::east:
switch (powered)
{
case true:
return 5928;
case false:
return 5929;
}
}
}
}
constexpr static acacia_button from_id(block_id_type id)
{
switch (id)
{
case 5906:
return {.face = face_type::floor, .facing = facing_type::north, .powered = true};
case 5907:
return {.face = face_type::floor, .facing = facing_type::north, .powered = false};
case 5908:
return {.face = face_type::floor, .facing = facing_type::south, .powered = true};
case 5909:
return {.face = face_type::floor, .facing = facing_type::south, .powered = false};
case 5910:
return {.face = face_type::floor, .facing = facing_type::west, .powered = true};
case 5911:
return {.face = face_type::floor, .facing = facing_type::west, .powered = false};
case 5912:
return {.face = face_type::floor, .facing = facing_type::east, .powered = true};
case 5913:
return {.face = face_type::floor, .facing = facing_type::east, .powered = false};
case 5914:
return {.face = face_type::wall, .facing = facing_type::north, .powered = true};
case 5915:
return {.face = face_type::wall, .facing = facing_type::north, .powered = false};
case 5916:
return {.face = face_type::wall, .facing = facing_type::south, .powered = true};
case 5917:
return {.face = face_type::wall, .facing = facing_type::south, .powered = false};
case 5918:
return {.face = face_type::wall, .facing = facing_type::west, .powered = true};
case 5919:
return {.face = face_type::wall, .facing = facing_type::west, .powered = false};
case 5920:
return {.face = face_type::wall, .facing = facing_type::east, .powered = true};
case 5921:
return {.face = face_type::wall, .facing = facing_type::east, .powered = false};
case 5922:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = true};
case 5923:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = false};
case 5924:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = true};
case 5925:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = false};
case 5926:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = true};
case 5927:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = false};
case 5928:
return {.face = face_type::ceiling, .facing = facing_type::east, .powered = true};
case 5929:
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
return "minecraft:acacia_button:floor:north:true";
case false:
return "minecraft:acacia_button:floor:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:acacia_button:floor:south:true";
case false:
return "minecraft:acacia_button:floor:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:acacia_button:floor:west:true";
case false:
return "minecraft:acacia_button:floor:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:acacia_button:floor:east:true";
case false:
return "minecraft:acacia_button:floor:east:false";
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:acacia_button:wall:north:true";
case false:
return "minecraft:acacia_button:wall:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:acacia_button:wall:south:true";
case false:
return "minecraft:acacia_button:wall:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:acacia_button:wall:west:true";
case false:
return "minecraft:acacia_button:wall:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:acacia_button:wall:east:true";
case false:
return "minecraft:acacia_button:wall:east:false";
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:acacia_button:ceiling:north:true";
case false:
return "minecraft:acacia_button:ceiling:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:acacia_button:ceiling:south:true";
case false:
return "minecraft:acacia_button:ceiling:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:acacia_button:ceiling:west:true";
case false:
return "minecraft:acacia_button:ceiling:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:acacia_button:ceiling:east:true";
case false:
return "minecraft:acacia_button:ceiling:east:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
