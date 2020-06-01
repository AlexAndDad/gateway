#include "connection_impl.hpp"

#include "config/span.hpp"
#include "keep_alive_handler.hpp"
#include "minecraft/packets/client_play_packet.hpp"
#include "minecraft/packets/server/chat_message.hpp"
#include "minecraft/packets/server/join_game.hpp"
#include "minecraft/packets/server/play_packet.hpp"
#include "minecraft/parse_error.hpp"
#include "minecraft/protocol/old_style_ping.hpp"
#include "minecraft/protocol/server_handshake.hpp"
#include "minecraft/protocol/server_status.hpp"
#include "minecraft/security/rsa.hpp"
#include "minecraft/variant.hpp"
#include "polyfill/async/async_task.hpp"
#include "polyfill/explain.hpp"
#include "polyfill/hexdump.hpp"
#include "polyfill/report.hpp"

#include <random>
#include <spdlog/fmt/bin_to_hex.h>

namespace gateway
{
    using namespace std::literals;

    namespace
    {
        std::string generate_server_id()
        {
            auto rng   = std::random_device();
            auto seq   = std::seed_seq { rng(), rng(), rng(), rng(), rng() };
            auto eng   = std::default_random_engine(seq);
            auto chars = "0123456789abcdefghijklmnopqrstuvwxyz"sv;
            auto dist  = std::uniform_int_distribution< std::size_t >(0, chars.size() - 1);

            auto result = std::string();
            std::generate_n(std::back_inserter(result), 16, [&] { return chars[dist(eng)]; });

            return result;
        }

        minecraft::security::private_key generate_server_key()
        {
            auto key = minecraft::security::private_key();
            key.assign(minecraft::security::rsa(1024));
            return key;
        }

    }   // namespace

    template < class... Ts >
    struct overloaded : Ts...
    {
        using Ts::operator()...;
    };
    template < class... Ts >
    overloaded(Ts...) -> overloaded< Ts... >;

    // =========================================

    connection_impl::connection_impl(polyfill::configuration &config, socket_type &&sock)
    : config_(config)
    , server_key_(generate_server_key())
    , server_id_(generate_server_id())
    , compression_threshold_(config_["client_connection"].as_object()["compression_threshold"].as_int64())
    , stream_(std::move(sock))
    , packet_read_queue_(get_executor())
    , packet_write_queue_(get_executor())
    , login_params_(server_id_, server_key_)
    {
    }

    auto connection_impl::start() -> void { spdlog::info("Started connection to [{}]", stream_.next_layer().remote_endpoint()); }

    auto connection_impl::attempt_handshake() -> net::awaitable< bool >
    {
        co_return co_await polyfill::async::async_task(
            get_executor(),
            [self = shared_from_this()]() mutable -> net::awaitable< bool > { co_return co_await self->handle_attempt_handshake(); },
            "connection_impl",
            "attempt_handshake()");
    }

    auto connection_impl::handle_attempt_handshake() -> net::awaitable< bool >
    {
        assert(client_state_ == client_state::CONNECTED);

        if (co_await minecraft::protocol::async_is_old_style_ping(stream_.next_layer(), net::use_awaitable))
        {
            client_state_ = client_state::STATUS_PING;
            co_await async_old_style_ping(stream_, net::use_awaitable);
            co_return false;
        }
        else
            switch (co_await minecraft::protocol::async_server_handshake(stream_, net::use_awaitable))
            {
            case minecraft::protocol::connection_state::status:
                client_state_ = client_state::STATUS_PING;
                co_await minecraft::protocol::async_server_status(stream_, net::use_awaitable);
                co_return false;
            case minecraft::protocol::connection_state::login:
                client_state_ = client_state::HANDSHAKE;
                break;
            default:
                spdlog::error("logic error"), void();
                client_state_ = client_state::ERROR;
                co_return false;
            }

        assert(client_state_ == client_state::HANDSHAKE);
        // Accept the client
        try
        {
            co_await minecraft::protocol::async_server_accept(stream_, this->login_params_, net::use_awaitable);
            spdlog::info("Welcome! {} on {}", std::quoted(stream_.player_name()), stream_.full_info());
            // Handshake complete, move to the login state
            client_state_ = client_state::PLAY;
            co_return true;
        }
        catch (system_error &se)
        {
            auto &&ec = se.code();
            if (ec.failed())
            {
                spdlog::error("{}::{}({}) on {} with params {}", this, __func__, polyfill::report(ec), stream_.full_info(), login_params_);
                client_state_ = client_state::ERROR;
            }
            co_return false;
        }
    }

