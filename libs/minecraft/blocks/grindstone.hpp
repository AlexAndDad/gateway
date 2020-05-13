#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct grindstone
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
constexpr block_id_type to_id() const {
switch (face)
{
case face_type::floor:
switch (facing)
{
case facing_type::north:
return 11165;
case facing_type::south:
return 11166;
case facing_type::west:
return 11167;
case facing_type::east:
return 11168;
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
return 11169;
case facing_type::south:
return 11170;
case facing_type::west:
return 11171;
case facing_type::east:
return 11172;
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
return 11173;
case facing_type::south:
return 11174;
case facing_type::west:
return 11175;
case facing_type::east:
return 11176;
}
}
}
constexpr static grindstone from_id(block_id_type id)
{
switch (id)
{
case 11165:
return {.face = face_type::floor, .facing = facing_type::north};
case 11166:
return {.face = face_type::floor, .facing = facing_type::south};
case 11167:
return {.face = face_type::floor, .facing = facing_type::west};
case 11168:
return {.face = face_type::floor, .facing = facing_type::east};
case 11169:
return {.face = face_type::wall, .facing = facing_type::north};
case 11170:
return {.face = face_type::wall, .facing = facing_type::south};
case 11171:
return {.face = face_type::wall, .facing = facing_type::west};
case 11172:
return {.face = face_type::wall, .facing = facing_type::east};
case 11173:
return {.face = face_type::ceiling, .facing = facing_type::north};
case 11174:
return {.face = face_type::ceiling, .facing = facing_type::south};
case 11175:
return {.face = face_type::ceiling, .facing = facing_type::west};
case 11176:
return {.face = face_type::ceiling, .facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (face)
{
case face_type::floor:
switch (facing)
{
case facing_type::north:
return "minecraft:grindstone:floor:north";
case facing_type::south:
return "minecraft:grindstone:floor:south";
case facing_type::west:
return "minecraft:grindstone:floor:west";
case facing_type::east:
return "minecraft:grindstone:floor:east";
}
case face_type::wall:
switch (facing)
{
case facing_type::north:
return "minecraft:grindstone:wall:north";
case facing_type::south:
return "minecraft:grindstone:wall:south";
case facing_type::west:
return "minecraft:grindstone:wall:west";
case facing_type::east:
return "minecraft:grindstone:wall:east";
}
case face_type::ceiling:
switch (facing)
{
case facing_type::north:
return "minecraft:grindstone:ceiling:north";
case facing_type::south:
return "minecraft:grindstone:ceiling:south";
case facing_type::west:
return "minecraft:grindstone:ceiling:west";
case facing_type::east:
return "minecraft:grindstone:ceiling:east";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
