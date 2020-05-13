#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jungle_trapdoor
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
return 4289;
case false:
return 4290;
}
case false:
switch (waterlogged)
{
case true:
return 4291;
case false:
return 4292;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4293;
case false:
return 4294;
}
case false:
switch (waterlogged)
{
case true:
return 4295;
case false:
return 4296;
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
return 4297;
case false:
return 4298;
}
case false:
switch (waterlogged)
{
case true:
return 4299;
case false:
return 4300;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4301;
case false:
return 4302;
}
case false:
switch (waterlogged)
{
case true:
return 4303;
case false:
return 4304;
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
return 4305;
case false:
return 4306;
}
case false:
switch (waterlogged)
{
case true:
return 4307;
case false:
return 4308;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4309;
case false:
return 4310;
}
case false:
switch (waterlogged)
{
case true:
return 4311;
case false:
return 4312;
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
return 4313;
case false:
return 4314;
}
case false:
switch (waterlogged)
{
case true:
return 4315;
case false:
return 4316;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4317;
case false:
return 4318;
}
case false:
switch (waterlogged)
{
case true:
return 4319;
case false:
return 4320;
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
return 4321;
case false:
return 4322;
}
case false:
switch (waterlogged)
{
case true:
return 4323;
case false:
return 4324;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4325;
case false:
return 4326;
}
case false:
switch (waterlogged)
{
case true:
return 4327;
case false:
return 4328;
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
return 4329;
case false:
return 4330;
}
case false:
switch (waterlogged)
{
case true:
return 4331;
case false:
return 4332;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4333;
case false:
return 4334;
}
case false:
switch (waterlogged)
{
case true:
return 4335;
case false:
return 4336;
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
return 4337;
case false:
return 4338;
}
case false:
switch (waterlogged)
{
case true:
return 4339;
case false:
return 4340;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4341;
case false:
return 4342;
}
case false:
switch (waterlogged)
{
case true:
return 4343;
case false:
return 4344;
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
return 4345;
case false:
return 4346;
}
case false:
switch (waterlogged)
{
case true:
return 4347;
case false:
return 4348;
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return 4349;
case false:
return 4350;
}
case false:
switch (waterlogged)
{
case true:
return 4351;
case false:
return 4352;
}
}
}
}
}
}
constexpr static jungle_trapdoor from_id(block_id_type id)
{
switch (id)
{
case 4289:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4290:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4291:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4292:
return {.facing = facing_type::north, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4293:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4294:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4295:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4296:
return {.facing = facing_type::north, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4297:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4298:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4299:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4300:
return {.facing = facing_type::north, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4301:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4302:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4303:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4304:
return {.facing = facing_type::north, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4305:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4306:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4307:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4308:
return {.facing = facing_type::south, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4309:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4310:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4311:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4312:
return {.facing = facing_type::south, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4313:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4314:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4315:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4316:
return {.facing = facing_type::south, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4317:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4318:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4319:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4320:
return {.facing = facing_type::south, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4321:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4322:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4323:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4324:
return {.facing = facing_type::west, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4325:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4326:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4327:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4328:
return {.facing = facing_type::west, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4329:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4330:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4331:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4332:
return {.facing = facing_type::west, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4333:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4334:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4335:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4336:
return {.facing = facing_type::west, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = false};
case 4337:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = true, .waterlogged = true};
case 4338:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = true, .waterlogged = false};
case 4339:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = false, .waterlogged = true};
case 4340:
return {.facing = facing_type::east, .half = half_type::top, .open = true, .powered = false, .waterlogged = false};
case 4341:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = true, .waterlogged = true};
case 4342:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = true, .waterlogged = false};
case 4343:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = false, .waterlogged = true};
case 4344:
return {.facing = facing_type::east, .half = half_type::top, .open = false, .powered = false, .waterlogged = false};
case 4345:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = true};
case 4346:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = true, .waterlogged = false};
case 4347:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = true};
case 4348:
return {.facing = facing_type::east, .half = half_type::bottom, .open = true, .powered = false, .waterlogged = false};
case 4349:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = true};
case 4350:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = true, .waterlogged = false};
case 4351:
return {.facing = facing_type::east, .half = half_type::bottom, .open = false, .powered = false, .waterlogged = true};
case 4352:
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
return "minecraft:jungle_trapdoor:north:top:true:true:true";
case false:
return "minecraft:jungle_trapdoor:north:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:north:top:true:false:true";
case false:
return "minecraft:jungle_trapdoor:north:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:north:top:false:true:true";
case false:
return "minecraft:jungle_trapdoor:north:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:north:top:false:false:true";
case false:
return "minecraft:jungle_trapdoor:north:top:false:false:false";
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
return "minecraft:jungle_trapdoor:north:bottom:true:true:true";
case false:
return "minecraft:jungle_trapdoor:north:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:north:bottom:true:false:true";
case false:
return "minecraft:jungle_trapdoor:north:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:north:bottom:false:true:true";
case false:
return "minecraft:jungle_trapdoor:north:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:north:bottom:false:false:true";
case false:
return "minecraft:jungle_trapdoor:north:bottom:false:false:false";
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
return "minecraft:jungle_trapdoor:south:top:true:true:true";
case false:
return "minecraft:jungle_trapdoor:south:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:south:top:true:false:true";
case false:
return "minecraft:jungle_trapdoor:south:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:south:top:false:true:true";
case false:
return "minecraft:jungle_trapdoor:south:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:south:top:false:false:true";
case false:
return "minecraft:jungle_trapdoor:south:top:false:false:false";
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
return "minecraft:jungle_trapdoor:south:bottom:true:true:true";
case false:
return "minecraft:jungle_trapdoor:south:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:south:bottom:true:false:true";
case false:
return "minecraft:jungle_trapdoor:south:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:south:bottom:false:true:true";
case false:
return "minecraft:jungle_trapdoor:south:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:south:bottom:false:false:true";
case false:
return "minecraft:jungle_trapdoor:south:bottom:false:false:false";
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
return "minecraft:jungle_trapdoor:west:top:true:true:true";
case false:
return "minecraft:jungle_trapdoor:west:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:west:top:true:false:true";
case false:
return "minecraft:jungle_trapdoor:west:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:west:top:false:true:true";
case false:
return "minecraft:jungle_trapdoor:west:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:west:top:false:false:true";
case false:
return "minecraft:jungle_trapdoor:west:top:false:false:false";
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
return "minecraft:jungle_trapdoor:west:bottom:true:true:true";
case false:
return "minecraft:jungle_trapdoor:west:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:west:bottom:true:false:true";
case false:
return "minecraft:jungle_trapdoor:west:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:west:bottom:false:true:true";
case false:
return "minecraft:jungle_trapdoor:west:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:west:bottom:false:false:true";
case false:
return "minecraft:jungle_trapdoor:west:bottom:false:false:false";
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
return "minecraft:jungle_trapdoor:east:top:true:true:true";
case false:
return "minecraft:jungle_trapdoor:east:top:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:east:top:true:false:true";
case false:
return "minecraft:jungle_trapdoor:east:top:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:east:top:false:true:true";
case false:
return "minecraft:jungle_trapdoor:east:top:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:east:top:false:false:true";
case false:
return "minecraft:jungle_trapdoor:east:top:false:false:false";
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
return "minecraft:jungle_trapdoor:east:bottom:true:true:true";
case false:
return "minecraft:jungle_trapdoor:east:bottom:true:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:east:bottom:true:false:true";
case false:
return "minecraft:jungle_trapdoor:east:bottom:true:false:false";
}
}
case false:
switch (powered)
{
case true:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:east:bottom:false:true:true";
case false:
return "minecraft:jungle_trapdoor:east:bottom:false:true:false";
}
case false:
switch (waterlogged)
{
case true:
return "minecraft:jungle_trapdoor:east:bottom:false:false:true";
case false:
return "minecraft:jungle_trapdoor:east:bottom:false:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
