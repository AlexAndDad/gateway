#pragma once
#include "config/net.hpp"
#include "listener.hpp"

namespace gateway
{
    struct application
    {
        using executor_type = net::io_context::executor_type;
        using signal_set = net::basic_signal_set<executor_type>;

        application(executor_type exec)
        : signals_(exec)
        , listener_(exec)
        {
            signals_.add(SIGINT);
        }

        void start()
        {
            dispatch(bind_executor(get_executor(), [this]{
                this->handle_start();
            }));
        }

        void cancel()
        {
            dispatch(bind_executor(get_executor(), [this]{
                this->handle_cancel();
            }));
        }

        auto get_executor() -> executor_type
        {
            return signals_.get_executor();
        }

    private:

        void handle_start()
        {
            signals_.async_wait([this](error_code const& ec, int sig){
                handle_signal(ec, sig);
            });
            start_all_services();
        }

        void handle_signal(error_code const& ec, int sig)
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
        }

        void cancel_all_services()
        {
            listener_.cancel();
        }

        signal_set signals_;
        listener listener_;
    };
}