#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct gray_terracotta
{constexpr block_id_type to_id() const {
return 6318;}
constexpr static gray_terracotta from_id(block_id_type id)
{
return gray_terracotta();
}
constexpr std::string_view to_string() const
{return "minecraft:gray_terracotta";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
