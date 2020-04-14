#pragma once

#include "config/net.hpp"
#include "connection_cache.hpp"
#include "minecraft/security/private_key.hpp"

#include <iostream>

namespace masquerade {
    struct listener_config : connection_config
    {
        std::string listen_port;

        auto as_connection_config() const -> connection_config const&
        {
            return *this;
        }

        friend auto operator<<(std::ostream& os, listener_config const& cfg) -> std::ostream&;
    };

    struct listener
    {
        using executor_type = net::io_context::executor_type;

        using protocol = net::ip::tcp;
        using socket_type = net::basic_stream_socket<protocol, executor_type>;
        using acceptor_type = net::basic_socket_acceptor<protocol, executor_type>;

        listener(executor_type exec, listener_config config);

        void
        start()
        {
            dispatch(bind_executor(get_executor(), [this] {
                this->initiate_accept();
            }));

        }

        void
        cancel()
        {
            dispatch(bind_executor(get_executor(), [this] {
                this->handle_cancel();
            }));
        }

        auto
        get_executor() -> net::executor
        {
            return acceptor_.get_executor();
        }

    private:

        void
        initiate_accept();

        void
        handle_accept(error_code ec, socket_type sock);

        void
        handle_cancel();

        listener_config config_;
        acceptor_type acceptor_;
        connection_cache connections_;
    };
}
