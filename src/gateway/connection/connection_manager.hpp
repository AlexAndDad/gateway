//
// Created by ahodges on 24/05/2020.
//
#pragma once

#include "connection_cache.hpp"
#include "gateway/listener.hpp"
#include "gateway/net.hpp"
#include "polyfill/async/async_queue.hpp"
#include "polyfill/async/async_tally.hpp"
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
        , pending_connection_limit_(config["connection_manager"].as_object()["pending_connection_limit"].as_int64())
        , connections_(exec)
        {
        }

        net::awaitable< void > start()
        {
            co_await polyfill::async::async_task(
                get_executor(), [this]() mutable -> net::awaitable< void > { co_await handle_start(); }, "connection_manager", "start()");
        }

        /// @brief Async wait for a connection that successfully completed a
        /// handshake.
        net::awaitable< connection > await_connection()
        {
            spdlog::debug("connection manager - awaiting new connection...");
            auto conn = co_await connections_.async_pop(net::use_awaitable);

            net::post(net::bind_executor(get_executor(), [this]() { pending_connections_tally_.decrement(); }));
            co_return conn;
        }

        executor_type get_executor() { return listener_.get_executor(); }
        void          cancel()
        {
            dispatch(bind_executor(get_executor(), [this]() { this->handle_cancel(); }));
        }

      private:
        net::awaitable< void > handle_start()
        {
            spdlog::debug("Connection manager started.");
            // Start services
            co_await listener_.start();

            // start handling new sockets
            net::co_spawn(
                get_executor(),
                [this]() mutable -> net::awaitable< void > { co_await accept_new_sockets(); },
                polyfill::coro_except_handler("connection_manager", "handle_start()"));
        }

        net::awaitable< void > accept_new_sockets()
        {
            try
            {
                for (;;)
                {
                    if (pending_connections_tally_.count() >= pending_connection_limit_)
                    {
                        co_await pending_connections_tally_.await_decrement();
                    }
                    // Wait for a new socket to connect
                    spdlog::debug("Connection manager - waiting for new socket.");
                    auto socket = co_await listener_.listen();
                    if (cancelled_)   // check for corner case
                        co_return;

                    // Create a connection object
                    pending_connections_tally_.increment();
                    spdlog::debug("Connection manager - creating new connection with endpoint = [{}].",socket.remote_endpoint());
                    auto connection = cache_.create(config_, std::move(socket));
                    handshake_connection(std::move(connection));
                }
            }
            catch (system_error &se)
            {
                auto ec = se.code();
                if (ec != net::error::operation_aborted)
                    std::rethrow_exception(std::current_exception());
            }
        }

        void handshake_connection(connection con)
        {
            net::co_spawn(
                get_executor(),
                [this, con = std::move(con)]() mutable -> net::awaitable< void > {
                    auto &con_impl = con.get();
                    spdlog::debug("Connection manager - attempting handshake with connection.");
                    auto  res      = co_await con_impl.attempt_handshake();

                    if (res)   // Success
                    {
                        spdlog::debug("Connection manager - handshake successful with connection.");
                        // post this connection on the queue to be handled
                        connections_.push(std::move(con));
                        co_return;
                    }

                    spdlog::debug("Connection manager - handshake unsuccessful with connection.");
                    // failure to handshake
                    switch (con_impl.get_state())
                    {
                    case client_state::CONNECTED:
                        assert(false);
                        break;
                    case client_state::STATUS_PING:
                        spdlog::debug("connection to [{}] ended in state STATUS_PING.", con_impl.get_endpoint());
                        break;
                    case client_state::HANDSHAKE:
                        assert(false);
                        break;
                    case client_state::PLAY:
                        assert(false);
                        break;
                    case client_state::ERROR:
                        spdlog::error("connection to [{}] ended in state ERROR.", con_impl.get_endpoint());
                        break;
                    }
                },
                polyfill::coro_except_handler("connection_manager", "handshake_connection()"));
        }

        void handle_cancel()
        {
            if (cancelled_)
                return;
            spdlog::debug("connection manager started.");
            cancelled_ = true;
            pending_connections_tally_.cancel();
            connections_.stop();
            listener_.cancel();
            cache_.cancel();
        }

        polyfill::configuration &config_;
        listener                 listener_;

        // config
        std::size_t pending_connection_limit_;

        // state
        connection_cache                           cache_;
        polyfill::async::async_queue< connection > connections_;
        polyfill::async::async_tally               pending_connections_tally_;

        bool cancelled_ = false;
    };
}   // namespace gateway