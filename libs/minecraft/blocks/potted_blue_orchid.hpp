#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct potted_blue_orchid
{constexpr block_id_type to_id() const {
return 5779;}
constexpr static potted_blue_orchid from_id(block_id_type id)
{
return potted_blue_orchid();
}
constexpr std::string_view to_string() const
{return "minecraft:potted_blue_orchid";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
