#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jungle_button
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
return 5882;
case false:
return 5883;
}
case facing_type::south:
switch (powered)
{
case true:
return 5884;
case false:
return 5885;
}
case facing_type::west:
switch (powered)
{
case true:
return 5886;
case false:
return 5887;
}
case facing_type::east:
switch (powered)
{
case true:
return 5888;
case false:
return 5889;
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5890;
case false:
return 5891;
}
case facing_type::south:
switch (powered)
{
case true:
return 5892;
case false:
return 5893;
}
case facing_type::west:
switch (powered)
{
case true:
return 5894;
case false:
return 5895;
}
case facing_type::east:
switch (powered)
{
case true:
return 5896;
case false:
return 5897;
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5898;
case false:
return 5899;
}
case facing_type::south:
switch (powered)
{
case true:
return 5900;
case false:
return 5901;
}
case facing_type::west:
switch (powered)
{
case true:
return 5902;
case false:
return 5903;
}
case facing_type::east:
switch (powered)
{
case true:
return 5904;
case false:
return 5905;
}
}
}
}
constexpr static jungle_button from_id(block_id_type id)
{
switch (id)
{
case 5882:
return {.face = face_type::floor, .facing = facing_type::north, .powered = true};
case 5883:
return {.face = face_type::floor, .facing = facing_type::north, .powered = false};
case 5884:
return {.face = face_type::floor, .facing = facing_type::south, .powered = true};
case 5885:
return {.face = face_type::floor, .facing = facing_type::south, .powered = false};
case 5886:
return {.face = face_type::floor, .facing = facing_type::west, .powered = true};
case 5887:
return {.face = face_type::floor, .facing = facing_type::west, .powered = false};
case 5888:
return {.face = face_type::floor, .facing = facing_type::east, .powered = true};
case 5889:
return {.face = face_type::floor, .facing = facing_type::east, .powered = false};
case 5890:
return {.face = face_type::wall, .facing = facing_type::north, .powered = true};
case 5891:
return {.face = face_type::wall, .facing = facing_type::north, .powered = false};
case 5892:
return {.face = face_type::wall, .facing = facing_type::south, .powered = true};
case 5893:
return {.face = face_type::wall, .facing = facing_type::south, .powered = false};
case 5894:
return {.face = face_type::wall, .facing = facing_type::west, .powered = true};
case 5895:
return {.face = face_type::wall, .facing = facing_type::west, .powered = false};
case 5896:
return {.face = face_type::wall, .facing = facing_type::east, .powered = true};
case 5897:
return {.face = face_type::wall, .facing = facing_type::east, .powered = false};
case 5898:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = true};
case 5899:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = false};
case 5900:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = true};
case 5901:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = false};
case 5902:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = true};
case 5903:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = false};
case 5904:
return {.face = face_type::ceiling, .facing = facing_type::east, .powered = true};
case 5905:
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
return "minecraft:jungle_button:floor:north:true";
case false:
return "minecraft:jungle_button:floor:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:jungle_button:floor:south:true";
case false:
return "minecraft:jungle_button:floor:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:jungle_button:floor:west:true";
case false:
return "minecraft:jungle_button:floor:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:jungle_button:floor:east:true";
case false:
return "minecraft:jungle_button:floor:east:false";
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:jungle_button:wall:north:true";
case false:
return "minecraft:jungle_button:wall:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:jungle_button:wall:south:true";
case false:
return "minecraft:jungle_button:wall:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:jungle_button:wall:west:true";
case false:
return "minecraft:jungle_button:wall:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:jungle_button:wall:east:true";
case false:
return "minecraft:jungle_button:wall:east:false";
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:jungle_button:ceiling:north:true";
case false:
return "minecraft:jungle_button:ceiling:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:jungle_button:ceiling:south:true";
case false:
return "minecraft:jungle_button:ceiling:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:jungle_button:ceiling:west:true";
case false:
return "minecraft:jungle_button:ceiling:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:jungle_button:ceiling:east:true";
case false:
return "minecraft:jungle_button:ceiling:east:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
