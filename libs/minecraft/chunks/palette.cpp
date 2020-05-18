#include "palette.hpp"

#include "minecraft/encode.hpp"
#include "minecraft/net.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/types/var.hpp"

#include <boost/core/ignore_unused.hpp>

namespace minecraft::chunks
{
    std::uint16_t palette::add(blocks::block_type blk)
    {
        auto [i, b] = map_.insert(map_type::value_type(blk, blk, 0));
        auto &cnt   = i->get< frequency >();
        ++cnt;
        return cnt;
    }

    void palette::clear()
    {
        map_.clear();
        map_.insert(map_type::value_type(blocks::air(), blocks::air(), 1));
    }

    std::uint16_t palette::count(blocks::block_type blk) const
    {
        std::uint16_t result = 0;
        auto          i      = map_.by< block >().find(blk);
        if (i != map_.by< block >().end())
            result = i->get< frequency >();
        return result;
    }

    std::size_t palette::size() const { return map_.size(); }

    auto palette::to_block(int idx) const -> blocks::block_type
    {
        return map_.by< index >().at(idx).get< block >();
    }

    std::uint16_t palette::subtract(blocks::block_type blk)
    {
        auto i = map_.by< block >().find(blk);
        if (i == map_.by< block >().end())
            throw std::out_of_range("palette::subtract");
        auto &f = i->get< frequency >();
        assert(f > 0);
        if (--f <= 0)
        {
            map_.erase(map_.project_up(i));
            return 0;
        }
        else
        {
            return f;
        }
    }

    auto palette::to_index(blocks::block_type blk) const -> int
    {
        auto il = map_.by< block >().find(blk);
        if (il == map_.by< block >().end())
            throw std::out_of_range("palette::to_index");

        return std::distance(map_.by< index >().begin(),
                             map_.project< index >(il));
    }

    std::uint8_t compose(palette const &p, compose_buffer &buf)
    {
        boost::ignore_unused(buf);

        auto uplog2 = [](std::size_t n) {
            auto result = 0;
            while (n)
            {
                n >>= 1;
                result += 1;
            }
            result = std::max(result, 1);
            return result;
        };

        const auto size           = p.size();
        std::uint8_t       bits_per_block = static_cast<std::uint8_t>(uplog2(size));
        encode(bits_per_block, back_inserter(buf));
        if (bits_per_block < 9)
        {
            var_int x;
            x          = size;
            auto i     = encode(x, back_inserter(buf));
            auto first = p.map_.by< palette::index >().begin();
            auto last  = p.map_.by< palette::index >().end();
            for (; first != last; ++first)
            {
                x = first->second.value();
                i = encode(x, i);
            }
        }

        return static_cast< std::uint8_t >(bits_per_block);
    }

    auto parse(const_buffer_iterator first,
               const_buffer_iterator last,
               realised_palette &    p) -> const_buffer_iterator
    {
        using minecraft::parse;

        var_int length;
        auto    next = parse(first, last, length);
        p.impl_.resize(length.value(), boost::container::default_init);
        std::generate_n(p.impl_.begin(), length.value(), [&] {
            var_int v;
            next = parse(next, last, v);
            return v.value();
        });
        return next;
    }

    auto parse(const_buffer_iterator     first,
               const_buffer_iterator     last,
               realised_palette_concept &p) -> const_buffer_iterator
    {
        return visit(
            [first, last](auto &actual) { return parse(first, last, actual); },
            p.as_variant());
    }

}   // namespace minecraft::chunks
