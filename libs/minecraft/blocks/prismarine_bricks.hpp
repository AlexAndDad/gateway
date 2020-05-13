#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct prismarine_bricks
{constexpr block_id_type to_id() const {
return 7066;}
constexpr static prismarine_bricks from_id(block_id_type id)
{
return prismarine_bricks();
}
constexpr std::string_view to_string() const
{return "minecraft:prismarine_bricks";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
