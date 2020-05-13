#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jungle_planks
{constexpr block_id_type to_id() const {
return 18;}
constexpr static jungle_planks from_id(block_id_type id)
{
return jungle_planks();
}
constexpr std::string_view to_string() const
{return "minecraft:jungle_planks";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
