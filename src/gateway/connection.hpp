#pragma once

#include "net.hpp"
#include <memory>
#include "minecraft/frame_parser.hpp"

namespace gateway {
    struct connection_impl
    : std::enable_shared_from_this<connection_impl>
    {
        using executor_type = net::io_context::executor_type;
        using protocol = net::ip::tcp;
        using socket_type = net::basic_stream_socket<protocol, executor_type>;

        explicit connection_impl(socket_type &&sock);

        auto start() -> void;

        auto cancel() -> void;

        auto get_executor() -> executor_type;

    private:

        auto handle_start() -> void;
        auto handle_cancel() -> void;

        auto initiate_read() -> void;
        auto handle_read(error_code const& ec, std::size_t bytes_transferred) -> void;

        socket_type sock_;
        std::vector<char> rx_buffer_;
        minecraft::frame_parser parser_;
        minecraft::frame_variant current_frame_;

};


    struct connection
    {
        using socket_type = connection_impl::socket_type;

        explicit connection(socket_type &&sock);

        void
        cancel();

        auto
        get_weak_impl() const -> std::weak_ptr<connection_impl>;

    private:

        std::shared_ptr<connection_impl> impl_;
    };

}