//
// Created by ahodges on 24/05/2020.
//
#pragma once

#include "listener.hpp"
#include "net.hpp"
#include "polyfill/async/async_task.hpp"
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
                    co_await listener_.start();
                },
                "connection_manager",
                "start()");
        }

        net::awaitable< void > wait_connection()
        {
            co_await polyfill::async::async_task(
                get_executor(),
                [this]() mutable -> net::awaitable< void > {

                },
                "connection_manager",
                "wait_connection()");
        }


        executor_type get_executor() { return listener_.get_executor(); }

        void cancel()
        {
            dispatch(bind_executor(get_executor(),
                                   [this]() { this->handle_cancel(); }))
        }

      private:

        net::awaitable<void> handle_wait_connection

        void handle_cancel()
        {
            if (cancelled_)
                return;
            cancelled_ = true;
            listener_.cancel();
        }

        polyfill::configuration &config_;
        listener                 listener_;

        // config
        std::size_t connection_queue_limit_;

        // state
        bool cancelled_ = false;
    };
}   // namespace gateway