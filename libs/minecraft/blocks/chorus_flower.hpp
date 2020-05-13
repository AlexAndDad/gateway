#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct chorus_flower
{std::uint8_t age = 0;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
return 8592;
case 1:
return 8593;
case 2:
return 8594;
case 3:
return 8595;
case 4:
return 8596;
case 5:
return 8597;
}
}
constexpr static chorus_flower from_id(block_id_type id)
{
switch (id)
{
case 8592:
return {.age = 0};
case 8593:
return {.age = 1};
case 8594:
return {.age = 2};
case 8595:
return {.age = 3};
case 8596:
return {.age = 4};
case 8597:
return {.age = 5};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
return "minecraft:chorus_flower:0";
case 1:
return "minecraft:chorus_flower:1";
case 2:
return "minecraft:chorus_flower:2";
case 3:
return "minecraft:chorus_flower:3";
case 4:
return "minecraft:chorus_flower:4";
case 5:
return "minecraft:chorus_flower:5";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
