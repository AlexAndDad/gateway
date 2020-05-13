#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct sea_pickle
{std::uint8_t pickles = 1;
bool waterlogged = true;
constexpr block_id_type to_id() const {
switch (pickles)
{
case 1:
switch (waterlogged)
{
case true:
return 9104;
case false:
return 9105;
}
case 2:
switch (waterlogged)
{
case true:
return 9106;
case false:
return 9107;
}
case 3:
switch (waterlogged)
{
case true:
return 9108;
case false:
return 9109;
}
case 4:
switch (waterlogged)
{
case true:
return 9110;
case false:
return 9111;
}
}
}
constexpr static sea_pickle from_id(block_id_type id)
{
switch (id)
{
case 9104:
return {.pickles = 1, .waterlogged = true};
case 9105:
return {.pickles = 1, .waterlogged = false};
case 9106:
return {.pickles = 2, .waterlogged = true};
case 9107:
return {.pickles = 2, .waterlogged = false};
case 9108:
return {.pickles = 3, .waterlogged = true};
case 9109:
return {.pickles = 3, .waterlogged = false};
case 9110:
return {.pickles = 4, .waterlogged = true};
case 9111:
return {.pickles = 4, .waterlogged = false};
}}
constexpr std::string_view to_string() const
{switch (pickles)
{
case 1:
switch (waterlogged)
{
case true:
return "minecraft:sea_pickle:1:true";
case false:
return "minecraft:sea_pickle:1:false";
}
case 2:
switch (waterlogged)
{
case true:
return "minecraft:sea_pickle:2:true";
case false:
return "minecraft:sea_pickle:2:false";
}
case 3:
switch (waterlogged)
{
case true:
return "minecraft:sea_pickle:3:true";
case false:
return "minecraft:sea_pickle:3:false";
}
case 4:
switch (waterlogged)
{
case true:
return "minecraft:sea_pickle:4:true";
case false:
return "minecraft:sea_pickle:4:false";
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
