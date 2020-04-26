#include "keep_alive.hpp"
#include "minecraft/parse.hpp"

namespace minecraft::packets::server
{
    std::ostream &operator<<(std::ostream &os, const keep_alive &arg)
    {
        os << "keep_alive_id: " << arg.keep_alive_id;
        return os;
    }

    void compose(const keep_alive &arg, std::vector< char > &target)
    {
        auto i = std::back_inserter(target);
        i      = encode(variable_length(arg.id()), i);
        encode(arg.keep_alive_id, i);
    }

    const_buffer_iterator parse(const_buffer_iterator first, const_buffer_iterator last, keep_alive& pkt, error_code& ec)
    {
        using minecraft::parse;

        return parse(first, last, pkt.keep_alive_id, ec);
    }

}   // namespace minecraft::packets::server
