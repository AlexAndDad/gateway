#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct structure_block
{enum class mode_type : std::uint8_t
{
save,
load,
corner,
data
} mode = mode_type::save;
constexpr block_id_type to_id() const {
switch (mode)
{
case mode_type::save:
return 11268;
case mode_type::load:
return 11269;
case mode_type::corner:
return 11270;
case mode_type::data:
return 11271;
}
}
constexpr static structure_block from_id(block_id_type id)
{
switch (id)
{
case 11268:
return {.mode = mode_type::save};
case 11269:
return {.mode = mode_type::load};
case 11270:
return {.mode = mode_type::corner};
case 11271:
return {.mode = mode_type::data};
}}
constexpr std::string_view to_string() const
{switch (mode)
{
case mode_type::save:
return "minecraft:structure_block:save";
case mode_type::load:
return "minecraft:structure_block:load";
case mode_type::corner:
return "minecraft:structure_block:corner";
case mode_type::data:
return "minecraft:structure_block:data";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
