#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct farmland
{std::uint8_t moisture = 0;
constexpr block_id_type to_id() const {
switch (moisture)
{
case 0:
return 3363;
case 1:
return 3364;
case 2:
return 3365;
case 3:
return 3366;
case 4:
return 3367;
case 5:
return 3368;
case 6:
return 3369;
case 7:
return 3370;
}
}
constexpr static farmland from_id(block_id_type id)
{
switch (id)
{
case 3363:
return {.moisture = 0};
case 3364:
return {.moisture = 1};
case 3365:
return {.moisture = 2};
case 3366:
return {.moisture = 3};
case 3367:
return {.moisture = 4};
case 3368:
return {.moisture = 5};
case 3369:
return {.moisture = 6};
case 3370:
return {.moisture = 7};
}}
constexpr std::string_view to_string() const
{switch (moisture)
{
case 0:
return "minecraft:farmland:0";
case 1:
return "minecraft:farmland:1";
case 2:
return "minecraft:farmland:2";
case 3:
return "minecraft:farmland:3";
case 4:
return "minecraft:farmland:4";
case 5:
return "minecraft:farmland:5";
case 6:
return "minecraft:farmland:6";
case 7:
return "minecraft:farmland:7";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
