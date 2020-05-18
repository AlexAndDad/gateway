#pragma once
#include "blocks/block_info.hpp"
#include "minecraft/blocks/block_info.hpp"
#include "minecraft/types/buffer.hpp"
#include "minecraft/variant.hpp"

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

        std::uint16_t add(block_type blk);

        void clear();

        std::uint16_t count(block_type blk) const;

        template < class Pred >
        auto count_if(Pred &&pred) const -> std::uint16_t;

        std::size_t size() const;

        std::uint16_t subtract(block_type blk);

        auto to_index(block_type blk) const -> int;

        auto to_block(int idx) const -> block_type;

        /// Compose the palette and return the number of bits per word for subsequent
        /// encoding.
        /// \param p
        /// \param buf
        /// \return the number of bits per word to used for encoding
        friend std::uint8_t compose(palette const& p, compose_buffer& buf);

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
            with_info< tagged< std::uint16_t, frequency > >
        >;
        // clang-format on
        map_type map_;
    };

    /// For reacding block data from the wire

    struct realised_palette
    {
        using block_type = blocks::block_type;

        realised_palette()
        : impl_()
        {
        }

        block_type to_block(std::uint16_t index) const
        {
            return block_type(impl_.at(index));
        }

        std::uint16_t size() const
        {
            return static_cast< std::uint16_t >(impl_.size());
        }

        friend auto parse(const_buffer_iterator first,
                          const_buffer_iterator last,
                          realised_palette &    p) -> const_buffer_iterator;

      private:
        boost::container::vector< blocks::block_id_type > impl_;
    };

    inline std::uint16_t size(realised_palette const &p) { return p.size(); }
    void          compose(realised_palette const &p, compose_buffer &buf);

    struct null_palette
    {
        using block_type = blocks::block_type;

        block_type to_block(std::uint16_t index) const
        {
            return block_type(blocks::block_id_type(index));
        }

        constexpr std::uint16_t size() const { return 0; }
    };

    inline auto parse(const_buffer_iterator first,
               const_buffer_iterator,
               null_palette &) -> const_buffer_iterator
    {
        return first;
    }

    inline std::uint16_t size(null_palette const &) { return 0; }
    void          compose(null_palette const &p, compose_buffer &buf);

    struct realised_palette_concept
    {
        using impl_type = variant< null_palette, realised_palette >;

        explicit realised_palette_concept(std::uint8_t bits_per_block)
        : var_(bits_per_block >= 9 ? impl_type(null_palette())
                                   : impl_type(realised_palette()))
        {
        }

        std::uint16_t size() const
        {
            return visit([](auto &actual) { return actual.size(); }, var_);
        }

        blocks::block_type operator[](std::uint16_t idx) const
        {
            return visit([idx](auto &actual) { return actual.to_block(idx); },
                         var_);
        }

        impl_type &      as_variant() { return var_; }
        impl_type const &as_variant() const { return var_; }

      private:
        impl_type var_;
    };

    auto parse(const_buffer_iterator     first,
               const_buffer_iterator     last,
               realised_palette_concept &p) -> const_buffer_iterator;

    inline std::uint16_t size(realised_palette_concept const &p) { return p.size(); }
    void compose(realised_palette_concept const &p, compose_buffer &buf);


    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, palette &p);
}   // namespace minecraft::chunks

namespace minecraft::chunks
{
    template < class Pred >
    auto palette::count_if(Pred &&pred) const -> std::uint16_t
    {
        auto result = std::uint16_t(0);
        for (auto &&e : map_)
        {
            if (pred(e.get< block >()))
                result += e.get< frequency >();
        }
        return result;
    }
}   // namespace minecraft::chunks