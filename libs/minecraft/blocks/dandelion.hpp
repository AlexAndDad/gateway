#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dandelion
{constexpr block_id_type to_id() const {
return 1411;}
constexpr static dandelion from_id(block_id_type id)
{
return dandelion();
}
constexpr std::string_view to_string() const
{return "minecraft:dandelion";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
