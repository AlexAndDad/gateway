#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct potatoes
{std::uint8_t age = 0;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
return 5802;
case 1:
return 5803;
case 2:
return 5804;
case 3:
return 5805;
case 4:
return 5806;
case 5:
return 5807;
case 6:
return 5808;
case 7:
return 5809;
}
}
constexpr static potatoes from_id(block_id_type id)
{
switch (id)
{
case 5802:
return {.age = 0};
case 5803:
return {.age = 1};
case 5804:
return {.age = 2};
case 5805:
return {.age = 3};
case 5806:
return {.age = 4};
case 5807:
return {.age = 5};
case 5808:
return {.age = 6};
case 5809:
return {.age = 7};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
return "minecraft:potatoes:0";
case 1:
return "minecraft:potatoes:1";
case 2:
return "minecraft:potatoes:2";
case 3:
return "minecraft:potatoes:3";
case 4:
return "minecraft:potatoes:4";
case 5:
return "minecraft:potatoes:5";
case 6:
return "minecraft:potatoes:6";
case 7:
return "minecraft:potatoes:7";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
