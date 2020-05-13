#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct hay_block
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
return 7327;
case axis_type::y:
return 7328;
case axis_type::z:
return 7329;
}
}
constexpr static hay_block from_id(block_id_type id)
{
switch (id)
{
case 7327:
return {.axis = axis_type::x};
case 7328:
return {.axis = axis_type::y};
case 7329:
return {.axis = axis_type::z};
}}
constexpr std::string_view to_string() const
{switch (axis)
{
case axis_type::x:
return "minecraft:hay_block:x";
case axis_type::y:
return "minecraft:hay_block:y";
case axis_type::z:
return "minecraft:hay_block:z";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
