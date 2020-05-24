#pragma once

#include "config/net.hpp"
#include "connection_cache.hpp"
#include "minecraft/security/private_key.hpp"
#include "polyfill/async/async_task.hpp"
#include "polyfill/configuration.hpp"

#include <iostream>

using namespace std::literals;

namespace gateway
{
    struct listener
    {
        using executor_type = net::io_context::executor_type;

        using protocol    = net::ip::tcp;
        using socket_type = net::basic_stream_socket< protocol, executor_type >;
        using acceptor_type =
            net::basic_socket_acceptor< protocol, executor_type >;

        listener(executor_type exec, polyfill::configuration &config)
        : config_(config)
        , acceptor_(exec)
        , port_(config_["listener"].as_object()["port"].as_uint64())
        {
        }

        net::awaitable< void > start()
        {
            co_await polyfill::async::async_task(
                get_executor(),
                [this]() mutable -> net::awaitable< void > {
                    co_await handle_start();
                },
                "listener",
                "start()");
        }

        void cancel()
        {
            dispatch(bind_executor(get_executor(),
                                   [this] { this->handle_cancel(); }));
        }

        net::awaitable< socket_type > listen()
        {
            co_return co_await polyfill::async::async_task(
                get_executor(),
                [this]() mutable -> net::awaitable< socket_type > {
                    co_return co_await handle_listen();
                },
                "listener",
                "listen()");
        }

        auto get_executor() -> net::executor
        {
            return acceptor_.get_executor();
        }

      private:
        net::awaitable< void > handle_start()
        {
            acceptor_.open(protocol::v4());
            acceptor_.set_option(socket_type::reuse_address(true));
            auto ec = error_code();
            do
            {
                acceptor_.bind(
                    protocol::endpoint(net::ip::make_address("0.0.0.0"), port_),
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
            co_return;
        }

        net::awaitable< socket_type > handle_listen()
        {
            for (;;)
            {
                try
                {
                    co_return co_await acceptor_.async_accept(
                        net::use_awaitable);
                }
                catch (system_error &se)
                {
                    auto ec = se.code();
                    if (ec == net::error::connection_aborted)
                        continue;
                    else if (ec != net::error::operation_aborted)
                        std::rethrow_exception(std::current_exception());
                }

            }
        }

        void handle_cancel()
        {
            acceptor_.cancel();
            connections_.cancel();
        }
        polyfill::configuration &config_;

        acceptor_type    acceptor_;
        connection_cache connections_;

        std::uint16_t port_;
    };

}   // namespace gateway
