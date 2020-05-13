#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct stripped_acacia_wood
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
return 138;
case axis_type::y:
return 139;
case axis_type::z:
return 140;
}
}
constexpr static stripped_acacia_wood from_id(block_id_type id)
{
switch (id)
{
case 138:
return {.axis = axis_type::x};
case 139:
return {.axis = axis_type::y};
case 140:
return {.axis = axis_type::z};
}}
constexpr std::string_view to_string() const
{switch (axis)
{
case axis_type::x:
return "minecraft:stripped_acacia_wood:x";
case axis_type::y:
return "minecraft:stripped_acacia_wood:y";
case axis_type::z:
return "minecraft:stripped_acacia_wood:z";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
