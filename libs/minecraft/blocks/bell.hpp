#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct bell
{enum class attachment_type : std::uint8_t
{
floor,
ceiling,
single_wall,
double_wall
} attachment = attachment_type::floor;
enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
bool powered = false;
constexpr block_id_type to_id() const {
switch (attachment)
{
case attachment_type::floor:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 11198;
case false:
return 11199;
}
case facing_type::south:
switch (powered)
{
case true:
return 11200;
case false:
return 11201;
}
case facing_type::west:
switch (powered)
{
case true:
return 11202;
case false:
return 11203;
}
case facing_type::east:
switch (powered)
{
case true:
return 11204;
case false:
return 11205;
}
}
case attachment_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 11206;
case false:
return 11207;
}
case facing_type::south:
switch (powered)
{
case true:
return 11208;
case false:
return 11209;
}
case facing_type::west:
switch (powered)
{
case true:
return 11210;
case false:
return 11211;
}
case facing_type::east:
switch (powered)
{
case true:
return 11212;
case false:
return 11213;
}
}
case attachment_type::single_wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 11214;
case false:
return 11215;
}
case facing_type::south:
switch (powered)
{
case true:
return 11216;
case false:
return 11217;
}
case facing_type::west:
switch (powered)
{
case true:
return 11218;
case false:
return 11219;
}
case facing_type::east:
switch (powered)
{
case true:
return 11220;
case false:
return 11221;
}
}
case attachment_type::double_wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return 11222;
case false:
return 11223;
}
case facing_type::south:
switch (powered)
{
case true:
return 11224;
case false:
return 11225;
}
case facing_type::west:
switch (powered)
{
case true:
return 11226;
case false:
return 11227;
}
case facing_type::east:
switch (powered)
{
case true:
return 11228;
case false:
return 11229;
}
}
}
}
constexpr static bell from_id(block_id_type id)
{
switch (id)
{
case 11198:
return {.attachment = attachment_type::floor, .facing = facing_type::north, .powered = true};
case 11199:
return {.attachment = attachment_type::floor, .facing = facing_type::north, .powered = false};
case 11200:
return {.attachment = attachment_type::floor, .facing = facing_type::south, .powered = true};
case 11201:
return {.attachment = attachment_type::floor, .facing = facing_type::south, .powered = false};
case 11202:
return {.attachment = attachment_type::floor, .facing = facing_type::west, .powered = true};
case 11203:
return {.attachment = attachment_type::floor, .facing = facing_type::west, .powered = false};
case 11204:
return {.attachment = attachment_type::floor, .facing = facing_type::east, .powered = true};
case 11205:
return {.attachment = attachment_type::floor, .facing = facing_type::east, .powered = false};
case 11206:
return {.attachment = attachment_type::ceiling, .facing = facing_type::north, .powered = true};
case 11207:
return {.attachment = attachment_type::ceiling, .facing = facing_type::north, .powered = false};
case 11208:
return {.attachment = attachment_type::ceiling, .facing = facing_type::south, .powered = true};
case 11209:
return {.attachment = attachment_type::ceiling, .facing = facing_type::south, .powered = false};
case 11210:
return {.attachment = attachment_type::ceiling, .facing = facing_type::west, .powered = true};
case 11211:
return {.attachment = attachment_type::ceiling, .facing = facing_type::west, .powered = false};
case 11212:
return {.attachment = attachment_type::ceiling, .facing = facing_type::east, .powered = true};
case 11213:
return {.attachment = attachment_type::ceiling, .facing = facing_type::east, .powered = false};
case 11214:
return {.attachment = attachment_type::single_wall, .facing = facing_type::north, .powered = true};
case 11215:
return {.attachment = attachment_type::single_wall, .facing = facing_type::north, .powered = false};
case 11216:
return {.attachment = attachment_type::single_wall, .facing = facing_type::south, .powered = true};
case 11217:
return {.attachment = attachment_type::single_wall, .facing = facing_type::south, .powered = false};
case 11218:
return {.attachment = attachment_type::single_wall, .facing = facing_type::west, .powered = true};
case 11219:
return {.attachment = attachment_type::single_wall, .facing = facing_type::west, .powered = false};
case 11220:
return {.attachment = attachment_type::single_wall, .facing = facing_type::east, .powered = true};
case 11221:
return {.attachment = attachment_type::single_wall, .facing = facing_type::east, .powered = false};
case 11222:
return {.attachment = attachment_type::double_wall, .facing = facing_type::north, .powered = true};
case 11223:
return {.attachment = attachment_type::double_wall, .facing = facing_type::north, .powered = false};
case 11224:
return {.attachment = attachment_type::double_wall, .facing = facing_type::south, .powered = true};
case 11225:
return {.attachment = attachment_type::double_wall, .facing = facing_type::south, .powered = false};
case 11226:
return {.attachment = attachment_type::double_wall, .facing = facing_type::west, .powered = true};
case 11227:
return {.attachment = attachment_type::double_wall, .facing = facing_type::west, .powered = false};
case 11228:
return {.attachment = attachment_type::double_wall, .facing = facing_type::east, .powered = true};
case 11229:
return {.attachment = attachment_type::double_wall, .facing = facing_type::east, .powered = false};
}}
constexpr std::string_view to_string() const
{switch (attachment)
{
case attachment_type::floor:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:bell:floor:north:true";
case false:
return "minecraft:bell:floor:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:bell:floor:south:true";
case false:
return "minecraft:bell:floor:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:bell:floor:west:true";
case false:
return "minecraft:bell:floor:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:bell:floor:east:true";
case false:
return "minecraft:bell:floor:east:false";
}
}
case attachment_type::ceiling:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:bell:ceiling:north:true";
case false:
return "minecraft:bell:ceiling:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:bell:ceiling:south:true";
case false:
return "minecraft:bell:ceiling:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:bell:ceiling:west:true";
case false:
return "minecraft:bell:ceiling:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:bell:ceiling:east:true";
case false:
return "minecraft:bell:ceiling:east:false";
}
}
case attachment_type::single_wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:bell:single_wall:north:true";
case false:
return "minecraft:bell:single_wall:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:bell:single_wall:south:true";
case false:
return "minecraft:bell:single_wall:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:bell:single_wall:west:true";
case false:
return "minecraft:bell:single_wall:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:bell:single_wall:east:true";
case false:
return "minecraft:bell:single_wall:east:false";
}
}
case attachment_type::double_wall:
switch (facing)
{
case facing_type::north:
switch (powered)
{
case true:
return "minecraft:bell:double_wall:north:true";
case false:
return "minecraft:bell:double_wall:north:false";
}
case facing_type::south:
switch (powered)
{
case true:
return "minecraft:bell:double_wall:south:true";
case false:
return "minecraft:bell:double_wall:south:false";
}
case facing_type::west:
switch (powered)
{
case true:
return "minecraft:bell:double_wall:west:true";
case false:
return "minecraft:bell:double_wall:west:false";
}
case facing_type::east:
switch (powered)
{
case true:
return "minecraft:bell:double_wall:east:true";
case false:
return "minecraft:bell:double_wall:east:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
