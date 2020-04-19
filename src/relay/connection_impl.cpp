#include "connection_impl.hpp"

#include "minecraft/protocol/client_connect.hpp"
#include "minecraft/protocol/old_style_ping.hpp"
#include "minecraft/protocol/server_handshake.hpp"
#include "minecraft/protocol/server_status.hpp"
#include "minecraft/report.hpp"
#include "minecraft/security/rsa.hpp"
#include "minecraft/send_frame.hpp"
#include "minecraft/server/chat_message.hpp"
#include "minecraft/server/play_packet.hpp"
#include "minecraft/utils/exception_handler.hpp"
#include "polyfill/explain.hpp"
#include "polyfill/hexdump.hpp"

#include <random>
#include <spdlog/fmt/bin_to_hex.h>
#include <spdlog/spdlog.h>

namespace relay
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

        auto& ppk = server_key.emplace();
        ppk.assign(minecraft::security::rsa(1024));

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

    connection_impl::connection_impl(connection_config config, socket_type &&sock)
    : config_(std::move(config))
    , stream_(std::move(sock))
    , upstream_(socket_type(get_executor()))
    , resolver_(get_executor())
    , login_params_(config_.server_id, config_.server_key, config_.compression_threshold)
    {
        spdlog::info("{} accepted", this);
        stream_.next_layer().set_option(protocol_type::no_delay(true));
    }

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

    auto connection_impl::cancel() -> void
    {
        dispatch(bind_executor(get_executor(), [self = shared_from_this()] { self->handle_cancel(); }));
    }

    auto connection_impl::get_executor() -> executor_type { return stream_.get_executor(); }

    auto connection_impl::handle_cancel() -> void
    {
        stream_.cancel();
        upstream_.cancel();
        resolver_.cancel();
    }

    auto connection_impl::run() -> net::awaitable< void >
    {
        // check if it's a ping

        if (co_await protocol::async_is_old_style_ping(stream_.next_layer(), net::use_awaitable))
            co_return spdlog::info("{} old style ping", this),
                co_await async_old_style_ping(stream_, net::use_awaitable);

        if (auto state = co_await protocol::async_server_handshake(stream_, net::use_awaitable); is_status(state))
        {
            spdlog::info("{} ping handshake - version {}", this, wise_enum::to_string(stream_.protocol_version()));
            co_return co_await async_server_status(stream_, net::use_awaitable);
        }
        else if (is_login(state))
        {
            spdlog::info("{} login handshake - version {}", stream_, wise_enum::to_string(stream_.protocol_version()));
            upstream_.protocol_version(stream_.protocol_version());
            co_await protocol::async_server_accept(stream_, this->login_params_, net::use_awaitable);

            spdlog::info("{} Welcome! {} on {}", this, std::quoted(stream_.player_name()), stream_.full_info());

            auto results =
                co_await resolver_.async_resolve(config_.upstream_host, config_.upstream_port, net::use_awaitable);

            auto ep = co_await net::async_connect(upstream_.next_layer(), results, net::use_awaitable);
            connect_state_.version(stream_.protocol_version());
            connect_state_.name(stream_.player_name());
            connect_state_.connection_args(config_.upstream_host, ep.port());

            co_await protocol::async_client_connect(upstream_, connect_state_, net::use_awaitable);
            spdlog::info(
                "{} We are welcome upstream! {} on {}", this, std::quoted(stream_.player_name()), stream_.full_info());

            net::co_spawn(
                get_executor(),
                [self = shared_from_this()]() -> net::awaitable< void > { return self->client_to_server(); },
                [this, ehandler = utils::make_exception_handler(this, "client to server")](std::exception_ptr ep) {
                    this->upstream_.next_layer().close();
                    this->stream_.next_layer().close();
                    ehandler(ep);
                });

            net::co_spawn(
                get_executor(),
                [self = shared_from_this()]() -> net::awaitable< void > { return self->server_to_client(); },
                [this, ehandler = utils::make_exception_handler(this, "server to client")](std::exception_ptr ep) {
                    this->upstream_.next_layer().close();
                    this->stream_.next_layer().close();
                    ehandler(ep);
                });
        }
        else
            throw std::runtime_error("client requested unrecognised or invalid state");
    }

    auto connection_impl::client_to_server() -> net::awaitable< void >
    {
        while (1)
        {
            co_await stream_.async_read_frame(net::use_awaitable);
            auto frame = stream_.current_frame();

            int32_t frame_type;
            auto    span = to_span(stream_.current_frame());
            auto    ec   = error_code();
            minecraft::parse_var(span.begin(), span.end(), frame_type, ec);
            if (ec.failed())
            {
                spdlog::error("{}::{} : {}", *this, __func__, report(ec));
                co_return;
            }
            else
            {
                spdlog::trace("{}::{} : frame type: {:0x} length {:0x}", *this, __func__, frame_type, frame.size());
                co_await upstream_.async_write_frame(frame, net::use_awaitable);
            }
        }
    }

    auto connection_impl::server_to_client() -> net::awaitable< void >
    {
        //        net::system_timer st(get_executor());
        while (1)
        {
            co_await upstream_.async_read_frame(net::use_awaitable);
            auto frame = upstream_.current_frame();

            int32_t frame_type;
            auto    span = to_span(frame);
            auto    ec   = error_code();
            minecraft::parse_var(span.begin(), span.end(), frame_type, ec);
            if (ec.failed())
            {
                spdlog::error("{}::{} : {}", *this, __func__, report(ec));
                co_return;
            }
            else
            {
                spdlog::trace("{}::{} : frame type: {:0x} length {:0x}", *this, __func__, frame_type, frame.size());
                //                spdlog::info("{}::{} : frame type: {:0x} length {:0x} {:n}", *this, __func__,
                //                frame_type, frame.size(), spdlog::to_hex(to_span(frame))); st.expires_after(500ms);
                //                co_await st.async_wait(net::use_awaitable);
                co_await stream_.async_write_frame(frame, net::use_awaitable);
            }
        }
    }

}   // namespace relay