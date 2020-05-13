#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct stripped_oak_log
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
return 105;
case axis_type::y:
return 106;
case axis_type::z:
return 107;
}
}
constexpr static stripped_oak_log from_id(block_id_type id)
{
switch (id)
{
case 105:
return {.axis = axis_type::x};
case 106:
return {.axis = axis_type::y};
case 107:
return {.axis = axis_type::z};
}}
constexpr std::string_view to_string() const
{switch (axis)
{
case axis_type::x:
return "minecraft:stripped_oak_log:x";
case axis_type::y:
return "minecraft:stripped_oak_log:y";
case axis_type::z:
return "minecraft:stripped_oak_log:z";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
