#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct mossy_cobblestone
{constexpr block_id_type to_id() const {
return 1432;}
constexpr static mossy_cobblestone from_id(block_id_type id)
{
return mossy_cobblestone();
}
constexpr std::string_view to_string() const
{return "minecraft:mossy_cobblestone";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
