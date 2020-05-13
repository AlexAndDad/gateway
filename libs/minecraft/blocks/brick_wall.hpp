#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct brick_wall
{bool east = false;
bool north = false;
bool south = false;
bool up = true;
bool waterlogged = false;
bool west = false;
constexpr block_id_type to_id() const {
switch (east)
{
case true:
switch (north)
{
case true:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10331;
case false:
return 10332;
}
case false:
switch (west)
{
case true:
return 10333;
case false:
return 10334;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10335;
case false:
return 10336;
}
case false:
switch (west)
{
case true:
return 10337;
case false:
return 10338;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10339;
case false:
return 10340;
}
case false:
switch (west)
{
case true:
return 10341;
case false:
return 10342;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10343;
case false:
return 10344;
}
case false:
switch (west)
{
case true:
return 10345;
case false:
return 10346;
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10347;
case false:
return 10348;
}
case false:
switch (west)
{
case true:
return 10349;
case false:
return 10350;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10351;
case false:
return 10352;
}
case false:
switch (west)
{
case true:
return 10353;
case false:
return 10354;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10355;
case false:
return 10356;
}
case false:
switch (west)
{
case true:
return 10357;
case false:
return 10358;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10359;
case false:
return 10360;
}
case false:
switch (west)
{
case true:
return 10361;
case false:
return 10362;
}
}
}
}
}
case false:
switch (north)
{
case true:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10363;
case false:
return 10364;
}
case false:
switch (west)
{
case true:
return 10365;
case false:
return 10366;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10367;
case false:
return 10368;
}
case false:
switch (west)
{
case true:
return 10369;
case false:
return 10370;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10371;
case false:
return 10372;
}
case false:
switch (west)
{
case true:
return 10373;
case false:
return 10374;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10375;
case false:
return 10376;
}
case false:
switch (west)
{
case true:
return 10377;
case false:
return 10378;
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10379;
case false:
return 10380;
}
case false:
switch (west)
{
case true:
return 10381;
case false:
return 10382;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10383;
case false:
return 10384;
}
case false:
switch (west)
{
case true:
return 10385;
case false:
return 10386;
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10387;
case false:
return 10388;
}
case false:
switch (west)
{
case true:
return 10389;
case false:
return 10390;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10391;
case false:
return 10392;
}
case false:
switch (west)
{
case true:
return 10393;
case false:
return 10394;
}
}
}
}
}
}
}
constexpr static brick_wall from_id(block_id_type id)
{
switch (id)
{
case 10331:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10332:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10333:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10334:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10335:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10336:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10337:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10338:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10339:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10340:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10341:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10342:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10343:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10344:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10345:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10346:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10347:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10348:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10349:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10350:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10351:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10352:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10353:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10354:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10355:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10356:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10357:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10358:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10359:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10360:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10361:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10362:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
case 10363:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10364:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10365:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10366:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10367:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10368:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10369:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10370:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10371:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10372:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10373:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10374:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10375:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10376:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10377:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10378:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10379:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10380:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10381:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10382:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10383:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10384:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10385:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10386:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10387:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10388:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10389:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10390:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10391:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10392:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10393:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10394:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
}}
constexpr std::string_view to_string() const
{switch (east)
{
case true:
switch (north)
{
case true:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:true:true:true:true:true:true";
case false:
return "minecraft:brick_wall:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:true:true:true:true:false:true";
case false:
return "minecraft:brick_wall:true:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:true:true:true:false:true:true";
case false:
return "minecraft:brick_wall:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:true:true:true:false:false:true";
case false:
return "minecraft:brick_wall:true:true:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:true:true:false:true:true:true";
case false:
return "minecraft:brick_wall:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:true:true:false:true:false:true";
case false:
return "minecraft:brick_wall:true:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:true:true:false:false:true:true";
case false:
return "minecraft:brick_wall:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:true:true:false:false:false:true";
case false:
return "minecraft:brick_wall:true:true:false:false:false:false";
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:true:false:true:true:true:true";
case false:
return "minecraft:brick_wall:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:true:false:true:true:false:true";
case false:
return "minecraft:brick_wall:true:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:true:false:true:false:true:true";
case false:
return "minecraft:brick_wall:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:true:false:true:false:false:true";
case false:
return "minecraft:brick_wall:true:false:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:true:false:false:true:true:true";
case false:
return "minecraft:brick_wall:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:true:false:false:true:false:true";
case false:
return "minecraft:brick_wall:true:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:true:false:false:false:true:true";
case false:
return "minecraft:brick_wall:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:true:false:false:false:false:true";
case false:
return "minecraft:brick_wall:true:false:false:false:false:false";
}
}
}
}
}
case false:
switch (north)
{
case true:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:false:true:true:true:true:true";
case false:
return "minecraft:brick_wall:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:false:true:true:true:false:true";
case false:
return "minecraft:brick_wall:false:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:false:true:true:false:true:true";
case false:
return "minecraft:brick_wall:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:false:true:true:false:false:true";
case false:
return "minecraft:brick_wall:false:true:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:false:true:false:true:true:true";
case false:
return "minecraft:brick_wall:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:false:true:false:true:false:true";
case false:
return "minecraft:brick_wall:false:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:false:true:false:false:true:true";
case false:
return "minecraft:brick_wall:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:false:true:false:false:false:true";
case false:
return "minecraft:brick_wall:false:true:false:false:false:false";
}
}
}
}
case false:
switch (south)
{
case true:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:false:false:true:true:true:true";
case false:
return "minecraft:brick_wall:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:false:false:true:true:false:true";
case false:
return "minecraft:brick_wall:false:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:false:false:true:false:true:true";
case false:
return "minecraft:brick_wall:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:false:false:true:false:false:true";
case false:
return "minecraft:brick_wall:false:false:true:false:false:false";
}
}
}
case false:
switch (up)
{
case true:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:false:false:false:true:true:true";
case false:
return "minecraft:brick_wall:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:false:false:false:true:false:true";
case false:
return "minecraft:brick_wall:false:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:brick_wall:false:false:false:false:true:true";
case false:
return "minecraft:brick_wall:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brick_wall:false:false:false:false:false:true";
case false:
return "minecraft:brick_wall:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
