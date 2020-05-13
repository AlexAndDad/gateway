#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct nether_wart
{std::uint8_t age = 0;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
return 5112;
case 1:
return 5113;
case 2:
return 5114;
case 3:
return 5115;
}
}
constexpr static nether_wart from_id(block_id_type id)
{
switch (id)
{
case 5112:
return {.age = 0};
case 5113:
return {.age = 1};
case 5114:
return {.age = 2};
case 5115:
return {.age = 3};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
return "minecraft:nether_wart:0";
case 1:
return "minecraft:nether_wart:1";
case 2:
return "minecraft:nether_wart:2";
case 3:
return "minecraft:nether_wart:3";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
