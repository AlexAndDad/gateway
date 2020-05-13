#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct fire_coral
{bool waterlogged = true;
constexpr block_id_type to_id() const {
switch (waterlogged)
{
case true:
return 9000;
case false:
return 9001;
}
}
constexpr static fire_coral from_id(block_id_type id)
{
switch (id)
{
case 9000:
return {.waterlogged = true};
case 9001:
return {.waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (waterlogged)
{
case true:
return "minecraft:fire_coral:true";
case false:
return "minecraft:fire_coral:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
