#pragma once

#include <boost/variant2/variant.hpp>
#include <string_view>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
#pragma clang diagnostic ignored "-Wswitch-bool"



namespace minecraft::blocks
{
    using block_id_type = std::uint16_t;

    struct air
    {
        constexpr block_id_type    to_id() const { return 0; }
        constexpr static air       from_id(block_id_type) { return air(); }
        constexpr std::string_view to_string() const { return "minecraft:air"; }
    };

    struct oak_leaves
    {
        std::uint8_t distance   = 7;
        bool         persistent = false;

        constexpr std::string_view to_string() const
        {
            switch (distance)
            {
            case 1:
                return persistent ? "minecraft:oak_leaves:1:true" : "minecraft:oak_leaves:1:false";
            case 2:
                return persistent ? "minecraft:oak_leaves:2:true" : "minecraft:oak_leaves:2:false";
            case 3:
                return persistent ? "minecraft:oak_leaves:3:true" : "minecraft:oak_leaves:3:false";
            case 4:
                return persistent ? "minecraft:oak_leaves:4:true" : "minecraft:oak_leaves:4:false";
            case 5:
                return persistent ? "minecraft:oak_leaves:5:true" : "minecraft:oak_leaves:5:false";
            case 6:
                return persistent ? "minecraft:oak_leaves:6:true" : "minecraft:oak_leaves:6:false";
            case 7:
                return persistent ? "minecraft:oak_leaves:7:true" : "minecraft:oak_leaves:7:false";
            }
        }

        constexpr block_id_type to_id() const
        {
            switch (distance)
            {
            case 1:
                return persistent ? 144 : 145;
            case 2:
                return persistent ? 146 : 147;
            case 3:
                return persistent ? 148 : 149;
            case 4:
                return persistent ? 150 : 151;
            case 5:
                return persistent ? 152 : 153;
            case 6:
                return persistent ? 154 : 155;
            case 7:
                return persistent ? 156 : 157;
            }
        }

        constexpr static oak_leaves from_id(block_id_type id)
        {
            switch (id)
            {
            case 144:
                return oak_leaves { 1, true };
            case 145:
                return oak_leaves { 1, false };
            case 146:
                return oak_leaves { 2, true };
            case 147:
                return oak_leaves { 2, false };
            case 148:
                return oak_leaves { 3, true };
            case 149:
                return oak_leaves { 3, false };
            case 150:
                return oak_leaves { 4, true };
            case 151:
                return oak_leaves { 4, false };
            case 152:
                return oak_leaves { 5, true };
            case 153:
                return oak_leaves { 5, false };
            case 154:
                return oak_leaves { 6, true };
            case 155:
                return oak_leaves { 6, false };
            case 156:
                return oak_leaves { 7, true };
            case 157:
                return oak_leaves { 7, false };
            }
        }
    };

    struct sticky_piston
    {
        bool extended = false;
        enum class facing_type: std::uint8_t
        {
            north,
            east,
            south,
            west,
            up,
            down
        } facing = facing_type::north;
        constexpr block_id_type to_id() const
        {
            switch (extended)
            {
            case true:
                switch (facing)
                {
                case north:
                    return 1328;
                case east:
                    return 1329;
                case south:
                    return 1330;
                case west:
                    return 1331;
                case up:
                    return 1332;
                case down:
                    return 1333;
                }
            case false:
                switch (facing)
                {
                case north:
                    return 1334;
                case east:
                    return 1335;
                case south:
                    return 1336;
                case west:
                    return 1337;
                case up:
                    return 1338;
                case down:
                    return 1339;
                }
            }
        }

        constexpr static sticky_piston from_id(block_id_type id)
        {
            switch (id)
            {
            case 1328:
                return { .extended = true, .facing = north };
            case 1329:
                return { .extended = true, .facing = east };
            case 1330:
                return { .extended = true, .facing = south };
            case 1331:
                return { .extended = true, .facing = west };
            case 1332:
                return { .extended = true, .facing = up };
            case 1333:
                return { .extended = true, .facing = down };
            case 1334:
                return { .extended = false, .facing = north };
            case 1335:
                return { .extended = false, .facing = east };
            case 1336:
                return { .extended = false, .facing = south };
            case 1337:
                return { .extended = false, .facing = west };
            case 1338:
                return { .extended = false, .facing = up };
            case 1339:
                return { .extended = false, .facing = down };
            }
        }

        constexpr std::string_view to_string() const
        {
            switch (extended)
            {
            case true:
                switch (facing)
                {
                case north:
                    return "minecraft:sticky_piston:true:north";
                case east:
                    return "minecraft:sticky_piston:true:east";
                case south:
                    return "minecraft:sticky_piston:true:south";
                case west:
                    return "minecraft:sticky_piston:true:west";
                case up:
                    return "minecraft:sticky_piston:true:up";
                case down:
                    return "minecraft:sticky_piston:true:down";
                }
            case false:
                switch (facing)
                {
                case north:
                    return "minecraft:sticky_piston:false:north";
                case east:
                    return "minecraft:sticky_piston:false:east";
                case south:
                    return "minecraft:sticky_piston:false:south";
                case west:
                    return "minecraft:sticky_piston:false:west";
                case up:
                    return "minecraft:sticky_piston:false:up";
                case down:
                    return "minecraft:sticky_piston:false:down";
                }
            }
        }
    };





    constexpr block_variant to_block(block_id_type id)
    {
        switch (id)
        {
        case 0:
            return air::from_id(id);
        case 144:
        case 145:
        case 146:
        case 147:
        case 148:
        case 149:
        case 150:
        case 151:
        case 152:
        case 153:
        case 154:
        case 155:
        case 156:
        case 157:
            return oak_leaves::from_id(id);
        case 1328:
        case 1329:
        case 1330:
        case 1331:
        case 1332:
        case 1333:
        case 1334:
        case 1335:
        case 1336:
        case 1337:
        case 1338:
        case 1339:
            return sticky_piston::from_id(id);

        }
    }

    template <class F>
    constexpr auto visit_block_id(F && func, block_id_type id) -> decltype(auto)
    {
        switch (id)
        {
        case 0:
            return func(air::from_id(id));
        case 144:
        case 145:
        case 146:
        case 147:
        case 148:
        case 149:
        case 150:
        case 151:
        case 152:
        case 153:
        case 154:
        case 155:
        case 156:
        case 157:
            return func(oak_leaves::from_id(id));
        case 1328:
        case 1329:
        case 1330:
        case 1331:
        case 1332:
        case 1333:
        case 1334:
        case 1335:
        case 1336:
        case 1337:
        case 1338:
        case 1339:
            return func(sticky_piston::from_id(id));
    }


        constexpr std::string_view id_to_string(block_id_type id)
        {
            return visit_block_id([](auto && block){return block.to_string();}, id);
        }

}   // namespace minecraft::blocks

#pragma clang diagnostic pop
