#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct smooth_stone
{constexpr block_id_type to_id() const {
return 7878;}
constexpr static smooth_stone from_id(block_id_type id)
{
return smooth_stone();
}
constexpr std::string_view to_string() const
{return "minecraft:smooth_stone";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
