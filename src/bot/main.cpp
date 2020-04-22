//#include <experimental/coroutine>
#include "minecraft/protocol/client_connect.hpp"
#include "minecraft/protocol/stream.hpp"
#include "polyfill/explain.hpp"
#include "minecraft/packets/server/play_packet.hpp"
#include <boost/asio/awaitable.hpp>

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

                    while(1)
                    {
                        co_await stream_.async_read_frame(net::use_awaitable);
                        server::play_packet packet;
                        auto span = to_span(stream_.current_frame());
                        error_code ec;
                        auto next = parse(span.begin(), span.end(), packet, ec);
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

        auto c = client(net::make_strand(ioc.get_executor()));
        c.start();
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