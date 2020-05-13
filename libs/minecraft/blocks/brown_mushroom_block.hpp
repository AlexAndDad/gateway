#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct brown_mushroom_block
{bool down = true;
bool east = true;
bool north = true;
bool south = true;
bool up = true;
bool west = true;
constexpr block_id_type to_id() const {
switch (down)
{
case true:
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
switch (west)
{
case true:
return 4491;
case false:
return 4492;
}
case false:
switch (west)
{
case true:
return 4493;
case false:
return 4494;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4495;
case false:
return 4496;
}
case false:
switch (west)
{
case true:
return 4497;
case false:
return 4498;
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
switch (west)
{
case true:
return 4499;
case false:
return 4500;
}
case false:
switch (west)
{
case true:
return 4501;
case false:
return 4502;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4503;
case false:
return 4504;
}
case false:
switch (west)
{
case true:
return 4505;
case false:
return 4506;
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
switch (west)
{
case true:
return 4507;
case false:
return 4508;
}
case false:
switch (west)
{
case true:
return 4509;
case false:
return 4510;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4511;
case false:
return 4512;
}
case false:
switch (west)
{
case true:
return 4513;
case false:
return 4514;
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
switch (west)
{
case true:
return 4515;
case false:
return 4516;
}
case false:
switch (west)
{
case true:
return 4517;
case false:
return 4518;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4519;
case false:
return 4520;
}
case false:
switch (west)
{
case true:
return 4521;
case false:
return 4522;
}
}
}
}
}
case false:
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
switch (west)
{
case true:
return 4523;
case false:
return 4524;
}
case false:
switch (west)
{
case true:
return 4525;
case false:
return 4526;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4527;
case false:
return 4528;
}
case false:
switch (west)
{
case true:
return 4529;
case false:
return 4530;
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
switch (west)
{
case true:
return 4531;
case false:
return 4532;
}
case false:
switch (west)
{
case true:
return 4533;
case false:
return 4534;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4535;
case false:
return 4536;
}
case false:
switch (west)
{
case true:
return 4537;
case false:
return 4538;
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
switch (west)
{
case true:
return 4539;
case false:
return 4540;
}
case false:
switch (west)
{
case true:
return 4541;
case false:
return 4542;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4543;
case false:
return 4544;
}
case false:
switch (west)
{
case true:
return 4545;
case false:
return 4546;
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
switch (west)
{
case true:
return 4547;
case false:
return 4548;
}
case false:
switch (west)
{
case true:
return 4549;
case false:
return 4550;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4551;
case false:
return 4552;
}
case false:
switch (west)
{
case true:
return 4553;
case false:
return 4554;
}
}
}
}
}
}
}
constexpr static brown_mushroom_block from_id(block_id_type id)
{
switch (id)
{
case 4491:
return {.down = true, .east = true, .north = true, .south = true, .up = true, .west = true};
case 4492:
return {.down = true, .east = true, .north = true, .south = true, .up = true, .west = false};
case 4493:
return {.down = true, .east = true, .north = true, .south = true, .up = false, .west = true};
case 4494:
return {.down = true, .east = true, .north = true, .south = true, .up = false, .west = false};
case 4495:
return {.down = true, .east = true, .north = true, .south = false, .up = true, .west = true};
case 4496:
return {.down = true, .east = true, .north = true, .south = false, .up = true, .west = false};
case 4497:
return {.down = true, .east = true, .north = true, .south = false, .up = false, .west = true};
case 4498:
return {.down = true, .east = true, .north = true, .south = false, .up = false, .west = false};
case 4499:
return {.down = true, .east = true, .north = false, .south = true, .up = true, .west = true};
case 4500:
return {.down = true, .east = true, .north = false, .south = true, .up = true, .west = false};
case 4501:
return {.down = true, .east = true, .north = false, .south = true, .up = false, .west = true};
case 4502:
return {.down = true, .east = true, .north = false, .south = true, .up = false, .west = false};
case 4503:
return {.down = true, .east = true, .north = false, .south = false, .up = true, .west = true};
case 4504:
return {.down = true, .east = true, .north = false, .south = false, .up = true, .west = false};
case 4505:
return {.down = true, .east = true, .north = false, .south = false, .up = false, .west = true};
case 4506:
return {.down = true, .east = true, .north = false, .south = false, .up = false, .west = false};
case 4507:
return {.down = true, .east = false, .north = true, .south = true, .up = true, .west = true};
case 4508:
return {.down = true, .east = false, .north = true, .south = true, .up = true, .west = false};
case 4509:
return {.down = true, .east = false, .north = true, .south = true, .up = false, .west = true};
case 4510:
return {.down = true, .east = false, .north = true, .south = true, .up = false, .west = false};
case 4511:
return {.down = true, .east = false, .north = true, .south = false, .up = true, .west = true};
case 4512:
return {.down = true, .east = false, .north = true, .south = false, .up = true, .west = false};
case 4513:
return {.down = true, .east = false, .north = true, .south = false, .up = false, .west = true};
case 4514:
return {.down = true, .east = false, .north = true, .south = false, .up = false, .west = false};
case 4515:
return {.down = true, .east = false, .north = false, .south = true, .up = true, .west = true};
case 4516:
return {.down = true, .east = false, .north = false, .south = true, .up = true, .west = false};
case 4517:
return {.down = true, .east = false, .north = false, .south = true, .up = false, .west = true};
case 4518:
return {.down = true, .east = false, .north = false, .south = true, .up = false, .west = false};
case 4519:
return {.down = true, .east = false, .north = false, .south = false, .up = true, .west = true};
case 4520:
return {.down = true, .east = false, .north = false, .south = false, .up = true, .west = false};
case 4521:
return {.down = true, .east = false, .north = false, .south = false, .up = false, .west = true};
case 4522:
return {.down = true, .east = false, .north = false, .south = false, .up = false, .west = false};
case 4523:
return {.down = false, .east = true, .north = true, .south = true, .up = true, .west = true};
case 4524:
return {.down = false, .east = true, .north = true, .south = true, .up = true, .west = false};
case 4525:
return {.down = false, .east = true, .north = true, .south = true, .up = false, .west = true};
case 4526:
return {.down = false, .east = true, .north = true, .south = true, .up = false, .west = false};
case 4527:
return {.down = false, .east = true, .north = true, .south = false, .up = true, .west = true};
case 4528:
return {.down = false, .east = true, .north = true, .south = false, .up = true, .west = false};
case 4529:
return {.down = false, .east = true, .north = true, .south = false, .up = false, .west = true};
case 4530:
return {.down = false, .east = true, .north = true, .south = false, .up = false, .west = false};
case 4531:
return {.down = false, .east = true, .north = false, .south = true, .up = true, .west = true};
case 4532:
return {.down = false, .east = true, .north = false, .south = true, .up = true, .west = false};
case 4533:
return {.down = false, .east = true, .north = false, .south = true, .up = false, .west = true};
case 4534:
return {.down = false, .east = true, .north = false, .south = true, .up = false, .west = false};
case 4535:
return {.down = false, .east = true, .north = false, .south = false, .up = true, .west = true};
case 4536:
return {.down = false, .east = true, .north = false, .south = false, .up = true, .west = false};
case 4537:
return {.down = false, .east = true, .north = false, .south = false, .up = false, .west = true};
case 4538:
return {.down = false, .east = true, .north = false, .south = false, .up = false, .west = false};
case 4539:
return {.down = false, .east = false, .north = true, .south = true, .up = true, .west = true};
case 4540:
return {.down = false, .east = false, .north = true, .south = true, .up = true, .west = false};
case 4541:
return {.down = false, .east = false, .north = true, .south = true, .up = false, .west = true};
case 4542:
return {.down = false, .east = false, .north = true, .south = true, .up = false, .west = false};
case 4543:
return {.down = false, .east = false, .north = true, .south = false, .up = true, .west = true};
case 4544:
return {.down = false, .east = false, .north = true, .south = false, .up = true, .west = false};
case 4545:
return {.down = false, .east = false, .north = true, .south = false, .up = false, .west = true};
case 4546:
return {.down = false, .east = false, .north = true, .south = false, .up = false, .west = false};
case 4547:
return {.down = false, .east = false, .north = false, .south = true, .up = true, .west = true};
case 4548:
return {.down = false, .east = false, .north = false, .south = true, .up = true, .west = false};
case 4549:
return {.down = false, .east = false, .north = false, .south = true, .up = false, .west = true};
case 4550:
return {.down = false, .east = false, .north = false, .south = true, .up = false, .west = false};
case 4551:
return {.down = false, .east = false, .north = false, .south = false, .up = true, .west = true};
case 4552:
return {.down = false, .east = false, .north = false, .south = false, .up = true, .west = false};
case 4553:
return {.down = false, .east = false, .north = false, .south = false, .up = false, .west = true};
case 4554:
return {.down = false, .east = false, .north = false, .south = false, .up = false, .west = false};
}}
constexpr std::string_view to_string() const
{switch (down)
{
case true:
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
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:true:true:true:true:true";
case false:
return "minecraft:brown_mushroom_block:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:true:true:true:false:true";
case false:
return "minecraft:brown_mushroom_block:true:true:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:true:true:false:true:true";
case false:
return "minecraft:brown_mushroom_block:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:true:true:false:false:true";
case false:
return "minecraft:brown_mushroom_block:true:true:true:false:false:false";
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
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:true:false:true:true:true";
case false:
return "minecraft:brown_mushroom_block:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:true:false:true:false:true";
case false:
return "minecraft:brown_mushroom_block:true:true:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:true:false:false:true:true";
case false:
return "minecraft:brown_mushroom_block:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:true:false:false:false:true";
case false:
return "minecraft:brown_mushroom_block:true:true:false:false:false:false";
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
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:false:true:true:true:true";
case false:
return "minecraft:brown_mushroom_block:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:false:true:true:false:true";
case false:
return "minecraft:brown_mushroom_block:true:false:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:false:true:false:true:true";
case false:
return "minecraft:brown_mushroom_block:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:false:true:false:false:true";
case false:
return "minecraft:brown_mushroom_block:true:false:true:false:false:false";
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
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:false:false:true:true:true";
case false:
return "minecraft:brown_mushroom_block:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:false:false:true:false:true";
case false:
return "minecraft:brown_mushroom_block:true:false:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:false:false:false:true:true";
case false:
return "minecraft:brown_mushroom_block:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:true:false:false:false:false:true";
case false:
return "minecraft:brown_mushroom_block:true:false:false:false:false:false";
}
}
}
}
}
case false:
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
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:true:true:true:true:true";
case false:
return "minecraft:brown_mushroom_block:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:true:true:true:false:true";
case false:
return "minecraft:brown_mushroom_block:false:true:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:true:true:false:true:true";
case false:
return "minecraft:brown_mushroom_block:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:true:true:false:false:true";
case false:
return "minecraft:brown_mushroom_block:false:true:true:false:false:false";
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
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:true:false:true:true:true";
case false:
return "minecraft:brown_mushroom_block:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:true:false:true:false:true";
case false:
return "minecraft:brown_mushroom_block:false:true:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:true:false:false:true:true";
case false:
return "minecraft:brown_mushroom_block:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:true:false:false:false:true";
case false:
return "minecraft:brown_mushroom_block:false:true:false:false:false:false";
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
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:false:true:true:true:true";
case false:
return "minecraft:brown_mushroom_block:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:false:true:true:false:true";
case false:
return "minecraft:brown_mushroom_block:false:false:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:false:true:false:true:true";
case false:
return "minecraft:brown_mushroom_block:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:false:true:false:false:true";
case false:
return "minecraft:brown_mushroom_block:false:false:true:false:false:false";
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
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:false:false:true:true:true";
case false:
return "minecraft:brown_mushroom_block:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:false:false:true:false:true";
case false:
return "minecraft:brown_mushroom_block:false:false:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:false:false:false:true:true";
case false:
return "minecraft:brown_mushroom_block:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:brown_mushroom_block:false:false:false:false:false:true";
case false:
return "minecraft:brown_mushroom_block:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
