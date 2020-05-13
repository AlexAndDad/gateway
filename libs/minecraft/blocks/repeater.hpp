#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct repeater
{std::uint8_t delay = 1;
enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
bool locked = false;
bool powered = false;
constexpr block_id_type to_id() const {
switch (delay)
{
case 1:
switch (facing)
{
case facing_type::north:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4017;
case false:
return 4018;
}
case false:
switch (powered)
{
case true:
return 4019;
case false:
return 4020;
}
}
case facing_type::south:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4021;
case false:
return 4022;
}
case false:
switch (powered)
{
case true:
return 4023;
case false:
return 4024;
}
}
case facing_type::west:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4025;
case false:
return 4026;
}
case false:
switch (powered)
{
case true:
return 4027;
case false:
return 4028;
}
}
case facing_type::east:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4029;
case false:
return 4030;
}
case false:
switch (powered)
{
case true:
return 4031;
case false:
return 4032;
}
}
}
case 2:
switch (facing)
{
case facing_type::north:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4033;
case false:
return 4034;
}
case false:
switch (powered)
{
case true:
return 4035;
case false:
return 4036;
}
}
case facing_type::south:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4037;
case false:
return 4038;
}
case false:
switch (powered)
{
case true:
return 4039;
case false:
return 4040;
}
}
case facing_type::west:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4041;
case false:
return 4042;
}
case false:
switch (powered)
{
case true:
return 4043;
case false:
return 4044;
}
}
case facing_type::east:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4045;
case false:
return 4046;
}
case false:
switch (powered)
{
case true:
return 4047;
case false:
return 4048;
}
}
}
case 3:
switch (facing)
{
case facing_type::north:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4049;
case false:
return 4050;
}
case false:
switch (powered)
{
case true:
return 4051;
case false:
return 4052;
}
}
case facing_type::south:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4053;
case false:
return 4054;
}
case false:
switch (powered)
{
case true:
return 4055;
case false:
return 4056;
}
}
case facing_type::west:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4057;
case false:
return 4058;
}
case false:
switch (powered)
{
case true:
return 4059;
case false:
return 4060;
}
}
case facing_type::east:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4061;
case false:
return 4062;
}
case false:
switch (powered)
{
case true:
return 4063;
case false:
return 4064;
}
}
}
case 4:
switch (facing)
{
case facing_type::north:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4065;
case false:
return 4066;
}
case false:
switch (powered)
{
case true:
return 4067;
case false:
return 4068;
}
}
case facing_type::south:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4069;
case false:
return 4070;
}
case false:
switch (powered)
{
case true:
return 4071;
case false:
return 4072;
}
}
case facing_type::west:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4073;
case false:
return 4074;
}
case false:
switch (powered)
{
case true:
return 4075;
case false:
return 4076;
}
}
case facing_type::east:
switch (locked)
{
case true:
switch (powered)
{
case true:
return 4077;
case false:
return 4078;
}
case false:
switch (powered)
{
case true:
return 4079;
case false:
return 4080;
}
}
}
}
}
constexpr static repeater from_id(block_id_type id)
{
switch (id)
{
case 4017:
return {.delay = 1, .facing = facing_type::north, .locked = true, .powered = true};
case 4018:
return {.delay = 1, .facing = facing_type::north, .locked = true, .powered = false};
case 4019:
return {.delay = 1, .facing = facing_type::north, .locked = false, .powered = true};
case 4020:
return {.delay = 1, .facing = facing_type::north, .locked = false, .powered = false};
case 4021:
return {.delay = 1, .facing = facing_type::south, .locked = true, .powered = true};
case 4022:
return {.delay = 1, .facing = facing_type::south, .locked = true, .powered = false};
case 4023:
return {.delay = 1, .facing = facing_type::south, .locked = false, .powered = true};
case 4024:
return {.delay = 1, .facing = facing_type::south, .locked = false, .powered = false};
case 4025:
return {.delay = 1, .facing = facing_type::west, .locked = true, .powered = true};
case 4026:
return {.delay = 1, .facing = facing_type::west, .locked = true, .powered = false};
case 4027:
return {.delay = 1, .facing = facing_type::west, .locked = false, .powered = true};
case 4028:
return {.delay = 1, .facing = facing_type::west, .locked = false, .powered = false};
case 4029:
return {.delay = 1, .facing = facing_type::east, .locked = true, .powered = true};
case 4030:
return {.delay = 1, .facing = facing_type::east, .locked = true, .powered = false};
case 4031:
return {.delay = 1, .facing = facing_type::east, .locked = false, .powered = true};
case 4032:
return {.delay = 1, .facing = facing_type::east, .locked = false, .powered = false};
case 4033:
return {.delay = 2, .facing = facing_type::north, .locked = true, .powered = true};
case 4034:
return {.delay = 2, .facing = facing_type::north, .locked = true, .powered = false};
case 4035:
return {.delay = 2, .facing = facing_type::north, .locked = false, .powered = true};
case 4036:
return {.delay = 2, .facing = facing_type::north, .locked = false, .powered = false};
case 4037:
return {.delay = 2, .facing = facing_type::south, .locked = true, .powered = true};
case 4038:
return {.delay = 2, .facing = facing_type::south, .locked = true, .powered = false};
case 4039:
return {.delay = 2, .facing = facing_type::south, .locked = false, .powered = true};
case 4040:
return {.delay = 2, .facing = facing_type::south, .locked = false, .powered = false};
case 4041:
return {.delay = 2, .facing = facing_type::west, .locked = true, .powered = true};
case 4042:
return {.delay = 2, .facing = facing_type::west, .locked = true, .powered = false};
case 4043:
return {.delay = 2, .facing = facing_type::west, .locked = false, .powered = true};
case 4044:
return {.delay = 2, .facing = facing_type::west, .locked = false, .powered = false};
case 4045:
return {.delay = 2, .facing = facing_type::east, .locked = true, .powered = true};
case 4046:
return {.delay = 2, .facing = facing_type::east, .locked = true, .powered = false};
case 4047:
return {.delay = 2, .facing = facing_type::east, .locked = false, .powered = true};
case 4048:
return {.delay = 2, .facing = facing_type::east, .locked = false, .powered = false};
case 4049:
return {.delay = 3, .facing = facing_type::north, .locked = true, .powered = true};
case 4050:
return {.delay = 3, .facing = facing_type::north, .locked = true, .powered = false};
case 4051:
return {.delay = 3, .facing = facing_type::north, .locked = false, .powered = true};
case 4052:
return {.delay = 3, .facing = facing_type::north, .locked = false, .powered = false};
case 4053:
return {.delay = 3, .facing = facing_type::south, .locked = true, .powered = true};
case 4054:
return {.delay = 3, .facing = facing_type::south, .locked = true, .powered = false};
case 4055:
return {.delay = 3, .facing = facing_type::south, .locked = false, .powered = true};
case 4056:
return {.delay = 3, .facing = facing_type::south, .locked = false, .powered = false};
case 4057:
return {.delay = 3, .facing = facing_type::west, .locked = true, .powered = true};
case 4058:
return {.delay = 3, .facing = facing_type::west, .locked = true, .powered = false};
case 4059:
return {.delay = 3, .facing = facing_type::west, .locked = false, .powered = true};
case 4060:
return {.delay = 3, .facing = facing_type::west, .locked = false, .powered = false};
case 4061:
return {.delay = 3, .facing = facing_type::east, .locked = true, .powered = true};
case 4062:
return {.delay = 3, .facing = facing_type::east, .locked = true, .powered = false};
case 4063:
return {.delay = 3, .facing = facing_type::east, .locked = false, .powered = true};
case 4064:
return {.delay = 3, .facing = facing_type::east, .locked = false, .powered = false};
case 4065:
return {.delay = 4, .facing = facing_type::north, .locked = true, .powered = true};
case 4066:
return {.delay = 4, .facing = facing_type::north, .locked = true, .powered = false};
case 4067:
return {.delay = 4, .facing = facing_type::north, .locked = false, .powered = true};
case 4068:
return {.delay = 4, .facing = facing_type::north, .locked = false, .powered = false};
case 4069:
return {.delay = 4, .facing = facing_type::south, .locked = true, .powered = true};
case 4070:
return {.delay = 4, .facing = facing_type::south, .locked = true, .powered = false};
case 4071:
return {.delay = 4, .facing = facing_type::south, .locked = false, .powered = true};
case 4072:
return {.delay = 4, .facing = facing_type::south, .locked = false, .powered = false};
case 4073:
return {.delay = 4, .facing = facing_type::west, .locked = true, .powered = true};
case 4074:
return {.delay = 4, .facing = facing_type::west, .locked = true, .powered = false};
case 4075:
return {.delay = 4, .facing = facing_type::west, .locked = false, .powered = true};
case 4076:
return {.delay = 4, .facing = facing_type::west, .locked = false, .powered = false};
case 4077:
return {.delay = 4, .facing = facing_type::east, .locked = true, .powered = true};
case 4078:
return {.delay = 4, .facing = facing_type::east, .locked = true, .powered = false};
case 4079:
return {.delay = 4, .facing = facing_type::east, .locked = false, .powered = true};
case 4080:
return {.delay = 4, .facing = facing_type::east, .locked = false, .powered = false};
}}
constexpr std::string_view to_string() const
{switch (delay)
{
case 1:
switch (facing)
{
case facing_type::north:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:1:north:true:true";
case false:
return "minecraft:repeater:1:north:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:1:north:false:true";
case false:
return "minecraft:repeater:1:north:false:false";
}
}
case facing_type::south:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:1:south:true:true";
case false:
return "minecraft:repeater:1:south:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:1:south:false:true";
case false:
return "minecraft:repeater:1:south:false:false";
}
}
case facing_type::west:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:1:west:true:true";
case false:
return "minecraft:repeater:1:west:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:1:west:false:true";
case false:
return "minecraft:repeater:1:west:false:false";
}
}
case facing_type::east:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:1:east:true:true";
case false:
return "minecraft:repeater:1:east:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:1:east:false:true";
case false:
return "minecraft:repeater:1:east:false:false";
}
}
}
case 2:
switch (facing)
{
case facing_type::north:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:2:north:true:true";
case false:
return "minecraft:repeater:2:north:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:2:north:false:true";
case false:
return "minecraft:repeater:2:north:false:false";
}
}
case facing_type::south:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:2:south:true:true";
case false:
return "minecraft:repeater:2:south:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:2:south:false:true";
case false:
return "minecraft:repeater:2:south:false:false";
}
}
case facing_type::west:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:2:west:true:true";
case false:
return "minecraft:repeater:2:west:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:2:west:false:true";
case false:
return "minecraft:repeater:2:west:false:false";
}
}
case facing_type::east:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:2:east:true:true";
case false:
return "minecraft:repeater:2:east:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:2:east:false:true";
case false:
return "minecraft:repeater:2:east:false:false";
}
}
}
case 3:
switch (facing)
{
case facing_type::north:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:3:north:true:true";
case false:
return "minecraft:repeater:3:north:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:3:north:false:true";
case false:
return "minecraft:repeater:3:north:false:false";
}
}
case facing_type::south:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:3:south:true:true";
case false:
return "minecraft:repeater:3:south:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:3:south:false:true";
case false:
return "minecraft:repeater:3:south:false:false";
}
}
case facing_type::west:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:3:west:true:true";
case false:
return "minecraft:repeater:3:west:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:3:west:false:true";
case false:
return "minecraft:repeater:3:west:false:false";
}
}
case facing_type::east:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:3:east:true:true";
case false:
return "minecraft:repeater:3:east:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:3:east:false:true";
case false:
return "minecraft:repeater:3:east:false:false";
}
}
}
case 4:
switch (facing)
{
case facing_type::north:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:4:north:true:true";
case false:
return "minecraft:repeater:4:north:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:4:north:false:true";
case false:
return "minecraft:repeater:4:north:false:false";
}
}
case facing_type::south:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:4:south:true:true";
case false:
return "minecraft:repeater:4:south:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:4:south:false:true";
case false:
return "minecraft:repeater:4:south:false:false";
}
}
case facing_type::west:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:4:west:true:true";
case false:
return "minecraft:repeater:4:west:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:4:west:false:true";
case false:
return "minecraft:repeater:4:west:false:false";
}
}
case facing_type::east:
switch (locked)
{
case true:
switch (powered)
{
case true:
return "minecraft:repeater:4:east:true:true";
case false:
return "minecraft:repeater:4:east:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:repeater:4:east:false:true";
case false:
return "minecraft:repeater:4:east:false:false";
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
