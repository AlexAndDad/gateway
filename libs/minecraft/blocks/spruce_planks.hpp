#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct spruce_planks
{constexpr block_id_type to_id() const {
return 16;}
constexpr static spruce_planks from_id(block_id_type id)
{
return spruce_planks();
}
constexpr std::string_view to_string() const
{return "minecraft:spruce_planks";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
