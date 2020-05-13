#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct yellow_wool
{constexpr block_id_type to_id() const {
return 1387;}
constexpr static yellow_wool from_id(block_id_type id)
{
return yellow_wool();
}
constexpr std::string_view to_string() const
{return "minecraft:yellow_wool";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop