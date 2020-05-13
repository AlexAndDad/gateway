#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct acacia_door
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
return 8394;
case false:
return 8395;
}
case false:
switch (powered)
{
case true:
return 8396;
case false:
return 8397;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8398;
case false:
return 8399;
}
case false:
switch (powered)
{
case true:
return 8400;
case false:
return 8401;
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
return 8402;
case false:
return 8403;
}
case false:
switch (powered)
{
case true:
return 8404;
case false:
return 8405;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8406;
case false:
return 8407;
}
case false:
switch (powered)
{
case true:
return 8408;
case false:
return 8409;
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
return 8410;
case false:
return 8411;
}
case false:
switch (powered)
{
case true:
return 8412;
case false:
return 8413;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8414;
case false:
return 8415;
}
case false:
switch (powered)
{
case true:
return 8416;
case false:
return 8417;
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
return 8418;
case false:
return 8419;
}
case false:
switch (powered)
{
case true:
return 8420;
case false:
return 8421;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8422;
case false:
return 8423;
}
case false:
switch (powered)
{
case true:
return 8424;
case false:
return 8425;
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
return 8426;
case false:
return 8427;
}
case false:
switch (powered)
{
case true:
return 8428;
case false:
return 8429;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8430;
case false:
return 8431;
}
case false:
switch (powered)
{
case true:
return 8432;
case false:
return 8433;
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
return 8434;
case false:
return 8435;
}
case false:
switch (powered)
{
case true:
return 8436;
case false:
return 8437;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8438;
case false:
return 8439;
}
case false:
switch (powered)
{
case true:
return 8440;
case false:
return 8441;
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
return 8442;
case false:
return 8443;
}
case false:
switch (powered)
{
case true:
return 8444;
case false:
return 8445;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8446;
case false:
return 8447;
}
case false:
switch (powered)
{
case true:
return 8448;
case false:
return 8449;
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
return 8450;
case false:
return 8451;
}
case false:
switch (powered)
{
case true:
return 8452;
case false:
return 8453;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8454;
case false:
return 8455;
}
case false:
switch (powered)
{
case true:
return 8456;
case false:
return 8457;
}
}
}
}
}
}
constexpr static acacia_door from_id(block_id_type id)
{
switch (id)
{
case 8394:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8395:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8396:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8397:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8398:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8399:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8400:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8401:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8402:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8403:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8404:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8405:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8406:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8407:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8408:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8409:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8410:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8411:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8412:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8413:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8414:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8415:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8416:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8417:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8418:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8419:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8420:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8421:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8422:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8423:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8424:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8425:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8426:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8427:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8428:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8429:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8430:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8431:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8432:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8433:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8434:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8435:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8436:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8437:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8438:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8439:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8440:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8441:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8442:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8443:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8444:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8445:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8446:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8447:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8448:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8449:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8450:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8451:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8452:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8453:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8454:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8455:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8456:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8457:
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
return "minecraft:acacia_door:north:upper:left:true:true";
case false:
return "minecraft:acacia_door:north:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:north:upper:left:false:true";
case false:
return "minecraft:acacia_door:north:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:acacia_door:north:upper:right:true:true";
case false:
return "minecraft:acacia_door:north:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:north:upper:right:false:true";
case false:
return "minecraft:acacia_door:north:upper:right:false:false";
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
return "minecraft:acacia_door:north:lower:left:true:true";
case false:
return "minecraft:acacia_door:north:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:north:lower:left:false:true";
case false:
return "minecraft:acacia_door:north:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:acacia_door:north:lower:right:true:true";
case false:
return "minecraft:acacia_door:north:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:north:lower:right:false:true";
case false:
return "minecraft:acacia_door:north:lower:right:false:false";
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
return "minecraft:acacia_door:south:upper:left:true:true";
case false:
return "minecraft:acacia_door:south:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:south:upper:left:false:true";
case false:
return "minecraft:acacia_door:south:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:acacia_door:south:upper:right:true:true";
case false:
return "minecraft:acacia_door:south:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:south:upper:right:false:true";
case false:
return "minecraft:acacia_door:south:upper:right:false:false";
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
return "minecraft:acacia_door:south:lower:left:true:true";
case false:
return "minecraft:acacia_door:south:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:south:lower:left:false:true";
case false:
return "minecraft:acacia_door:south:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:acacia_door:south:lower:right:true:true";
case false:
return "minecraft:acacia_door:south:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:south:lower:right:false:true";
case false:
return "minecraft:acacia_door:south:lower:right:false:false";
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
return "minecraft:acacia_door:west:upper:left:true:true";
case false:
return "minecraft:acacia_door:west:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:west:upper:left:false:true";
case false:
return "minecraft:acacia_door:west:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:acacia_door:west:upper:right:true:true";
case false:
return "minecraft:acacia_door:west:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:west:upper:right:false:true";
case false:
return "minecraft:acacia_door:west:upper:right:false:false";
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
return "minecraft:acacia_door:west:lower:left:true:true";
case false:
return "minecraft:acacia_door:west:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:west:lower:left:false:true";
case false:
return "minecraft:acacia_door:west:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:acacia_door:west:lower:right:true:true";
case false:
return "minecraft:acacia_door:west:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:west:lower:right:false:true";
case false:
return "minecraft:acacia_door:west:lower:right:false:false";
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
return "minecraft:acacia_door:east:upper:left:true:true";
case false:
return "minecraft:acacia_door:east:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:east:upper:left:false:true";
case false:
return "minecraft:acacia_door:east:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:acacia_door:east:upper:right:true:true";
case false:
return "minecraft:acacia_door:east:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:east:upper:right:false:true";
case false:
return "minecraft:acacia_door:east:upper:right:false:false";
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
return "minecraft:acacia_door:east:lower:left:true:true";
case false:
return "minecraft:acacia_door:east:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:east:lower:left:false:true";
case false:
return "minecraft:acacia_door:east:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:acacia_door:east:lower:right:true:true";
case false:
return "minecraft:acacia_door:east:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:acacia_door:east:lower:right:false:true";
case false:
return "minecraft:acacia_door:east:lower:right:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
