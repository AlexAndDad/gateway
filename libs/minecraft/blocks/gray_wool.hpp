#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct gray_wool
{constexpr block_id_type to_id() const {
return 1390;}
constexpr static gray_wool from_id(block_id_type id)
{
return gray_wool();
}
constexpr std::string_view to_string() const
{return "minecraft:gray_wool";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop