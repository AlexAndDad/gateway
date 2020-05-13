#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct potted_cornflower
{constexpr block_id_type to_id() const {
return 5787;}
constexpr static potted_cornflower from_id(block_id_type id)
{
return potted_cornflower();
}
constexpr std::string_view to_string() const
{return "minecraft:potted_cornflower";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop