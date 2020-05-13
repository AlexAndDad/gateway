#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct acacia_trapdoor
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
return 4353;
case false:
return 4354;
}
case false:
switch (waterlogged)
{
case true:
return 4355;
case false:
return 4356;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4357;
case false:
return 4358;
}
case false:
switch (waterlogged)
{
case true:
return 4359;
case false:
return 4360;
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
return 4361;
case false:
return 4362;
}
case false:
switch (waterlogged)
{
case true:
return 4363;
case false:
return 4364;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4365;
case false:
return 4366;
}
case false:
switch (waterlogged)
{
case true:
return 4367;
case false:
return 4368;
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
return 4369;
case false:
return 4370;
}
case false:
switch (waterlogged)
{
case true:
return 4371;
case false:
return 4372;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4373;
case false:
return 4374;
}
case false:
switch (waterlogged)
{
case true:
return 4375;
case false:
return 4376;
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
return 4377;
case false:
return 4378;
}
case false:
switch (waterlogged)
{
case true:
return 4379;
case false:
return 4380;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4381;
case false:
return 4382;
}
case false:
switch (waterlogged)
{
case true:
return 4383;
case false:
return 4384;
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
return 4385;
case false:
return 4386;
}
case false:
switch (waterlogged)
{
case true:
return 4387;
case false:
return 4388;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4389;
case false:
return 4390;
}
case false:
switch (waterlogged)
{
case true:
return 4391;
case false:
return 4392;
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
return 4393;
case false:
return 4394;
}
case false:
switch (waterlogged)
{
case true:
return 4395;
case false:
return 4396;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4397;
case false:
return 4398;
}
case false:
switch (waterlogged)
{
case true:
return 4399;
case false:
return 4400;
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
return 4401;
case false:
return 4402;
}
case false:
switch (waterlogged)
{
case true:
return 4403;
case false:
return 4404;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4405;
case false:
return 4406;
}
case false:
switch (waterlogged)
{
case true:
return 4407;
case false:
return 4408;
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
return 4409;
case false:
return 4410;
}
case false:
switch (waterlogged)
{
case true:
return 4411;
case false:
return 4412;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4413;
case false:
return 4414;
}
case false:
switch (waterlogged)
{
case true:
return 4415;
case false:
return 4416;
}
}
}
}
}
}
constexpr static acacia_trapdoor from_id(block_id_type id)
{
switch (id)
{
case 4353:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4354:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4355:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4356:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4357:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4358:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4359:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4360:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4361:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4362:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4363:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4364:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4365:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4366:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4367:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4368:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4369:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4370:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4371:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4372:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4373:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4374:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4375:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4376:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4377:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4378:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4379:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4380:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4381:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4382:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4383:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4384:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4385:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4386:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4387:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4388:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4389:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4390:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4391:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4392:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4393:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4394:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4395:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4396:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4397:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4398:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4399:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4400:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4401:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4402:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4403:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4404:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4405:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4406:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4407:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4408:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4409:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4410:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4411:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4412:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4413:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4414:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4415:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4416:
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
return "minecraft:acacia_trapdoor:north:top:true:true:true";
case false:
return "minecraft:acacia_trapdoor:north:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:north:top:true:false:true";
case false:
return "minecraft:acacia_trapdoor:north:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:north:top:false:true:true";
case false:
return "minecraft:acacia_trapdoor:north:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:north:top:false:false:true";
case false:
return "minecraft:acacia_trapdoor:north:top:false:false:false";
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
return "minecraft:acacia_trapdoor:north:bottom:true:true:true";
case false:
return "minecraft:acacia_trapdoor:north:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:north:bottom:true:false:true";
case false:
return "minecraft:acacia_trapdoor:north:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:north:bottom:false:true:true";
case false:
return "minecraft:acacia_trapdoor:north:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:north:bottom:false:false:true";
case false:
return "minecraft:acacia_trapdoor:north:bottom:false:false:false";
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
return "minecraft:acacia_trapdoor:south:top:true:true:true";
case false:
return "minecraft:acacia_trapdoor:south:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:south:top:true:false:true";
case false:
return "minecraft:acacia_trapdoor:south:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:south:top:false:true:true";
case false:
return "minecraft:acacia_trapdoor:south:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:south:top:false:false:true";
case false:
return "minecraft:acacia_trapdoor:south:top:false:false:false";
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
return "minecraft:acacia_trapdoor:south:bottom:true:true:true";
case false:
return "minecraft:acacia_trapdoor:south:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:south:bottom:true:false:true";
case false:
return "minecraft:acacia_trapdoor:south:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:south:bottom:false:true:true";
case false:
return "minecraft:acacia_trapdoor:south:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:south:bottom:false:false:true";
case false:
return "minecraft:acacia_trapdoor:south:bottom:false:false:false";
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
return "minecraft:acacia_trapdoor:west:top:true:true:true";
case false:
return "minecraft:acacia_trapdoor:west:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:west:top:true:false:true";
case false:
return "minecraft:acacia_trapdoor:west:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:west:top:false:true:true";
case false:
return "minecraft:acacia_trapdoor:west:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:west:top:false:false:true";
case false:
return "minecraft:acacia_trapdoor:west:top:false:false:false";
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
return "minecraft:acacia_trapdoor:west:bottom:true:true:true";
case false:
return "minecraft:acacia_trapdoor:west:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:west:bottom:true:false:true";
case false:
return "minecraft:acacia_trapdoor:west:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:west:bottom:false:true:true";
case false:
return "minecraft:acacia_trapdoor:west:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:west:bottom:false:false:true";
case false:
return "minecraft:acacia_trapdoor:west:bottom:false:false:false";
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
return "minecraft:acacia_trapdoor:east:top:true:true:true";
case false:
return "minecraft:acacia_trapdoor:east:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:east:top:true:false:true";
case false:
return "minecraft:acacia_trapdoor:east:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:east:top:false:true:true";
case false:
return "minecraft:acacia_trapdoor:east:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:east:top:false:false:true";
case false:
return "minecraft:acacia_trapdoor:east:top:false:false:false";
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
return "minecraft:acacia_trapdoor:east:bottom:true:true:true";
case false:
return "minecraft:acacia_trapdoor:east:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:east:bottom:true:false:true";
case false:
return "minecraft:acacia_trapdoor:east:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:east:bottom:false:true:true";
case false:
return "minecraft:acacia_trapdoor:east:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:acacia_trapdoor:east:bottom:false:false:true";
case false:
return "minecraft:acacia_trapdoor:east:bottom:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
