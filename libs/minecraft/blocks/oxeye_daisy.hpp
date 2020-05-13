#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct oxeye_daisy
{constexpr block_id_type to_id() const {
return 1420;}
constexpr static oxeye_daisy from_id(block_id_type id)
{
return oxeye_daisy();
}
constexpr std::string_view to_string() const
{return "minecraft:oxeye_daisy";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
