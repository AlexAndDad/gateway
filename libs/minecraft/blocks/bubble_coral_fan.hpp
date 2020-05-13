#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct bubble_coral_fan
{bool waterlogged = true;
constexpr block_id_type to_id() const {
switch (waterlogged)
{
case true:
return 9018;
case false:
return 9019;
}
}
constexpr static bubble_coral_fan from_id(block_id_type id)
{
switch (id)
{
case 9018:
return {.waterlogged = true};
case 9019:
return {.waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (waterlogged)
{
case true:
return "minecraft:bubble_coral_fan:true";
case false:
return "minecraft:bubble_coral_fan:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
