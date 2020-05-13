#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct carrots
{std::uint8_t age = 0;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
return 5794;
case 1:
return 5795;
case 2:
return 5796;
case 3:
return 5797;
case 4:
return 5798;
case 5:
return 5799;
case 6:
return 5800;
case 7:
return 5801;
}
}
constexpr static carrots from_id(block_id_type id)
{
switch (id)
{
case 5794:
return {.age = 0};
case 5795:
return {.age = 1};
case 5796:
return {.age = 2};
case 5797:
return {.age = 3};
case 5798:
return {.age = 4};
case 5799:
return {.age = 5};
case 5800:
return {.age = 6};
case 5801:
return {.age = 7};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
return "minecraft:carrots:0";
case 1:
return "minecraft:carrots:1";
case 2:
return "minecraft:carrots:2";
case 3:
return "minecraft:carrots:3";
case 4:
return "minecraft:carrots:4";
case 5:
return "minecraft:carrots:5";
case 6:
return "minecraft:carrots:6";
case 7:
return "minecraft:carrots:7";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
