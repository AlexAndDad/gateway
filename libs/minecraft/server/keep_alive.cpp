#include "minecraft/server/keep_alive.hpp"

namespace minecraft::server
{
    std::ostream &operator<<(std::ostream &os, const keep_alive &arg)
    {
        os << "keep_alive_id: " << arg.keep_alive_id;
        return os;
    }

    void compose(const keep_alive &arg, std::vector< char > &target)
    {
        auto i = std::back_inserter(target);
        i      = encode(arg.id(), i);
        encode(arg.keep_alive_id, i);
    }
}   // namespace minecraft::server
