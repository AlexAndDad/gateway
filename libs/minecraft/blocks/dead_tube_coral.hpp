#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dead_tube_coral
{bool waterlogged = true;
constexpr block_id_type to_id() const {
switch (waterlogged)
{
case true:
return 8984;
case false:
return 8985;
}
}
constexpr static dead_tube_coral from_id(block_id_type id)
{
switch (id)
{
case 8984:
return {.waterlogged = true};
case 8985:
return {.waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (waterlogged)
{
case true:
return "minecraft:dead_tube_coral:true";
case false:
return "minecraft:dead_tube_coral:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
