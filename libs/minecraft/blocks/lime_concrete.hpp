#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct lime_concrete
{constexpr block_id_type to_id() const {
return 8907;}
constexpr static lime_concrete from_id(block_id_type id)
{
return lime_concrete();
}
constexpr std::string_view to_string() const
{return "minecraft:lime_concrete";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
