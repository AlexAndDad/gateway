#pragma once

#include "config/net.hpp"
#include "connection_cache.hpp"
#include "minecraft/security/private_key.hpp"

#include <iostream>

using namespace std::literals;

namespace gateway
{
    struct listener_config : connection_config
    {
        auto as_connection_config() const -> connection_config const & { return *this; }

        std::string listen_port = "25565";

        friend auto operator<<(std::ostream &os, listener_config const &cfg) -> std::ostream &;
    };

    struct listener
    {
        using executor_type = net::io_context::executor_type;

        using protocol      = net::ip::tcp;
        using socket_type   = net::basic_stream_socket< protocol, executor_type >;
        using acceptor_type = net::basic_socket_acceptor< protocol, executor_type >;

        listener(executor_type exec, listener_config config, minecraft::region::player_update_queue &queue)
        : config_(std::move(config))
        , acceptor_(exec)
        , queue_(queue)
        {
            acceptor_.open(protocol::v4());
            acceptor_.set_option(socket_type::reuse_address());
            auto ec = error_code();
            do
            {
                acceptor_.bind(protocol::endpoint(net::ip::make_address("0.0.0.0"),
                                                  std::uint16_t(::atoi(config_.listen_port.c_str()))),
                               ec);
                if (not ec.failed())
                    break;
                if (ec.failed() && ec != net::error::address_in_use)
                    throw system_error(ec);
                std::cout << ec.message() << std::endl;
                auto t = net::system_timer(get_executor());
                t.expires_after(5s);
                t.wait();
            } while (ec.failed());

            acceptor_.listen();
        }

        void start()
        {
            dispatch(bind_executor(get_executor(), [this] { this->initiate_accept(); }));
        }

        void cancel()
        {
            dispatch(bind_executor(get_executor(), [this] { this->handle_cancel(); }));
        }

        auto get_executor() -> net::executor { return acceptor_.get_executor(); }

      private:
        void initiate_accept();

        void handle_accept(error_code ec, socket_type sock);

        void handle_cancel();

        listener_config                         config_;
        acceptor_type                           acceptor_;
        connection_cache                        connections_;
        minecraft::region::player_update_queue &queue_;
    };
}   // namespace gateway
