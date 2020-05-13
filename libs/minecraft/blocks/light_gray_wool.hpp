#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct light_gray_wool
{constexpr block_id_type to_id() const {
return 1391;}
constexpr static light_gray_wool from_id(block_id_type id)
{
return light_gray_wool();
}
constexpr std::string_view to_string() const
{return "minecraft:light_gray_wool";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop