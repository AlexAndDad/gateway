#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct grass
{constexpr block_id_type to_id() const {
return 1341;}
constexpr static grass from_id(block_id_type id)
{
return grass();
}
constexpr std::string_view to_string() const
{return "minecraft:grass";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
