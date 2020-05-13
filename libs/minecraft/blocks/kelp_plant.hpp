#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct kelp_plant
{constexpr block_id_type to_id() const {
return 8960;}
constexpr static kelp_plant from_id(block_id_type id)
{
return kelp_plant();
}
constexpr std::string_view to_string() const
{return "minecraft:kelp_plant";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
