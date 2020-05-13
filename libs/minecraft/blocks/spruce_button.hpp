#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct spruce_button
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
return 5834;
case false:
return 5835;
}
case facing_type::south:
switch (powered)
{
case true:
return 5836;
case false:
return 5837;
}
case facing_type::west:
switch (powered)
{
case true:
return 5838;
case false:
return 5839;
}
case facing_type::east:
switch (powered)
{
case true:
return 5840;
case false:
return 5841;
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5842;
case false:
return 5843;
}
case facing_type::south:
switch (powered)
{
case true:
return 5844;
case false:
return 5845;
}
case facing_type::west:
switch (powered)
{
case true:
return 5846;
case false:
return 5847;
}
case facing_type::east:
switch (powered)
{
case true:
return 5848;
case false:
return 5849;
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5850;
case false:
return 5851;
}
case facing_type::south:
switch (powered)
{
case true:
return 5852;
case false:
return 5853;
}
case facing_type::west:
switch (powered)
{
case true:
return 5854;
case false:
return 5855;
}
case facing_type::east:
switch (powered)
{
case true:
return 5856;
case false:
return 5857;
}
}
}
}
constexpr static spruce_button from_id(block_id_type id)
{
switch (id)
{
case 5834:
return {.face = face_type::floor, .facing = facing_type::north, .powered = true};
case 5835:
return {.face = face_type::floor, .facing = facing_type::north, .powered = false};
case 5836:
return {.face = face_type::floor, .facing = facing_type::south, .powered = true};
case 5837:
return {.face = face_type::floor, .facing = facing_type::south, .powered = false};
case 5838:
return {.face = face_type::floor, .facing = facing_type::west, .powered = true};
case 5839:
return {.face = face_type::floor, .facing = facing_type::west, .powered = false};
case 5840:
return {.face = face_type::floor, .facing = facing_type::east, .powered = true};
case 5841:
return {.face = face_type::floor, .facing = facing_type::east, .powered = false};
case 5842:
return {.face = face_type::wall, .facing = facing_type::north, .powered = true};
case 5843:
return {.face = face_type::wall, .facing = facing_type::north, .powered = false};
case 5844:
return {.face = face_type::wall, .facing = facing_type::south, .powered = true};
case 5845:
return {.face = face_type::wall, .facing = facing_type::south, .powered = false};
case 5846:
return {.face = face_type::wall, .facing = facing_type::west, .powered = true};
case 5847:
return {.face = face_type::wall, .facing = facing_type::west, .powered = false};
case 5848:
return {.face = face_type::wall, .facing = facing_type::east, .powered = true};
case 5849:
return {.face = face_type::wall, .facing = facing_type::east, .powered = false};
case 5850:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = true};
case 5851:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = false};
case 5852:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = true};
case 5853:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = false};
case 5854:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = true};
case 5855:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = false};
case 5856:
return {.face = face_type::ceiling, .facing = facing_type::east, .powered = true};
case 5857:
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
return "minecraft:spruce_button:floor:north:true";
case false:
return "minecraft:spruce_button:floor:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:spruce_button:floor:south:true";
case false:
return "minecraft:spruce_button:floor:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:spruce_button:floor:west:true";
case false:
return "minecraft:spruce_button:floor:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:spruce_button:floor:east:true";
case false:
return "minecraft:spruce_button:floor:east:false";
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:spruce_button:wall:north:true";
case false:
return "minecraft:spruce_button:wall:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:spruce_button:wall:south:true";
case false:
return "minecraft:spruce_button:wall:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:spruce_button:wall:west:true";
case false:
return "minecraft:spruce_button:wall:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:spruce_button:wall:east:true";
case false:
return "minecraft:spruce_button:wall:east:false";
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:spruce_button:ceiling:north:true";
case false:
return "minecraft:spruce_button:ceiling:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:spruce_button:ceiling:south:true";
case false:
return "minecraft:spruce_button:ceiling:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:spruce_button:ceiling:west:true";
case false:
return "minecraft:spruce_button:ceiling:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:spruce_button:ceiling:east:true";
case false:
return "minecraft:spruce_button:ceiling:east:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
