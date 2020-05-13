#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct nether_portal
{enum class axis_type : std::uint8_t
{
x,
z
} axis = axis_type::x;
constexpr block_id_type to_id() const {
switch (axis)
{
case axis_type::x:
return 4000;
case axis_type::z:
return 4001;
}
}
constexpr static nether_portal from_id(block_id_type id)
{
switch (id)
{
case 4000:
return {.axis = axis_type::x};
case 4001:
return {.axis = axis_type::z};
}}
constexpr std::string_view to_string() const
{switch (axis)
{
case axis_type::x:
return "minecraft:nether_portal:x";
case axis_type::z:
return "minecraft:nether_portal:z";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
