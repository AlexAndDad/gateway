#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct large_fern
{enum class half_type : std::uint8_t
{
upper,
lower
} half = half_type::lower;
constexpr block_id_type to_id() const {
switch (half)
{
case half_type::upper:
return 7359;
case half_type::lower:
return 7360;
}
}
constexpr static large_fern from_id(block_id_type id)
{
switch (id)
{
case 7359:
return {.half = half_type::upper};
case 7360:
return {.half = half_type::lower};
}}
constexpr std::string_view to_string() const
{switch (half)
{
case half_type::upper:
return "minecraft:large_fern:upper";
case half_type::lower:
return "minecraft:large_fern:lower";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
