#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct prismarine_wall
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
return 10395;
case false:
return 10396;
}
case false:
switch (west)
{
case true:
return 10397;
case false:
return 10398;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10399;
case false:
return 10400;
}
case false:
switch (west)
{
case true:
return 10401;
case false:
return 10402;
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
return 10403;
case false:
return 10404;
}
case false:
switch (west)
{
case true:
return 10405;
case false:
return 10406;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10407;
case false:
return 10408;
}
case false:
switch (west)
{
case true:
return 10409;
case false:
return 10410;
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
return 10411;
case false:
return 10412;
}
case false:
switch (west)
{
case true:
return 10413;
case false:
return 10414;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10415;
case false:
return 10416;
}
case false:
switch (west)
{
case true:
return 10417;
case false:
return 10418;
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
return 10419;
case false:
return 10420;
}
case false:
switch (west)
{
case true:
return 10421;
case false:
return 10422;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10423;
case false:
return 10424;
}
case false:
switch (west)
{
case true:
return 10425;
case false:
return 10426;
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
return 10427;
case false:
return 10428;
}
case false:
switch (west)
{
case true:
return 10429;
case false:
return 10430;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10431;
case false:
return 10432;
}
case false:
switch (west)
{
case true:
return 10433;
case false:
return 10434;
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
return 10435;
case false:
return 10436;
}
case false:
switch (west)
{
case true:
return 10437;
case false:
return 10438;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10439;
case false:
return 10440;
}
case false:
switch (west)
{
case true:
return 10441;
case false:
return 10442;
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
return 10443;
case false:
return 10444;
}
case false:
switch (west)
{
case true:
return 10445;
case false:
return 10446;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10447;
case false:
return 10448;
}
case false:
switch (west)
{
case true:
return 10449;
case false:
return 10450;
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
return 10451;
case false:
return 10452;
}
case false:
switch (west)
{
case true:
return 10453;
case false:
return 10454;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10455;
case false:
return 10456;
}
case false:
switch (west)
{
case true:
return 10457;
case false:
return 10458;
}
}
}
}
}
}
}
constexpr static prismarine_wall from_id(block_id_type id)
{
switch (id)
{
case 10395:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10396:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10397:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10398:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10399:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10400:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10401:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10402:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10403:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10404:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10405:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10406:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10407:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10408:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10409:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10410:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10411:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10412:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10413:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10414:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10415:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10416:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10417:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10418:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10419:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10420:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10421:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10422:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10423:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10424:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10425:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10426:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
case 10427:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10428:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10429:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10430:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10431:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10432:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10433:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10434:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10435:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10436:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10437:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10438:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10439:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10440:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10441:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10442:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10443:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10444:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10445:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10446:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10447:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10448:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10449:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10450:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10451:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10452:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10453:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10454:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10455:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10456:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10457:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10458:
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
return "minecraft:prismarine_wall:true:true:true:true:true:true";
case false:
return "minecraft:prismarine_wall:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:true:true:true:true:false:true";
case false:
return "minecraft:prismarine_wall:true:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:prismarine_wall:true:true:true:false:true:true";
case false:
return "minecraft:prismarine_wall:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:true:true:true:false:false:true";
case false:
return "minecraft:prismarine_wall:true:true:true:false:false:false";
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
return "minecraft:prismarine_wall:true:true:false:true:true:true";
case false:
return "minecraft:prismarine_wall:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:true:true:false:true:false:true";
case false:
return "minecraft:prismarine_wall:true:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:prismarine_wall:true:true:false:false:true:true";
case false:
return "minecraft:prismarine_wall:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:true:true:false:false:false:true";
case false:
return "minecraft:prismarine_wall:true:true:false:false:false:false";
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
return "minecraft:prismarine_wall:true:false:true:true:true:true";
case false:
return "minecraft:prismarine_wall:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:true:false:true:true:false:true";
case false:
return "minecraft:prismarine_wall:true:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:prismarine_wall:true:false:true:false:true:true";
case false:
return "minecraft:prismarine_wall:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:true:false:true:false:false:true";
case false:
return "minecraft:prismarine_wall:true:false:true:false:false:false";
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
return "minecraft:prismarine_wall:true:false:false:true:true:true";
case false:
return "minecraft:prismarine_wall:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:true:false:false:true:false:true";
case false:
return "minecraft:prismarine_wall:true:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:prismarine_wall:true:false:false:false:true:true";
case false:
return "minecraft:prismarine_wall:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:true:false:false:false:false:true";
case false:
return "minecraft:prismarine_wall:true:false:false:false:false:false";
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
return "minecraft:prismarine_wall:false:true:true:true:true:true";
case false:
return "minecraft:prismarine_wall:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:false:true:true:true:false:true";
case false:
return "minecraft:prismarine_wall:false:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:prismarine_wall:false:true:true:false:true:true";
case false:
return "minecraft:prismarine_wall:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:false:true:true:false:false:true";
case false:
return "minecraft:prismarine_wall:false:true:true:false:false:false";
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
return "minecraft:prismarine_wall:false:true:false:true:true:true";
case false:
return "minecraft:prismarine_wall:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:false:true:false:true:false:true";
case false:
return "minecraft:prismarine_wall:false:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:prismarine_wall:false:true:false:false:true:true";
case false:
return "minecraft:prismarine_wall:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:false:true:false:false:false:true";
case false:
return "minecraft:prismarine_wall:false:true:false:false:false:false";
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
return "minecraft:prismarine_wall:false:false:true:true:true:true";
case false:
return "minecraft:prismarine_wall:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:false:false:true:true:false:true";
case false:
return "minecraft:prismarine_wall:false:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:prismarine_wall:false:false:true:false:true:true";
case false:
return "minecraft:prismarine_wall:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:false:false:true:false:false:true";
case false:
return "minecraft:prismarine_wall:false:false:true:false:false:false";
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
return "minecraft:prismarine_wall:false:false:false:true:true:true";
case false:
return "minecraft:prismarine_wall:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:false:false:false:true:false:true";
case false:
return "minecraft:prismarine_wall:false:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:prismarine_wall:false:false:false:false:true:true";
case false:
return "minecraft:prismarine_wall:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:prismarine_wall:false:false:false:false:false:true";
case false:
return "minecraft:prismarine_wall:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
