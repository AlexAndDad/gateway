#pragma once
#include "minecraft/compose.hpp"
#include "net.hpp"

#include <vector>

namespace minecraft
{
    template < class Stream >
    struct send_frame_op : net::coroutine
    {
        explicit send_frame_op(Stream &s)
        : stream_(s)
        {
        }

        template < class Self >
        void operator()(Self &self, error_code ec = {}, std::size_t bytes_transferred = 0)
        {
#include <boost/asio/yield.hpp>
            reenter(this) for (;;)
            {
                yield
                {
                    auto buf = net::buffer(tx_data_.data(), tx_data_.size());
                    async_write(stream_, buf, std::move(self));
                }

                return self.complete(ec, bytes_transferred);
            }
#include <boost/asio/unyield.hpp>
        }

        Stream &            stream_;
        std::vector< char > tx_data_;
    };

    template < class Stream, class Frame, class CompletionToken, bool compression = false >
    auto async_send_frame(Stream &stream, Frame const &frame, CompletionToken &&handler)
    {
        static thread_local auto compose_buffer = std::vector< char >();
        compose_buffer.clear();
        compose(frame, compose_buffer);
        if constexpr (compression)
        {
            // todo
        }

        auto op = send_frame_op< Stream >(stream);
        compose(compose_buffer, op.tx_data_);
        return net::async_compose< CompletionToken, void(error_code, std::size_t) >(
            std::move(op), handler, stream);
    }
}   // namespace minecraft