#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct sweet_berry_bush
{std::uint8_t age = 0;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
return 11264;
case 1:
return 11265;
case 2:
return 11266;
case 3:
return 11267;
}
}
constexpr static sweet_berry_bush from_id(block_id_type id)
{
switch (id)
{
case 11264:
return {.age = 0};
case 11265:
return {.age = 1};
case 11266:
return {.age = 2};
case 11267:
return {.age = 3};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
return "minecraft:sweet_berry_bush:0";
case 1:
return "minecraft:sweet_berry_bush:1";
case 2:
return "minecraft:sweet_berry_bush:2";
case 3:
return "minecraft:sweet_berry_bush:3";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
