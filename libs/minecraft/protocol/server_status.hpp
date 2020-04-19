//
// Created by rhodges on 19/04/2020.
//

#pragma once

#include "minecraft/protocol/stream.hpp"
#include "minecraft/status_packets.hpp"
#include "minecraft/protocol/read_frame.hpp"

namespace minecraft::protocol
{
    template < class NextLayer, class CompletionToken >
    auto async_server_status(stream< NextLayer > &stream, CompletionToken &&token)
    {
        struct op_state
        {
            minecraft::client::status_request client_request;
            minecraft::server::status_response server_response;
            minecraft::client::status_ping client_ping;
            minecraft::server::status_pong server_pong;
        };

        auto op = [&stream, coro = net::coroutine(), request = std::make_unique< op_state >()](
                      auto &self, error_code ec = {}, std::size_t bytes_transferred = 0) mutable {
#include <boost/asio/yield.hpp>
            if (ec.failed())
                self.complete(ec);
            reenter(coro)
            {
                yield stream.async_read_frame(std::move(self));
                self.complete(ec);
            }

#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionToken, void(error_code) >(std::move(op), token, stream);
    }
}   // namespace minecraft::protocol
