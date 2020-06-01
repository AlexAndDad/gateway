#pragma once

#include "gateway/net.hpp"
#include "keep_alive_handler.hpp"
#include "polyfill/async/async_queue.hpp"
#include "polyfill/configuration.hpp"

#include <minecraft/packets/client_play_packet.hpp>
#include <minecraft/protocol/server_accept.hpp>
#include <minecraft/protocol/stream.hpp>
#include <minecraft/security/private_key.hpp>
#include <packets/server_play_packet.hpp>
#include <player/player.hpp>
#include <player/player_connection_base.hpp>
#include <world/world.hpp>

namespace gateway
{
    enum class client_state
    {
        ERROR,
        CONNECTED,
        STATUS_PING,
        HANDSHAKE,
        PLAY,
    };

    struct connection_impl final
    : std::enable_shared_from_this< connection_impl >
    , minecraft::player::player_connection_base
    {
        using executor_type      = net::executor;
        using transport_protocol = net::ip::tcp;
        using socket_type        = net::basic_stream_socket< transport_protocol, executor_type >;
        using stream_type        = minecraft::protocol::stream< socket_type >;

        explicit connection_impl(polyfill::configuration &config, socket_type &&sock);

        auto start() -> void;
        void cancel() override;
        auto attempt_handshake() -> net::awaitable< bool >;

        // Virtual interface functions
        auto async_get_client_packet() -> net::awaitable< minecraft::packets::client::client_play_packet > override;
        void send_packet(minecraft::packets::server::server_play_packet packet) override;
        void start_play() override;


        // Attributes
        auto get_executor() -> executor_type;
        auto get_state() -> client_state { return client_state_; }
        auto get_endpoint() -> socket_type::endpoint_type { return stream_.next_layer().remote_endpoint(); }
        auto get_name() const -> const minecraft::player::player::name_type & { return stream_.player_name(); }

      private:
        template < class Stream >
        friend Stream &operator<<(Stream &os, connection_impl const &i)
        {
            os << "[connection " << minecraft::report(i.stream_.next_layer()) << ']';
            return os;
        }

        template < class Stream >
        friend Stream &operator<<(Stream &os, connection_impl *p)
        {
            os << "[connection " << minecraft::report(p->stream_.next_layer()) << ']';
            return os;
        }

      private:
        auto handle_attempt_handshake() -> net::awaitable< bool >;
        auto run() -> net::awaitable< void >;
        auto handle_cancel() -> void;

        template < class Packet >
        auto async_write_packet(Packet const &p) -> net::awaitable< void >
        {
            try
            {
                co_await stream_.async_write_packet(p, net::use_awaitable);
            }
            catch (system_error &se)
            {
                auto &&ec = se.code();
                spdlog::warn("{}::{}({})", this, "async_write_packet", minecraft::report(ec));
            }
        }
        auto async_read_packet(error_code &ec) -> net::awaitable< minecraft::packets::client::client_play_packet >
        {
            co_await stream_.async_read_frame(net::use_awaitable);

            auto data  = stream_.current_frame();
            auto buf   = minecraft::to_span(data);
            auto first = buf.begin();
            auto last  = buf.end();

            // parse the packet using the new expect frame using a variant
            minecraft::packets::client::client_play_packet pack = minecraft::packets::client::client_play_packet();

            parse(first, last, pack, ec);

            if (ec)
            {
                spdlog::warn("Unable to parse packet from the client with ID: {}", wise_enum::to_string(pack.id()));
                spdlog::warn("{}::{}({})", this, __func__, polyfill::report(ec));
                spdlog::warn("{}", pack);
            }
            co_return pack;
        }

        void on_keep_alive_timeout()
        {
            // TODO cancel connection
            spdlog::error("connection_impl[player[{}]] - keep_alive timeout. Disconnecting.", stream_.player_name());
            cancel();
        }
        void on_keep_alive_update()
        {
            // Queue a keep alive packet to be sent
            using packet_type = minecraft::packets::server::keep_alive;
            auto packet       = minecraft::packets::server::server_play_packet();
            packet.emplace< packet_type >();
            packet.query< packet_type >()->prepare();
            packet_write_queue_.push(std::move(packet));
        }

        polyfill::configuration &config_;

        // config
        std::optional< minecraft::security::private_key > server_key_;
        std::string                                       server_id_;
        int                                               compression_threshold_;

        client_state client_state_ = client_state::CONNECTED;

        stream_type         stream_;
        std::vector< char > compose_buffer_;

        polyfill::async::async_queue< minecraft::packets::client::client_play_packet > packet_read_queue_;
        polyfill::async::async_queue< minecraft::packets::server::server_play_packet > packet_write_queue_;

        minecraft::protocol::server_accept_state login_params_;
    };

}   // namespace gateway
