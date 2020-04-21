#pragma once
#include "application/console.hpp"
#include "config/net.hpp"
#include "listener.hpp"
#include "minecraft/security/private_key.hpp"
#include "minecraft/security/rsa.hpp"

namespace relay
{
    struct app_config : listener_config
    {
        auto as_listener_config() const -> listener_config const & { return *this; }

        friend auto operator<<(std::ostream &os, app_config const &cfg) -> std::ostream &
        {
            os << "Application Config\n";
            os << cfg.as_listener_config();
            return os;
        }
    };

    struct app
    {
        using executor_type = net::io_context::executor_type;
        using signal_set    = net::basic_signal_set< executor_type >;

        app(executor_type exec, app_config config)
        : config_(std::move(config))
        , signals_(exec)
        , listener_(exec, config_)
        , console_(exec, ::dup(0))
        {
            std::cout << "Application Starting\n\n";
            std::cout << config_ << std::endl;
            signals_.add(SIGINT);
        }

        void start()
        {
            dispatch(bind_executor(get_executor(), [this] { this->handle_start(); }));
        }

        void cancel()
        {
            dispatch(bind_executor(get_executor(), [this] { this->handle_cancel(); }));
        }

        auto get_executor() -> executor_type { return signals_.get_executor(); }

      private:
        void handle_start()
        {
            signals_.async_wait([this](error_code const &ec, int sig) { handle_signal(ec, sig); });
            start_all_services();
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

        void start_all_services()
        {
            listener_.start();
            console_.start([this]{
                dispatch(bind_executor(this->get_executor(), [this]{
                    this->cancel_all_services();
                    this->signals_.cancel();
                }));
            });
        }

        void cancel_all_services()
        {
            listener_.cancel();
            console_.stop();
        }

        app_config config_;

        signal_set           signals_;
        listener             listener_;
        application::console console_;
    };
}   // namespace relay