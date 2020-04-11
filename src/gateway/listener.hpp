#pragma once

#include "config/net.hpp"
#include <iostream>
#include "connection_cache.hpp"

namespace gateway {
    struct listener
    {
        using executor_type = net::io_context::executor_type;

        using protocol = net::ip::tcp;
        using socket_type = net::basic_stream_socket<protocol, executor_type>;
        using acceptor_type = net::basic_socket_acceptor<protocol, executor_type>;

        listener(executor_type exec);

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

        acceptor_type acceptor_;
        connection_cache connections_;
    };
}
