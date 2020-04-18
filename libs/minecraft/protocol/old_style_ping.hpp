//
// Created by rhodges on 18/04/2020.
//

#pragma once

#include "minecraft/net.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/report.hpp"

#include <cstdint>
#include <spdlog/spdlog.h>

namespace minecraft::protocol
{
    namespace client
    {
        struct old_style_ping
        {
            std::uint8_t   packet_id;   // = fe
            std::uint8_t   payload;     // = 01
            std::uint8_t   plugin;      // = fa
            std::u16string pinghost;

            std::uint8_t   protocol_version;   // = 4a
            std::u16string hostname;
            std::uint32_t  port;

            const_buffer_iterator parse_start(const_buffer_iterator first, const_buffer_iterator last, error_code& ec)
            {
                using minecraft::parse;
                first = parse(first, last, packet_id, ec);
                if (not ec.failed() and packet_id != 254)
                    ec = error::invalid_packet;

                first = parse(first, last, payload, ec);
                if (not ec.failed() and payload != 1)
                    ec = error::invalid_payload;

                first = parse(first, last, plugin, ec);
                if (not ec.failed() and plugin != 0xfa)
                    ec = error::invalid_plugin;


                if (not ec.failed() and first != last)
                    ec = error::invalid_packet;
                return first;
            }
            const_buffer_iterator parse_rest(const_buffer_iterator first, const_buffer_iterator last, error_code& ec)
            {
                using minecraft::parse;
                first = parse(first, last, protocol_version, ec);
                first = parse(first, last, hostname, ec);
                first = parse(first, last, port, ec);
                if (not ec.failed() and first != last)
                    ec = error::invalid_packet;
                return first;
            }
        };
    }   // namespace client

    template < class Protocol, class Executor, class CompletionToken >
    auto async_is_old_style_ping(net::basic_stream_socket< Protocol, Executor > &sock, CompletionToken &&token)
    {
        using socket_type = net::basic_stream_socket< Protocol, Executor >;

        auto op = [&sock, coro = net::coroutine(), mem = std::vector< char >(1)](
                      auto &self, error_code ec = {}, std::size_t bytes_transfered = 0) mutable {
#include <boost/asio/yield.hpp>
            reenter(coro)
            {
                yield
                {
                    auto buf = net::buffer(mem);
                    sock.async_receive(buf, socket_type::message_peek, std::move(self));
                }
                if (ec.failed())
                {
                    spdlog::info("is_old_style_ping read failure: {}", report(ec));
                    return self.complete(ec, false);
                }

                self.complete(ec, (mem[0] == '\xfe'));
            }
#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionToken, void(error_code, bool) >(std::move(op), token, sock);
    }

    template < class Stream, class CompletionToken >
    auto async_read_be_utf16(Stream &stream, std::u16string &result, CompletionToken &&token)
    {
        auto op = [&stream, &result, coro = net::coroutine(), length = std::uint16_t(), buffer = std::vector< char >()](
                      auto &self, error_code ec = {}, std::size_t bytes_transfered = 0) mutable {
            using minecraft::parse;
            if (ec.failed())
                return self.complete(ec);
#include <boost/asio/yield.hpp>
            reenter(coro)
            {
                yield
                {
                    buffer.reserve(256);
                    buffer.resize(2);
                    auto buf = net::buffer(buffer);
                    net::async_read(stream, buf, std::move(self));
                }

                parse(buffer.data(), buffer.data() + 2, length, ec);
                if (ec.failed())
                    return self.complete(ec);

                buffer.resize(2 + length * 2);
                yield
                {
                    auto buf = net::buffer(buffer);
                    buf += 2;
                    net::async_read(stream, buf, std::move(self));
                }
                parse(buffer.data(), buffer.data() + buffer.size(), result, ec);
                self.complete(ec);
            }
#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionToken, void(error_code) >(std::move(op), token, stream);
    }

    struct osp_state
    {
        client::old_style_ping ping;

        std::vector< char > tmpv;
        std::uint16_t       tmplen;
    };
    template < class NextLayer, class CompletionToken >
    auto async_old_style_ping(stream< NextLayer > &stream, CompletionToken &&token)
    {
        auto op = [&stream, coro = net::coroutine(), state = std::make_unique< osp_state >()](
                      auto &self, error_code ec = {}, std::size_t bytes_transferred = 0) mutable {
            using minecraft::parse;
#include <boost/asio/yield.hpp>
            if (ec.failed())
                self.complete(ec);
            reenter(coro)
            {
                yield
                {
                    state->tmpv.resize(3);
                    auto bufs = net::buffer(state->tmpv);
                    async_read(stream.next_layer(), bufs, std::move(self));
                }
                {
                    auto first = state->tmpv.data();
                    auto last = first + 3;
                    state->ping.parse_start(first, last, ec);
                }
                if (ec.failed())
                    self.complete(ec);

                yield async_read_be_utf16(stream.next_layer(), state->ping.pinghost, std::move(self));

                yield
                {
                    state->tmpv.resize(2);
                    auto bufs = net::buffer(state->tmpv);
                    async_read(stream.next_layer(), bufs, std::move(self));
                }

                parse(state->tmpv.data(), state->tmpv.data() + 2, state->tmplen, ec);
                if (state->ping.plugin != 0xfa)
                    return self.complete(error::invalid_packet);

                yield
                {
                    state->tmpv.resize(state->tmplen);
                    auto bufs = net::buffer(state->tmpv);
                    async_read(stream.next_layer(), bufs, std::move(self));
                }

                state->ping.parse_rest(state->tmpv.data(), state->tmpv.data() + state->tmpv.size(), ec);

                self.complete(ec);
            }
#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionToken, void(error_code) >(std::move(op), token, stream);
    }

}   // namespace minecraft::protocol
