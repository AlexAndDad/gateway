#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct cornflower
{constexpr block_id_type to_id() const {
return 1421;}
constexpr static cornflower from_id(block_id_type id)
{
return cornflower();
}
constexpr std::string_view to_string() const
{return "minecraft:cornflower";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
