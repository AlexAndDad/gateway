#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct spawner
{constexpr block_id_type to_id() const {
return 1951;}
constexpr static spawner from_id(block_id_type id)
{
return spawner();
}
constexpr std::string_view to_string() const
{return "minecraft:spawner";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
