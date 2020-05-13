#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct brain_coral_fan
{bool waterlogged = true;
constexpr block_id_type to_id() const {
switch (waterlogged)
{
case true:
return 9016;
case false:
return 9017;
}
}
constexpr static brain_coral_fan from_id(block_id_type id)
{
switch (id)
{
case 9016:
return {.waterlogged = true};
case 9017:
return {.waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (waterlogged)
{
case true:
return "minecraft:brain_coral_fan:true";
case false:
return "minecraft:brain_coral_fan:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
