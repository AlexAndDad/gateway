#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct smooth_red_sandstone
{constexpr block_id_type to_id() const {
return 7881;}
constexpr static smooth_red_sandstone from_id(block_id_type id)
{
return smooth_red_sandstone();
}
constexpr std::string_view to_string() const
{return "minecraft:smooth_red_sandstone";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop