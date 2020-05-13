#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dark_oak_sign
{std::uint8_t rotation = 0;
bool waterlogged = false;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
switch (waterlogged)
{
case true:
return 3539;
case false:
return 3540;
}
case 1:
switch (waterlogged)
{
case true:
return 3541;
case false:
return 3542;
}
case 2:
switch (waterlogged)
{
case true:
return 3543;
case false:
return 3544;
}
case 3:
switch (waterlogged)
{
case true:
return 3545;
case false:
return 3546;
}
case 4:
switch (waterlogged)
{
case true:
return 3547;
case false:
return 3548;
}
case 5:
switch (waterlogged)
{
case true:
return 3549;
case false:
return 3550;
}
case 6:
switch (waterlogged)
{
case true:
return 3551;
case false:
return 3552;
}
case 7:
switch (waterlogged)
{
case true:
return 3553;
case false:
return 3554;
}
case 8:
switch (waterlogged)
{
case true:
return 3555;
case false:
return 3556;
}
case 9:
switch (waterlogged)
{
case true:
return 3557;
case false:
return 3558;
}
case 10:
switch (waterlogged)
{
case true:
return 3559;
case false:
return 3560;
}
case 11:
switch (waterlogged)
{
case true:
return 3561;
case false:
return 3562;
}
case 12:
switch (waterlogged)
{
case true:
return 3563;
case false:
return 3564;
}
case 13:
switch (waterlogged)
{
case true:
return 3565;
case false:
return 3566;
}
case 14:
switch (waterlogged)
{
case true:
return 3567;
case false:
return 3568;
}
case 15:
switch (waterlogged)
{
case true:
return 3569;
case false:
return 3570;
}
}
}
constexpr static dark_oak_sign from_id(block_id_type id)
{
switch (id)
{
case 3539:
return {.rotation = 0, .waterlogged = true};
case 3540:
return {.rotation = 0, .waterlogged = false};
case 3541:
return {.rotation = 1, .waterlogged = true};
case 3542:
return {.rotation = 1, .waterlogged = false};
case 3543:
return {.rotation = 2, .waterlogged = true};
case 3544:
return {.rotation = 2, .waterlogged = false};
case 3545:
return {.rotation = 3, .waterlogged = true};
case 3546:
return {.rotation = 3, .waterlogged = false};
case 3547:
return {.rotation = 4, .waterlogged = true};
case 3548:
return {.rotation = 4, .waterlogged = false};
case 3549:
return {.rotation = 5, .waterlogged = true};
case 3550:
return {.rotation = 5, .waterlogged = false};
case 3551:
return {.rotation = 6, .waterlogged = true};
case 3552:
return {.rotation = 6, .waterlogged = false};
case 3553:
return {.rotation = 7, .waterlogged = true};
case 3554:
return {.rotation = 7, .waterlogged = false};
case 3555:
return {.rotation = 8, .waterlogged = true};
case 3556:
return {.rotation = 8, .waterlogged = false};
case 3557:
return {.rotation = 9, .waterlogged = true};
case 3558:
return {.rotation = 9, .waterlogged = false};
case 3559:
return {.rotation = 10, .waterlogged = true};
case 3560:
return {.rotation = 10, .waterlogged = false};
case 3561:
return {.rotation = 11, .waterlogged = true};
case 3562:
return {.rotation = 11, .waterlogged = false};
case 3563:
return {.rotation = 12, .waterlogged = true};
case 3564:
return {.rotation = 12, .waterlogged = false};
case 3565:
return {.rotation = 13, .waterlogged = true};
case 3566:
return {.rotation = 13, .waterlogged = false};
case 3567:
return {.rotation = 14, .waterlogged = true};
case 3568:
return {.rotation = 14, .waterlogged = false};
case 3569:
return {.rotation = 15, .waterlogged = true};
case 3570:
return {.rotation = 15, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:0:true";
case false:
return "minecraft:dark_oak_sign:0:false";
}
case 1:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:1:true";
case false:
return "minecraft:dark_oak_sign:1:false";
}
case 2:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:2:true";
case false:
return "minecraft:dark_oak_sign:2:false";
}
case 3:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:3:true";
case false:
return "minecraft:dark_oak_sign:3:false";
}
case 4:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:4:true";
case false:
return "minecraft:dark_oak_sign:4:false";
}
case 5:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:5:true";
case false:
return "minecraft:dark_oak_sign:5:false";
}
case 6:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:6:true";
case false:
return "minecraft:dark_oak_sign:6:false";
}
case 7:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:7:true";
case false:
return "minecraft:dark_oak_sign:7:false";
}
case 8:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:8:true";
case false:
return "minecraft:dark_oak_sign:8:false";
}
case 9:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:9:true";
case false:
return "minecraft:dark_oak_sign:9:false";
}
case 10:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:10:true";
case false:
return "minecraft:dark_oak_sign:10:false";
}
case 11:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:11:true";
case false:
return "minecraft:dark_oak_sign:11:false";
}
case 12:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:12:true";
case false:
return "minecraft:dark_oak_sign:12:false";
}
case 13:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:13:true";
case false:
return "minecraft:dark_oak_sign:13:false";
}
case 14:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:14:true";
case false:
return "minecraft:dark_oak_sign:14:false";
}
case 15:
switch (waterlogged)
{
case true:
return "minecraft:dark_oak_sign:15:true";
case false:
return "minecraft:dark_oak_sign:15:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
