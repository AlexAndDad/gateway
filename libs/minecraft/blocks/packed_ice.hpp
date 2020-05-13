#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct packed_ice
{constexpr block_id_type to_id() const {
return 7348;}
constexpr static packed_ice from_id(block_id_type id)
{
return packed_ice();
}
constexpr std::string_view to_string() const
{return "minecraft:packed_ice";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
