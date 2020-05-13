#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct spruce_sign
{std::uint8_t rotation = 0;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
switch (waterlogged)
{
case true:
return 3411;
case false:
return 3412;
}
case 1:
switch (waterlogged)
{
case true:
return 3413;
case false:
return 3414;
}
case 2:
switch (waterlogged)
{
case true:
return 3415;
case false:
return 3416;
}
case 3:
switch (waterlogged)
{
case true:
return 3417;
case false:
return 3418;
}
case 4:
switch (waterlogged)
{
case true:
return 3419;
case false:
return 3420;
}
case 5:
switch (waterlogged)
{
case true:
return 3421;
case false:
return 3422;
}
case 6:
switch (waterlogged)
{
case true:
return 3423;
case false:
return 3424;
}
case 7:
switch (waterlogged)
{
case true:
return 3425;
case false:
return 3426;
}
case 8:
switch (waterlogged)
{
case true:
return 3427;
case false:
return 3428;
}
case 9:
switch (waterlogged)
{
case true:
return 3429;
case false:
return 3430;
}
case 10:
switch (waterlogged)
{
case true:
return 3431;
case false:
return 3432;
}
case 11:
switch (waterlogged)
{
case true:
return 3433;
case false:
return 3434;
}
case 12:
switch (waterlogged)
{
case true:
return 3435;
case false:
return 3436;
}
case 13:
switch (waterlogged)
{
case true:
return 3437;
case false:
return 3438;
}
case 14:
switch (waterlogged)
{
case true:
return 3439;
case false:
return 3440;
}
case 15:
switch (waterlogged)
{
case true:
return 3441;
case false:
return 3442;
}
}
}
constexpr static spruce_sign from_id(block_id_type id)
{
switch (id)
{
case 3411:
return {.rotation = 0, .waterlogged = true};
case 3412:
return {.rotation = 0, .waterlogged = false};
case 3413:
return {.rotation = 1, .waterlogged = true};
case 3414:
return {.rotation = 1, .waterlogged = false};
case 3415:
return {.rotation = 2, .waterlogged = true};
case 3416:
return {.rotation = 2, .waterlogged = false};
case 3417:
return {.rotation = 3, .waterlogged = true};
case 3418:
return {.rotation = 3, .waterlogged = false};
case 3419:
return {.rotation = 4, .waterlogged = true};
case 3420:
return {.rotation = 4, .waterlogged = false};
case 3421:
return {.rotation = 5, .waterlogged = true};
case 3422:
return {.rotation = 5, .waterlogged = false};
case 3423:
return {.rotation = 6, .waterlogged = true};
case 3424:
return {.rotation = 6, .waterlogged = false};
case 3425:
return {.rotation = 7, .waterlogged = true};
case 3426:
return {.rotation = 7, .waterlogged = false};
case 3427:
return {.rotation = 8, .waterlogged = true};
case 3428:
return {.rotation = 8, .waterlogged = false};
case 3429:
return {.rotation = 9, .waterlogged = true};
case 3430:
return {.rotation = 9, .waterlogged = false};
case 3431:
return {.rotation = 10, .waterlogged = true};
case 3432:
return {.rotation = 10, .waterlogged = false};
case 3433:
return {.rotation = 11, .waterlogged = true};
case 3434:
return {.rotation = 11, .waterlogged = false};
case 3435:
return {.rotation = 12, .waterlogged = true};
case 3436:
return {.rotation = 12, .waterlogged = false};
case 3437:
return {.rotation = 13, .waterlogged = true};
case 3438:
return {.rotation = 13, .waterlogged = false};
case 3439:
return {.rotation = 14, .waterlogged = true};
case 3440:
return {.rotation = 14, .waterlogged = false};
case 3441:
return {.rotation = 15, .waterlogged = true};
case 3442:
return {.rotation = 15, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:0:true";
case false:
return "minecraft:spruce_sign:0:false";
}
case 1:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:1:true";
case false:
return "minecraft:spruce_sign:1:false";
}
case 2:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:2:true";
case false:
return "minecraft:spruce_sign:2:false";
}
case 3:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:3:true";
case false:
return "minecraft:spruce_sign:3:false";
}
case 4:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:4:true";
case false:
return "minecraft:spruce_sign:4:false";
}
case 5:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:5:true";
case false:
return "minecraft:spruce_sign:5:false";
}
case 6:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:6:true";
case false:
return "minecraft:spruce_sign:6:false";
}
case 7:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:7:true";
case false:
return "minecraft:spruce_sign:7:false";
}
case 8:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:8:true";
case false:
return "minecraft:spruce_sign:8:false";
}
case 9:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:9:true";
case false:
return "minecraft:spruce_sign:9:false";
}
case 10:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:10:true";
case false:
return "minecraft:spruce_sign:10:false";
}
case 11:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:11:true";
case false:
return "minecraft:spruce_sign:11:false";
}
case 12:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:12:true";
case false:
return "minecraft:spruce_sign:12:false";
}
case 13:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:13:true";
case false:
return "minecraft:spruce_sign:13:false";
}
case 14:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:14:true";
case false:
return "minecraft:spruce_sign:14:false";
}
case 15:
switch (waterlogged)
{
case true:
return "minecraft:spruce_sign:15:true";
case false:
return "minecraft:spruce_sign:15:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
