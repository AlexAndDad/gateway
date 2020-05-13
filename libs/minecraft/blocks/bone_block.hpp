#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct bone_block
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
return 8720;
case axis_type::y:
return 8721;
case axis_type::z:
return 8722;
}
}
constexpr static bone_block from_id(block_id_type id)
{
switch (id)
{
case 8720:
return {.axis = axis_type::x};
case 8721:
return {.axis = axis_type::y};
case 8722:
return {.axis = axis_type::z};
}}
constexpr std::string_view to_string() const
{switch (axis)
{
case axis_type::x:
return "minecraft:bone_block:x";
case axis_type::y:
return "minecraft:bone_block:y";
case axis_type::z:
return "minecraft:bone_block:z";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
