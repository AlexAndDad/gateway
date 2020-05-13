#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct wheat
{std::uint8_t age = 0;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
return 3355;
case 1:
return 3356;
case 2:
return 3357;
case 3:
return 3358;
case 4:
return 3359;
case 5:
return 3360;
case 6:
return 3361;
case 7:
return 3362;
}
}
constexpr static wheat from_id(block_id_type id)
{
switch (id)
{
case 3355:
return {.age = 0};
case 3356:
return {.age = 1};
case 3357:
return {.age = 2};
case 3358:
return {.age = 3};
case 3359:
return {.age = 4};
case 3360:
return {.age = 5};
case 3361:
return {.age = 6};
case 3362:
return {.age = 7};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
return "minecraft:wheat:0";
case 1:
return "minecraft:wheat:1";
case 2:
return "minecraft:wheat:2";
case 3:
return "minecraft:wheat:3";
case 4:
return "minecraft:wheat:4";
case 5:
return "minecraft:wheat:5";
case 6:
return "minecraft:wheat:6";
case 7:
return "minecraft:wheat:7";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
