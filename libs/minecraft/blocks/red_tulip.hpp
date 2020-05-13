#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct red_tulip
{constexpr block_id_type to_id() const {
return 1416;}
constexpr static red_tulip from_id(block_id_type id)
{
return red_tulip();
}
constexpr std::string_view to_string() const
{return "minecraft:red_tulip";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
