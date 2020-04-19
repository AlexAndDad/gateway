#pragma once

#include "minecraft/protocol/server_accept.hpp"
#include "minecraft/security/private_key.hpp"
#include "net.hpp"

#include <minecraft/protocol/stream.hpp>

namespace gateway
{
    struct connection_config
    {
        connection_config();

        minecraft::security::private_key server_key;
        std::string                      server_id;

        friend auto operator<<(std::ostream &os, connection_config const &cfg) -> std::ostream &;
    };

    struct connection_impl : std::enable_shared_from_this< connection_impl >
    {
        using executor_type      = net::io_context::executor_type;
        using transport_protocol = net::ip::tcp;
        using socket_type        = net::basic_stream_socket< transport_protocol, executor_type >;
        using stream_type        = minecraft::protocol::stream< socket_type >;

        explicit connection_impl(connection_config config, socket_type &&sock);

        auto start() -> void;

        auto cancel() -> void;

        auto get_executor() -> executor_type;

      private:
        template < class Stream >
        friend Stream &operator<<(Stream &os, connection_impl const &i)
        {
            os << "[connection " << minecraft::report(i.stream_.next_layer()) << ']';
            return os;
        }

        template < class Stream >
        friend Stream &operator<<(Stream &os, connection_impl *p)
        {
            os << "[connection " << minecraft::report(p->stream_.next_layer()) << ']';
            return os;
        }

      private:
        net::awaitable< void > run();
        auto                   handle_cancel() -> void;

        template < class Packet >
        auto async_write_packet(Packet const &p) -> net::awaitable< void >
        {
            try
            {
                co_await stream_.async_write_packet(p, net::use_awaitable);
                spdlog::info("{}::{}({})", this, "async_write_packet", minecraft::report(error_code()));
            }
            catch (system_error &se)
            {
                auto &&ec = se.code();
                spdlog::warn("{}::{}({})", this, "async_write_packet", minecraft::report(ec));
            }
        }

        connection_config config_;

        stream_type         stream_;
        std::vector< char > compose_buffer_;

        minecraft::protocol::server_accept_login_params login_params_;
    };

}   // namespace gateway