    auto connection_impl::run() -> net::awaitable< void >
    {
        BOOST_ASSERT(client_state_ == client_state::PLAY);
        client_state_ = client_state::PLAY;

        // Start the keep_alive handler
        auto keep_alive = keep_alive_handler(std::make_shared< keep_alive_impl >(get_executor()));
        keep_alive.get().set_callbacks([self = shared_from_this()]() { self->on_keep_alive_timeout(); },
                                       [self = shared_from_this()]() { self->on_keep_alive_update(); });

        // Start writer coroutine
        net::co_spawn(
            get_executor(),
            [self = shared_from_this()]() mutable -> net::awaitable< void > {
                try
                {
                    for (;;)
                    {
                        auto packet = co_await self->packet_write_queue_.async_pop(net::use_awaitable);
                        co_await self->async_write_packet(packet);
                    }
                }
                catch (system_error &se)
                {
                    auto ec = se.code();
                    if (ec == net::error::operation_aborted)
                        co_return;
                    else
                        throw se;
                }
            },
            polyfill::coro_except_handler("connection_impl", "run[writer_coroutine]()"));

        // Spin reading packets and sending to queue to be processed
        while (true)
        {
            try
            {
                auto ec   = error_code();
                auto pack = co_await async_read_packet(ec);

                if (not ec)
                {
                    // Handle the packet, if its a ping we handle it here, else
                    // pass it to the bus
                    visit(overloaded {
                              [this](minecraft::monostate &) {
                                  spdlog::error("connection_impl[player[{}]] - received monostate packet in run().", stream_.player_name());
                              },
                              [this, &pack](auto &) {
                                  // A normal play packet
                                  packet_read_queue_.push(std::move(pack));
                              },
                              [&keep_alive](minecraft::packets::client::keep_alive &) {
                                  // handle keep alive packet
                                  keep_alive.get().reset_expiry();
                              },
                          },
                          pack.as_variant());
                }
            }
            catch (system_error &se)
            {
                auto &&ec = se.code();
                spdlog::warn("{}::{}({})", this, __func__, polyfill::report(ec));

                if (ec.category() != minecraft::parse_error_category())
                {
                    co_return;
                }
            }
        }
    }

    auto connection_impl::cancel() -> void
    {
        dispatch(bind_executor(get_executor(), [self = shared_from_this()] { self->handle_cancel(); }));
    }

    auto connection_impl::get_executor() -> executor_type { return stream_.get_executor(); }

    auto connection_impl::handle_cancel() -> void { stream_.close(); }

    // Virtual functions
    net::awaitable< minecraft::packets::client::client_play_packet > connection_impl::async_get_client_packet()
    {
        co_return co_await packet_read_queue_.async_pop(net::use_awaitable);
    }
    void connection_impl::send_packet(minecraft::packets::server::server_play_packet packet)
    {
        net::dispatch(net::bind_executor(get_executor(), [self = shared_from_this(), packet = std::move(packet)]() {
            self->packet_write_queue_.push(std::move(packet));
        }));
    }
    void connection_impl::start_play()
    {
        net::co_spawn(
            get_executor(),
            [self = shared_from_this()]() mutable -> net::awaitable< void > { co_await self->run(); },
            polyfill::coro_except_handler("connetion_impl", "start_play()"));
    }

}   // namespace gateway