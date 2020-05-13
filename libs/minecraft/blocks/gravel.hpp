#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct gravel
{constexpr block_id_type to_id() const {
return 68;}
constexpr static gravel from_id(block_id_type id)
{
return gravel();
}
constexpr std::string_view to_string() const
{return "minecraft:gravel";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
