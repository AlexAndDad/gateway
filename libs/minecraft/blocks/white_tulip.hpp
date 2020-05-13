#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct white_tulip
{constexpr block_id_type to_id() const {
return 1418;}
constexpr static white_tulip from_id(block_id_type id)
{
return white_tulip();
}
constexpr std::string_view to_string() const
{return "minecraft:white_tulip";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
