#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct pink_carpet
{constexpr block_id_type to_id() const {
return 7336;}
constexpr static pink_carpet from_id(block_id_type id)
{
return pink_carpet();
}
constexpr std::string_view to_string() const
{return "minecraft:pink_carpet";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop