#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct cauldron
{std::uint8_t level = 0;
constexpr block_id_type to_id() const {
switch (level)
{
case 0:
return 5125;
case 1:
return 5126;
case 2:
return 5127;
case 3:
return 5128;
}
}
constexpr static cauldron from_id(block_id_type id)
{
switch (id)
{
case 5125:
return {.level = 0};
case 5126:
return {.level = 1};
case 5127:
return {.level = 2};
case 5128:
return {.level = 3};
}}
constexpr std::string_view to_string() const
{switch (level)
{
case 0:
return "minecraft:cauldron:0";
case 1:
return "minecraft:cauldron:1";
case 2:
return "minecraft:cauldron:2";
case 3:
return "minecraft:cauldron:3";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
