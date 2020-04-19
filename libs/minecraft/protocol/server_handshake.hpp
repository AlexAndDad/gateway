#pragma once
#include "minecraft/client/handshake.hpp"
#include "minecraft/net.hpp"
#include "minecraft/protocol/connection_state.hpp"
#include "minecraft/protocol/read_frame.hpp"
#include "minecraft/protocol/stream.hpp"

/// @file server_handshake.hpp
///
/// Provide async fuctions for performing handshake as a client and for receiving the handshake as a server
///
namespace minecraft::protocol
{
    template < class NextLayer, class CompletionHandler >
    auto async_client_handshake(stream< NextLayer > &      stream,
                                version_type               version,
                                protocol::connection_state next_state,
                                CompletionHandler &&       handler)
    {
        auto request = std::make_unique< minecraft::client::handshake >();

        request->protocol_version = version;
        request->server_port      = stream.server_port();
        request->server_address   = stream.server_address();
        request->next_state       = next_state;

        auto op = [&stream, coro = net::coroutine(), request = std::move(request)](
                      auto &self, error_code ec = {}, std::size_t bytes_transferred = 0) mutable {
#include <boost/asio/yield.hpp>
            reenter(coro)
            {
                yield
                {
                    auto &hs = *request;
                    stream.async_write_packet(hs, std::move(self));
                }

                self.complete(ec);
            }

#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionHandler, void(error_code) >(std::move(op), handler, stream);
    }

    template < class NextLayer, class CompletionHandler >
    auto async_server_handshake(stream< NextLayer > &stream, CompletionHandler &&handler)
    {
        auto op = [&stream, coro = net::coroutine(), request = std::make_unique< minecraft::client::handshake >()](
                      auto &self, error_code ec = {}, std::size_t bytes_transferred = 0) mutable {
#include <boost/asio/yield.hpp>
            if (ec.failed())
                self.complete(ec, connection_state::initial);
            reenter(coro)
            {
                yield stream.async_read_frame(std::move(self));
                expect_frame(stream.current_frame(), *request, ec);
                if (ec.failed())
                    return self.complete(ec, connection_state::initial);
                verify(*request, ec);
                if (ec.failed())
                    return self.complete(ec, connection_state::initial);
                stream.protocol_version(request->protocol_version);
                stream.server_address(request->server_address);
                stream.server_port(request->server_port);
                self.complete(ec, request->next_state);
            }

#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionHandler, void(error_code, connection_state) >(
            std::move(op), handler, stream);
    }

}   // namespace minecraft::protocol