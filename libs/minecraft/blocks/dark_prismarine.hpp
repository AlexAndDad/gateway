#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dark_prismarine
{constexpr block_id_type to_id() const {
return 7067;}
constexpr static dark_prismarine from_id(block_id_type id)
{
return dark_prismarine();
}
constexpr std::string_view to_string() const
{return "minecraft:dark_prismarine";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
