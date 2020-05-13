#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct smooth_sandstone
{constexpr block_id_type to_id() const {
return 7879;}
constexpr static smooth_sandstone from_id(block_id_type id)
{
return smooth_sandstone();
}
constexpr std::string_view to_string() const
{return "minecraft:smooth_sandstone";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
