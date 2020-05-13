#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct orange_concrete
{constexpr block_id_type to_id() const {
return 8903;}
constexpr static orange_concrete from_id(block_id_type id)
{
return orange_concrete();
}
constexpr std::string_view to_string() const
{return "minecraft:orange_concrete";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
