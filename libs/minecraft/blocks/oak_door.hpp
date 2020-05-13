#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct oak_door
{enum class facing_type : std::uint8_t
{
north,
south,
west,
east
} facing = facing_type::north;
enum class half_type : std::uint8_t
{
upper,
lower
} half = half_type::lower;
enum class hinge_type : std::uint8_t
{
left,
right
} hinge = hinge_type::left;
bool open = false;
bool powered = false;
constexpr block_id_type to_id() const {
switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3571;
case false:
return 3572;
}
case false:
switch (powered)
{
case true:
return 3573;
case false:
return 3574;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3575;
case false:
return 3576;
}
case false:
switch (powered)
{
case true:
return 3577;
case false:
return 3578;
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3579;
case false:
return 3580;
}
case false:
switch (powered)
{
case true:
return 3581;
case false:
return 3582;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3583;
case false:
return 3584;
}
case false:
switch (powered)
{
case true:
return 3585;
case false:
return 3586;
}
}
}
}
case facing_type::south:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3587;
case false:
return 3588;
}
case false:
switch (powered)
{
case true:
return 3589;
case false:
return 3590;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3591;
case false:
return 3592;
}
case false:
switch (powered)
{
case true:
return 3593;
case false:
return 3594;
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3595;
case false:
return 3596;
}
case false:
switch (powered)
{
case true:
return 3597;
case false:
return 3598;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3599;
case false:
return 3600;
}
case false:
switch (powered)
{
case true:
return 3601;
case false:
return 3602;
}
}
}
}
case facing_type::west:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3603;
case false:
return 3604;
}
case false:
switch (powered)
{
case true:
return 3605;
case false:
return 3606;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3607;
case false:
return 3608;
}
case false:
switch (powered)
{
case true:
return 3609;
case false:
return 3610;
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3611;
case false:
return 3612;
}
case false:
switch (powered)
{
case true:
return 3613;
case false:
return 3614;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3615;
case false:
return 3616;
}
case false:
switch (powered)
{
case true:
return 3617;
case false:
return 3618;
}
}
}
}
case facing_type::east:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3619;
case false:
return 3620;
}
case false:
switch (powered)
{
case true:
return 3621;
case false:
return 3622;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3623;
case false:
return 3624;
}
case false:
switch (powered)
{
case true:
return 3625;
case false:
return 3626;
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3627;
case false:
return 3628;
}
case false:
switch (powered)
{
case true:
return 3629;
case false:
return 3630;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 3631;
case false:
return 3632;
}
case false:
switch (powered)
{
case true:
return 3633;
case false:
return 3634;
}
}
}
}
}
}
constexpr static oak_door from_id(block_id_type id)
{
switch (id)
{
case 3571:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 3572:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 3573:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 3574:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 3575:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 3576:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 3577:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 3578:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 3579:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 3580:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 3581:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 3582:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 3583:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 3584:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 3585:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 3586:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 3587:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 3588:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 3589:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 3590:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 3591:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 3592:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 3593:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 3594:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 3595:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 3596:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 3597:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 3598:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 3599:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 3600:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 3601:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 3602:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 3603:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 3604:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 3605:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 3606:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 3607:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 3608:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 3609:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 3610:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 3611:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 3612:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 3613:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 3614:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 3615:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 3616:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 3617:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 3618:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 3619:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 3620:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 3621:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 3622:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 3623:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 3624:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 3625:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 3626:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 3627:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 3628:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 3629:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 3630:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 3631:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 3632:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 3633:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 3634:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
}}
constexpr std::string_view to_string() const
{switch (facing)
{
case facing_type::north:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:north:upper:left:true:true";
case false:
return "minecraft:oak_door:north:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:north:upper:left:false:true";
case false:
return "minecraft:oak_door:north:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:north:upper:right:true:true";
case false:
return "minecraft:oak_door:north:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:north:upper:right:false:true";
case false:
return "minecraft:oak_door:north:upper:right:false:false";
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:north:lower:left:true:true";
case false:
return "minecraft:oak_door:north:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:north:lower:left:false:true";
case false:
return "minecraft:oak_door:north:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:north:lower:right:true:true";
case false:
return "minecraft:oak_door:north:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:north:lower:right:false:true";
case false:
return "minecraft:oak_door:north:lower:right:false:false";
}
}
}
}
case facing_type::south:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:south:upper:left:true:true";
case false:
return "minecraft:oak_door:south:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:south:upper:left:false:true";
case false:
return "minecraft:oak_door:south:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:south:upper:right:true:true";
case false:
return "minecraft:oak_door:south:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:south:upper:right:false:true";
case false:
return "minecraft:oak_door:south:upper:right:false:false";
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:south:lower:left:true:true";
case false:
return "minecraft:oak_door:south:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:south:lower:left:false:true";
case false:
return "minecraft:oak_door:south:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:south:lower:right:true:true";
case false:
return "minecraft:oak_door:south:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:south:lower:right:false:true";
case false:
return "minecraft:oak_door:south:lower:right:false:false";
}
}
}
}
case facing_type::west:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:west:upper:left:true:true";
case false:
return "minecraft:oak_door:west:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:west:upper:left:false:true";
case false:
return "minecraft:oak_door:west:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:west:upper:right:true:true";
case false:
return "minecraft:oak_door:west:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:west:upper:right:false:true";
case false:
return "minecraft:oak_door:west:upper:right:false:false";
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:west:lower:left:true:true";
case false:
return "minecraft:oak_door:west:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:west:lower:left:false:true";
case false:
return "minecraft:oak_door:west:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:west:lower:right:true:true";
case false:
return "minecraft:oak_door:west:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:west:lower:right:false:true";
case false:
return "minecraft:oak_door:west:lower:right:false:false";
}
}
}
}
case facing_type::east:
switch (half)
{
case half_type::upper:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:east:upper:left:true:true";
case false:
return "minecraft:oak_door:east:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:east:upper:left:false:true";
case false:
return "minecraft:oak_door:east:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:east:upper:right:true:true";
case false:
return "minecraft:oak_door:east:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:east:upper:right:false:true";
case false:
return "minecraft:oak_door:east:upper:right:false:false";
}
}
}
case half_type::lower:
switch (hinge)
{
case hinge_type::left:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:east:lower:left:true:true";
case false:
return "minecraft:oak_door:east:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:east:lower:left:false:true";
case false:
return "minecraft:oak_door:east:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:oak_door:east:lower:right:true:true";
case false:
return "minecraft:oak_door:east:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:oak_door:east:lower:right:false:true";
case false:
return "minecraft:oak_door:east:lower:right:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
