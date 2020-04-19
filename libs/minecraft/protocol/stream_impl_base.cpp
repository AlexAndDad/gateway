//
// Created by rhodges on 19/04/2020.
//

#include "stream_impl_base.hpp"

namespace minecraft::protocol
{
    std::ostream &operator<<(std::ostream &os, stream_impl_base const &base)
    {
        fmt::print(os,
                   "[player_name {}] [protocol {}] [compression {}] [encryption {}] [hostname {}] [port {}]",
                   base.player_name,
                   wise_enum::to_string(base.protocol_version_),
                   base.compression_threshold_,
                   (base.encryption_ ? "yes" : "no"),
                   base.hostname,
                   base.port);

        return os;
    }

}   // namespace minecraft::protocol