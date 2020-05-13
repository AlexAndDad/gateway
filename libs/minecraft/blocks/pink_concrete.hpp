#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct pink_concrete
{constexpr block_id_type to_id() const {
return 8908;}
constexpr static pink_concrete from_id(block_id_type id)
{
return pink_concrete();
}
constexpr std::string_view to_string() const
{return "minecraft:pink_concrete";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
