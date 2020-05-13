#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct dead_horn_coral_block
{constexpr block_id_type to_id() const {
return 8978;}
constexpr static dead_horn_coral_block from_id(block_id_type id)
{
return dead_horn_coral_block();
}
constexpr std::string_view to_string() const
{return "minecraft:dead_horn_coral_block";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
