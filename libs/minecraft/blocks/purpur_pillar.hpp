#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct purpur_pillar
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
return 8599;
case axis_type::y:
return 8600;
case axis_type::z:
return 8601;
}
}
constexpr static purpur_pillar from_id(block_id_type id)
{
switch (id)
{
case 8599:
return {.axis = axis_type::x};
case 8600:
return {.axis = axis_type::y};
case 8601:
return {.axis = axis_type::z};
}}
constexpr std::string_view to_string() const
{switch (axis)
{
case axis_type::x:
return "minecraft:purpur_pillar:x";
case axis_type::y:
return "minecraft:purpur_pillar:y";
case axis_type::z:
return "minecraft:purpur_pillar:z";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop