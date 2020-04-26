//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
// Copyright (c) 2020 Alexander Hodges
//
// Official repository: https://github.com/AlexAndDad/gateway
//

#pragma once
#include "minecraft/compose.hpp"
#include "minecraft/nvp.hpp"
#include "minecraft/parse.hpp"

#include <boost/mp11/tuple.hpp>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <spdlog/spdlog.h>

namespace minecraft::packets
{
    template < auto Ident, class Impl, class = std::enable_if_t< wise_enum::is_wise_enum_v< decltype(Ident) > > >
    struct packet_base
    {
        static constexpr auto id() { return Ident; }

        friend auto to_string(packet_base const &base) -> std::string
        {
            auto &self = static_cast< Impl const & >(base);
            return fmt::format("[{} {}]", wise_enum::to_string(Ident), Impl::as_nvps(self));
        }

        friend std::ostream &operator<<(std::ostream &os, packet_base const &base)
        {
            auto &self = static_cast< Impl const & >(base);
            fmt::print(os, "[{} {}]", wise_enum::to_string(Ident), Impl::as_nvps(self));
            return os;
        }

        friend void compose(packet_base const &base, std::vector< char > &target)
        {
            auto &self = static_cast< Impl const & >(base);
            auto  i1   = std::back_inserter(target);

            i1           = encode(variable_length(base.id()), i1);
            auto encoder = [&](auto &&nvp) { i1 = encode(nvp.value, i1); };
            auto nvps = Impl::as_nvps(self);
            boost::mp11::tuple_for_each(nvps.tuple_, encoder);
        }

        friend const_buffer_iterator
        parse(const_buffer_iterator first, const_buffer_iterator last, packet_base &target, error_code &ec)
        {
            auto &self     = static_cast< Impl const & >(target);
            auto  original = first;
            auto  parser   = [&](auto &&nvp) {
                using minecraft::parse;
                first = parse(first, last, nvp.value, ec);
            };
            auto nvps = Impl::as_nvps(self);
            boost::mp11::tuple_for_each(nvps.tuple_, parser);
            if (not ec and first != last)
                ec = error::invalid_packet;
            return ec ? original : first;
        }
    };
}   // namespace minecraft::packets
