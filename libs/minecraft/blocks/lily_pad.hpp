#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct lily_pad
{constexpr block_id_type to_id() const {
return 4998;}
constexpr static lily_pad from_id(block_id_type id)
{
return lily_pad();
}
constexpr std::string_view to_string() const
{return "minecraft:lily_pad";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop