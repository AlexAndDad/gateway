#pragma once
#include "minecraft/blocks/block.hpp"

#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/vector_of.hpp>

namespace minecraft::chunks
{
    /// Maps block id <-> palette index.
    /// Also maintains statistics on block population to allow the palette to
    /// grow as necessary
    struct palette
    {
        std::size_t add(blocks::block_id_type blk);

        std::size_t count(blocks::block_id_type blk) const;

        std::size_t size() const;

        std::size_t subtract(blocks::block_id_type blk);

        auto to_index(blocks::block_id_type blk) const -> int;

        auto to_block(int idx) const -> blocks::block_id_type;

      private:
        // clang-format off
        struct block {};
        struct index {};
        struct frequency {};

        template<typename...Ts> using tagged = boost::bimaps::tagged<Ts...>;
        template<typename...Ts> using unordered_set_of = boost::bimaps::unordered_set_of<Ts...>;
        template<typename...Ts> using vector_of = boost::bimaps::vector_of<Ts...>;
        template<typename...Ts> using with_info = boost::bimaps::with_info<Ts...>;

        using map_type =
        boost::bimap
        <
            unordered_set_of< tagged<blocks::block_id_type, block> >,
            vector_of< tagged< blocks::block_id_type, index > >,
            with_info< tagged< std::size_t, frequency > >
        >;
        // clang-format on
        map_type map_;
    };
}   // namespace minecraft::chunks