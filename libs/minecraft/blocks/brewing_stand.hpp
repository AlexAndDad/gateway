#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct brewing_stand
{bool has_bottle_0 = false;
bool has_bottle_1 = false;
bool has_bottle_2 = false;
constexpr block_id_type to_id() const {
switch (has_bottle_0)
{
case true:
switch (has_bottle_1)
{
case true:
switch (has_bottle_2)
{
case true:
return 5117;
case false:
return 5118;
}
case false:
switch (has_bottle_2)
{
case true:
return 5119;
case false:
return 5120;
}
}
case false:
switch (has_bottle_1)
{
case true:
switch (has_bottle_2)
{
case true:
return 5121;
case false:
return 5122;
}
case false:
switch (has_bottle_2)
{
case true:
return 5123;
case false:
return 5124;
}
}
}
}
constexpr static brewing_stand from_id(block_id_type id)
{
switch (id)
{
case 5117:
return {.has_bottle_0 = true, .has_bottle_1 = true, .has_bottle_2 = true};
case 5118:
return {.has_bottle_0 = true, .has_bottle_1 = true, .has_bottle_2 = false};
case 5119:
return {.has_bottle_0 = true, .has_bottle_1 = false, .has_bottle_2 = true};
case 5120:
return {.has_bottle_0 = true, .has_bottle_1 = false, .has_bottle_2 = false};
case 5121:
return {.has_bottle_0 = false, .has_bottle_1 = true, .has_bottle_2 = true};
case 5122:
return {.has_bottle_0 = false, .has_bottle_1 = true, .has_bottle_2 = false};
case 5123:
return {.has_bottle_0 = false, .has_bottle_1 = false, .has_bottle_2 = true};
case 5124:
return {.has_bottle_0 = false, .has_bottle_1 = false, .has_bottle_2 = false};
}}
constexpr std::string_view to_string() const
{switch (has_bottle_0)
{
case true:
switch (has_bottle_1)
{
case true:
switch (has_bottle_2)
{
case true:
return "minecraft:brewing_stand:true:true:true";
case false:
return "minecraft:brewing_stand:true:true:false";
}
case false:
switch (has_bottle_2)
{
case true:
return "minecraft:brewing_stand:true:false:true";
case false:
return "minecraft:brewing_stand:true:false:false";
}
}
case false:
switch (has_bottle_1)
{
case true:
switch (has_bottle_2)
{
case true:
return "minecraft:brewing_stand:false:true:true";
case false:
return "minecraft:brewing_stand:false:true:false";
}
case false:
switch (has_bottle_2)
{
case true:
return "minecraft:brewing_stand:false:false:true";
case false:
return "minecraft:brewing_stand:false:false:false";
}
}
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
