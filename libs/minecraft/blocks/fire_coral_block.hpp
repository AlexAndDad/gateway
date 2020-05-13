#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct fire_coral_block
{constexpr block_id_type to_id() const {
return 8982;}
constexpr static fire_coral_block from_id(block_id_type id)
{
return fire_coral_block();
}
constexpr std::string_view to_string() const
{return "minecraft:fire_coral_block";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
