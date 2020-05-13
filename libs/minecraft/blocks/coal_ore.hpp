#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct coal_ore
{constexpr block_id_type to_id() const {
return 71;}
constexpr static coal_ore from_id(block_id_type id)
{
return coal_ore();
}
constexpr std::string_view to_string() const
{return "minecraft:coal_ore";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
