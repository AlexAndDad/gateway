#pragma once

#include "net.hpp"
#include "minecraft/security/private_key.hpp"
#include "minecraft/server/receive_login.hpp"

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
        using executor_type = net::io_context::executor_type;
        using protocol      = net::ip::tcp;
        using socket_type   = net::basic_stream_socket< protocol, executor_type >;

        explicit connection_impl(connection_config config, socket_type &&sock);

        auto start() -> void;

        auto cancel() -> void;

        auto get_executor() -> executor_type;

      private:
        auto handle_start() -> void;
        auto handle_cancel() -> void;

        void initiate_spin();
        void handle_spin(error_code ec, std::size_t bytes_transferrred);

        connection_config config_;

        socket_type         sock_;
        std::vector< char > rx_buffer_;

        minecraft::server::receive_login_params login_params_;
    };





}   // namespace gateway
