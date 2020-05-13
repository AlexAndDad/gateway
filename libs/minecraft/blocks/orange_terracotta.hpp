#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct orange_terracotta
{constexpr block_id_type to_id() const {
return 6312;}
constexpr static orange_terracotta from_id(block_id_type id)
{
return orange_terracotta();
}
constexpr std::string_view to_string() const
{return "minecraft:orange_terracotta";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
