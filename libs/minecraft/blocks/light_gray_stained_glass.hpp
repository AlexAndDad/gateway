#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct light_gray_stained_glass
{constexpr block_id_type to_id() const {
return 4089;}
constexpr static light_gray_stained_glass from_id(block_id_type id)
{
return light_gray_stained_glass();
}
constexpr std::string_view to_string() const
{return "minecraft:light_gray_stained_glass";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
