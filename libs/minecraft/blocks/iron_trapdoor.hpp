#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct iron_trapdoor
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
return 7001;
case false:
return 7002;
}
case false:
switch (waterlogged)
{
case true:
return 7003;
case false:
return 7004;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 7005;
case false:
return 7006;
}
case false:
switch (waterlogged)
{
case true:
return 7007;
case false:
return 7008;
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
return 7009;
case false:
return 7010;
}
case false:
switch (waterlogged)
{
case true:
return 7011;
case false:
return 7012;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 7013;
case false:
return 7014;
}
case false:
switch (waterlogged)
{
case true:
return 7015;
case false:
return 7016;
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
return 7017;
case false:
return 7018;
}
case false:
switch (waterlogged)
{
case true:
return 7019;
case false:
return 7020;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 7021;
case false:
return 7022;
}
case false:
switch (waterlogged)
{
case true:
return 7023;
case false:
return 7024;
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
return 7025;
case false:
return 7026;
}
case false:
switch (waterlogged)
{
case true:
return 7027;
case false:
return 7028;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 7029;
case false:
return 7030;
}
case false:
switch (waterlogged)
{
case true:
return 7031;
case false:
return 7032;
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
return 7033;
case false:
return 7034;
}
case false:
switch (waterlogged)
{
case true:
return 7035;
case false:
return 7036;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 7037;
case false:
return 7038;
}
case false:
switch (waterlogged)
{
case true:
return 7039;
case false:
return 7040;
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
return 7041;
case false:
return 7042;
}
case false:
switch (waterlogged)
{
case true:
return 7043;
case false:
return 7044;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 7045;
case false:
return 7046;
}
case false:
switch (waterlogged)
{
case true:
return 7047;
case false:
return 7048;
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
return 7049;
case false:
return 7050;
}
case false:
switch (waterlogged)
{
case true:
return 7051;
case false:
return 7052;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 7053;
case false:
return 7054;
}
case false:
switch (waterlogged)
{
case true:
return 7055;
case false:
return 7056;
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
return 7057;
case false:
return 7058;
}
case false:
switch (waterlogged)
{
case true:
return 7059;
case false:
return 7060;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 7061;
case false:
return 7062;
}
case false:
switch (waterlogged)
{
case true:
return 7063;
case false:
return 7064;
}
}
}
}
}
}
constexpr static iron_trapdoor from_id(block_id_type id)
{
switch (id)
{
case 7001:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 7002:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 7003:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 7004:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 7005:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 7006:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 7007:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 7008:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 7009:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 7010:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 7011:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 7012:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 7013:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 7014:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 7015:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 7016:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 7017:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 7018:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 7019:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 7020:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 7021:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 7022:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 7023:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 7024:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 7025:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 7026:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 7027:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 7028:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 7029:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 7030:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 7031:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 7032:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 7033:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 7034:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 7035:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 7036:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 7037:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 7038:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 7039:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 7040:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 7041:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 7042:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 7043:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 7044:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 7045:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 7046:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 7047:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 7048:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 7049:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 7050:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 7051:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 7052:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 7053:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 7054:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 7055:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 7056:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 7057:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 7058:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 7059:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 7060:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 7061:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 7062:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 7063:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 7064:
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
return "minecraft:iron_trapdoor:north:top:true:true:true";
case false:
return "minecraft:iron_trapdoor:north:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:north:top:true:false:true";
case false:
return "minecraft:iron_trapdoor:north:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:north:top:false:true:true";
case false:
return "minecraft:iron_trapdoor:north:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:north:top:false:false:true";
case false:
return "minecraft:iron_trapdoor:north:top:false:false:false";
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
return "minecraft:iron_trapdoor:north:bottom:true:true:true";
case false:
return "minecraft:iron_trapdoor:north:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:north:bottom:true:false:true";
case false:
return "minecraft:iron_trapdoor:north:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:north:bottom:false:true:true";
case false:
return "minecraft:iron_trapdoor:north:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:north:bottom:false:false:true";
case false:
return "minecraft:iron_trapdoor:north:bottom:false:false:false";
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
return "minecraft:iron_trapdoor:south:top:true:true:true";
case false:
return "minecraft:iron_trapdoor:south:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:south:top:true:false:true";
case false:
return "minecraft:iron_trapdoor:south:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:south:top:false:true:true";
case false:
return "minecraft:iron_trapdoor:south:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:south:top:false:false:true";
case false:
return "minecraft:iron_trapdoor:south:top:false:false:false";
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
return "minecraft:iron_trapdoor:south:bottom:true:true:true";
case false:
return "minecraft:iron_trapdoor:south:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:south:bottom:true:false:true";
case false:
return "minecraft:iron_trapdoor:south:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:south:bottom:false:true:true";
case false:
return "minecraft:iron_trapdoor:south:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:south:bottom:false:false:true";
case false:
return "minecraft:iron_trapdoor:south:bottom:false:false:false";
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
return "minecraft:iron_trapdoor:west:top:true:true:true";
case false:
return "minecraft:iron_trapdoor:west:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:west:top:true:false:true";
case false:
return "minecraft:iron_trapdoor:west:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:west:top:false:true:true";
case false:
return "minecraft:iron_trapdoor:west:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:west:top:false:false:true";
case false:
return "minecraft:iron_trapdoor:west:top:false:false:false";
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
return "minecraft:iron_trapdoor:west:bottom:true:true:true";
case false:
return "minecraft:iron_trapdoor:west:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:west:bottom:true:false:true";
case false:
return "minecraft:iron_trapdoor:west:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:west:bottom:false:true:true";
case false:
return "minecraft:iron_trapdoor:west:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:west:bottom:false:false:true";
case false:
return "minecraft:iron_trapdoor:west:bottom:false:false:false";
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
return "minecraft:iron_trapdoor:east:top:true:true:true";
case false:
return "minecraft:iron_trapdoor:east:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:east:top:true:false:true";
case false:
return "minecraft:iron_trapdoor:east:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:east:top:false:true:true";
case false:
return "minecraft:iron_trapdoor:east:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:east:top:false:false:true";
case false:
return "minecraft:iron_trapdoor:east:top:false:false:false";
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
return "minecraft:iron_trapdoor:east:bottom:true:true:true";
case false:
return "minecraft:iron_trapdoor:east:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:east:bottom:true:false:true";
case false:
return "minecraft:iron_trapdoor:east:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:east:bottom:false:true:true";
case false:
return "minecraft:iron_trapdoor:east:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:iron_trapdoor:east:bottom:false:false:true";
case false:
return "minecraft:iron_trapdoor:east:bottom:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
