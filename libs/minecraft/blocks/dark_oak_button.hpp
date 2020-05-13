#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dark_oak_button
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
return 5930;
case false:
return 5931;
}
case facing_type::south:
switch (powered)
{
case true:
return 5932;
case false:
return 5933;
}
case facing_type::west:
switch (powered)
{
case true:
return 5934;
case false:
return 5935;
}
case facing_type::east:
switch (powered)
{
case true:
return 5936;
case false:
return 5937;
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5938;
case false:
return 5939;
}
case facing_type::south:
switch (powered)
{
case true:
return 5940;
case false:
return 5941;
}
case facing_type::west:
switch (powered)
{
case true:
return 5942;
case false:
return 5943;
}
case facing_type::east:
switch (powered)
{
case true:
return 5944;
case false:
return 5945;
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 5946;
case false:
return 5947;
}
case facing_type::south:
switch (powered)
{
case true:
return 5948;
case false:
return 5949;
}
case facing_type::west:
switch (powered)
{
case true:
return 5950;
case false:
return 5951;
}
case facing_type::east:
switch (powered)
{
case true:
return 5952;
case false:
return 5953;
}
}
}
}
constexpr static dark_oak_button from_id(block_id_type id)
{
switch (id)
{
case 5930:
return {.face = face_type::floor, .facing = facing_type::north, .powered = true};
case 5931:
return {.face = face_type::floor, .facing = facing_type::north, .powered = false};
case 5932:
return {.face = face_type::floor, .facing = facing_type::south, .powered = true};
case 5933:
return {.face = face_type::floor, .facing = facing_type::south, .powered = false};
case 5934:
return {.face = face_type::floor, .facing = facing_type::west, .powered = true};
case 5935:
return {.face = face_type::floor, .facing = facing_type::west, .powered = false};
case 5936:
return {.face = face_type::floor, .facing = facing_type::east, .powered = true};
case 5937:
return {.face = face_type::floor, .facing = facing_type::east, .powered = false};
case 5938:
return {.face = face_type::wall, .facing = facing_type::north, .powered = true};
case 5939:
return {.face = face_type::wall, .facing = facing_type::north, .powered = false};
case 5940:
return {.face = face_type::wall, .facing = facing_type::south, .powered = true};
case 5941:
return {.face = face_type::wall, .facing = facing_type::south, .powered = false};
case 5942:
return {.face = face_type::wall, .facing = facing_type::west, .powered = true};
case 5943:
return {.face = face_type::wall, .facing = facing_type::west, .powered = false};
case 5944:
return {.face = face_type::wall, .facing = facing_type::east, .powered = true};
case 5945:
return {.face = face_type::wall, .facing = facing_type::east, .powered = false};
case 5946:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = true};
case 5947:
return {.face = face_type::ceiling, .facing = facing_type::north, .powered = false};
case 5948:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = true};
case 5949:
return {.face = face_type::ceiling, .facing = facing_type::south, .powered = false};
case 5950:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = true};
case 5951:
return {.face = face_type::ceiling, .facing = facing_type::west, .powered = false};
case 5952:
return {.face = face_type::ceiling, .facing = facing_type::east, .powered = true};
case 5953:
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
return "minecraft:dark_oak_button:floor:north:true";
case false:
return "minecraft:dark_oak_button:floor:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:dark_oak_button:floor:south:true";
case false:
return "minecraft:dark_oak_button:floor:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:dark_oak_button:floor:west:true";
case false:
return "minecraft:dark_oak_button:floor:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:dark_oak_button:floor:east:true";
case false:
return "minecraft:dark_oak_button:floor:east:false";
}
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:dark_oak_button:wall:north:true";
case false:
return "minecraft:dark_oak_button:wall:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:dark_oak_button:wall:south:true";
case false:
return "minecraft:dark_oak_button:wall:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:dark_oak_button:wall:west:true";
case false:
return "minecraft:dark_oak_button:wall:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:dark_oak_button:wall:east:true";
case false:
return "minecraft:dark_oak_button:wall:east:false";
}
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:dark_oak_button:ceiling:north:true";
case false:
return "minecraft:dark_oak_button:ceiling:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:dark_oak_button:ceiling:south:true";
case false:
return "minecraft:dark_oak_button:ceiling:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:dark_oak_button:ceiling:west:true";
case false:
return "minecraft:dark_oak_button:ceiling:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:dark_oak_button:ceiling:east:true";
case false:
return "minecraft:dark_oak_button:ceiling:east:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
