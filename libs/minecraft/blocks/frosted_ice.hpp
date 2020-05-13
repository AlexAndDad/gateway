#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct frosted_ice
{std::uint8_t age = 0;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
return 8713;
case 1:
return 8714;
case 2:
return 8715;
case 3:
return 8716;
}
}
constexpr static frosted_ice from_id(block_id_type id)
{
switch (id)
{
case 8713:
return {.age = 0};
case 8714:
return {.age = 1};
case 8715:
return {.age = 2};
case 8716:
return {.age = 3};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
return "minecraft:frosted_ice:0";
case 1:
return "minecraft:frosted_ice:1";
case 2:
return "minecraft:frosted_ice:2";
case 3:
return "minecraft:frosted_ice:3";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
