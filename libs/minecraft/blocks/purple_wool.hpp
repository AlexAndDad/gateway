#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct purple_wool
{constexpr block_id_type to_id() const {
return 1393;}
constexpr static purple_wool from_id(block_id_type id)
{
return purple_wool();
}
constexpr std::string_view to_string() const
{return "minecraft:purple_wool";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop