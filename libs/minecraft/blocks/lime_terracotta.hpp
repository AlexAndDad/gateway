#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct lime_terracotta
{constexpr block_id_type to_id() const {
return 6316;}
constexpr static lime_terracotta from_id(block_id_type id)
{
return lime_terracotta();
}
constexpr std::string_view to_string() const
{return "minecraft:lime_terracotta";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
