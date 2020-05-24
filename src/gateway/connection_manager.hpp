//
// Created by ahodges on 24/05/2020.
//
#pragma once

#include "connection_cache.hpp"
#include "listener.hpp"
#include "net.hpp"
#include "polyfill/async/async_task.hpp"
#include "polyfill/async/coro_except_handler.hpp"
#include "polyfill/configuration.hpp"

namespace gateway
{
    struct connection_manager
    {
        using executor_type = net::executor;
        connection_manager(executor_type exec, polyfill::configuration &config)
        : config_(config)
        , listener_(exec, config)
        , connection_queue_limit_(config["connection_manager"]
                                      .as_object()["connection_queue_limit"]
                                      .as_uint64())
        {
        }

        net::awaitable< void > start()
        {
            co_await polyfill::async::async_task(
                get_executor(),
                [this]() mutable -> net::awaitable< void > {
                    co_await handle_start();
                },
                "connection_manager",
                "start()");
        }

        net::awaitable< void > await_authed_connection()
        {
            co_await polyfill::async::async_task(
                get_executor(),
                [this]() mutable -> net::awaitable< void > {

                },
                "connection_manager",
                "wait_connection()");
        }

        executor_type get_executor() { return listener_.get_executor(); }
        void          cancel()
        {
            dispatch(bind_executor(get_executor(),
                                   [this]() { this->handle_cancel(); }))
        }

      private:
        net::awaitable< void > handle_start()
        {
            // Start services
            co_await listener_.start();

            // start handling new sockets
            net::co_spawn(
                get_executor(),
                [this]() { co_await handle_new_sockets(); },
                polyfill::async::coro_except_handler("connection_manager",
                                                     "handle_start()"));
        }

        net::awaitable< void > handle_await_authed_connection() {}

        net::awaitable< void > handle_new_sockets
        {
            try
            {
                for (;;)
                {
                    // Wait for a new socket to connect
                    auto socket = co_await listener_.listen();

                    // Create a connection object and attempt to complete a
                    // handshake.
                    cache_.create()
                }
            }
            catch (system_error &se)
            {
                auto ec = se.code();
                if (ec != net::error::operation_aborted)
                    std::rethrow_exception(std::current_exception());
            }
        }

        void handle_cancel()
        {
            if (cancelled_)
                return;
            cancelled_ = true;
            listener_.cancel();
            cache_.cancel();
        }

        polyfill::configuration &config_;
        listener                 listener_;

        // config
        std::size_t connection_queue_limit_;

        // state
        connection_cache                    cache_;
        std::deque< listener::socket_type > waiting_sockets_;
        bool                                listening_ = false;

        bool cancelled_ = false;
    };
}   // namespace gateway