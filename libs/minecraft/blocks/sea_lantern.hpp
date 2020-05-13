#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct sea_lantern
{constexpr block_id_type to_id() const {
return 7326;}
constexpr static sea_lantern from_id(block_id_type id)
{
return sea_lantern();
}
constexpr std::string_view to_string() const
{return "minecraft:sea_lantern";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
