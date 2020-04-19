#pragma once

#include "minecraft/net.hpp"
#include "minecraft/types.hpp"
#include "minecraft/parse_error.hpp"
#include <boost/mp11/tuple.hpp>

namespace minecraft::protocol
{
    template < class FrameType >
    auto expect_frame(net::const_buffer source, FrameType &target, error_code &ec) -> error_code &
    {
        ec.clear();

        var_enum< decltype(target.id()) > which;
        auto                              first = reinterpret_cast< const char * >(source.data());
        auto                              last  = first + source.size();

        auto next = parse(first, last, which, ec);

        if (not ec.failed())
        {
            if (which == target.id())
            {
                next = parse(next, last, target, ec);
                if (not ec.failed())
                    if (next != last)
                        ec = error::invalid_packet;
            }
            else
            {
                ec = error::unexpected_packet;
            }
        }
        return ec;
    }

    template < class Enum, class... FrameTypes >
    auto expect_frames(net::const_buffer             source,
                       var_enum< Enum > &            which,
                       std::tuple< FrameTypes &... > targets,
                       error_code &                  ec) -> error_code &
    {
        ec.clear();

        auto first = reinterpret_cast< const char * >(source.data());
        auto last  = first + source.size();

        auto next = parse(first, last, which, ec);

        if (not ec.failed())
        {
            ec = error::unexpected_packet;
            boost::mp11::tuple_for_each(targets, [&](auto &frame) {
                if (which.value() == frame.id())
                {
                    ec.clear();
                    next = parse(next, last, frame, ec);
                    if (not ec.failed())
                        if (next != last)
                            ec = error::invalid_packet;
                }
            });
        }

        return ec;
    }


}