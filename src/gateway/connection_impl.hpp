#pragma once

#include "keep_alive_handler.hpp"
#include "minecraft/protocol/server_accept.hpp"
#include "minecraft/security/private_key.hpp"
#include "net.hpp"

#include <minecraft/protocol/stream.hpp>
#include <minecraft/region/player_updates_queue.hpp>

#include "polyfill/configuration.hpp"

namespace gateway
{
    struct connection_config
    {
        connection_config();

        std::optional< minecraft::security::private_key > server_key;
        std::string                                       server_id;
        int                                               compression_threshold;
        friend auto operator<<(std::ostream &os, connection_config const &cfg)
            -> std::ostream &;
    };

    struct connection_impl : std::enable_shared_from_this< connection_impl >
    {
        using executor_type      = net::io_context::executor_type;
        using transport_protocol = net::ip::tcp;
        using socket_type =
            net::basic_stream_socket< transport_protocol, executor_type >;
        using stream_type = minecraft::protocol::stream< socket_type >;

        explicit connection_impl(polyfill::configuration &config,
                                 socket_type &&           sock)
        : config_(config)
        , stream_(std::move(sock))
        , login_params_(config_.server_id, config_.server_key)
        , keep_alive_impl_(get_executor())
        {
        }

        auto start() -> void;

        auto cancel() -> void;

        auto get_executor() -> executor_type;

      private:
        template < class Stream >
        friend Stream &operator<<(Stream &os, connection_impl const &i)
        {
            os << "[connection " << minecraft::report(i.stream_.next_layer())
               << ']';
            return os;
        }

        template < class Stream >
        friend Stream &operator<<(Stream &os, connection_impl *p)
        {
            os << "[connection " << minecraft::report(p->stream_.next_layer())
               << ']';
            return os;
        }

      private:
        net::awaitable< void > run();
        auto                   handle_cancel() -> void;

        void handle_server_packets(
            minecraft::region::client_queue_update &client_queue)
        {
            net::co_spawn(
                get_executor(),
                [self = shared_from_this(),
                 &client_queue]() -> net::awaitable< void > {
                    while (true)   // Loop
                    {
                        // Read a packet to send
                        auto packet =
                            co_await client_queue.client_consumer.consume();

                        // Send the packet
                        co_await self->async_write_packet(packet);
                    }
                },
                net::detached);
        }

        template < class Packet >
        auto async_write_packet(Packet const &p) -> net::awaitable< void >
        {
            try
            {
                co_await stream_.async_write_packet(p, net::use_awaitable);
            }
            catch (system_error &se)
            {
                auto &&ec = se.code();
                spdlog::warn("{}::{}({})",
                             this,
                             "async_write_packet",
                             minecraft::report(ec));
            }
        }

        net::awaitable< minecraft::packets::client::client_play_packet >
        async_read_packet(error_code &ec)
        {
            co_await stream_.async_read_frame(net::use_awaitable);

            auto data  = stream_.current_frame();
            auto buf   = minecraft::to_span(data);
            auto first = buf.begin();
            auto last  = buf.end();

            // parse the packet using the new expect frame using a variant
            minecraft::packets::client::client_play_packet pack =
                minecraft::packets::client::client_play_packet();

            parse(first, last, pack, ec);

            if (ec)
            {
                spdlog::warn(
                    "Unable to parse packet from the client with ID: {}",
                    wise_enum::to_string(pack.id()));
                spdlog::warn(
                    "{}::{}({})", this, __func__, polyfill::report(ec));
                spdlog::warn("{}", pack);
            }
            co_return pack;
        }

        void on_keep_alive_timeout()
        {
            // TODO cancel connection
        }

        polyfill::configuration &config_;

        stream_type         stream_;
        std::vector< char > compose_buffer_;

        minecraft::protocol::server_accept_state login_params_;
        keep_alive_impl                          keep_alive_impl_;
    };

}   // namespace gateway
