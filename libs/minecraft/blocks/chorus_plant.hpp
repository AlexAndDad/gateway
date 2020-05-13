#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct chorus_plant
{bool down = false;
bool east = false;
bool north = false;
bool south = false;
bool up = false;
bool west = false;
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
return 8528;
case false:
return 8529;
}
case false:
switch (west)
{
case true:
return 8530;
case false:
return 8531;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 8532;
case false:
return 8533;
}
case false:
switch (west)
{
case true:
return 8534;
case false:
return 8535;
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
return 8536;
case false:
return 8537;
}
case false:
switch (west)
{
case true:
return 8538;
case false:
return 8539;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 8540;
case false:
return 8541;
}
case false:
switch (west)
{
case true:
return 8542;
case false:
return 8543;
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
return 8544;
case false:
return 8545;
}
case false:
switch (west)
{
case true:
return 8546;
case false:
return 8547;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 8548;
case false:
return 8549;
}
case false:
switch (west)
{
case true:
return 8550;
case false:
return 8551;
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
return 8552;
case false:
return 8553;
}
case false:
switch (west)
{
case true:
return 8554;
case false:
return 8555;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 8556;
case false:
return 8557;
}
case false:
switch (west)
{
case true:
return 8558;
case false:
return 8559;
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
return 8560;
case false:
return 8561;
}
case false:
switch (west)
{
case true:
return 8562;
case false:
return 8563;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 8564;
case false:
return 8565;
}
case false:
switch (west)
{
case true:
return 8566;
case false:
return 8567;
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
return 8568;
case false:
return 8569;
}
case false:
switch (west)
{
case true:
return 8570;
case false:
return 8571;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 8572;
case false:
return 8573;
}
case false:
switch (west)
{
case true:
return 8574;
case false:
return 8575;
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
return 8576;
case false:
return 8577;
}
case false:
switch (west)
{
case true:
return 8578;
case false:
return 8579;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 8580;
case false:
return 8581;
}
case false:
switch (west)
{
case true:
return 8582;
case false:
return 8583;
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
return 8584;
case false:
return 8585;
}
case false:
switch (west)
{
case true:
return 8586;
case false:
return 8587;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 8588;
case false:
return 8589;
}
case false:
switch (west)
{
case true:
return 8590;
case false:
return 8591;
}
}
}
}
}
}
}
constexpr static chorus_plant from_id(block_id_type id)
{
switch (id)
{
case 8528:
return {.down = true, .east = true, .north = true, .south = true, .up = true, .west = true};
case 8529:
return {.down = true, .east = true, .north = true, .south = true, .up = true, .west = false};
case 8530:
return {.down = true, .east = true, .north = true, .south = true, .up = false, .west = true};
case 8531:
return {.down = true, .east = true, .north = true, .south = true, .up = false, .west = false};
case 8532:
return {.down = true, .east = true, .north = true, .south = false, .up = true, .west = true};
case 8533:
return {.down = true, .east = true, .north = true, .south = false, .up = true, .west = false};
case 8534:
return {.down = true, .east = true, .north = true, .south = false, .up = false, .west = true};
case 8535:
return {.down = true, .east = true, .north = true, .south = false, .up = false, .west = false};
case 8536:
return {.down = true, .east = true, .north = false, .south = true, .up = true, .west = true};
case 8537:
return {.down = true, .east = true, .north = false, .south = true, .up = true, .west = false};
case 8538:
return {.down = true, .east = true, .north = false, .south = true, .up = false, .west = true};
case 8539:
return {.down = true, .east = true, .north = false, .south = true, .up = false, .west = false};
case 8540:
return {.down = true, .east = true, .north = false, .south = false, .up = true, .west = true};
case 8541:
return {.down = true, .east = true, .north = false, .south = false, .up = true, .west = false};
case 8542:
return {.down = true, .east = true, .north = false, .south = false, .up = false, .west = true};
case 8543:
return {.down = true, .east = true, .north = false, .south = false, .up = false, .west = false};
case 8544:
return {.down = true, .east = false, .north = true, .south = true, .up = true, .west = true};
case 8545:
return {.down = true, .east = false, .north = true, .south = true, .up = true, .west = false};
case 8546:
return {.down = true, .east = false, .north = true, .south = true, .up = false, .west = true};
case 8547:
return {.down = true, .east = false, .north = true, .south = true, .up = false, .west = false};
case 8548:
return {.down = true, .east = false, .north = true, .south = false, .up = true, .west = true};
case 8549:
return {.down = true, .east = false, .north = true, .south = false, .up = true, .west = false};
case 8550:
return {.down = true, .east = false, .north = true, .south = false, .up = false, .west = true};
case 8551:
return {.down = true, .east = false, .north = true, .south = false, .up = false, .west = false};
case 8552:
return {.down = true, .east = false, .north = false, .south = true, .up = true, .west = true};
case 8553:
return {.down = true, .east = false, .north = false, .south = true, .up = true, .west = false};
case 8554:
return {.down = true, .east = false, .north = false, .south = true, .up = false, .west = true};
case 8555:
return {.down = true, .east = false, .north = false, .south = true, .up = false, .west = false};
case 8556:
return {.down = true, .east = false, .north = false, .south = false, .up = true, .west = true};
case 8557:
return {.down = true, .east = false, .north = false, .south = false, .up = true, .west = false};
case 8558:
return {.down = true, .east = false, .north = false, .south = false, .up = false, .west = true};
case 8559:
return {.down = true, .east = false, .north = false, .south = false, .up = false, .west = false};
case 8560:
return {.down = false, .east = true, .north = true, .south = true, .up = true, .west = true};
case 8561:
return {.down = false, .east = true, .north = true, .south = true, .up = true, .west = false};
case 8562:
return {.down = false, .east = true, .north = true, .south = true, .up = false, .west = true};
case 8563:
return {.down = false, .east = true, .north = true, .south = true, .up = false, .west = false};
case 8564:
return {.down = false, .east = true, .north = true, .south = false, .up = true, .west = true};
case 8565:
return {.down = false, .east = true, .north = true, .south = false, .up = true, .west = false};
case 8566:
return {.down = false, .east = true, .north = true, .south = false, .up = false, .west = true};
case 8567:
return {.down = false, .east = true, .north = true, .south = false, .up = false, .west = false};
case 8568:
return {.down = false, .east = true, .north = false, .south = true, .up = true, .west = true};
case 8569:
return {.down = false, .east = true, .north = false, .south = true, .up = true, .west = false};
case 8570:
return {.down = false, .east = true, .north = false, .south = true, .up = false, .west = true};
case 8571:
return {.down = false, .east = true, .north = false, .south = true, .up = false, .west = false};
case 8572:
return {.down = false, .east = true, .north = false, .south = false, .up = true, .west = true};
case 8573:
return {.down = false, .east = true, .north = false, .south = false, .up = true, .west = false};
case 8574:
return {.down = false, .east = true, .north = false, .south = false, .up = false, .west = true};
case 8575:
return {.down = false, .east = true, .north = false, .south = false, .up = false, .west = false};
case 8576:
return {.down = false, .east = false, .north = true, .south = true, .up = true, .west = true};
case 8577:
return {.down = false, .east = false, .north = true, .south = true, .up = true, .west = false};
case 8578:
return {.down = false, .east = false, .north = true, .south = true, .up = false, .west = true};
case 8579:
return {.down = false, .east = false, .north = true, .south = true, .up = false, .west = false};
case 8580:
return {.down = false, .east = false, .north = true, .south = false, .up = true, .west = true};
case 8581:
return {.down = false, .east = false, .north = true, .south = false, .up = true, .west = false};
case 8582:
return {.down = false, .east = false, .north = true, .south = false, .up = false, .west = true};
case 8583:
return {.down = false, .east = false, .north = true, .south = false, .up = false, .west = false};
case 8584:
return {.down = false, .east = false, .north = false, .south = true, .up = true, .west = true};
case 8585:
return {.down = false, .east = false, .north = false, .south = true, .up = true, .west = false};
case 8586:
return {.down = false, .east = false, .north = false, .south = true, .up = false, .west = true};
case 8587:
return {.down = false, .east = false, .north = false, .south = true, .up = false, .west = false};
case 8588:
return {.down = false, .east = false, .north = false, .south = false, .up = true, .west = true};
case 8589:
return {.down = false, .east = false, .north = false, .south = false, .up = true, .west = false};
case 8590:
return {.down = false, .east = false, .north = false, .south = false, .up = false, .west = true};
case 8591:
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
return "minecraft:chorus_plant:true:true:true:true:true:true";
case false:
return "minecraft:chorus_plant:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:true:true:true:true:false:true";
case false:
return "minecraft:chorus_plant:true:true:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:chorus_plant:true:true:true:false:true:true";
case false:
return "minecraft:chorus_plant:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:true:true:true:false:false:true";
case false:
return "minecraft:chorus_plant:true:true:true:false:false:false";
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
return "minecraft:chorus_plant:true:true:false:true:true:true";
case false:
return "minecraft:chorus_plant:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:true:true:false:true:false:true";
case false:
return "minecraft:chorus_plant:true:true:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:chorus_plant:true:true:false:false:true:true";
case false:
return "minecraft:chorus_plant:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:true:true:false:false:false:true";
case false:
return "minecraft:chorus_plant:true:true:false:false:false:false";
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
return "minecraft:chorus_plant:true:false:true:true:true:true";
case false:
return "minecraft:chorus_plant:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:true:false:true:true:false:true";
case false:
return "minecraft:chorus_plant:true:false:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:chorus_plant:true:false:true:false:true:true";
case false:
return "minecraft:chorus_plant:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:true:false:true:false:false:true";
case false:
return "minecraft:chorus_plant:true:false:true:false:false:false";
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
return "minecraft:chorus_plant:true:false:false:true:true:true";
case false:
return "minecraft:chorus_plant:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:true:false:false:true:false:true";
case false:
return "minecraft:chorus_plant:true:false:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:chorus_plant:true:false:false:false:true:true";
case false:
return "minecraft:chorus_plant:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:true:false:false:false:false:true";
case false:
return "minecraft:chorus_plant:true:false:false:false:false:false";
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
return "minecraft:chorus_plant:false:true:true:true:true:true";
case false:
return "minecraft:chorus_plant:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:false:true:true:true:false:true";
case false:
return "minecraft:chorus_plant:false:true:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:chorus_plant:false:true:true:false:true:true";
case false:
return "minecraft:chorus_plant:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:false:true:true:false:false:true";
case false:
return "minecraft:chorus_plant:false:true:true:false:false:false";
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
return "minecraft:chorus_plant:false:true:false:true:true:true";
case false:
return "minecraft:chorus_plant:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:false:true:false:true:false:true";
case false:
return "minecraft:chorus_plant:false:true:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:chorus_plant:false:true:false:false:true:true";
case false:
return "minecraft:chorus_plant:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:false:true:false:false:false:true";
case false:
return "minecraft:chorus_plant:false:true:false:false:false:false";
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
return "minecraft:chorus_plant:false:false:true:true:true:true";
case false:
return "minecraft:chorus_plant:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:false:false:true:true:false:true";
case false:
return "minecraft:chorus_plant:false:false:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:chorus_plant:false:false:true:false:true:true";
case false:
return "minecraft:chorus_plant:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:false:false:true:false:false:true";
case false:
return "minecraft:chorus_plant:false:false:true:false:false:false";
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
return "minecraft:chorus_plant:false:false:false:true:true:true";
case false:
return "minecraft:chorus_plant:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:false:false:false:true:false:true";
case false:
return "minecraft:chorus_plant:false:false:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:chorus_plant:false:false:false:false:true:true";
case false:
return "minecraft:chorus_plant:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:chorus_plant:false:false:false:false:false:true";
case false:
return "minecraft:chorus_plant:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
