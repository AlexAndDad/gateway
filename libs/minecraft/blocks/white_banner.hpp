#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct white_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7361;
case 1:
return 7362;
case 2:
return 7363;
case 3:
return 7364;
case 4:
return 7365;
case 5:
return 7366;
case 6:
return 7367;
case 7:
return 7368;
case 8:
return 7369;
case 9:
return 7370;
case 10:
return 7371;
case 11:
return 7372;
case 12:
return 7373;
case 13:
return 7374;
case 14:
return 7375;
case 15:
return 7376;
}
}
constexpr static white_banner from_id(block_id_type id)
{
switch (id)
{
case 7361:
return {.rotation = 0};
case 7362:
return {.rotation = 1};
case 7363:
return {.rotation = 2};
case 7364:
return {.rotation = 3};
case 7365:
return {.rotation = 4};
case 7366:
return {.rotation = 5};
case 7367:
return {.rotation = 6};
case 7368:
return {.rotation = 7};
case 7369:
return {.rotation = 8};
case 7370:
return {.rotation = 9};
case 7371:
return {.rotation = 10};
case 7372:
return {.rotation = 11};
case 7373:
return {.rotation = 12};
case 7374:
return {.rotation = 13};
case 7375:
return {.rotation = 14};
case 7376:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:white_banner:0";
case 1:
return "minecraft:white_banner:1";
case 2:
return "minecraft:white_banner:2";
case 3:
return "minecraft:white_banner:3";
case 4:
return "minecraft:white_banner:4";
case 5:
return "minecraft:white_banner:5";
case 6:
return "minecraft:white_banner:6";
case 7:
return "minecraft:white_banner:7";
case 8:
return "minecraft:white_banner:8";
case 9:
return "minecraft:white_banner:9";
case 10:
return "minecraft:white_banner:10";
case 11:
return "minecraft:white_banner:11";
case 12:
return "minecraft:white_banner:12";
case 13:
return "minecraft:white_banner:13";
case 14:
return "minecraft:white_banner:14";
case 15:
return "minecraft:white_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
