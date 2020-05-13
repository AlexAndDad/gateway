#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct bubble_coral_block
{constexpr block_id_type to_id() const {
return 8981;}
constexpr static bubble_coral_block from_id(block_id_type id)
{
return bubble_coral_block();
}
constexpr std::string_view to_string() const
{return "minecraft:bubble_coral_block";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop