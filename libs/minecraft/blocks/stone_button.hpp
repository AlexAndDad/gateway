#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct stone_button
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
return 3895;
case false:
return 3896;
}
case facing_type::south:
switch (powered)
{
case true:
return 3897;
case false:
return 3898;
}
case facing_type::west:
switch (powered)
{
case true:
return 3899;
case false:
return 3900;
}
case facing_type::east:
switch (powered)
{
case true:
return 3901;
case false:
return 3902;
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 3903;
case false:
return 3904;
}
case facing_type::south:
switch (powered)
{
case true:
return 3905;
case false:
return 3906;
}
case facing_type::west:
switch (powered)
{
case true:
return 3907;
case false:
return 3908;
}
case facing_type::east:
switch (powered)
{
case true:
return 3909;
case false:
return 3910;
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 3911;
case false:
return 3912;
}
case facing_type::south:
switch (powered)
{
case true:
return 3913;
case false:
return 3914;
}
case facing_type::west:
switch (powered)
{
case true:
return 3915;
case false:
return 3916;
}
case facing_type::east:
switch (powered)
{
case true:
return 3917;
case false:
return 3918;
}
}
}
}
constexpr static stone_button from_id(block_id_type id)
{
switch (id)
{
case 3895:
return {.face = face_type::floor, .facing = facing_type::north, .powered = true};
case 3896:
return {.face = face_type::floor, .facing = facing_type::north, .powered = false};
case 3897:
return {.face = face_type::floor, .facing = facing_type::south, .powered = true};
case 3898:
return {.face = face_type::floor, .facing = facing_type::south, .powered = false};
case 3899:
return {.face = face_type::floor, .facing = facing_type::west, .powered = true};
case 3900:
return {.face = face_type::floor, .facing = facing_type::west, .powered = false};
case 3901:
return {.face = face_type::floor, .facing = facing_type::east, .powered = true};
case 3902:
return {.face = face_type::floor, .facing = facing_type::east, .powered = false};
case 3903:
return {.face = face_type::wall, .facing = facing_type::north, .powered = true};
case 3904:
return {.face = face_type::wall, .facing = facing_type::north, .powered = false};
case 3905:
return {.face = face_type::wall, .facing = facing_type::south, .powered = true};
case 3906:
return {.face = face_type::wall, .facing = facing_type::south, .powered = false};
case 3907:
return {.face = face_type::wall, .facing = facing_type::west, .powered = true};
case 3908:
return {.face = face_type::wall, .facing = facing_type::west, .powered = false};
case 3909:
return {.face = face_type::wall, .facing = facing_type::east, .powered = true};
case 3910:
return {.face = face_type::wall, .facing = facing_type::east, .powered = false};
case 3911:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = true};
case 3912:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = false};
case 3913:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = true};
case 3914:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = false};
case 3915:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = true};
case 3916:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = false};
case 3917:
return {.face = face_type::ceiling, .facing = facing_type::east, .powered = true};
case 3918:
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
return "minecraft:stone_button:floor:north:true";
case false:
return "minecraft:stone_button:floor:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:stone_button:floor:south:true";
case false:
return "minecraft:stone_button:floor:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:stone_button:floor:west:true";
case false:
return "minecraft:stone_button:floor:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:stone_button:floor:east:true";
case false:
return "minecraft:stone_button:floor:east:false";
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:stone_button:wall:north:true";
case false:
return "minecraft:stone_button:wall:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:stone_button:wall:south:true";
case false:
return "minecraft:stone_button:wall:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:stone_button:wall:west:true";
case false:
return "minecraft:stone_button:wall:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:stone_button:wall:east:true";
case false:
return "minecraft:stone_button:wall:east:false";
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:stone_button:ceiling:north:true";
case false:
return "minecraft:stone_button:ceiling:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:stone_button:ceiling:south:true";
case false:
return "minecraft:stone_button:ceiling:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:stone_button:ceiling:west:true";
case false:
return "minecraft:stone_button:ceiling:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:stone_button:ceiling:east:true";
case false:
return "minecraft:stone_button:ceiling:east:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
