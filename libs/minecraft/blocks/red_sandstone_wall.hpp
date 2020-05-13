#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct red_sandstone_wall
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
return 10459;
case false:
return 10460;
}
case false:
switch (west)
{
case true:
return 10461;
case false:
return 10462;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10463;
case false:
return 10464;
}
case false:
switch (west)
{
case true:
return 10465;
case false:
return 10466;
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
return 10467;
case false:
return 10468;
}
case false:
switch (west)
{
case true:
return 10469;
case false:
return 10470;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10471;
case false:
return 10472;
}
case false:
switch (west)
{
case true:
return 10473;
case false:
return 10474;
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
return 10475;
case false:
return 10476;
}
case false:
switch (west)
{
case true:
return 10477;
case false:
return 10478;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10479;
case false:
return 10480;
}
case false:
switch (west)
{
case true:
return 10481;
case false:
return 10482;
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
return 10483;
case false:
return 10484;
}
case false:
switch (west)
{
case true:
return 10485;
case false:
return 10486;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10487;
case false:
return 10488;
}
case false:
switch (west)
{
case true:
return 10489;
case false:
return 10490;
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
return 10491;
case false:
return 10492;
}
case false:
switch (west)
{
case true:
return 10493;
case false:
return 10494;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10495;
case false:
return 10496;
}
case false:
switch (west)
{
case true:
return 10497;
case false:
return 10498;
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
return 10499;
case false:
return 10500;
}
case false:
switch (west)
{
case true:
return 10501;
case false:
return 10502;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10503;
case false:
return 10504;
}
case false:
switch (west)
{
case true:
return 10505;
case false:
return 10506;
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
return 10507;
case false:
return 10508;
}
case false:
switch (west)
{
case true:
return 10509;
case false:
return 10510;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10511;
case false:
return 10512;
}
case false:
switch (west)
{
case true:
return 10513;
case false:
return 10514;
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
return 10515;
case false:
return 10516;
}
case false:
switch (west)
{
case true:
return 10517;
case false:
return 10518;
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return 10519;
case false:
return 10520;
}
case false:
switch (west)
{
case true:
return 10521;
case false:
return 10522;
}
}
}
}
}
}
}
constexpr static red_sandstone_wall from_id(block_id_type id)
{
switch (id)
{
case 10459:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10460:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10461:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10462:
return {.east = true, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10463:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10464:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10465:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10466:
return {.east = true, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10467:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10468:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10469:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10470:
return {.east = true, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10471:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10472:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10473:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10474:
return {.east = true, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10475:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10476:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10477:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10478:
return {.east = true, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10479:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10480:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10481:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10482:
return {.east = true, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10483:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10484:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10485:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10486:
return {.east = true, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10487:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10488:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10489:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10490:
return {.east = true, .north = false, .south = false, .up = false, .waterlogged = false, .west = false};
case 10491:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = true};
case 10492:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = true, .west = false};
case 10493:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = true};
case 10494:
return {.east = false, .north = true, .south = true, .up = true, .waterlogged = false, .west = false};
case 10495:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = true};
case 10496:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = true, .west = false};
case 10497:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = true};
case 10498:
return {.east = false, .north = true, .south = true, .up = false, .waterlogged = false, .west = false};
case 10499:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = true};
case 10500:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = true, .west = false};
case 10501:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = true};
case 10502:
return {.east = false, .north = true, .south = false, .up = true, .waterlogged = false, .west = false};
case 10503:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = true};
case 10504:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = true, .west = false};
case 10505:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = true};
case 10506:
return {.east = false, .north = true, .south = false, .up = false, .waterlogged = false, .west = false};
case 10507:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = true};
case 10508:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = true, .west = false};
case 10509:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = true};
case 10510:
return {.east = false, .north = false, .south = true, .up = true, .waterlogged = false, .west = false};
case 10511:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = true};
case 10512:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = true, .west = false};
case 10513:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = true};
case 10514:
return {.east = false, .north = false, .south = true, .up = false, .waterlogged = false, .west = false};
case 10515:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = true};
case 10516:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = true, .west = false};
case 10517:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = true};
case 10518:
return {.east = false, .north = false, .south = false, .up = true, .waterlogged = false, .west = false};
case 10519:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = true};
case 10520:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = true, .west = false};
case 10521:
return {.east = false, .north = false, .south = false, .up = false, .waterlogged = false, .west = true};
case 10522:
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
return "minecraft:red_sandstone_wall:true:true:true:true:true:true";
case false:
return "minecraft:red_sandstone_wall:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:true:true:true:true:false:true";
case false:
return "minecraft:red_sandstone_wall:true:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:true:true:true:false:true:true";
case false:
return "minecraft:red_sandstone_wall:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:true:true:true:false:false:true";
case false:
return "minecraft:red_sandstone_wall:true:true:true:false:false:false";
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
return "minecraft:red_sandstone_wall:true:true:false:true:true:true";
case false:
return "minecraft:red_sandstone_wall:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:true:true:false:true:false:true";
case false:
return "minecraft:red_sandstone_wall:true:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:true:true:false:false:true:true";
case false:
return "minecraft:red_sandstone_wall:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:true:true:false:false:false:true";
case false:
return "minecraft:red_sandstone_wall:true:true:false:false:false:false";
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
return "minecraft:red_sandstone_wall:true:false:true:true:true:true";
case false:
return "minecraft:red_sandstone_wall:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:true:false:true:true:false:true";
case false:
return "minecraft:red_sandstone_wall:true:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:true:false:true:false:true:true";
case false:
return "minecraft:red_sandstone_wall:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:true:false:true:false:false:true";
case false:
return "minecraft:red_sandstone_wall:true:false:true:false:false:false";
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
return "minecraft:red_sandstone_wall:true:false:false:true:true:true";
case false:
return "minecraft:red_sandstone_wall:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:true:false:false:true:false:true";
case false:
return "minecraft:red_sandstone_wall:true:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:true:false:false:false:true:true";
case false:
return "minecraft:red_sandstone_wall:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:true:false:false:false:false:true";
case false:
return "minecraft:red_sandstone_wall:true:false:false:false:false:false";
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
return "minecraft:red_sandstone_wall:false:true:true:true:true:true";
case false:
return "minecraft:red_sandstone_wall:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:false:true:true:true:false:true";
case false:
return "minecraft:red_sandstone_wall:false:true:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:false:true:true:false:true:true";
case false:
return "minecraft:red_sandstone_wall:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:false:true:true:false:false:true";
case false:
return "minecraft:red_sandstone_wall:false:true:true:false:false:false";
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
return "minecraft:red_sandstone_wall:false:true:false:true:true:true";
case false:
return "minecraft:red_sandstone_wall:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:false:true:false:true:false:true";
case false:
return "minecraft:red_sandstone_wall:false:true:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:false:true:false:false:true:true";
case false:
return "minecraft:red_sandstone_wall:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:false:true:false:false:false:true";
case false:
return "minecraft:red_sandstone_wall:false:true:false:false:false:false";
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
return "minecraft:red_sandstone_wall:false:false:true:true:true:true";
case false:
return "minecraft:red_sandstone_wall:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:false:false:true:true:false:true";
case false:
return "minecraft:red_sandstone_wall:false:false:true:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:false:false:true:false:true:true";
case false:
return "minecraft:red_sandstone_wall:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:false:false:true:false:false:true";
case false:
return "minecraft:red_sandstone_wall:false:false:true:false:false:false";
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
return "minecraft:red_sandstone_wall:false:false:false:true:true:true";
case false:
return "minecraft:red_sandstone_wall:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:false:false:false:true:false:true";
case false:
return "minecraft:red_sandstone_wall:false:false:false:true:false:false";
}
}
case false:
switch (waterlogged)
{
case true:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:false:false:false:false:true:true";
case false:
return "minecraft:red_sandstone_wall:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_sandstone_wall:false:false:false:false:false:true";
case false:
return "minecraft:red_sandstone_wall:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
