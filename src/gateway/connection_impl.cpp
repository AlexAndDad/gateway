#include "connection_impl.hpp"

#include "config/span.hpp"
#include "minecraft/packets/client_play_packet.hpp"
#include "minecraft/packets/server/chat_message.hpp"
#include "minecraft/packets/server/join_game.hpp"
#include "minecraft/packets/server/play_packet.hpp"
#include "minecraft/protocol/old_style_ping.hpp"
#include "minecraft/protocol/server_handshake.hpp"
#include "minecraft/protocol/server_status.hpp"
#include "minecraft/security/rsa.hpp"
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

    }   // namespace

    connection_config::connection_config()
    : server_key()
    , server_id(generate_server_id())
    , compression_threshold(256)
    {
        server_key.emplace();
        server_key->assign(minecraft::security::rsa(1024));
    };

    auto operator<<(std::ostream &os, connection_config const &cfg) -> std::ostream &
    {
        fmt::print(
            "[connection_config [server_id {}] [server_key {:n}] [compression_threshold {}]",
            cfg.server_id,
            spdlog::to_hex(cfg.server_key.has_value() ? cfg.server_key->public_asn1() : std::vector< std::uint8_t >()),
            cfg.compression_threshold);
        return os;
    }

    // =========================================

    auto connection_impl::start() -> void
    {
        net::co_spawn(
            get_executor(),
            [self = shared_from_this()]() -> net::awaitable< void > { co_await self->run(); },
            [self = shared_from_this()](std::exception_ptr ep) {
                try
                {
                    if (ep)
                        std::rethrow_exception(ep);
                }
                catch (system_error &se)
                {
                    auto &&ec = se.code();
                    if (ec == net::error::operation_aborted)
                        return;
                    spdlog::error("{}::{}({})", *self, "run", minecraft::report(ec));
                }
                catch (...)
                {
                    spdlog::error("{}::{} - exception: ", *self, "run", polyfill::explain());
                }
            });
    }

    template < class... Ts >
    struct overloaded : Ts...
    {
        using Ts::operator()...;
    };
    template < class... Ts >
    overloaded(Ts...) -> overloaded< Ts... >;

    auto connection_impl::run() -> net::awaitable< void >
    {
        //
        // handle handshake and/or server ping
        //

        if (co_await minecraft::protocol::async_is_old_style_ping(stream_.next_layer(), net::use_awaitable))
            co_return spdlog::info("old style ping request..."),
                co_await async_old_style_ping(stream_, net::use_awaitable);
        else
            switch (co_await minecraft::protocol::async_server_handshake(stream_, net::use_awaitable))
            {
            case minecraft::protocol::connection_state::status:
                co_return co_await minecraft::protocol::async_server_status(stream_, net::use_awaitable);
            default:
                co_return spdlog::error("logic error"), void();
            case minecraft::protocol::connection_state::login:
                break;
            }

        //        initiate_read();

        try
        {
            co_await minecraft::protocol::async_server_accept(stream_, this->login_params_, net::use_awaitable);
            spdlog::info("Welcome! {} on {}", std::quoted(stream_.player_name()), stream_.full_info());
        }
        catch (system_error &se)
        {
            auto &&ec = se.code();
            if (ec.failed())
            {
                spdlog::error("{}::{}({}) on {} with params {}",
                              this,
                              __func__,
                              polyfill::report(ec),
                              stream_.full_info(),
                              login_params_);
                co_return;
            }
        }

        // Client is now logged in.
        // Notify the bus
        bus_.produce_username({ stream_.player_name(), true });

        {   // Send join game packet
            auto packet                  = minecraft::packets::server::join_game();
            packet.entity_id             = 1;
            packet.game_mode             = minecraft::packets::server::join_game::survival;
            packet.dimension             = minecraft::packets::server::join_game::overworld;
            packet.hashed_seed           = 123412341234;
            packet.max_players           = 20;
            packet.level_type            = "default";
            packet.view_distance         = 16;
            packet.reduced_debug_info    = false;
            packet.enable_respawn_screen = true;
            co_await async_write_packet(packet);
        }

        {   // Send a spawn packet
            auto pack     = minecraft::packets::server::spawn_position();
            pack.location = { 0, 60, 0 };
            co_await async_write_packet(pack);
        }

        {   // Send a player position and look packet
            auto pack  = minecraft::packets::server::player_position_and_look();
            pack.x     = 0;
            pack.y     = 60;
            pack.z     = 0;
            pack.yaw   = 0.0f;
            pack.pitch = 0.0f;
            pack.set_flags(false, false, false, false, false);
            pack.teleport_ID = 666;
            co_await async_write_packet(pack);
        }

        {   // Await a teleport confirm packet
        }

        // Send 3 chat messages
        for (int i = 0; i < 3; ++i)
        {
            auto pack      = minecraft::packets::server::chat_message();
            pack.json_data = R"json({ "text" : "Hello, World!", "bold" : true })json";
            pack.position  = minecraft::packets::server::chat_message::chat_position ::system_message;
            co_await async_write_packet(pack);
        }

        // Spin
        while (true)
        {
            try
            {
                auto bt = co_await stream_.async_read_frame(net::use_awaitable);

                auto data  = stream_.current_frame();
                auto buf   = minecraft::to_span(data);
                auto first = buf.begin();
                auto last  = buf.end();
                boost::ignore_unused(bt);

                // parse the packet using the new expect frame using a variant
                minecraft::packets::client_play_packet pack = minecraft::packets::client_play_packet();
                auto                                   ec   = error_code();
                parse(first, last, pack, ec);

                if (ec)
                {
                    spdlog::warn("Unable to parse packet from the client");
                    spdlog::warn("{}::{}({})", this, __func__, polyfill::report(ec));
                }
                else
                {
                    // Handle the packet, if its a ping we handle it here, else pass it to the bus
                    auto &func_name = __func__;
                    std::visit(overloaded {
                                   [this, &pack, &func_name](std::monostate &arg) {
                                       spdlog::warn("{}::{}({})", this, func_name, "got 'monostate' in packet_handler");
                                   },
                                   [this, &pack, &func_name](auto &arg) {
                                       spdlog::warn(
                                           "{}::{}({})", this, func_name, "unhandled packet type with ID: " + arg.id());
                                   },
                                   [this, &pack](minecraft::packets::client::keep_alive &arg) { this->bus_ },
                               },
                               pack.as_variant());
                }
            }
            catch (system_error &se)
            {
                auto &&ec = se.code();
                spdlog::warn("{}::{}({})", this, __func__, polyfill::report(ec));
            }
        }
    }

    auto connection_impl::cancel() -> void
    {
        dispatch(bind_executor(get_executor(), [self = shared_from_this()] { self->handle_cancel(); }));
    }

    auto connection_impl::get_executor() -> executor_type { return stream_.get_executor(); }

    auto connection_impl::handle_cancel() -> void { stream_.close(); }

}   // namespace gateway