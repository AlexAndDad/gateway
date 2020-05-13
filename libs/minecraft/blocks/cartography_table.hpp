#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct cartography_table
{constexpr block_id_type to_id() const {
return 11163;}
constexpr static cartography_table from_id(block_id_type id)
{
return cartography_table();
}
constexpr std::string_view to_string() const
{return "minecraft:cartography_table";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
