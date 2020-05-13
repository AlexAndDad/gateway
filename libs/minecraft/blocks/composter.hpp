#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct composter
{std::uint8_t level = 0;
constexpr block_id_type to_id() const {
switch (level)
{
case 0:
return 11278;
case 1:
return 11279;
case 2:
return 11280;
case 3:
return 11281;
case 4:
return 11282;
case 5:
return 11283;
case 6:
return 11284;
case 7:
return 11285;
case 8:
return 11286;
}
}
constexpr static composter from_id(block_id_type id)
{
switch (id)
{
case 11278:
return {.level = 0};
case 11279:
return {.level = 1};
case 11280:
return {.level = 2};
case 11281:
return {.level = 3};
case 11282:
return {.level = 4};
case 11283:
return {.level = 5};
case 11284:
return {.level = 6};
case 11285:
return {.level = 7};
case 11286:
return {.level = 8};
}}
constexpr std::string_view to_string() const
{switch (level)
{
case 0:
return "minecraft:composter:0";
case 1:
return "minecraft:composter:1";
case 2:
return "minecraft:composter:2";
case 3:
return "minecraft:composter:3";
case 4:
return "minecraft:composter:4";
case 5:
return "minecraft:composter:5";
case 6:
return "minecraft:composter:6";
case 7:
return "minecraft:composter:7";
case 8:
return "minecraft:composter:8";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
