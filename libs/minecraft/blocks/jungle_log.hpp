#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jungle_log
{enum class axis_type : std::uint8_t
{
x,
y,
z
} axis = axis_type::y;
constexpr block_id_type to_id() const {
switch (axis)
{
case axis_type::x:
return 81;
case axis_type::y:
return 82;
case axis_type::z:
return 83;
}
}
constexpr static jungle_log from_id(block_id_type id)
{
switch (id)
{
case 81:
return {.axis = axis_type::x};
case 82:
return {.axis = axis_type::y};
case 83:
return {.axis = axis_type::z};
}}
constexpr std::string_view to_string() const
{switch (axis)
{
case axis_type::x:
return "minecraft:jungle_log:x";
case axis_type::y:
return "minecraft:jungle_log:y";
case axis_type::z:
return "minecraft:jungle_log:z";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
