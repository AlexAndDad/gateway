#pragma once
#include "minecraft/blocks/block_info.hpp"
#include "minecraft/types/buffer.hpp"

#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/vector_of.hpp>
#include <boost/container/vector.hpp>

namespace minecraft::chunks
{
    /// Maps block id <-> palette index.
    /// Also maintains statistics on block population to allow the palette to
    /// grow as necessary
    struct palette
    {
        using block_type = blocks::block_type;

        std::size_t add(block_type blk);

        void compose(compose_buffer &buf) const;

        void clear();

        std::size_t count(block_type blk) const;

        std::size_t size() const;

        std::size_t subtract(block_type blk);

        auto to_index(block_type blk) const -> int;

        auto to_block(int idx) const -> block_type;

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
            unordered_set_of< tagged<block_type, block> >,
            vector_of< tagged< block_type, index > >,
            with_info< tagged< std::size_t, frequency > >
        >;
        // clang-format on
        map_type map_;
    };

    /// For reacding block data from the wire

    struct realised_palette_concept
    {
        using block_type = blocks::block_type;

        std::size_t size() const { return handle_size(); }

        block_type operator[](int idx) const { return to_block(idx); }

      private:
        virtual block_type to_block(int index) const = 0;

        virtual const_buffer_iterator
        handle_parse(const_buffer_iterator first,
                     const_buffer_iterator last) = 0;

        virtual std::size_t handle_size() const = 0;

        friend auto parse(const_buffer_iterator     first,
                          const_buffer_iterator     last,
                          realised_palette_concept &p) -> const_buffer_iterator;
    };

    struct realised_palette final : realised_palette_concept
    {
        realised_palette()
        : impl_()
        {
        }

        virtual block_type to_block(int index) const override
        {
            return block_type(impl_.at(index));
        }

      private:
        virtual const_buffer_iterator
        handle_parse(const_buffer_iterator first,
                     const_buffer_iterator last) override;

        std::size_t handle_size() const override { return impl_.size(); }

        boost::container::vector< std::int32_t > impl_;
    };

    struct null_palette final : realised_palette_concept
    {
      private:
        block_type to_block(int index) const override
        {
            return block_type(index);
        }

        auto handle_parse(const_buffer_iterator first, const_buffer_iterator)
            -> const_buffer_iterator override
        {
            return first;
        }

        auto handle_size() const -> std::size_t override { return 0; }
    };

    void compose(palette const &p, compose_buffer &buf);

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, palette &p);
}   // namespace minecraft::chunks