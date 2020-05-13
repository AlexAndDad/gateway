#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct magenta_banner
{std::uint8_t rotation = 0;
constexpr block_id_type to_id() const {
switch (rotation)
{
case 0:
return 7393;
case 1:
return 7394;
case 2:
return 7395;
case 3:
return 7396;
case 4:
return 7397;
case 5:
return 7398;
case 6:
return 7399;
case 7:
return 7400;
case 8:
return 7401;
case 9:
return 7402;
case 10:
return 7403;
case 11:
return 7404;
case 12:
return 7405;
case 13:
return 7406;
case 14:
return 7407;
case 15:
return 7408;
}
}
constexpr static magenta_banner from_id(block_id_type id)
{
switch (id)
{
case 7393:
return {.rotation = 0};
case 7394:
return {.rotation = 1};
case 7395:
return {.rotation = 2};
case 7396:
return {.rotation = 3};
case 7397:
return {.rotation = 4};
case 7398:
return {.rotation = 5};
case 7399:
return {.rotation = 6};
case 7400:
return {.rotation = 7};
case 7401:
return {.rotation = 8};
case 7402:
return {.rotation = 9};
case 7403:
return {.rotation = 10};
case 7404:
return {.rotation = 11};
case 7405:
return {.rotation = 12};
case 7406:
return {.rotation = 13};
case 7407:
return {.rotation = 14};
case 7408:
return {.rotation = 15};
}}
constexpr std::string_view to_string() const
{switch (rotation)
{
case 0:
return "minecraft:magenta_banner:0";
case 1:
return "minecraft:magenta_banner:1";
case 2:
return "minecraft:magenta_banner:2";
case 3:
return "minecraft:magenta_banner:3";
case 4:
return "minecraft:magenta_banner:4";
case 5:
return "minecraft:magenta_banner:5";
case 6:
return "minecraft:magenta_banner:6";
case 7:
return "minecraft:magenta_banner:7";
case 8:
return "minecraft:magenta_banner:8";
case 9:
return "minecraft:magenta_banner:9";
case 10:
return "minecraft:magenta_banner:10";
case 11:
return "minecraft:magenta_banner:11";
case 12:
return "minecraft:magenta_banner:12";
case 13:
return "minecraft:magenta_banner:13";
case 14:
return "minecraft:magenta_banner:14";
case 15:
return "minecraft:magenta_banner:15";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
