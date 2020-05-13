#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct quartz_pillar
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
return 6204;
case axis_type::y:
return 6205;
case axis_type::z:
return 6206;
}
}
constexpr static quartz_pillar from_id(block_id_type id)
{
switch (id)
{
case 6204:
return {.axis = axis_type::x};
case 6205:
return {.axis = axis_type::y};
case 6206:
return {.axis = axis_type::z};
}}
constexpr std::string_view to_string() const
{switch (axis)
{
case axis_type::x:
return "minecraft:quartz_pillar:x";
case axis_type::y:
return "minecraft:quartz_pillar:y";
case axis_type::z:
return "minecraft:quartz_pillar:z";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
