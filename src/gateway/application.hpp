#pragma once
#include "config/net.hpp"
#include "gateway/connection/connection_manager.hpp"
#include "gateway/player/player_manager.hpp"
#include "minecraft/region/player_updates_queue.hpp"
#include "minecraft/security/private_key.hpp"
#include "minecraft/security/rsa.hpp"
#include "polyfill/async/coro_except_handler.hpp"
#include "polyfill/configuration.hpp"
#include "minecraft/chunks/chunk_cache.hpp"

namespace gateway
{
    struct application
    {
        using executor_type = net::io_context::executor_type;
        using signal_set    = net::basic_signal_set< executor_type >;

        application(executor_type exec, polyfill::configuration config)
        : config_(std::move(config))
        , signals_(exec)
        , connection_manager_(exec, config_)
        , player_manager_(exec, config_)
        {
            spdlog::debug("Application created.");
            signals_.add(SIGINT);
        }

        void start()
        {
            net::co_spawn(
                get_executor(),
                [this]() mutable -> net::awaitable< void > { co_await this->run(); },
                polyfill::coro_except_handler("application", "start()"));
        }

        void cancel()
        {
            dispatch(bind_executor(get_executor(), [this] { this->handle_cancel(); }));
        }

        auto get_executor() -> executor_type { return signals_.get_executor(); }

      private:
        net::awaitable< void > run()
        {
            spdlog::debug("Application started.");

            // Setup signals callback
            signals_.async_wait([this](error_code const &ec, int sig) { handle_signal(ec, sig); });

            // Start services
            co_await connection_manager_.start();
            co_await player_manager_.start();

            // Create a world
            spdlog::debug("Application - created world.");
            auto world = minecraft::world();
            spdlog::debug("Application - created chunk cache.");
            auto chunk_cache = minecraft::chunks::chunk_cache(get_executor());

            for (;;)   // Listen for, and create new players
            {
                try
                {
                    spdlog::debug("Application - awaiting new connection.");
                    auto conn = co_await connection_manager_.await_connection();
                    auto & player_name = conn.get().get_name();
                    player_manager_.create_player(player_name, get_executor(), std::move(conn),world,&chunk_cache);
                }
                catch (...)
                {
                    // TODO log that we have stopped listening for new players,
                    // We should probably shutdown the server here...
                    break;
                }


            }
        }

        void handle_signal(error_code const &ec, int sig)
        {
            if (ec.failed())
            {
                if (ec != net::error::operation_aborted)
                {
                    cancel();
                }
            }
            else if (sig == SIGINT)
            {
                std::clog << "app: interrupted" << std::endl;
                cancel();
            }
            else
            {
                std::clog << "app: unexpected signal " << sig << std::endl;
                cancel();
            }
        }

        void handle_cancel()
        {
            if (cancelled_)
                return;
            cancelled_ = true;
            signals_.cancel();
            cancel_all_services();
        }

        void cancel_all_services()
        {
            connection_manager_.cancel();
            player_manager_.cancel();
        }

        polyfill::configuration config_;

        signal_set         signals_;
        connection_manager connection_manager_;
        player_manager     player_manager_;

        bool cancelled_;
    };
}   // namespace gateway