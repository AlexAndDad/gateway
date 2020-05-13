#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct jungle_sapling
{std::uint8_t stage = 0;
constexpr block_id_type to_id() const {
switch (stage)
{
case 0:
return 27;
case 1:
return 28;
}
}
constexpr static jungle_sapling from_id(block_id_type id)
{
switch (id)
{
case 27:
return {.stage = 0};
case 28:
return {.stage = 1};
}}
constexpr std::string_view to_string() const
{switch (stage)
{
case 0:
return "minecraft:jungle_sapling:0";
case 1:
return "minecraft:jungle_sapling:1";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
