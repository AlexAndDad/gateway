#include "palette.hpp"

#include "minecraft/net.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/types/var.hpp"

#include <boost/core/ignore_unused.hpp>

namespace minecraft::chunks
{
    std::size_t palette::add(blocks::block_id_type blk)
    {
        auto [i, b] = map_.insert(map_type::value_type(blk, 0));
        auto &cnt   = i->get< frequency >();
        ++cnt;
        return cnt;
    }

    std::size_t palette::count(blocks::block_id_type blk) const
    {
        std::size_t result = 0;
        auto        i      = map_.by< block >().find(blk);
        if (i != map_.by< block >().end())
            result = i->get< frequency >();
        return result;
    }

    std::size_t palette::size() const { return map_.size(); }

    auto palette::to_block(int idx) const -> blocks::block_id_type
    {
        return map_.by< index >().at(idx).get< block >();
    }

    std::size_t palette::subtract(blocks::block_id_type blk)
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

    auto palette::to_index(blocks::block_id_type blk) const -> int
    {
        auto il = map_.by< block >().find(blk);
        if (il == map_.by< block >().end())
            throw std::out_of_range("palette::to_index");

        return std::distance(map_.by< index >().begin(),
                             map_.project< index >(il));
    }

    void palette::compose(compose_buffer &buf) const
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

        auto bits_per_block = uplog2(size());

        if (bits_per_block <= 4)
            bits_per_block = 4;
        else if (bits_per_block <= 8)
            bits_per_block = 8;
        else
            bits_per_block = 14;
    }

    void compose(palette const &p, compose_buffer &buf) { p.compose(buf); }

    auto realised_palette::handle_parse(const_buffer_iterator first,
                                        const_buffer_iterator last)
        -> const_buffer_iterator
    {
        using minecraft::parse;

        var_int length;
        auto    next = parse(first, last, length);
        impl_.clear();
        impl_.resize(length.value(), boost::container::default_init);
        std::generate_n(impl_.begin(), length.value(), [&] {
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
        return p.handle_parse(first, last);
    }

}   // namespace minecraft::chunks
