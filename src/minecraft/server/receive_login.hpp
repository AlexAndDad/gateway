#pragma once
#include "minecraft/net.hpp"
#include "minecraft/read_frame.hpp"

namespace minecraft::server
{
    struct receive_login_params
    {
        // inputs
        std::vector<std::uint8_t> security_token;
        minecraft::security::private_key server_key;

        // state
        client::handshake client_handshake_frame;

        // outputs
        std::vector<std::uint8_t> shared_secret;
    };

    template<class Stream, class DynamicBuffer>
    struct receive_login_op : net::coroutine
    {
        receive_login_op(Stream& stream, DynamicBuffer buffer, receive_login_params& params)
        : stream_(stream)
        , buffer_(buffer)
        , params_(params)
        {

        }

        template<class Self>
        void
        operator()(Self &self, error_code ec = {}, std::size_t bytes_transferred = 0)
        {
#include <boost/asio/yield.hpp>
            reenter(this)
            {
                yield async_read_frame(stream_, buffer_, std::move(self));
                {
                    auto frame_extent = buffer_.data(0, bytes_transferred);
                    parse(net::buffers_begin(frame_extent), buffers_end(frame_extent), params_.client_handshake_frame, ec);
                    if (ec.failed())
                        return self.complete(ec);
                    buffer_.consume(bytes_transferred);
                    if (params_.client_handshake_frame.validate(ec).failed())
                        return self.complete(ec);
                }

                self.complete(ec);
            }
#include <boost/asio/unyield.hpp>

        }

        Stream& stream_;
        DynamicBuffer buffer_;
        receive_login_params& params_;
    };


    template<class Stream, class DynamicBuffer, class CompletionHandler>
    auto
    async_receive_login(Stream &stream, DynamicBuffer buffer, receive_login_params& params, CompletionHandler &&handler)
    {
        using op_type = receive_login_op<Stream, DynamicBuffer>;
        return
        net::async_compose<CompletionHandler, void(error_code)>(
        op_type(stream, buffer, params),
        handler, stream);
    }
}