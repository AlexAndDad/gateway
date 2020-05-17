#include "palette.hpp"

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
        auto i = map_.by<block>().find(blk);
        if (i == map_.by<block>().end())
            throw std::out_of_range("palette::subtract");
        auto& f = i->get<frequency>();
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

}   // namespace minecraft::chunks
