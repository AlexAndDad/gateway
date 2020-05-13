#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jungle_sign
{std::uint8_t rotation = 0;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
switch (waterlogged)
{
case true:
return 3507;
case false:
return 3508;
}
case 1:
switch (waterlogged)
{
case true:
return 3509;
case false:
return 3510;
}
case 2:
switch (waterlogged)
{
case true:
return 3511;
case false:
return 3512;
}
case 3:
switch (waterlogged)
{
case true:
return 3513;
case false:
return 3514;
}
case 4:
switch (waterlogged)
{
case true:
return 3515;
case false:
return 3516;
}
case 5:
switch (waterlogged)
{
case true:
return 3517;
case false:
return 3518;
}
case 6:
switch (waterlogged)
{
case true:
return 3519;
case false:
return 3520;
}
case 7:
switch (waterlogged)
{
case true:
return 3521;
case false:
return 3522;
}
case 8:
switch (waterlogged)
{
case true:
return 3523;
case false:
return 3524;
}
case 9:
switch (waterlogged)
{
case true:
return 3525;
case false:
return 3526;
}
case 10:
switch (waterlogged)
{
case true:
return 3527;
case false:
return 3528;
}
case 11:
switch (waterlogged)
{
case true:
return 3529;
case false:
return 3530;
}
case 12:
switch (waterlogged)
{
case true:
return 3531;
case false:
return 3532;
}
case 13:
switch (waterlogged)
{
case true:
return 3533;
case false:
return 3534;
}
case 14:
switch (waterlogged)
{
case true:
return 3535;
case false:
return 3536;
}
case 15:
switch (waterlogged)
{
case true:
return 3537;
case false:
return 3538;
}
}
}
constexpr static jungle_sign from_id(block_id_type id)
{
switch (id)
{
case 3507:
return {.rotation = 0, .waterlogged = true};
case 3508:
return {.rotation = 0, .waterlogged = false};
case 3509:
return {.rotation = 1, .waterlogged = true};
case 3510:
return {.rotation = 1, .waterlogged = false};
case 3511:
return {.rotation = 2, .waterlogged = true};
case 3512:
return {.rotation = 2, .waterlogged = false};
case 3513:
return {.rotation = 3, .waterlogged = true};
case 3514:
return {.rotation = 3, .waterlogged = false};
case 3515:
return {.rotation = 4, .waterlogged = true};
case 3516:
return {.rotation = 4, .waterlogged = false};
case 3517:
return {.rotation = 5, .waterlogged = true};
case 3518:
return {.rotation = 5, .waterlogged = false};
case 3519:
return {.rotation = 6, .waterlogged = true};
case 3520:
return {.rotation = 6, .waterlogged = false};
case 3521:
return {.rotation = 7, .waterlogged = true};
case 3522:
return {.rotation = 7, .waterlogged = false};
case 3523:
return {.rotation = 8, .waterlogged = true};
case 3524:
return {.rotation = 8, .waterlogged = false};
case 3525:
return {.rotation = 9, .waterlogged = true};
case 3526:
return {.rotation = 9, .waterlogged = false};
case 3527:
return {.rotation = 10, .waterlogged = true};
case 3528:
return {.rotation = 10, .waterlogged = false};
case 3529:
return {.rotation = 11, .waterlogged = true};
case 3530:
return {.rotation = 11, .waterlogged = false};
case 3531:
return {.rotation = 12, .waterlogged = true};
case 3532:
return {.rotation = 12, .waterlogged = false};
case 3533:
return {.rotation = 13, .waterlogged = true};
case 3534:
return {.rotation = 13, .waterlogged = false};
case 3535:
return {.rotation = 14, .waterlogged = true};
case 3536:
return {.rotation = 14, .waterlogged = false};
case 3537:
return {.rotation = 15, .waterlogged = true};
case 3538:
return {.rotation = 15, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:0:true";
case false:
return "minecraft:jungle_sign:0:false";
}
case 1:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:1:true";
case false:
return "minecraft:jungle_sign:1:false";
}
case 2:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:2:true";
case false:
return "minecraft:jungle_sign:2:false";
}
case 3:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:3:true";
case false:
return "minecraft:jungle_sign:3:false";
}
case 4:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:4:true";
case false:
return "minecraft:jungle_sign:4:false";
}
case 5:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:5:true";
case false:
return "minecraft:jungle_sign:5:false";
}
case 6:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:6:true";
case false:
return "minecraft:jungle_sign:6:false";
}
case 7:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:7:true";
case false:
return "minecraft:jungle_sign:7:false";
}
case 8:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:8:true";
case false:
return "minecraft:jungle_sign:8:false";
}
case 9:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:9:true";
case false:
return "minecraft:jungle_sign:9:false";
}
case 10:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:10:true";
case false:
return "minecraft:jungle_sign:10:false";
}
case 11:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:11:true";
case false:
return "minecraft:jungle_sign:11:false";
}
case 12:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:12:true";
case false:
return "minecraft:jungle_sign:12:false";
}
case 13:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:13:true";
case false:
return "minecraft:jungle_sign:13:false";
}
case 14:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:14:true";
case false:
return "minecraft:jungle_sign:14:false";
}
case 15:
switch (waterlogged)
{
case true:
return "minecraft:jungle_sign:15:true";
case false:
return "minecraft:jungle_sign:15:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
