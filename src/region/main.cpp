

#include "config/net.hpp"
#include "gateway/application.hpp"
#include "minecraft/region/player_updates_queue.hpp"
#include "minecraft/utils/exception_handler.hpp"
#include "polyfill/explain.hpp"
#include "region_server.hpp"

#include <iostream>
#include <memory>

namespace region
{
    struct application
    {
        using executor_type = config::net::io_context::executor_type;
        application(executor_type exec)
        : exec_(exec)
        , queue_(exec)
        , region_server_(exec, queue_)
        , gateway_server_(exec, queue_)
        {
        }

        void start()
        {
            config::net::co_spawn(
                exec_,
                [this]() -> config::net::awaitable< void > { co_await this->run(); },
                minecraft::utils::make_exception_handler_standalone("region application run"));
        }

      private:
        config::net::awaitable< void > run()
        {
            region_server_.start();
            gateway_server_.start();

            co_return;
        }

        executor_type                          exec_;
        minecraft::region::player_update_queue queue_;
        region_server                          region_server_;
        gateway::application                   gateway_server_;
    };

    void run()
    {
        auto ioc  = config::net::io_context(1);
        auto exec = ioc.get_executor();

        application app = application(exec);
        app.start();

        ioc.run();
    }
}   // namespace region

int main()
{
    using polyfill::deduce_return_code;
    using polyfill::explain;

    spdlog::set_level(spdlog::level::info);

    try
    {
        region::run();
        return 0;
    }
    catch (...)
    {
        std::cerr << explain() << std::endl;
        return deduce_return_code();
    }
}