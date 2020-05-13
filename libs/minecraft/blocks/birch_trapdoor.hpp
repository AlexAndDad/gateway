#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct birch_trapdoor
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
return 4225;
case false:
return 4226;
}
case false:
switch (waterlogged)
{
case true:
return 4227;
case false:
return 4228;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4229;
case false:
return 4230;
}
case false:
switch (waterlogged)
{
case true:
return 4231;
case false:
return 4232;
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
return 4233;
case false:
return 4234;
}
case false:
switch (waterlogged)
{
case true:
return 4235;
case false:
return 4236;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4237;
case false:
return 4238;
}
case false:
switch (waterlogged)
{
case true:
return 4239;
case false:
return 4240;
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
return 4241;
case false:
return 4242;
}
case false:
switch (waterlogged)
{
case true:
return 4243;
case false:
return 4244;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4245;
case false:
return 4246;
}
case false:
switch (waterlogged)
{
case true:
return 4247;
case false:
return 4248;
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
return 4249;
case false:
return 4250;
}
case false:
switch (waterlogged)
{
case true:
return 4251;
case false:
return 4252;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4253;
case false:
return 4254;
}
case false:
switch (waterlogged)
{
case true:
return 4255;
case false:
return 4256;
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
return 4257;
case false:
return 4258;
}
case false:
switch (waterlogged)
{
case true:
return 4259;
case false:
return 4260;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4261;
case false:
return 4262;
}
case false:
switch (waterlogged)
{
case true:
return 4263;
case false:
return 4264;
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
return 4265;
case false:
return 4266;
}
case false:
switch (waterlogged)
{
case true:
return 4267;
case false:
return 4268;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4269;
case false:
return 4270;
}
case false:
switch (waterlogged)
{
case true:
return 4271;
case false:
return 4272;
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
return 4273;
case false:
return 4274;
}
case false:
switch (waterlogged)
{
case true:
return 4275;
case false:
return 4276;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4277;
case false:
return 4278;
}
case false:
switch (waterlogged)
{
case true:
return 4279;
case false:
return 4280;
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
return 4281;
case false:
return 4282;
}
case false:
switch (waterlogged)
{
case true:
return 4283;
case false:
return 4284;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4285;
case false:
return 4286;
}
case false:
switch (waterlogged)
{
case true:
return 4287;
case false:
return 4288;
}
}
}
}
}
}
constexpr static birch_trapdoor from_id(block_id_type id)
{
switch (id)
{
case 4225:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4226:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4227:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4228:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4229:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4230:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4231:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4232:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4233:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4234:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4235:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4236:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4237:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4238:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4239:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4240:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4241:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4242:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4243:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4244:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4245:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4246:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4247:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4248:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4249:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4250:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4251:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4252:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4253:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4254:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4255:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4256:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4257:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4258:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4259:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4260:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4261:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4262:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4263:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4264:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4265:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4266:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4267:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4268:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4269:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4270:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4271:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4272:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4273:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4274:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4275:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4276:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4277:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4278:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4279:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4280:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4281:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4282:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4283:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4284:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4285:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4286:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4287:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4288:
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
return "minecraft:birch_trapdoor:north:top:true:true:true";
case false:
return "minecraft:birch_trapdoor:north:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:north:top:true:false:true";
case false:
return "minecraft:birch_trapdoor:north:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:north:top:false:true:true";
case false:
return "minecraft:birch_trapdoor:north:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:north:top:false:false:true";
case false:
return "minecraft:birch_trapdoor:north:top:false:false:false";
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
return "minecraft:birch_trapdoor:north:bottom:true:true:true";
case false:
return "minecraft:birch_trapdoor:north:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:north:bottom:true:false:true";
case false:
return "minecraft:birch_trapdoor:north:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:north:bottom:false:true:true";
case false:
return "minecraft:birch_trapdoor:north:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:north:bottom:false:false:true";
case false:
return "minecraft:birch_trapdoor:north:bottom:false:false:false";
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
return "minecraft:birch_trapdoor:south:top:true:true:true";
case false:
return "minecraft:birch_trapdoor:south:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:south:top:true:false:true";
case false:
return "minecraft:birch_trapdoor:south:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:south:top:false:true:true";
case false:
return "minecraft:birch_trapdoor:south:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:south:top:false:false:true";
case false:
return "minecraft:birch_trapdoor:south:top:false:false:false";
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
return "minecraft:birch_trapdoor:south:bottom:true:true:true";
case false:
return "minecraft:birch_trapdoor:south:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:south:bottom:true:false:true";
case false:
return "minecraft:birch_trapdoor:south:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:south:bottom:false:true:true";
case false:
return "minecraft:birch_trapdoor:south:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:south:bottom:false:false:true";
case false:
return "minecraft:birch_trapdoor:south:bottom:false:false:false";
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
return "minecraft:birch_trapdoor:west:top:true:true:true";
case false:
return "minecraft:birch_trapdoor:west:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:west:top:true:false:true";
case false:
return "minecraft:birch_trapdoor:west:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:west:top:false:true:true";
case false:
return "minecraft:birch_trapdoor:west:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:west:top:false:false:true";
case false:
return "minecraft:birch_trapdoor:west:top:false:false:false";
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
return "minecraft:birch_trapdoor:west:bottom:true:true:true";
case false:
return "minecraft:birch_trapdoor:west:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:west:bottom:true:false:true";
case false:
return "minecraft:birch_trapdoor:west:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:west:bottom:false:true:true";
case false:
return "minecraft:birch_trapdoor:west:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:west:bottom:false:false:true";
case false:
return "minecraft:birch_trapdoor:west:bottom:false:false:false";
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
return "minecraft:birch_trapdoor:east:top:true:true:true";
case false:
return "minecraft:birch_trapdoor:east:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:east:top:true:false:true";
case false:
return "minecraft:birch_trapdoor:east:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:east:top:false:true:true";
case false:
return "minecraft:birch_trapdoor:east:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:east:top:false:false:true";
case false:
return "minecraft:birch_trapdoor:east:top:false:false:false";
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
return "minecraft:birch_trapdoor:east:bottom:true:true:true";
case false:
return "minecraft:birch_trapdoor:east:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:east:bottom:true:false:true";
case false:
return "minecraft:birch_trapdoor:east:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:east:bottom:false:true:true";
case false:
return "minecraft:birch_trapdoor:east:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:birch_trapdoor:east:bottom:false:false:true";
case false:
return "minecraft:birch_trapdoor:east:bottom:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
