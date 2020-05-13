#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct wet_sponge
{constexpr block_id_type to_id() const {
return 229;}
constexpr static wet_sponge from_id(block_id_type id)
{
return wet_sponge();
}
constexpr std::string_view to_string() const
{return "minecraft:wet_sponge";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop