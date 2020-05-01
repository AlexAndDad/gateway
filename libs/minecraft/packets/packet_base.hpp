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
#include "minecraft/types.hpp"
#include "minecraft/print.hpp"
#include "minecraft/to_json.hpp"

#include <boost/mp11/tuple.hpp>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <spdlog/spdlog.h>
#include "minecraft/to_json.hpp"

namespace minecraft::packets
{

    template<class Impl>
    struct packet_enable_json
    {
        auto to_json(boost::json::value& jv) const
        {
            using minecraft::to_json;
            auto& self = static_cast<Impl const&>(*this);
            auto& object = jv.emplace_object();
            object.reserve(2);
            object.emplace("type", to_json(self.id(), object.storage()));
            object.emplace("data", to_json(Impl::as_nvps(self), object.storage()));
        }
    };

    template < auto Ident, class Impl, class = std::enable_if_t< wise_enum::is_wise_enum_v< decltype(Ident) > > >
    struct packet_base :  packet_enable_json<Impl>
    {
        static constexpr auto id() { return Ident; }

        friend auto to_string(packet_base const &base) -> std::string
        {
            auto &self = static_cast< Impl const & >(base);
            return fmt::format("[{} {}]", print(Ident), Impl::as_nvps(self));
        }

        friend std::ostream &operator<<(std::ostream &os, packet_base const &base)
        {
            auto &self = static_cast< Impl const & >(base);
            fmt::print(os, "[{} {}]", print(Ident), Impl::as_nvps(self));
            return os;
        }

        friend void compose(packet_base const &base, std::vector< char > &target)
        {
            auto &self = static_cast< Impl const & >(base);
            auto  i1   = std::back_inserter(target);

            i1           = encode(variable_length(base.id()), i1);
            auto encoder = [&](auto &&nvp) { i1 = encode(nvp.value, i1); };
            auto nvps    = Impl::as_nvps(self);
            boost::mp11::tuple_for_each(nvps.tuple_, encoder);
        }

        friend const_buffer_iterator
        parse(const_buffer_iterator first, const_buffer_iterator last, packet_base &target, error_code &ec)
        {
            auto &self     = static_cast< Impl & >(target);
            auto  original = first;
            auto  parser   = [&](auto &nvp) {
                using minecraft::parse;
                first = parse(first, last, nvp.value, ec);
                if (ec)
                {
                    spdlog::warn("parse failed at: {}", nvp.name);
                }
            };
            auto nvps = Impl::as_nvps(self);
            boost::mp11::tuple_for_each(nvps.tuple_, parser);
            if (not ec and first != last)
            {
                ec = error::invalid_packet;
                spdlog::warn("packet length mismatch (invalid structure): {} - remaining bytes: {}", to_string(target.id()), last-first);
            }

            return ec ? original : first;
        }

        friend auto operator==(packet_base const &a, packet_base const &b)
        {
            auto &self_a = static_cast< Impl const & >(a);
            auto &self_b = static_cast< Impl const & >(b);
            return Impl::as_nvps(self_a) == Impl::as_nvps(self_b);
        }
    };
}   // namespace minecraft::packets
