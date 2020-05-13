#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct brown_concrete_powder
{constexpr block_id_type to_id() const {
return 8930;}
constexpr static brown_concrete_powder from_id(block_id_type id)
{
return brown_concrete_powder();
}
constexpr std::string_view to_string() const
{return "minecraft:brown_concrete_powder";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop