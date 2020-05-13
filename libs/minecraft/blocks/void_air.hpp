#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct void_air
{constexpr block_id_type to_id() const {
return 9129;}
constexpr static void_air from_id(block_id_type id)
{
return void_air();
}
constexpr std::string_view to_string() const
{return "minecraft:void_air";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop