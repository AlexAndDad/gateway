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
            std::uint16_t  length_od_rest;
            std::uint8_t   protocol_version;   // = 4a
            std::u16string hostname;
            std::uint32_t  port;
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
    };
    template < class NextLayer, class CompletionToken >
    auto async_old_style_ping(stream< NextLayer > &stream, CompletionToken &&token)
    {
        auto op = [&stream, coro = net::coroutine(), state = std::make_unique< osp_state >()](
                      auto &self, error_code ec = {}, std::size_t bytes_transferred = 0) mutable {
#include <boost/asio/yield.hpp>
            if (ec.failed())
                self.complete(ec);
            reenter(coro)
            {
                yield
                {
                    auto bufs = net::mutable_buffer(&state->ping.packet_id, 1);
                    async_read(stream.next_layer(), bufs, std::move(self));
                }

                if (state->ping.packet_id != '\xfe')
                    return self.complete(error::invalid_packet);
                yield
                {
                    auto bufs = std::array< net::mutable_buffer, 2 > { net::mutable_buffer { &state->ping.payload, 1 },
                                                                       net::mutable_buffer { &state->ping.plugin, 1 } };
                    async_read(stream.next_layer(), bufs, std::move(self));
                }

                if (state->ping.payload != 1)
                    return self.complete(error::invalid_packet);
                if (state->ping.plugin != 0xfa)
                    return self.complete(error::invalid_packet);

                yield async_read_be_utf16(stream.next_layer(), state->ping.pinghost, std::move(self));

                self.complete(ec);
            }
#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionToken, void(error_code) >(std::move(op), token, stream);
    }

}   // namespace minecraft::protocol
