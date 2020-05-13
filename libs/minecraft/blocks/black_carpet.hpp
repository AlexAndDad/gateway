#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct black_carpet
{constexpr block_id_type to_id() const {
return 7345;}
constexpr static black_carpet from_id(block_id_type id)
{
return black_carpet();
}
constexpr std::string_view to_string() const
{return "minecraft:black_carpet";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
