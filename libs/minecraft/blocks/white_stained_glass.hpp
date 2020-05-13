#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct white_stained_glass
{constexpr block_id_type to_id() const {
return 4081;}
constexpr static white_stained_glass from_id(block_id_type id)
{
return white_stained_glass();
}
constexpr std::string_view to_string() const
{return "minecraft:white_stained_glass";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
