//
// Created by rhodges on 29/04/2020.
//

#include "client_ping.hpp"

#include <boost/beast/core/basic_stream.hpp>

using namespace std::literals;

namespace bot
{
    /*
        minecraft::protocol::stream< NextLayer > &          stream_;
        std::string                                         hostname_, service_;
        typename has_resolver::results_type::const_iterator iter;
        minecraft::packets::client::handshake               handshake_;
        minecraft::client::status_packet                    client_packet_;
        minecraft::server::status_packet                    server_packet_;
        ping_result                                         result_;
        std::chrono::high_resolution_clock::time_point      rx_time_, tx_time_;

     */

    namespace
    {
        template < class ServerPkt >
        auto expect(net::const_buffer frame_data) -> ServerPkt
        {
            auto result = ServerPkt();
            auto span   = minecraft::to_span(frame_data);
            auto ec     = error_code();
            auto vid = minecraft::variable_length(result.id());
            auto first = span.begin(), last = span.end();
            first = parse(first, last, vid, ec);
            if (!ec and vid != result.id())
                ec = minecraft::error::unexpected_packet;
            parse(first, last, result, ec);
            if (ec)
                throw system_error(ec);
            return result;
        }

        template < class ServerPkt ,class Duration = std::chrono::seconds>
        auto expect(minecraft_stream& stream, Duration dur = 5s) -> net::awaitable<ServerPkt>
        {
            stream.next_layer().expires_after(dur);
            co_await stream.async_read_frame(net::use_awaitable);
            co_return expect<ServerPkt>(stream.current_frame());
        }

    }   // namespace

    auto send_status_handshake(minecraft_stream &                stream,
                               std::string const &               hostname,
                               std::uint16_t                     port,
                               minecraft::protocol::version_type version) -> net::awaitable< void >
    {
        auto handshake             = minecraft::packets::client::handshake();
        handshake.protocol_version = version;
        handshake.server_address   = hostname;
        handshake.server_port      = port;
        handshake.next_state       = minecraft::protocol::connection_state::status;
        co_await stream.async_write_packet(handshake, net::use_awaitable);
    }

    auto coro_ping(std::string const &hostname, std::string const &service) -> net::awaitable< ping_result >
    {
        auto results = co_await transport_protocol::resolver(co_await net::this_coro::executor)
                           .async_resolve(hostname, service, net::use_awaitable);

        auto stream = minecraft_stream(transport_stream(co_await net::this_coro::executor));

        auto set_timeout = [&stream](auto dur) { stream.next_layer().expires_after(dur); };

        set_timeout(20s);
        auto remote_endpoint = co_await stream.next_layer().async_connect(results, net::use_awaitable);

        set_timeout(20s);
        co_await send_status_handshake(stream, hostname, remote_endpoint.port());
        co_await stream.async_write_packet(minecraft::client::status_request(), net::use_awaitable);

        auto response = co_await expect< minecraft::server::status_response >(stream);

        auto       result = ping_result();
        error_code ec;
        result.json = boost::json::parse(response.json, ec);
        if (ec)
            throw system_error(ec);

        auto clock   = std::chrono::high_resolution_clock();
        auto ping    = minecraft::client::status_ping::generate();
        set_timeout(1s);
        auto tx_time = clock.now();
        co_await stream.async_write_packet(ping, net::use_awaitable);

        auto correct_pong = false;
        do
        {
            auto pong        = co_await expect< minecraft::server::status_pong >(stream);
            result.ping_time = std::chrono::duration_cast< decltype(result.ping_time) >(clock.now() - tx_time);
            correct_pong     = (pong.payload == ping.payload);
        } while (not correct_pong);

        co_return result;
    }

}   // namespace bot