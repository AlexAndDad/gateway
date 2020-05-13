#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct coarse_dirt
{constexpr block_id_type to_id() const {
return 11;}
constexpr static coarse_dirt from_id(block_id_type id)
{
return coarse_dirt();
}
constexpr std::string_view to_string() const
{return "minecraft:coarse_dirt";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
