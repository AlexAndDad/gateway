#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct ice
{constexpr block_id_type to_id() const {
return 3927;}
constexpr static ice from_id(block_id_type id)
{
return ice();
}
constexpr std::string_view to_string() const
{return "minecraft:ice";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
