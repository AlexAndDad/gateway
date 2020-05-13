#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dead_fire_coral
{bool waterlogged = true;
constexpr block_id_type to_id() const {
switch (waterlogged)
{
case true:
return 8990;
case false:
return 8991;
}
}
constexpr static dead_fire_coral from_id(block_id_type id)
{
switch (id)
{
case 8990:
return {.waterlogged = true};
case 8991:
return {.waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (waterlogged)
{
case true:
return "minecraft:dead_fire_coral:true";
case false:
return "minecraft:dead_fire_coral:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
