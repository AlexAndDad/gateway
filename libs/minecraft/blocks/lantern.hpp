#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct lantern
{bool hanging = false;
constexpr block_id_type to_id() const {
switch (hanging)
{
case true:
return 11230;
case false:
return 11231;
}
}
constexpr static lantern from_id(block_id_type id)
{
switch (id)
{
case 11230:
return {.hanging = true};
case 11231:
return {.hanging = false};
}}
constexpr std::string_view to_string() const
{switch (hanging)
{
case true:
return "minecraft:lantern:true";
case false:
return "minecraft:lantern:false";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
