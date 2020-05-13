#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct red_mushroom_block
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
return 4555;
case false:
return 4556;
}
case false:
switch (west)
{
case true:
return 4557;
case false:
return 4558;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4559;
case false:
return 4560;
}
case false:
switch (west)
{
case true:
return 4561;
case false:
return 4562;
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
return 4563;
case false:
return 4564;
}
case false:
switch (west)
{
case true:
return 4565;
case false:
return 4566;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4567;
case false:
return 4568;
}
case false:
switch (west)
{
case true:
return 4569;
case false:
return 4570;
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
return 4571;
case false:
return 4572;
}
case false:
switch (west)
{
case true:
return 4573;
case false:
return 4574;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4575;
case false:
return 4576;
}
case false:
switch (west)
{
case true:
return 4577;
case false:
return 4578;
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
return 4579;
case false:
return 4580;
}
case false:
switch (west)
{
case true:
return 4581;
case false:
return 4582;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4583;
case false:
return 4584;
}
case false:
switch (west)
{
case true:
return 4585;
case false:
return 4586;
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
return 4587;
case false:
return 4588;
}
case false:
switch (west)
{
case true:
return 4589;
case false:
return 4590;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4591;
case false:
return 4592;
}
case false:
switch (west)
{
case true:
return 4593;
case false:
return 4594;
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
return 4595;
case false:
return 4596;
}
case false:
switch (west)
{
case true:
return 4597;
case false:
return 4598;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4599;
case false:
return 4600;
}
case false:
switch (west)
{
case true:
return 4601;
case false:
return 4602;
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
return 4603;
case false:
return 4604;
}
case false:
switch (west)
{
case true:
return 4605;
case false:
return 4606;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4607;
case false:
return 4608;
}
case false:
switch (west)
{
case true:
return 4609;
case false:
return 4610;
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
return 4611;
case false:
return 4612;
}
case false:
switch (west)
{
case true:
return 4613;
case false:
return 4614;
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return 4615;
case false:
return 4616;
}
case false:
switch (west)
{
case true:
return 4617;
case false:
return 4618;
}
}
}
}
}
}
}
constexpr static red_mushroom_block from_id(block_id_type id)
{
switch (id)
{
case 4555:
return {.down = true, .east = true, .north = true, .south = true, .up = true, .west = true};
case 4556:
return {.down = true, .east = true, .north = true, .south = true, .up = true, .west = false};
case 4557:
return {.down = true, .east = true, .north = true, .south = true, .up = false, .west = true};
case 4558:
return {.down = true, .east = true, .north = true, .south = true, .up = false, .west = false};
case 4559:
return {.down = true, .east = true, .north = true, .south = false, .up = true, .west = true};
case 4560:
return {.down = true, .east = true, .north = true, .south = false, .up = true, .west = false};
case 4561:
return {.down = true, .east = true, .north = true, .south = false, .up = false, .west = true};
case 4562:
return {.down = true, .east = true, .north = true, .south = false, .up = false, .west = false};
case 4563:
return {.down = true, .east = true, .north = false, .south = true, .up = true, .west = true};
case 4564:
return {.down = true, .east = true, .north = false, .south = true, .up = true, .west = false};
case 4565:
return {.down = true, .east = true, .north = false, .south = true, .up = false, .west = true};
case 4566:
return {.down = true, .east = true, .north = false, .south = true, .up = false, .west = false};
case 4567:
return {.down = true, .east = true, .north = false, .south = false, .up = true, .west = true};
case 4568:
return {.down = true, .east = true, .north = false, .south = false, .up = true, .west = false};
case 4569:
return {.down = true, .east = true, .north = false, .south = false, .up = false, .west = true};
case 4570:
return {.down = true, .east = true, .north = false, .south = false, .up = false, .west = false};
case 4571:
return {.down = true, .east = false, .north = true, .south = true, .up = true, .west = true};
case 4572:
return {.down = true, .east = false, .north = true, .south = true, .up = true, .west = false};
case 4573:
return {.down = true, .east = false, .north = true, .south = true, .up = false, .west = true};
case 4574:
return {.down = true, .east = false, .north = true, .south = true, .up = false, .west = false};
case 4575:
return {.down = true, .east = false, .north = true, .south = false, .up = true, .west = true};
case 4576:
return {.down = true, .east = false, .north = true, .south = false, .up = true, .west = false};
case 4577:
return {.down = true, .east = false, .north = true, .south = false, .up = false, .west = true};
case 4578:
return {.down = true, .east = false, .north = true, .south = false, .up = false, .west = false};
case 4579:
return {.down = true, .east = false, .north = false, .south = true, .up = true, .west = true};
case 4580:
return {.down = true, .east = false, .north = false, .south = true, .up = true, .west = false};
case 4581:
return {.down = true, .east = false, .north = false, .south = true, .up = false, .west = true};
case 4582:
return {.down = true, .east = false, .north = false, .south = true, .up = false, .west = false};
case 4583:
return {.down = true, .east = false, .north = false, .south = false, .up = true, .west = true};
case 4584:
return {.down = true, .east = false, .north = false, .south = false, .up = true, .west = false};
case 4585:
return {.down = true, .east = false, .north = false, .south = false, .up = false, .west = true};
case 4586:
return {.down = true, .east = false, .north = false, .south = false, .up = false, .west = false};
case 4587:
return {.down = false, .east = true, .north = true, .south = true, .up = true, .west = true};
case 4588:
return {.down = false, .east = true, .north = true, .south = true, .up = true, .west = false};
case 4589:
return {.down = false, .east = true, .north = true, .south = true, .up = false, .west = true};
case 4590:
return {.down = false, .east = true, .north = true, .south = true, .up = false, .west = false};
case 4591:
return {.down = false, .east = true, .north = true, .south = false, .up = true, .west = true};
case 4592:
return {.down = false, .east = true, .north = true, .south = false, .up = true, .west = false};
case 4593:
return {.down = false, .east = true, .north = true, .south = false, .up = false, .west = true};
case 4594:
return {.down = false, .east = true, .north = true, .south = false, .up = false, .west = false};
case 4595:
return {.down = false, .east = true, .north = false, .south = true, .up = true, .west = true};
case 4596:
return {.down = false, .east = true, .north = false, .south = true, .up = true, .west = false};
case 4597:
return {.down = false, .east = true, .north = false, .south = true, .up = false, .west = true};
case 4598:
return {.down = false, .east = true, .north = false, .south = true, .up = false, .west = false};
case 4599:
return {.down = false, .east = true, .north = false, .south = false, .up = true, .west = true};
case 4600:
return {.down = false, .east = true, .north = false, .south = false, .up = true, .west = false};
case 4601:
return {.down = false, .east = true, .north = false, .south = false, .up = false, .west = true};
case 4602:
return {.down = false, .east = true, .north = false, .south = false, .up = false, .west = false};
case 4603:
return {.down = false, .east = false, .north = true, .south = true, .up = true, .west = true};
case 4604:
return {.down = false, .east = false, .north = true, .south = true, .up = true, .west = false};
case 4605:
return {.down = false, .east = false, .north = true, .south = true, .up = false, .west = true};
case 4606:
return {.down = false, .east = false, .north = true, .south = true, .up = false, .west = false};
case 4607:
return {.down = false, .east = false, .north = true, .south = false, .up = true, .west = true};
case 4608:
return {.down = false, .east = false, .north = true, .south = false, .up = true, .west = false};
case 4609:
return {.down = false, .east = false, .north = true, .south = false, .up = false, .west = true};
case 4610:
return {.down = false, .east = false, .north = true, .south = false, .up = false, .west = false};
case 4611:
return {.down = false, .east = false, .north = false, .south = true, .up = true, .west = true};
case 4612:
return {.down = false, .east = false, .north = false, .south = true, .up = true, .west = false};
case 4613:
return {.down = false, .east = false, .north = false, .south = true, .up = false, .west = true};
case 4614:
return {.down = false, .east = false, .north = false, .south = true, .up = false, .west = false};
case 4615:
return {.down = false, .east = false, .north = false, .south = false, .up = true, .west = true};
case 4616:
return {.down = false, .east = false, .north = false, .south = false, .up = true, .west = false};
case 4617:
return {.down = false, .east = false, .north = false, .south = false, .up = false, .west = true};
case 4618:
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
return "minecraft:red_mushroom_block:true:true:true:true:true:true";
case false:
return "minecraft:red_mushroom_block:true:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:true:true:true:true:false:true";
case false:
return "minecraft:red_mushroom_block:true:true:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:true:true:true:false:true:true";
case false:
return "minecraft:red_mushroom_block:true:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:true:true:true:false:false:true";
case false:
return "minecraft:red_mushroom_block:true:true:true:false:false:false";
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
return "minecraft:red_mushroom_block:true:true:false:true:true:true";
case false:
return "minecraft:red_mushroom_block:true:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:true:true:false:true:false:true";
case false:
return "minecraft:red_mushroom_block:true:true:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:true:true:false:false:true:true";
case false:
return "minecraft:red_mushroom_block:true:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:true:true:false:false:false:true";
case false:
return "minecraft:red_mushroom_block:true:true:false:false:false:false";
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
return "minecraft:red_mushroom_block:true:false:true:true:true:true";
case false:
return "minecraft:red_mushroom_block:true:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:true:false:true:true:false:true";
case false:
return "minecraft:red_mushroom_block:true:false:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:true:false:true:false:true:true";
case false:
return "minecraft:red_mushroom_block:true:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:true:false:true:false:false:true";
case false:
return "minecraft:red_mushroom_block:true:false:true:false:false:false";
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
return "minecraft:red_mushroom_block:true:false:false:true:true:true";
case false:
return "minecraft:red_mushroom_block:true:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:true:false:false:true:false:true";
case false:
return "minecraft:red_mushroom_block:true:false:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:true:false:false:false:true:true";
case false:
return "minecraft:red_mushroom_block:true:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:true:false:false:false:false:true";
case false:
return "minecraft:red_mushroom_block:true:false:false:false:false:false";
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
return "minecraft:red_mushroom_block:false:true:true:true:true:true";
case false:
return "minecraft:red_mushroom_block:false:true:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:false:true:true:true:false:true";
case false:
return "minecraft:red_mushroom_block:false:true:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:false:true:true:false:true:true";
case false:
return "minecraft:red_mushroom_block:false:true:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:false:true:true:false:false:true";
case false:
return "minecraft:red_mushroom_block:false:true:true:false:false:false";
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
return "minecraft:red_mushroom_block:false:true:false:true:true:true";
case false:
return "minecraft:red_mushroom_block:false:true:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:false:true:false:true:false:true";
case false:
return "minecraft:red_mushroom_block:false:true:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:false:true:false:false:true:true";
case false:
return "minecraft:red_mushroom_block:false:true:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:false:true:false:false:false:true";
case false:
return "minecraft:red_mushroom_block:false:true:false:false:false:false";
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
return "minecraft:red_mushroom_block:false:false:true:true:true:true";
case false:
return "minecraft:red_mushroom_block:false:false:true:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:false:false:true:true:false:true";
case false:
return "minecraft:red_mushroom_block:false:false:true:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:false:false:true:false:true:true";
case false:
return "minecraft:red_mushroom_block:false:false:true:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:false:false:true:false:false:true";
case false:
return "minecraft:red_mushroom_block:false:false:true:false:false:false";
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
return "minecraft:red_mushroom_block:false:false:false:true:true:true";
case false:
return "minecraft:red_mushroom_block:false:false:false:true:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:false:false:false:true:false:true";
case false:
return "minecraft:red_mushroom_block:false:false:false:true:false:false";
}
}
case false:
switch (up)
{
case true:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:false:false:false:false:true:true";
case false:
return "minecraft:red_mushroom_block:false:false:false:false:true:false";
}
case false:
switch (west)
{
case true:
return "minecraft:red_mushroom_block:false:false:false:false:false:true";
case false:
return "minecraft:red_mushroom_block:false:false:false:false:false:false";
}
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
