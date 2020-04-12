#pragma once

#include "net.hpp"
#include <memory>
#include <iostream>
#include <minecraft/server/login_state.hpp>
#include "minecraft/frame_parser.hpp"
#include "gateway/hexdump.hpp"

namespace gateway {
    struct connection_config
    {
        connection_config();

        minecraft::security::private_key server_key;
        std::string server_id;

        friend auto operator<<(std::ostream& os, connection_config const& cfg) -> std::ostream&;
    };

    struct connection_impl
    : std::enable_shared_from_this<connection_impl>
    {
        using executor_type = net::io_context::executor_type;
        using protocol = net::ip::tcp;
        using socket_type = net::basic_stream_socket<protocol, executor_type>;

        explicit connection_impl(connection_config config, socket_type &&sock);

        auto start() -> void;

        auto cancel() -> void;

        auto get_executor() -> executor_type;

    private:

        auto handle_start() -> void;
        auto handle_cancel() -> void;

        auto initiate_read() -> void;
        auto handle_read(error_code ec, std::size_t bytes_transferred) -> void;
        auto handle_write(error_code ec, std::size_t bytes_transferred) -> void;
        auto handle_rx(error_code ec) -> void;
        auto handle_rx(minecraft::incomplete) -> void;
        auto handle_rx(minecraft::client::handshake const& ch) -> void;
        auto handle_rx(minecraft::client::login_start const& packet) -> void;
        auto handle_rx(minecraft::client::encryption_response const& packet) -> void;

        template<class Packet>
        auto queue(Packet const& packet)
        {
            auto& buf = tx_buffer_[1];
            auto org_size = buf.size();
            encode(packet, back_inserter(buf));

            maybe_send();
        }

        void maybe_send();

        connection_config config_;

        socket_type sock_;
        std::vector<char> rx_buffer_;
        std::vector<char> tx_buffer_[2];
        minecraft::frame_parser parser_;
        minecraft::frame_variant current_frame_;
        minecraft::server::login_state login_state_;
};


    struct connection
    {
        using socket_type = connection_impl::socket_type;

        explicit connection(connection_config config, socket_type &&sock);

        void
        cancel();

        auto
        get_weak_impl() const -> std::weak_ptr<connection_impl>;

    private:

        std::shared_ptr<connection_impl> impl_;
    };

}