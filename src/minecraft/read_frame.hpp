//
// Created by rhodges on 13/04/2020.
//

#pragma once

#include "minecraft/parse.hpp"
#include "net.hpp"

#include <boost/beast/core/bind_handler.hpp>

namespace minecraft
{
    template < class Stream, class DynamicBuffer, class CompletionHandler >
    auto async_read_frame(Stream &stream, DynamicBuffer buffer, CompletionHandler &&handler)
    {
        auto op = [&stream,
                   coro = net::coroutine(),
                   buffer,
                   cont         = false,
                   ec_          = error_code(),
                   transferred_ = std::size_t(0),
                   frame_length =
                       std::int32_t(0)](auto &self, error_code ec = {}, std::size_t bytes_transferred = 0) mutable {
#include <boost/asio/yield.hpp>
            std::size_t len, original_size;
            reenter(coro)
            {
                {
                read_length:
                    auto available = buffer.data(0, buffer.size());
                    auto first     = buffers_begin(available);
                    auto last      = buffers_end(available);
                    auto next      = parse_var(first, last, frame_length, ec);
                    len            = std::distance(first, next);
                };

                if (!ec.failed())
                {
                    if (frame_length > 1000000)
                    {
                        ec                = error::huge_frame;
                        bytes_transferred = 0;
                        goto do_completion;
                    }
                    else
                    {
                        buffer.consume(len);
                        goto read_frame;
                    }
                }
                else if (ec != error::incomplete_parse)
                {
                    bytes_transferred = 0;
                    goto do_completion;
                }
                else   // incomplete parse
                {
                    yield
                    {
                        cont          = true;
                        original_size = buffer.size();
                        buffer.grow(4096);
                        auto buf = buffer.data(original_size, buffer.size() - original_size);
                        stream.async_read_some(buf, std::move(self));
                    }
                    buffer.shrink(buffer.size() - bytes_transferred);
                    if (ec.failed())
                    {
                        bytes_transferred = 0;
                        goto do_completion;
                    }
                    goto read_length;
                }

            read_frame:

                while (buffer.size() < frame_length)
                {
                    original_size = buffer.size();
                    buffer.grow(frame_length - buffer.size());
                    cont = true;
                    yield
                    {
                        auto buf = buffer.data(original_size, buffer.size() - original_size);
                        stream.async_read_some(buf, std::move(self));
                    }
                    buffer.shrink(buffer.size() - bytes_transferred);
                    if (ec.failed())
                    {
                        bytes_transferred = 0;
                        goto do_completion;
                    }
                }

                ec.clear();
                bytes_transferred = frame_length;

            do_completion:
                if (!cont)
                {
                    cont = true;
                    yield net::post(boost::beast::bind_front_handler(std::move(self), ec, bytes_transferred));
                }
                self.complete(ec, bytes_transferred);
            }
#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionHandler, void(error_code, std::size_t) >(std::move(op), handler, stream);
    }

    template < class Stream, class DynamicBuffer, class FrameType, class CompletionHandler >
    auto async_expect_frame(Stream &stream, DynamicBuffer buffer, FrameType &target, CompletionHandler &&handler)
    {
        auto op = [&stream, coro = net::coroutine(), buffer, &target](
                      auto &self, error_code ec = {}, std::size_t bytes_transferred = 0) mutable {
#include <boost/asio/yield.hpp>
            reenter(coro)
            {
                yield async_read_frame(stream, buffer, std::move(self));
                if (not ec.failed())
                {
                    auto extent = buffer.data(0, bytes_transferred);
                    auto first  = net::buffers_begin(extent);
                    auto last   = net::buffers_end(extent);
                    using which_type = var_enum<decltype(target.id())>;
                    auto which  = which_type();
                    first = parse(first, last, which, ec);
                    if (!ec.failed())
                        if (which != target.id())
                            ec = error::unexpected_packet;
                    if (!ec.failed())
                        parse(first, last, target, ec);
                    if (not ec.failed())
                        buffer.consume(bytes_transferred);
                    return self.complete(ec);
                }
            }
#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionHandler, void(error_code) >(std::move(op), handler, stream);
    }
}   // namespace minecraft