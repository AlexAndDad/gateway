#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct light_blue_carpet
{constexpr block_id_type to_id() const {
return 7333;}
constexpr static light_blue_carpet from_id(block_id_type id)
{
return light_blue_carpet();
}
constexpr std::string_view to_string() const
{return "minecraft:light_blue_carpet";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
