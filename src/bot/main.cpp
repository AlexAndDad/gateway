//#include <experimental/coroutine>
#include "minecraft/packets/server_play_packet.hpp"
#include "minecraft/protocol/client_connect.hpp"
#include "minecraft/protocol/client_ping.hpp"
#include "minecraft/protocol/stream.hpp"
#include "polyfill/explain.hpp"

#include <boost/asio/awaitable.hpp>
#include <exception>

namespace bot
{
    using namespace minecraft;

    struct client
    {
        using executor_type = net::executor;
        using transport     = net::ip::tcp;
        using socket_type   = net::basic_stream_socket< transport, executor_type >;
        using resolver_type = net::ip::basic_resolver< transport, executor_type >;

        client(executor_type exec)
        : resolver_(exec)
        , stream_(socket_type(exec))
        {
        }

        void start()
        {
            net::co_spawn(
                get_executor(),
                [this]() -> net::awaitable< void > {
                    auto results = co_await resolver_.async_resolve("127.0.0.1", "25565", net::use_awaitable);
                    auto ep      = co_await net::async_connect(stream_.next_layer(), results, net::use_awaitable);
                    spdlog::info("connected to {}", ep);
                    connect_state_.name("MadMongo38");
                    connect_state_.connection_args("127.0.0.1", stream_.next_layer().remote_endpoint().port());
                    connect_state_.version(protocol::version_type::v1_11);
                    co_await protocol::async_client_connect(stream_, connect_state_, net::use_awaitable);

                    while (1)
                    {
                        co_await stream_.async_read_frame(net::use_awaitable);
                        auto       packet = packets::server::server_play_packet();
                        auto       span   = to_span(stream_.current_frame());
                        error_code ec;
                        auto       next = parse(span.begin(), span.end(), packet, ec);
                        boost::ignore_unused(next);
                        if (not ec.failed())
                        {
                            spdlog::info("recognised {}", packet);
                        }
                    }
                },
                [](auto...) {});
        }

        auto get_executor() -> executor_type { return resolver_.get_executor(); }

        resolver_type                   resolver_;
        protocol::stream< socket_type > stream_;

        protocol::client_connect_state connect_state_;
    };

    void run()
    {
        auto ioc = net::io_context();

        auto c = client(ioc.get_executor());
        c.start();

        net::co_spawn(
            ioc.get_executor(),
            []() -> net::awaitable< void > {
                auto result = co_await minecraft::protocol::ping("play.minesuperior.com", "25565");
                spdlog::info("[ping {}us] [json {}]", result.ping_time.count(), result.json);
                co_return;
            },
            [work = net::make_work_guard(ioc)](std::exception_ptr ep) {
                try
                {
                    if (ep)
                        std::rethrow_exception(ep);
                }
                catch (...)
                {
                    spdlog::error("error in ping: {}", polyfill::explain());
                }
            });

        ioc.run();
    }

}   // namespace bot

int main()
{
    try
    {
        bot::run();
    }
    catch (...)
    {
        std::cerr << polyfill::explain();
        return polyfill::deduce_return_code();
    }
    return 0;
}