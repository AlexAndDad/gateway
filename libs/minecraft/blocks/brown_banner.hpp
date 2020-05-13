#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct brown_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7553;
case 1:
return 7554;
case 2:
return 7555;
case 3:
return 7556;
case 4:
return 7557;
case 5:
return 7558;
case 6:
return 7559;
case 7:
return 7560;
case 8:
return 7561;
case 9:
return 7562;
case 10:
return 7563;
case 11:
return 7564;
case 12:
return 7565;
case 13:
return 7566;
case 14:
return 7567;
case 15:
return 7568;
}
}
constexpr static brown_banner from_id(block_id_type id)
{
switch (id)
{
case 7553:
return {.rotation = 0};
case 7554:
return {.rotation = 1};
case 7555:
return {.rotation = 2};
case 7556:
return {.rotation = 3};
case 7557:
return {.rotation = 4};
case 7558:
return {.rotation = 5};
case 7559:
return {.rotation = 6};
case 7560:
return {.rotation = 7};
case 7561:
return {.rotation = 8};
case 7562:
return {.rotation = 9};
case 7563:
return {.rotation = 10};
case 7564:
return {.rotation = 11};
case 7565:
return {.rotation = 12};
case 7566:
return {.rotation = 13};
case 7567:
return {.rotation = 14};
case 7568:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:brown_banner:0";
case 1:
return "minecraft:brown_banner:1";
case 2:
return "minecraft:brown_banner:2";
case 3:
return "minecraft:brown_banner:3";
case 4:
return "minecraft:brown_banner:4";
case 5:
return "minecraft:brown_banner:5";
case 6:
return "minecraft:brown_banner:6";
case 7:
return "minecraft:brown_banner:7";
case 8:
return "minecraft:brown_banner:8";
case 9:
return "minecraft:brown_banner:9";
case 10:
return "minecraft:brown_banner:10";
case 11:
return "minecraft:brown_banner:11";
case 12:
return "minecraft:brown_banner:12";
case 13:
return "minecraft:brown_banner:13";
case 14:
return "minecraft:brown_banner:14";
case 15:
return "minecraft:brown_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
