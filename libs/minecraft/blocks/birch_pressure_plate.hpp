#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct birch_pressure_plate
{bool powered = false;
constexpr block_id_type to_id() const {
switch (powered)
{
case true:
return 3875;
case false:
return 3876;
}
}
constexpr static birch_pressure_plate from_id(block_id_type id)
{
switch (id)
{
case 3875:
return {.powered = true};
case 3876:
return {.powered = false};
}}
constexpr std::string_view to_string() const
{switch (powered)
{
case true:
return "minecraft:birch_pressure_plate:true";
case false:
return "minecraft:birch_pressure_plate:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
