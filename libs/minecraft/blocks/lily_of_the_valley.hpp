#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct lily_of_the_valley
{constexpr block_id_type to_id() const {
return 1423;}
constexpr static lily_of_the_valley from_id(block_id_type id)
{
return lily_of_the_valley();
}
constexpr std::string_view to_string() const
{return "minecraft:lily_of_the_valley";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop