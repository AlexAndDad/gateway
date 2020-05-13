#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dark_oak_door
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
return 8458;
case false:
return 8459;
}
case false:
switch (powered)
{
case true:
return 8460;
case false:
return 8461;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8462;
case false:
return 8463;
}
case false:
switch (powered)
{
case true:
return 8464;
case false:
return 8465;
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
return 8466;
case false:
return 8467;
}
case false:
switch (powered)
{
case true:
return 8468;
case false:
return 8469;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8470;
case false:
return 8471;
}
case false:
switch (powered)
{
case true:
return 8472;
case false:
return 8473;
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
return 8474;
case false:
return 8475;
}
case false:
switch (powered)
{
case true:
return 8476;
case false:
return 8477;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8478;
case false:
return 8479;
}
case false:
switch (powered)
{
case true:
return 8480;
case false:
return 8481;
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
return 8482;
case false:
return 8483;
}
case false:
switch (powered)
{
case true:
return 8484;
case false:
return 8485;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8486;
case false:
return 8487;
}
case false:
switch (powered)
{
case true:
return 8488;
case false:
return 8489;
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
return 8490;
case false:
return 8491;
}
case false:
switch (powered)
{
case true:
return 8492;
case false:
return 8493;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8494;
case false:
return 8495;
}
case false:
switch (powered)
{
case true:
return 8496;
case false:
return 8497;
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
return 8498;
case false:
return 8499;
}
case false:
switch (powered)
{
case true:
return 8500;
case false:
return 8501;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8502;
case false:
return 8503;
}
case false:
switch (powered)
{
case true:
return 8504;
case false:
return 8505;
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
return 8506;
case false:
return 8507;
}
case false:
switch (powered)
{
case true:
return 8508;
case false:
return 8509;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8510;
case false:
return 8511;
}
case false:
switch (powered)
{
case true:
return 8512;
case false:
return 8513;
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
return 8514;
case false:
return 8515;
}
case false:
switch (powered)
{
case true:
return 8516;
case false:
return 8517;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8518;
case false:
return 8519;
}
case false:
switch (powered)
{
case true:
return 8520;
case false:
return 8521;
}
}
}
}
}
}
constexpr static dark_oak_door from_id(block_id_type id)
{
switch (id)
{
case 8458:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8459:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8460:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8461:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8462:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8463:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8464:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8465:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8466:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8467:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8468:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8469:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8470:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8471:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8472:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8473:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8474:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8475:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8476:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8477:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8478:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8479:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8480:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8481:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8482:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8483:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8484:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8485:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8486:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8487:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8488:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8489:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8490:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8491:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8492:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8493:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8494:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8495:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8496:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8497:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8498:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8499:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8500:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8501:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8502:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8503:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8504:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8505:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8506:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8507:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8508:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8509:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8510:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8511:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8512:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8513:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8514:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8515:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8516:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8517:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8518:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8519:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8520:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8521:
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
return "minecraft:dark_oak_door:north:upper:left:true:true";
case false:
return "minecraft:dark_oak_door:north:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:north:upper:left:false:true";
case false:
return "minecraft:dark_oak_door:north:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:north:upper:right:true:true";
case false:
return "minecraft:dark_oak_door:north:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:north:upper:right:false:true";
case false:
return "minecraft:dark_oak_door:north:upper:right:false:false";
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
return "minecraft:dark_oak_door:north:lower:left:true:true";
case false:
return "minecraft:dark_oak_door:north:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:north:lower:left:false:true";
case false:
return "minecraft:dark_oak_door:north:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:north:lower:right:true:true";
case false:
return "minecraft:dark_oak_door:north:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:north:lower:right:false:true";
case false:
return "minecraft:dark_oak_door:north:lower:right:false:false";
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
return "minecraft:dark_oak_door:south:upper:left:true:true";
case false:
return "minecraft:dark_oak_door:south:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:south:upper:left:false:true";
case false:
return "minecraft:dark_oak_door:south:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:south:upper:right:true:true";
case false:
return "minecraft:dark_oak_door:south:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:south:upper:right:false:true";
case false:
return "minecraft:dark_oak_door:south:upper:right:false:false";
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
return "minecraft:dark_oak_door:south:lower:left:true:true";
case false:
return "minecraft:dark_oak_door:south:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:south:lower:left:false:true";
case false:
return "minecraft:dark_oak_door:south:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:south:lower:right:true:true";
case false:
return "minecraft:dark_oak_door:south:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:south:lower:right:false:true";
case false:
return "minecraft:dark_oak_door:south:lower:right:false:false";
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
return "minecraft:dark_oak_door:west:upper:left:true:true";
case false:
return "minecraft:dark_oak_door:west:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:west:upper:left:false:true";
case false:
return "minecraft:dark_oak_door:west:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:west:upper:right:true:true";
case false:
return "minecraft:dark_oak_door:west:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:west:upper:right:false:true";
case false:
return "minecraft:dark_oak_door:west:upper:right:false:false";
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
return "minecraft:dark_oak_door:west:lower:left:true:true";
case false:
return "minecraft:dark_oak_door:west:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:west:lower:left:false:true";
case false:
return "minecraft:dark_oak_door:west:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:west:lower:right:true:true";
case false:
return "minecraft:dark_oak_door:west:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:west:lower:right:false:true";
case false:
return "minecraft:dark_oak_door:west:lower:right:false:false";
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
return "minecraft:dark_oak_door:east:upper:left:true:true";
case false:
return "minecraft:dark_oak_door:east:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:east:upper:left:false:true";
case false:
return "minecraft:dark_oak_door:east:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:east:upper:right:true:true";
case false:
return "minecraft:dark_oak_door:east:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:east:upper:right:false:true";
case false:
return "minecraft:dark_oak_door:east:upper:right:false:false";
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
return "minecraft:dark_oak_door:east:lower:left:true:true";
case false:
return "minecraft:dark_oak_door:east:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:east:lower:left:false:true";
case false:
return "minecraft:dark_oak_door:east:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:east:lower:right:true:true";
case false:
return "minecraft:dark_oak_door:east:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:dark_oak_door:east:lower:right:false:true";
case false:
return "minecraft:dark_oak_door:east:lower:right:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
