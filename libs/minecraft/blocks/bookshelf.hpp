#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct bookshelf
{constexpr block_id_type to_id() const {
return 1431;}
constexpr static bookshelf from_id(block_id_type id)
{
return bookshelf();
}
constexpr std::string_view to_string() const
{return "minecraft:bookshelf";}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
