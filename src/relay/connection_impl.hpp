#pragma once

#include "minecraft/protocol/client_connect.hpp"
#include "minecraft/protocol/server_accept.hpp"
#include "minecraft/protocol/stream.hpp"
#include "minecraft/security/private_key.hpp"
#include "net.hpp"

namespace relay
{
    struct connection_config
    {
        connection_config();

        minecraft::security::private_key server_key;
        std::string                      server_id;

        std::string upstream_host;
        std::string upstream_port;

        friend auto operator<<(std::ostream &os, connection_config const &cfg) -> std::ostream &;
    };

    struct connection_impl : std::enable_shared_from_this< connection_impl >
    {
        using executor_type = net::io_context::executor_type;
        using protocol      = net::ip::tcp;
        using socket_type   = net::basic_stream_socket< protocol, executor_type >;
        using stream_type   = minecraft::protocol::stream< socket_type >;

        explicit connection_impl(connection_config config, socket_type &&sock);

        auto start() -> void;

        auto cancel() -> void;

        auto get_executor() -> executor_type;

      private:
        auto handle_start() -> void;
        auto handle_cancel() -> void;

        auto initiate_upstream_resove() -> void;
        auto handle_upstream_resolve(error_code ec, protocol::resolver::results_type results) -> void;
        auto initiate_upstream_transport(protocol::resolver::results_type results) -> void;
        auto handle_upstream_transport(error_code ec) -> void;
        auto handle_upstream_connect(error_code ec) -> void;

        auto handle_login(error_code const &ec) -> void;
        void initiate_spin();
        void handle_spin(error_code ec, std::size_t bytes_transferrred);

        template < class F >
        auto bind_self(F &&f)
        {
            return bind_executor(this->get_executor(),
                                 [f = std::forward< F >(f), self = this->shared_from_this()](auto &&... args) mutable {
                                     f(std::move(self), std::forward< decltype(args) >(args)...);
                                 });
        }

        connection_config config_;

        stream_type        stream_;     //! client connection
        stream_type        upstream_;   //! connection to the server
        protocol::resolver resolver_;

        minecraft::protocol::server_accept_login_params login_params_;

        minecraft::protocol::client_connect_state connect_state_;

        template < class Stream >
        friend Stream &operator<<(Stream &os, connection_impl *p)
        {
            os << "[connection " << minecraft::report(p->stream_.next_layer()) << ']';
            return os;
        }
    };

}   // namespace relay
