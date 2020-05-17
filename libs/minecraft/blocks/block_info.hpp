#pragma once
#include "blocks/block.hpp"
#include "minecraft/overloaded.hpp"

#include <boost/functional/hash/hash.hpp>

namespace minecraft::blocks
{
    struct block_type
    {
        explicit constexpr block_type(block_id_type v = air().to_id())
        : value_(v)
        {
        }

        template < class BlockInstance,
                   class = std::void_t<
                       decltype(std::declval< BlockInstance >().to_id()) > >
        constexpr block_type(BlockInstance bi)
        : value_(bi.to_id())
        {
        }

        constexpr bool operator==(block_type const &r) const
        {
            return value_ == r.value_;
        }

        constexpr bool operator!=(block_type const &r) const
        {
            return value_ != r.value_;
        }

        friend std::size_t hash_value(block_type const &bt)
        {
            return boost::hash_value(bt.value());
        }

        constexpr block_id_type value() const { return value_; }

      private:
        block_id_type value_;
    };

    inline std::string_view to_string(block_type const &blk)
    {
        return visit_block_id([](auto &&actual) { return actual.to_string(); },
                              blk.value());
    }

    inline std::ostream &operator<<(std::ostream &os, block_type const &blk)
    {
        os << to_string(blk);
        return os;
    }

    inline constexpr bool is_transparent(block_id_type id)
    {
        return visit_block_id(overloaded { [](air) { return true; },
                                           [](void_air) { return true; },
                                           [](cave_air) { return true; },
                                           [](auto) { return false; } },
                              id);
    }

    inline constexpr bool is_transparent(block_type blk)
    {
        return is_transparent(blk.value());
    }
}   // namespace minecraft::blocks

namespace std
{
    template <>
    struct hash< minecraft::blocks::block_type >
    : boost::hash< minecraft::blocks::block_type >
    {
    };
}   // namespace std