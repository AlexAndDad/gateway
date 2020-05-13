#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct oak_log
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
return 72;
case axis_type::y:
return 73;
case axis_type::z:
return 74;
}
}
constexpr static oak_log from_id(block_id_type id)
{
switch (id)
{
case 72:
return {.axis = axis_type::x};
case 73:
return {.axis = axis_type::y};
case 74:
return {.axis = axis_type::z};
}}
constexpr std::string_view to_string() const
{switch (axis)
{
case axis_type::x:
return "minecraft:oak_log:x";
case axis_type::y:
return "minecraft:oak_log:y";
case axis_type::z:
return "minecraft:oak_log:z";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
