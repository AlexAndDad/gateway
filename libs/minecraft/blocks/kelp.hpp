#pragma once
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"
namespace minecraft::blocks
{
using block_id_type = std::uint16_t;
struct kelp
{std::uint16_t age = 0;
constexpr block_id_type to_id() const {
switch (age)
{
case 0:
return 8934;
case 1:
return 8935;
case 2:
return 8936;
case 3:
return 8937;
case 4:
return 8938;
case 5:
return 8939;
case 6:
return 8940;
case 7:
return 8941;
case 8:
return 8942;
case 9:
return 8943;
case 10:
return 8944;
case 11:
return 8945;
case 12:
return 8946;
case 13:
return 8947;
case 14:
return 8948;
case 15:
return 8949;
case 16:
return 8950;
case 17:
return 8951;
case 18:
return 8952;
case 19:
return 8953;
case 20:
return 8954;
case 21:
return 8955;
case 22:
return 8956;
case 23:
return 8957;
case 24:
return 8958;
case 25:
return 8959;
}
}
constexpr static kelp from_id(block_id_type id)
{
switch (id)
{
case 8934:
return {.age = 0};
case 8935:
return {.age = 1};
case 8936:
return {.age = 2};
case 8937:
return {.age = 3};
case 8938:
return {.age = 4};
case 8939:
return {.age = 5};
case 8940:
return {.age = 6};
case 8941:
return {.age = 7};
case 8942:
return {.age = 8};
case 8943:
return {.age = 9};
case 8944:
return {.age = 10};
case 8945:
return {.age = 11};
case 8946:
return {.age = 12};
case 8947:
return {.age = 13};
case 8948:
return {.age = 14};
case 8949:
return {.age = 15};
case 8950:
return {.age = 16};
case 8951:
return {.age = 17};
case 8952:
return {.age = 18};
case 8953:
return {.age = 19};
case 8954:
return {.age = 20};
case 8955:
return {.age = 21};
case 8956:
return {.age = 22};
case 8957:
return {.age = 23};
case 8958:
return {.age = 24};
case 8959:
return {.age = 25};
}}
constexpr std::string_view to_string() const
{switch (age)
{
case 0:
return "minecraft:kelp:0";
case 1:
return "minecraft:kelp:1";
case 2:
return "minecraft:kelp:2";
case 3:
return "minecraft:kelp:3";
case 4:
return "minecraft:kelp:4";
case 5:
return "minecraft:kelp:5";
case 6:
return "minecraft:kelp:6";
case 7:
return "minecraft:kelp:7";
case 8:
return "minecraft:kelp:8";
case 9:
return "minecraft:kelp:9";
case 10:
return "minecraft:kelp:10";
case 11:
return "minecraft:kelp:11";
case 12:
return "minecraft:kelp:12";
case 13:
return "minecraft:kelp:13";
case 14:
return "minecraft:kelp:14";
case 15:
return "minecraft:kelp:15";
case 16:
return "minecraft:kelp:16";
case 17:
return "minecraft:kelp:17";
case 18:
return "minecraft:kelp:18";
case 19:
return "minecraft:kelp:19";
case 20:
return "minecraft:kelp:20";
case 21:
return "minecraft:kelp:21";
case 22:
return "minecraft:kelp:22";
case 23:
return "minecraft:kelp:23";
case 24:
return "minecraft:kelp:24";
case 25:
return "minecraft:kelp:25";
}
}};
}   // namespace minecraft::blocks

#pragma clang diagnostic pop
