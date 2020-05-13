#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct beetroots
{std::uint8_t age = 0;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
return 8683;
case 1:
return 8684;
case 2:
return 8685;
case 3:
return 8686;
}
}
constexpr static beetroots from_id(block_id_type id)
{
switch (id)
{
case 8683:
return {.age = 0};
case 8684:
return {.age = 1};
case 8685:
return {.age = 2};
case 8686:
return {.age = 3};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
return "minecraft:beetroots:0";
case 1:
return "minecraft:beetroots:1";
case 2:
return "minecraft:beetroots:2";
case 3:
return "minecraft:beetroots:3";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
