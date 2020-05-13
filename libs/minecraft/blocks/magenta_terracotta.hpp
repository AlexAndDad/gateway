#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct magenta_terracotta
{constexpr block_id_type to_id() const {
return 6313;}
constexpr static magenta_terracotta from_id(block_id_type id)
{
return magenta_terracotta();
}
constexpr std::string_view to_string() const
{return "minecraft:magenta_terracotta";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
