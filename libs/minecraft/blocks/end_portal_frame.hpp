#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct end_portal_frame
{bool eye = false;
enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
constexpr block_id_type to_id() const {
switch (eye)
{
case true:
switch (facing)
{
case facing_type::north:
return 5130;
case facing_type::south:
return 5131;
case facing_type::west:
return 5132;
case facing_type::east:
return 5133;
}
case false:
switch (facing)
{
case facing_type::north:
return 5134;
case facing_type::south:
return 5135;
case facing_type::west:
return 5136;
case facing_type::east:
return 5137;
}
}
}
constexpr static end_portal_frame from_id(block_id_type id)
{
switch (id)
{
case 5130:
return {.eye = true, .facing = facing_type::north};
case 5131:
return {.eye = true, .facing = facing_type::south};
case 5132:
return {.eye = true, .facing = facing_type::west};
case 5133:
return {.eye = true, .facing = facing_type::east};
case 5134:
return {.eye = false, .facing = facing_type::north};
case 5135:
return {.eye = false, .facing = facing_type::south};
case 5136:
return {.eye = false, .facing = facing_type::west};
case 5137:
return {.eye = false, .facing = facing_type::east};
}}
constexpr std::string_view to_string() const
{switch (eye)
{
case true:
switch (facing)
{
case facing_type::north:
return "minecraft:end_portal_frame:true:north";
case facing_type::south:
return "minecraft:end_portal_frame:true:south";
case facing_type::west:
return "minecraft:end_portal_frame:true:west";
case facing_type::east:
return "minecraft:end_portal_frame:true:east";
}
case false:
switch (facing)
{
case facing_type::north:
return "minecraft:end_portal_frame:false:north";
case facing_type::south:
return "minecraft:end_portal_frame:false:south";
case facing_type::west:
return "minecraft:end_portal_frame:false:west";
case facing_type::east:
return "minecraft:end_portal_frame:false:east";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
