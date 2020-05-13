#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct snow
{std::uint8_t layers = 1;
constexpr block_id_type to_id() const {
switch (layers)
{
case 1:
return 3919;
case 2:
return 3920;
case 3:
return 3921;
case 4:
return 3922;
case 5:
return 3923;
case 6:
return 3924;
case 7:
return 3925;
case 8:
return 3926;
}
}
constexpr static snow from_id(block_id_type id)
{
switch (id)
{
case 3919:
return {.layers = 1};
case 3920:
return {.layers = 2};
case 3921:
return {.layers = 3};
case 3922:
return {.layers = 4};
case 3923:
return {.layers = 5};
case 3924:
return {.layers = 6};
case 3925:
return {.layers = 7};
case 3926:
return {.layers = 8};
}}
constexpr std::string_view to_string() const
{switch (layers)
{
case 1:
return "minecraft:snow:1";
case 2:
return "minecraft:snow:2";
case 3:
return "minecraft:snow:3";
case 4:
return "minecraft:snow:4";
case 5:
return "minecraft:snow:5";
case 6:
return "minecraft:snow:6";
case 7:
return "minecraft:snow:7";
case 8:
return "minecraft:snow:8";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
