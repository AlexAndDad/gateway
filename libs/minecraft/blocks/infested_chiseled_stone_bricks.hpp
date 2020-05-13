#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct infested_chiseled_stone_bricks
{constexpr block_id_type to_id() const {
return 4490;}
constexpr static infested_chiseled_stone_bricks from_id(block_id_type id)
{
return infested_chiseled_stone_bricks();
}
constexpr std::string_view to_string() const
{return "minecraft:infested_chiseled_stone_bricks";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
