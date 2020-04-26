//
// Created by rhodges on 13/04/2020.
//

#include "join_game.hpp"

#include "minecraft/parse.hpp"

#include <fmt/ostream.h>

namespace minecraft::packets::server
{
    void compose(join_game const &packet, std::vector< char > &target)
    {
        using minecraft::encode;
        auto i1 = std::back_inserter(target);
        i1      = encode(variable_length(packet.id()), i1);
        i1      = encode(packet.entity_id, i1);
        i1      = encode(packet.game_mode, i1);
        i1      = encode(packet.dimension, i1);
        i1      = encode(packet.hashed_seed, i1);
        i1      = encode(packet.max_players, i1);
        i1      = encode(packet.level_type, i1);
        i1      = encode(packet.view_distance, i1);
        i1      = encode(packet.reduced_debug_info, i1);
        encode(packet.enable_respawn_screen, i1);
    }

    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, join_game &pkt, error_code &ec)
    {
        auto ret = first;

        using minecraft::parse;
        first = parse(first, last, pkt.entity_id, ec);
        first = parse(first, last, pkt.game_mode, ec);
        first = parse(first, last, pkt.dimension, ec);
        first = parse(first, last, pkt.hashed_seed, ec);
        first = parse(first, last, pkt.max_players, ec);
        first = parse(first, last, pkt.level_type, ec);
        first = parse(first, last, pkt.view_distance, ec);
        first = parse(first, last, pkt.reduced_debug_info, ec);
        first = parse(first, last, pkt.enable_respawn_screen, ec);
        if (not ec)
            ret = first;
        return ret;
    }

    std::ostream &operator<<(std::ostream &os, join_game const &pkt)
    {
        auto use = [](auto&&...) {};
        use(pkt);
        fmt::print(os, "[]");
        return os;
    }

}   // namespace minecraft::packets::server