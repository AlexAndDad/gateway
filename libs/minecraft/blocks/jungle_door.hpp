#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jungle_door
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
return 8330;
case false:
return 8331;
}
case false:
switch (powered)
{
case true:
return 8332;
case false:
return 8333;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8334;
case false:
return 8335;
}
case false:
switch (powered)
{
case true:
return 8336;
case false:
return 8337;
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
return 8338;
case false:
return 8339;
}
case false:
switch (powered)
{
case true:
return 8340;
case false:
return 8341;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8342;
case false:
return 8343;
}
case false:
switch (powered)
{
case true:
return 8344;
case false:
return 8345;
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
return 8346;
case false:
return 8347;
}
case false:
switch (powered)
{
case true:
return 8348;
case false:
return 8349;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8350;
case false:
return 8351;
}
case false:
switch (powered)
{
case true:
return 8352;
case false:
return 8353;
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
return 8354;
case false:
return 8355;
}
case false:
switch (powered)
{
case true:
return 8356;
case false:
return 8357;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8358;
case false:
return 8359;
}
case false:
switch (powered)
{
case true:
return 8360;
case false:
return 8361;
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
return 8362;
case false:
return 8363;
}
case false:
switch (powered)
{
case true:
return 8364;
case false:
return 8365;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8366;
case false:
return 8367;
}
case false:
switch (powered)
{
case true:
return 8368;
case false:
return 8369;
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
return 8370;
case false:
return 8371;
}
case false:
switch (powered)
{
case true:
return 8372;
case false:
return 8373;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8374;
case false:
return 8375;
}
case false:
switch (powered)
{
case true:
return 8376;
case false:
return 8377;
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
return 8378;
case false:
return 8379;
}
case false:
switch (powered)
{
case true:
return 8380;
case false:
return 8381;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8382;
case false:
return 8383;
}
case false:
switch (powered)
{
case true:
return 8384;
case false:
return 8385;
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
return 8386;
case false:
return 8387;
}
case false:
switch (powered)
{
case true:
return 8388;
case false:
return 8389;
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return 8390;
case false:
return 8391;
}
case false:
switch (powered)
{
case true:
return 8392;
case false:
return 8393;
}
}
}
}
}
}
constexpr static jungle_door from_id(block_id_type id)
{
switch (id)
{
case 8330:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8331:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8332:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8333:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8334:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8335:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8336:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8337:
return {.facing = facing_type::north, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8338:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8339:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8340:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8341:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8342:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8343:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8344:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8345:
return {.facing = facing_type::north, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8346:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8347:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8348:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8349:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8350:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8351:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8352:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8353:
return {.facing = facing_type::south, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8354:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8355:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8356:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8357:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8358:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8359:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8360:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8361:
return {.facing = facing_type::south, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8362:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8363:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8364:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8365:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8366:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8367:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8368:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8369:
return {.facing = facing_type::west, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8370:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8371:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8372:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8373:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8374:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8375:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8376:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8377:
return {.facing = facing_type::west, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = false};
case 8378:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = true};
case 8379:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = true, .powered = false};
case 8380:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = true};
case 8381:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::left, .open = false, .powered = false};
case 8382:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = true};
case 8383:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = true, .powered = false};
case 8384:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = true};
case 8385:
return {.facing = facing_type::east, .half = half_type::upper, .hinge = hinge_type::right, .open = false, .powered = false};
case 8386:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = true};
case 8387:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = true, .powered = false};
case 8388:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = true};
case 8389:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::left, .open = false, .powered = false};
case 8390:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = true};
case 8391:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = true, .powered = false};
case 8392:
return {.facing = facing_type::east, .half = half_type::lower, .hinge = hinge_type::right, .open = false, .powered = true};
case 8393:
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
return "minecraft:jungle_door:north:upper:left:true:true";
case false:
return "minecraft:jungle_door:north:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:north:upper:left:false:true";
case false:
return "minecraft:jungle_door:north:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:jungle_door:north:upper:right:true:true";
case false:
return "minecraft:jungle_door:north:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:north:upper:right:false:true";
case false:
return "minecraft:jungle_door:north:upper:right:false:false";
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
return "minecraft:jungle_door:north:lower:left:true:true";
case false:
return "minecraft:jungle_door:north:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:north:lower:left:false:true";
case false:
return "minecraft:jungle_door:north:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:jungle_door:north:lower:right:true:true";
case false:
return "minecraft:jungle_door:north:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:north:lower:right:false:true";
case false:
return "minecraft:jungle_door:north:lower:right:false:false";
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
return "minecraft:jungle_door:south:upper:left:true:true";
case false:
return "minecraft:jungle_door:south:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:south:upper:left:false:true";
case false:
return "minecraft:jungle_door:south:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:jungle_door:south:upper:right:true:true";
case false:
return "minecraft:jungle_door:south:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:south:upper:right:false:true";
case false:
return "minecraft:jungle_door:south:upper:right:false:false";
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
return "minecraft:jungle_door:south:lower:left:true:true";
case false:
return "minecraft:jungle_door:south:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:south:lower:left:false:true";
case false:
return "minecraft:jungle_door:south:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:jungle_door:south:lower:right:true:true";
case false:
return "minecraft:jungle_door:south:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:south:lower:right:false:true";
case false:
return "minecraft:jungle_door:south:lower:right:false:false";
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
return "minecraft:jungle_door:west:upper:left:true:true";
case false:
return "minecraft:jungle_door:west:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:west:upper:left:false:true";
case false:
return "minecraft:jungle_door:west:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:jungle_door:west:upper:right:true:true";
case false:
return "minecraft:jungle_door:west:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:west:upper:right:false:true";
case false:
return "minecraft:jungle_door:west:upper:right:false:false";
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
return "minecraft:jungle_door:west:lower:left:true:true";
case false:
return "minecraft:jungle_door:west:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:west:lower:left:false:true";
case false:
return "minecraft:jungle_door:west:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:jungle_door:west:lower:right:true:true";
case false:
return "minecraft:jungle_door:west:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:west:lower:right:false:true";
case false:
return "minecraft:jungle_door:west:lower:right:false:false";
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
return "minecraft:jungle_door:east:upper:left:true:true";
case false:
return "minecraft:jungle_door:east:upper:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:east:upper:left:false:true";
case false:
return "minecraft:jungle_door:east:upper:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:jungle_door:east:upper:right:true:true";
case false:
return "minecraft:jungle_door:east:upper:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:east:upper:right:false:true";
case false:
return "minecraft:jungle_door:east:upper:right:false:false";
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
return "minecraft:jungle_door:east:lower:left:true:true";
case false:
return "minecraft:jungle_door:east:lower:left:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:east:lower:left:false:true";
case false:
return "minecraft:jungle_door:east:lower:left:false:false";
}
}
case hinge_type::right:
switch (open)
{
case true:
switch (powered)
{
case true:
return "minecraft:jungle_door:east:lower:right:true:true";
case false:
return "minecraft:jungle_door:east:lower:right:true:false";
}
case false:
switch (powered)
{
case true:
return "minecraft:jungle_door:east:lower:right:false:true";
case false:
return "minecraft:jungle_door:east:lower:right:false:false";
}
}
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
