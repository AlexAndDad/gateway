#include "minecraft/server/spawn_position.hpp"
#include "minecraft/parse.hpp"
#include <fmt/ostream.h>
namespace minecraft::server
{
    std::ostream &operator<<(std::ostream &os, spawn_position const &arg)
    {
        fmt::print(os, "[frame {} [location {}]]", wise_enum::to_string(arg.id()), arg.location);
        return os;
    }

    const_buffer_iterator
    parse(const_buffer_iterator first, const_buffer_iterator last, spawn_position &packet, error_code &ec)
    {
        using minecraft::parse;
        first = parse(first, last, packet.location, ec);
        return first;
    }

}   // namespace minecraft::server