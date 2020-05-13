#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct oak_trapdoor
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
enum class half_type : std::uint8_t
{
top,
bottom
} half = half_type::bottom;
bool open = false;
bool powered = false;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::top:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4097;
case false:
return 4098;
}
case false:
switch (waterlogged)
{
case true:
return 4099;
case false:
return 4100;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4101;
case false:
return 4102;
}
case false:
switch (waterlogged)
{
case true:
return 4103;
case false:
return 4104;
}
}
}
case half_type::bottom:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4105;
case false:
return 4106;
}
case false:
switch (waterlogged)
{
case true:
return 4107;
case false:
return 4108;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4109;
case false:
return 4110;
}
case false:
switch (waterlogged)
{
case true:
return 4111;
case false:
return 4112;
}
}
}
}
case facing_type::south:
switch (half)
{
case half_type::top:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4113;
case false:
return 4114;
}
case false:
switch (waterlogged)
{
case true:
return 4115;
case false:
return 4116;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4117;
case false:
return 4118;
}
case false:
switch (waterlogged)
{
case true:
return 4119;
case false:
return 4120;
}
}
}
case half_type::bottom:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4121;
case false:
return 4122;
}
case false:
switch (waterlogged)
{
case true:
return 4123;
case false:
return 4124;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4125;
case false:
return 4126;
}
case false:
switch (waterlogged)
{
case true:
return 4127;
case false:
return 4128;
}
}
}
}
case facing_type::west:
switch (half)
{
case half_type::top:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4129;
case false:
return 4130;
}
case false:
switch (waterlogged)
{
case true:
return 4131;
case false:
return 4132;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4133;
case false:
return 4134;
}
case false:
switch (waterlogged)
{
case true:
return 4135;
case false:
return 4136;
}
}
}
case half_type::bottom:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4137;
case false:
return 4138;
}
case false:
switch (waterlogged)
{
case true:
return 4139;
case false:
return 4140;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4141;
case false:
return 4142;
}
case false:
switch (waterlogged)
{
case true:
return 4143;
case false:
return 4144;
}
}
}
}
case facing_type::east:
switch (half)
{
case half_type::top:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4145;
case false:
return 4146;
}
case false:
switch (waterlogged)
{
case true:
return 4147;
case false:
return 4148;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4149;
case false:
return 4150;
}
case false:
switch (waterlogged)
{
case true:
return 4151;
case false:
return 4152;
}
}
}
case half_type::bottom:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4153;
case false:
return 4154;
}
case false:
switch (waterlogged)
{
case true:
return 4155;
case false:
return 4156;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4157;
case false:
return 4158;
}
case false:
switch (waterlogged)
{
case true:
return 4159;
case false:
return 4160;
}
}
}
}
}
}
constexpr static oak_trapdoor from_id(block_id_type id)
{
switch (id)
{
case 4097:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4098:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4099:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4100:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4101:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4102:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4103:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4104:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4105:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4106:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4107:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4108:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4109:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4110:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4111:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4112:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4113:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4114:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4115:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4116:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4117:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4118:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4119:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4120:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4121:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4122:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4123:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4124:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4125:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4126:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4127:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4128:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4129:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4130:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4131:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4132:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4133:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4134:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4135:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4136:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4137:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4138:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4139:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4140:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4141:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4142:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4143:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4144:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4145:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4146:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4147:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4148:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4149:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4150:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4151:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4152:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4153:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4154:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4155:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4156:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4157:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4158:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4159:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4160:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::top:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:north:top:true:true:true";
case false:
return "minecraft:oak_trapdoor:north:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:north:top:true:false:true";
case false:
return "minecraft:oak_trapdoor:north:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:north:top:false:true:true";
case false:
return "minecraft:oak_trapdoor:north:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:north:top:false:false:true";
case false:
return "minecraft:oak_trapdoor:north:top:false:false:false";
}
}
}
case half_type::bottom:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:north:bottom:true:true:true";
case false:
return "minecraft:oak_trapdoor:north:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:north:bottom:true:false:true";
case false:
return "minecraft:oak_trapdoor:north:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:north:bottom:false:true:true";
case false:
return "minecraft:oak_trapdoor:north:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:north:bottom:false:false:true";
case false:
return "minecraft:oak_trapdoor:north:bottom:false:false:false";
}
}
}
}
case facing_type::south:
switch (half)
{
case half_type::top:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:south:top:true:true:true";
case false:
return "minecraft:oak_trapdoor:south:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:south:top:true:false:true";
case false:
return "minecraft:oak_trapdoor:south:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:south:top:false:true:true";
case false:
return "minecraft:oak_trapdoor:south:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:south:top:false:false:true";
case false:
return "minecraft:oak_trapdoor:south:top:false:false:false";
}
}
}
case half_type::bottom:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:south:bottom:true:true:true";
case false:
return "minecraft:oak_trapdoor:south:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:south:bottom:true:false:true";
case false:
return "minecraft:oak_trapdoor:south:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:south:bottom:false:true:true";
case false:
return "minecraft:oak_trapdoor:south:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:south:bottom:false:false:true";
case false:
return "minecraft:oak_trapdoor:south:bottom:false:false:false";
}
}
}
}
case facing_type::west:
switch (half)
{
case half_type::top:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:west:top:true:true:true";
case false:
return "minecraft:oak_trapdoor:west:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:west:top:true:false:true";
case false:
return "minecraft:oak_trapdoor:west:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:west:top:false:true:true";
case false:
return "minecraft:oak_trapdoor:west:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:west:top:false:false:true";
case false:
return "minecraft:oak_trapdoor:west:top:false:false:false";
}
}
}
case half_type::bottom:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:west:bottom:true:true:true";
case false:
return "minecraft:oak_trapdoor:west:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:west:bottom:true:false:true";
case false:
return "minecraft:oak_trapdoor:west:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:west:bottom:false:true:true";
case false:
return "minecraft:oak_trapdoor:west:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:west:bottom:false:false:true";
case false:
return "minecraft:oak_trapdoor:west:bottom:false:false:false";
}
}
}
}
case facing_type::east:
switch (half)
{
case half_type::top:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:east:top:true:true:true";
case false:
return "minecraft:oak_trapdoor:east:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:east:top:true:false:true";
case false:
return "minecraft:oak_trapdoor:east:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:east:top:false:true:true";
case false:
return "minecraft:oak_trapdoor:east:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:east:top:false:false:true";
case false:
return "minecraft:oak_trapdoor:east:top:false:false:false";
}
}
}
case half_type::bottom:
switch (open)
{
case true:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:east:bottom:true:true:true";
case false:
return "minecraft:oak_trapdoor:east:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:east:bottom:true:false:true";
case false:
return "minecraft:oak_trapdoor:east:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:east:bottom:false:true:true";
case false:
return "minecraft:oak_trapdoor:east:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:oak_trapdoor:east:bottom:false:false:true";
case false:
return "minecraft:oak_trapdoor:east:bottom:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
