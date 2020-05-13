#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dark_oak_planks
{constexpr block_id_type to_id() const {
return 20;}
constexpr static dark_oak_planks from_id(block_id_type id)
{
return dark_oak_planks();
}
constexpr std::string_view to_string() const
{return "minecraft:dark_oak_planks";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
