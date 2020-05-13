#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct grass_path
{constexpr block_id_type to_id() const {
return 8687;}
constexpr static grass_path from_id(block_id_type id)
{
return grass_path();
}
constexpr std::string_view to_string() const
{return "minecraft:grass_path";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
