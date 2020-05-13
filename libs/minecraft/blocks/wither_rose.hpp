#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct wither_rose
{constexpr block_id_type to_id() const {
return 1422;}
constexpr static wither_rose from_id(block_id_type id)
{
return wither_rose();
}
constexpr std::string_view to_string() const
{return "minecraft:wither_rose";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
