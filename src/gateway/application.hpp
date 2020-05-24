#pragma once
#include "config/net.hpp"


#include "listener.hpp"
#include "player_manager.hpp"


#include "minecraft/region/player_updates_queue.hpp"
#include "minecraft/security/private_key.hpp"
#include "minecraft/security/rsa.hpp"
#include "polyfill/async/coro_except_handler.hpp"
#include "polyfill/configuration.hpp"

namespace gateway
{
    struct application
    {
        using executor_type = net::io_context::executor_type;
        using signal_set    = net::basic_signal_set< executor_type >;

        application(executor_type exec, polyfill::configuration config)
        : config_(std::move(config))
        , signals_(exec)
        , listener_(exec, config_)
        , player_manager_(exec,config_)
        {
            signals_.add(SIGINT);
        }

        void start()
        {
            net::co_spawn(
                get_executor(),
                [this]() mutable -> net::awaitable< void > {
                    co_await this->run();
                },
                polyfill::coro_except_handler("application", "start()"));
        }

        void cancel()
        {
            dispatch(bind_executor(get_executor(),
                                   [this] { this->handle_cancel(); }));
        }

        auto get_executor() -> executor_type { return signals_.get_executor(); }

      private:
        net::awaitable< void > run()
        {
            // Setup signals callback
            signals_.async_wait([this](error_code const &ec, int sig) {
                handle_signal(ec, sig);
            });

            // Start services
            co_await listener_.start();
            co_await player_manager_.start();
        }

        void handle_signal(error_code const &ec, int sig)
        {
            if (ec.failed())
            {
                if (ec != net::error::operation_aborted)
                {
                    cancel_all_services();
                }
            }
            else if (sig == SIGINT)
            {
                std::clog << "app: interrupted" << std::endl;
                cancel_all_services();
            }
            else
            {
                std::clog << "app: unexpected signal " << sig << std::endl;
                cancel_all_services();
            }
        }

        void handle_cancel()
        {
            signals_.cancel();
            cancel_all_services();
        }

        void cancel_all_services() { listener_.cancel(); }

        polyfill::configuration config_;

        signal_set     signals_;
        listener       listener_;
        player_manager player_manager_;
    };
}   // namespace gateway