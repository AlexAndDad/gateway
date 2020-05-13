#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct bubble_column
{bool drag = true;
constexpr block_id_type to_id() const {
switch (drag)
{
case true:
return 9131;
case false:
return 9132;
}
}
constexpr static bubble_column from_id(block_id_type id)
{
switch (id)
{
case 9131:
return {.drag = true};
case 9132:
return {.drag = false};
}}
constexpr std::string_view to_string() const
{switch (drag)
{
case true:
return "minecraft:bubble_column:true";
case false:
return "minecraft:bubble_column:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
