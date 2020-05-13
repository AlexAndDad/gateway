#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct diamond_ore
{constexpr block_id_type to_id() const {
return 3352;}
constexpr static diamond_ore from_id(block_id_type id)
{
return diamond_ore();
}
constexpr std::string_view to_string() const
{return "minecraft:diamond_ore";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop