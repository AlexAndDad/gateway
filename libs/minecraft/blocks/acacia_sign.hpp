#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct acacia_sign
{std::uint8_t rotation = 0;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
switch (waterlogged)
{
case true:
return 3475;
case false:
return 3476;
}
case 1:
switch (waterlogged)
{
case true:
return 3477;
case false:
return 3478;
}
case 2:
switch (waterlogged)
{
case true:
return 3479;
case false:
return 3480;
}
case 3:
switch (waterlogged)
{
case true:
return 3481;
case false:
return 3482;
}
case 4:
switch (waterlogged)
{
case true:
return 3483;
case false:
return 3484;
}
case 5:
switch (waterlogged)
{
case true:
return 3485;
case false:
return 3486;
}
case 6:
switch (waterlogged)
{
case true:
return 3487;
case false:
return 3488;
}
case 7:
switch (waterlogged)
{
case true:
return 3489;
case false:
return 3490;
}
case 8:
switch (waterlogged)
{
case true:
return 3491;
case false:
return 3492;
}
case 9:
switch (waterlogged)
{
case true:
return 3493;
case false:
return 3494;
}
case 10:
switch (waterlogged)
{
case true:
return 3495;
case false:
return 3496;
}
case 11:
switch (waterlogged)
{
case true:
return 3497;
case false:
return 3498;
}
case 12:
switch (waterlogged)
{
case true:
return 3499;
case false:
return 3500;
}
case 13:
switch (waterlogged)
{
case true:
return 3501;
case false:
return 3502;
}
case 14:
switch (waterlogged)
{
case true:
return 3503;
case false:
return 3504;
}
case 15:
switch (waterlogged)
{
case true:
return 3505;
case false:
return 3506;
}
}
}
constexpr static acacia_sign from_id(block_id_type id)
{
switch (id)
{
case 3475:
return {.rotation = 0, .waterlogged = true};
case 3476:
return {.rotation = 0, .waterlogged = false};
case 3477:
return {.rotation = 1, .waterlogged = true};
case 3478:
return {.rotation = 1, .waterlogged = false};
case 3479:
return {.rotation = 2, .waterlogged = true};
case 3480:
return {.rotation = 2, .waterlogged = false};
case 3481:
return {.rotation = 3, .waterlogged = true};
case 3482:
return {.rotation = 3, .waterlogged = false};
case 3483:
return {.rotation = 4, .waterlogged = true};
case 3484:
return {.rotation = 4, .waterlogged = false};
case 3485:
return {.rotation = 5, .waterlogged = true};
case 3486:
return {.rotation = 5, .waterlogged = false};
case 3487:
return {.rotation = 6, .waterlogged = true};
case 3488:
return {.rotation = 6, .waterlogged = false};
case 3489:
return {.rotation = 7, .waterlogged = true};
case 3490:
return {.rotation = 7, .waterlogged = false};
case 3491:
return {.rotation = 8, .waterlogged = true};
case 3492:
return {.rotation = 8, .waterlogged = false};
case 3493:
return {.rotation = 9, .waterlogged = true};
case 3494:
return {.rotation = 9, .waterlogged = false};
case 3495:
return {.rotation = 10, .waterlogged = true};
case 3496:
return {.rotation = 10, .waterlogged = false};
case 3497:
return {.rotation = 11, .waterlogged = true};
case 3498:
return {.rotation = 11, .waterlogged = false};
case 3499:
return {.rotation = 12, .waterlogged = true};
case 3500:
return {.rotation = 12, .waterlogged = false};
case 3501:
return {.rotation = 13, .waterlogged = true};
case 3502:
return {.rotation = 13, .waterlogged = false};
case 3503:
return {.rotation = 14, .waterlogged = true};
case 3504:
return {.rotation = 14, .waterlogged = false};
case 3505:
return {.rotation = 15, .waterlogged = true};
case 3506:
return {.rotation = 15, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:0:true";
case false:
return "minecraft:acacia_sign:0:false";
}
case 1:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:1:true";
case false:
return "minecraft:acacia_sign:1:false";
}
case 2:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:2:true";
case false:
return "minecraft:acacia_sign:2:false";
}
case 3:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:3:true";
case false:
return "minecraft:acacia_sign:3:false";
}
case 4:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:4:true";
case false:
return "minecraft:acacia_sign:4:false";
}
case 5:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:5:true";
case false:
return "minecraft:acacia_sign:5:false";
}
case 6:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:6:true";
case false:
return "minecraft:acacia_sign:6:false";
}
case 7:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:7:true";
case false:
return "minecraft:acacia_sign:7:false";
}
case 8:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:8:true";
case false:
return "minecraft:acacia_sign:8:false";
}
case 9:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:9:true";
case false:
return "minecraft:acacia_sign:9:false";
}
case 10:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:10:true";
case false:
return "minecraft:acacia_sign:10:false";
}
case 11:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:11:true";
case false:
return "minecraft:acacia_sign:11:false";
}
case 12:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:12:true";
case false:
return "minecraft:acacia_sign:12:false";
}
case 13:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:13:true";
case false:
return "minecraft:acacia_sign:13:false";
}
case 14:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:14:true";
case false:
return "minecraft:acacia_sign:14:false";
}
case 15:
switch (waterlogged)
{
case true:
return "minecraft:acacia_sign:15:true";
case false:
return "minecraft:acacia_sign:15:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
