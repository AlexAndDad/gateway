#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dark_oak_trapdoor
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
return 4417;
case false:
return 4418;
}
case false:
switch (waterlogged)
{
case true:
return 4419;
case false:
return 4420;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4421;
case false:
return 4422;
}
case false:
switch (waterlogged)
{
case true:
return 4423;
case false:
return 4424;
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
return 4425;
case false:
return 4426;
}
case false:
switch (waterlogged)
{
case true:
return 4427;
case false:
return 4428;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4429;
case false:
return 4430;
}
case false:
switch (waterlogged)
{
case true:
return 4431;
case false:
return 4432;
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
return 4433;
case false:
return 4434;
}
case false:
switch (waterlogged)
{
case true:
return 4435;
case false:
return 4436;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4437;
case false:
return 4438;
}
case false:
switch (waterlogged)
{
case true:
return 4439;
case false:
return 4440;
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
return 4441;
case false:
return 4442;
}
case false:
switch (waterlogged)
{
case true:
return 4443;
case false:
return 4444;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4445;
case false:
return 4446;
}
case false:
switch (waterlogged)
{
case true:
return 4447;
case false:
return 4448;
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
return 4449;
case false:
return 4450;
}
case false:
switch (waterlogged)
{
case true:
return 4451;
case false:
return 4452;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4453;
case false:
return 4454;
}
case false:
switch (waterlogged)
{
case true:
return 4455;
case false:
return 4456;
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
return 4457;
case false:
return 4458;
}
case false:
switch (waterlogged)
{
case true:
return 4459;
case false:
return 4460;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4461;
case false:
return 4462;
}
case false:
switch (waterlogged)
{
case true:
return 4463;
case false:
return 4464;
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
return 4465;
case false:
return 4466;
}
case false:
switch (waterlogged)
{
case true:
return 4467;
case false:
return 4468;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4469;
case false:
return 4470;
}
case false:
switch (waterlogged)
{
case true:
return 4471;
case false:
return 4472;
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
return 4473;
case false:
return 4474;
}
case false:
switch (waterlogged)
{
case true:
return 4475;
case false:
return 4476;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4477;
case false:
return 4478;
}
case false:
switch (waterlogged)
{
case true:
return 4479;
case false:
return 4480;
}
}
}
}
}
}
constexpr static dark_oak_trapdoor from_id(block_id_type id)
{
switch (id)
{
case 4417:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4418:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4419:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4420:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4421:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4422:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4423:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4424:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4425:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4426:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4427:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4428:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4429:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4430:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4431:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4432:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4433:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4434:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4435:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4436:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4437:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4438:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4439:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4440:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4441:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4442:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4443:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4444:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4445:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4446:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4447:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4448:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4449:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4450:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4451:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4452:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4453:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4454:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4455:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4456:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4457:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4458:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4459:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4460:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4461:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4462:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4463:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4464:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4465:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4466:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4467:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4468:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4469:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4470:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4471:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4472:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4473:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4474:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4475:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4476:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4477:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4478:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4479:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4480:
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
return "minecraft:dark_oak_trapdoor:north:top:true:true:true";
case false:
return "minecraft:dark_oak_trapdoor:north:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:north:top:true:false:true";
case false:
return "minecraft:dark_oak_trapdoor:north:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:north:top:false:true:true";
case false:
return "minecraft:dark_oak_trapdoor:north:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:north:top:false:false:true";
case false:
return "minecraft:dark_oak_trapdoor:north:top:false:false:false";
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
return "minecraft:dark_oak_trapdoor:north:bottom:true:true:true";
case false:
return "minecraft:dark_oak_trapdoor:north:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:north:bottom:true:false:true";
case false:
return "minecraft:dark_oak_trapdoor:north:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:north:bottom:false:true:true";
case false:
return "minecraft:dark_oak_trapdoor:north:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:north:bottom:false:false:true";
case false:
return "minecraft:dark_oak_trapdoor:north:bottom:false:false:false";
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
return "minecraft:dark_oak_trapdoor:south:top:true:true:true";
case false:
return "minecraft:dark_oak_trapdoor:south:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:south:top:true:false:true";
case false:
return "minecraft:dark_oak_trapdoor:south:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:south:top:false:true:true";
case false:
return "minecraft:dark_oak_trapdoor:south:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:south:top:false:false:true";
case false:
return "minecraft:dark_oak_trapdoor:south:top:false:false:false";
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
return "minecraft:dark_oak_trapdoor:south:bottom:true:true:true";
case false:
return "minecraft:dark_oak_trapdoor:south:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:south:bottom:true:false:true";
case false:
return "minecraft:dark_oak_trapdoor:south:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:south:bottom:false:true:true";
case false:
return "minecraft:dark_oak_trapdoor:south:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:south:bottom:false:false:true";
case false:
return "minecraft:dark_oak_trapdoor:south:bottom:false:false:false";
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
return "minecraft:dark_oak_trapdoor:west:top:true:true:true";
case false:
return "minecraft:dark_oak_trapdoor:west:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:west:top:true:false:true";
case false:
return "minecraft:dark_oak_trapdoor:west:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:west:top:false:true:true";
case false:
return "minecraft:dark_oak_trapdoor:west:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:west:top:false:false:true";
case false:
return "minecraft:dark_oak_trapdoor:west:top:false:false:false";
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
return "minecraft:dark_oak_trapdoor:west:bottom:true:true:true";
case false:
return "minecraft:dark_oak_trapdoor:west:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:west:bottom:true:false:true";
case false:
return "minecraft:dark_oak_trapdoor:west:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:west:bottom:false:true:true";
case false:
return "minecraft:dark_oak_trapdoor:west:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:west:bottom:false:false:true";
case false:
return "minecraft:dark_oak_trapdoor:west:bottom:false:false:false";
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
return "minecraft:dark_oak_trapdoor:east:top:true:true:true";
case false:
return "minecraft:dark_oak_trapdoor:east:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:east:top:true:false:true";
case false:
return "minecraft:dark_oak_trapdoor:east:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:east:top:false:true:true";
case false:
return "minecraft:dark_oak_trapdoor:east:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:east:top:false:false:true";
case false:
return "minecraft:dark_oak_trapdoor:east:top:false:false:false";
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
return "minecraft:dark_oak_trapdoor:east:bottom:true:true:true";
case false:
return "minecraft:dark_oak_trapdoor:east:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:east:bottom:true:false:true";
case false:
return "minecraft:dark_oak_trapdoor:east:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:east:bottom:false:true:true";
case false:
return "minecraft:dark_oak_trapdoor:east:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_trapdoor:east:bottom:false:false:true";
case false:
return "minecraft:dark_oak_trapdoor:east:bottom:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
