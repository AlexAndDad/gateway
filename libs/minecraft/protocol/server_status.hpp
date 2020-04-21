//
// Created by rhodges on 19/04/2020.
//

#pragma once

#include "minecraft/protocol/expect_frame.hpp"
#include "minecraft/protocol/read_frame.hpp"
#include "minecraft/protocol/stream.hpp"
#include "minecraft/status_packets.hpp"

namespace minecraft::protocol
{
    template < class NextLayer, class CompletionToken >
    auto async_server_status(stream< NextLayer > &stream, CompletionToken &&token)
    {
        struct op_state
        {
            minecraft::client::status_request               client_request;
            minecraft::server::status_response              server_response;
            minecraft::client::status_ping                  client_ping;
            minecraft::server::status_pong                  server_pong;
            var_enum< minecraft::client::status_packet_id > client_which;
        };

        auto state                  = std::make_unique< op_state >();
        state->server_response.json = "{\n"
                                      "    \"version\": {\n"
                                      "        \"name\": \"1.15.2\",\n"
                                      "        \"protocol\": 578\n"
                                      "    },\n"
                                      "    \"players\": {\n"
                                      "        \"max\": 1000000000,\n"
                                      "        \"online\": 1000000,\n"
                                      "        \"sample\": [\n"
                                      "            {\n"
                                      "                \"name\": \"thinkofdeath\",\n"
                                      "                \"id\": \"4566e69f-c907-48ee-8d71-d7ba5aa00d20\"\n"
                                      "            }\n"
                                      "        ]\n"
                                      "    },\t\n"
                                      "    \"description\": {\n"
                                      "        \"text\": \"Welcome to Awesomeness!\"\n"
                                      "    },\n"
                                      "    \"favicon\": \"data:image/png;base64,<data>\"\n"
                                      "}";

        auto op = [&stream, coro = net::coroutine(), pstate = std::move(state)](
                      auto &self, error_code ec = {}, std::size_t /*bytes_transferred*/ = 0) mutable {
#include <boost/asio/yield.hpp>
            auto not_eof = [&ec]() -> error_code&
            {
                if (ec == net::error::eof)
                    ec.clear();
                return ec;
            };

            if (ec.failed())
                return self.complete(not_eof());

            auto &state = *pstate;

            reenter(coro) for (;;)
            {
                yield stream.async_read_frame(std::move(self));
                expect_frames(
                    stream.current_frame(), state.client_which, std::tie(state.client_request, state.client_ping), ec);
                if (ec.failed())
                    return self.complete(ec);

                if (state.client_which == minecraft::client::status_packet_id::request)
                {
                    spdlog::info("server_status {} rx {}", stream, state.client_request);
                    spdlog::info("server_status {} tx {}", stream, state.server_response);
                    yield stream.async_write_packet(state.server_response, std::move(self));
                }
                else if (state.client_which == minecraft::client::status_packet_id::ping)
                {
                    state.server_pong.payload = state.client_ping.payload;
                    spdlog::info("server_status {} rx {}", stream, state.client_ping);
                    spdlog::info("server_status {} tx {}", stream, state.server_pong);
                    yield stream.async_write_packet(state.server_pong, std::move(self));
                }
                else
                    return self.complete(error::unexpected_packet);
            }

#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionToken, void(error_code) >(std::move(op), token, stream);
    }
}   // namespace minecraft::protocol
