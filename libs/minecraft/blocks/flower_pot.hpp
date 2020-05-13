#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct flower_pot
{constexpr block_id_type to_id() const {
return 5769;}
constexpr static flower_pot from_id(block_id_type id)
{
return flower_pot();
}
constexpr std::string_view to_string() const
{return "minecraft:flower_pot";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
