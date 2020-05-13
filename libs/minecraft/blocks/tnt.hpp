#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct tnt
{bool unstable = false;
constexpr block_id_type to_id() const {
switch (unstable)
{
case true:
return 1429;
case false:
return 1430;
}
}
constexpr static tnt from_id(block_id_type id)
{
switch (id)
{
case 1429:
return {.unstable = true};
case 1430:
return {.unstable = false};
}}
constexpr std::string_view to_string() const
{switch (unstable)
{
case true:
return "minecraft:tnt:true";
case false:
return "minecraft:tnt:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
