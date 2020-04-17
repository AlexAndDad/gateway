#include "minecraft/encode.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/parse_error.hpp"
#include "minecraft/span.hpp"

#include <cassert>
#include <spdlog/fmt/bin_to_hex.h>
#include <spdlog/spdlog.h>

namespace minecraft::protocol
{
    template < class NextLayer >
    stream_impl< NextLayer >::stream_impl(next_layer_type &&next)
    : next_layer_(std::move(next))
    {
    }

    template < class NextLayer >
    auto stream_impl< NextLayer >::close() -> void
    {
        encryption_.reset();
        next_layer().close();
    }

    template < class NextLayer >
    template < class CompletionToken >
    auto stream_impl< NextLayer >::async_read_frame(CompletionToken &&token) ->
        typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type
    {
        auto op = [this, coro = net::coroutine(), ec_ = error_code()](
                      auto &self, error_code ec = {}, std::size_t bytes_transferred = 0) mutable {
#include <boost/asio/yield.hpp>
            reenter(coro) for (;;)
            {
                // first try to use current available data
                while (compressed_rx_data_.decode_frame_length(ec) == error::incomplete_parse)
                {
                    yield this->async_read_more(std::move(self));
                    if (ec.failed())
                    {
                        spdlog::error("{}::read_more {} compressed_data={:n}",
                                      log_id(),
                                      report(ec),
                                      spdlog::to_hex(compressed_rx_data_.payload));
                        return self.complete(ec, compressed_rx_data_.payload.size());
                    }
                    spdlog::info(FMT_STRING("{}::read_more compressed_data={:n}"),
                                 log_id(),
                                 spdlog::to_hex(compressed_rx_data_.payload));
                }

                while (compressed_rx_data_.shortfall())
                {
                    yield this->async_read_more(std::move(self));
                    if (ec.failed())
                        return self.complete(ec, compressed_rx_data_.payload.size());
                }

                if (compression_enabled())
                {
                    var_int original_length;
                    auto first = compressed_rx_data_.begin();
                    auto    next = parse(first, compressed_rx_data_.end(), original_length, ec);
                    if (ec.failed())
                        return self.complete(ec, compressed_rx_data_.payload.size());

                    compressed_rx_data_.consume(std::distance(first, next));

                    if (original_length.value() == 0)
                    {
                        // not compressed
                        current_frame_data_ = compressed_rx_data_.get_data();
                        spdlog::info(FMT_STRING("{}::uncompressed frame={:n}"),
                                     log_id(),
                                     spdlog::to_hex(to_span(current_frame_data_)));
                    }
                    else
                    {
                        // decompress here
                        //decompress(compressed_rx_data_, uncompressed_rx_data_);
                        current_frame_data_ = compressed_rx_data_.get_data();
                        spdlog::error(FMT_STRING("{}::compressed frame: packet_length={} offset={} uncompressed_size={} {:n}"),
                                     log_id(),
                                      compressed_rx_data_.payload_size,
                                      compressed_rx_data_.data_position,
                                      original_length.value(),
                                     spdlog::to_hex(to_span(current_frame_data_)));
                        std::abort();
                    }
                }
                else
                {
                    current_frame_data_ = compressed_rx_data_.get_data();
                    spdlog::info(FMT_STRING("{}::uncompressed frame={:n}"),
                                 log_id(),
                                 spdlog::to_hex(to_span(current_frame_data_)));
                }
                return self.complete(ec, current_frame_data_.size());
            }
#include <boost/asio/unyield.hpp>
        };

        // erase any data from previous frame
        compressed_rx_data_.remove_one();
        uncompressed_rx_data_.reset();

        return net::async_compose< CompletionToken, void(error_code, std::size_t) >(
            std::move(op), token, this->next_layer());
    }

    template < class NextLayer >
    template < class CompletionToken >
    auto stream_impl< NextLayer >::async_read_more(CompletionToken &&token) ->
        typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type
    {
        auto op = [this, coro = net::coroutine(), ec_ = error_code(), original_size_ = std::size_t()](
                      auto &self, error_code ec = {}, std::size_t bytes_transferred = 0) mutable {
#include <boost/asio/yield.hpp>
            std::size_t grow_size;

            reenter(coro) for (;;)
            {
                if (encryption_)
                {
                    assert(encryption_->rx_cipher_.empty());
                    yield
                    {
                        auto buf       = net::dynamic_buffer(encryption_->rx_cipher_);
                        original_size_ = buf.size();
                        buf.grow(65536);
                        next_layer().async_read_some(buf.data(original_size_, buf.size()), std::move(self));
                    }
                    auto buf = net::dynamic_buffer(encryption_->rx_cipher_);
                    buf.shrink(buf.size() - (original_size_ + bytes_transferred));
                    if (ec)
                        return self.complete(ec, bytes_transferred);

                    encryption_->rx_context_.update(buf.data(0, buf.size()),
                                                    net::dynamic_buffer(compressed_rx_data_.payload));
                    encryption_->rx_cipher_.clear();
                }
                else
                {
                    yield
                    {
                        auto buf       = net::dynamic_buffer(compressed_rx_data_.payload);
                        original_size_ = buf.size();
                        buf.grow((std::max)(compressed_rx_data_.shortfall(), std::size_t(4096)));
                        next_layer().async_read_some(buf.data(original_size_, buf.size()), std::move(self));
                    }
                    auto buf = net::dynamic_buffer(compressed_rx_data_.payload);
                    buf.shrink(buf.size() - (original_size_ + bytes_transferred));
                }

                return self.complete(ec, bytes_transferred);
            }
#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionToken, void(error_code, std::size_t) >(
            std::move(op), token, this->next_layer());
    }

    template < class NextLayer >
    template < class CompletionToken >
    auto stream_impl< NextLayer >::async_write(net::const_buffer plaintext, CompletionToken &&token) ->
        typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type
    {
        auto op = [this, plaintext, coro = net::coroutine()](
                      auto &self, error_code ec = {}, std::size_t bytes_transferred = 0) mutable {
#include <boost/asio/yield.hpp>
            reenter(coro) for (;;)
            {
                if (encryption_)
                {
                    assert(encryption_->tx_cipher_.empty());
                    encryption_->tx_context_.update(plaintext, net::dynamic_buffer(encryption_->tx_cipher_));
                    yield net::async_write(next_layer(), net::dynamic_buffer(encryption_->tx_cipher_), std::move(self));
                    assert(ec.failed() or encryption_->tx_cipher_.empty());
                }
                else
                {
                    yield net::async_write(next_layer(), plaintext, std::move(self));
                }
                return self.complete(ec, bytes_transferred);
            }
#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionToken, void(error_code, std::size_t) >(
            std::move(op), token, this->next_layer());
    }

    template < class NextLayer >
    template < class CompletionToken >
    auto stream_impl< NextLayer >::async_write_composed_frame(CompletionToken &&token) ->
        typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type
    {
        auto op = [this,
                   coro = net::coroutine()](auto &self, error_code ec = {}, std::size_t bytes_transferred = 0) mutable {
#include <boost/asio/yield.hpp>
            reenter(coro) for (;;)
            {
                yield this->async_write(net::buffer(tx_compose_buffer_), std::move(self));
                assert(ec.failed() or bytes_transferred == tx_compose_buffer_.size());
                tx_compose_buffer_.clear();
                return self.complete(ec, bytes_transferred);
            }
#include <boost/asio/unyield.hpp>
        };

        return net::async_compose< CompletionToken, void(error_code, std::size_t) >(
            std::move(op), token, this->next_layer());
    }

    template < class NextLayer >
    auto stream_impl< NextLayer >::enable_encryption(shared_secret const &secret) -> void
    {
        encryption_.emplace(secret);
    }

    template < class NextLayer >
    auto stream_impl< NextLayer >::compose_tx_frame(net::const_buffer frame_extent) -> void
    {
        assert(tx_compose_buffer_.empty());
        if (compression_threshold_ >= 0 and frame_extent.size() > compression_threshold_)
        {
            compress_tx_frame(frame_extent);
            compose_tx_frame_uncompressed(net::buffer(tx_compressed_buffer_));
        }
        else
        {
            compose_tx_frame_uncompressed(frame_extent);
        }
    }

    template < class NextLayer >
    auto stream_impl< NextLayer >::compose_tx_frame_uncompressed(net::const_buffer frame_extent) -> void
    {
        auto frame_length = var_int(frame_extent.size());
        tx_compose_buffer_.resize(max_encoded_bytes(frame_length) + frame_extent.size());
        auto iter = tx_compose_buffer_.data();
        iter      = encode(frame_length, iter);
        iter += net::buffer_copy(net::buffer(iter, frame_extent.size()), frame_extent);
        tx_compose_buffer_.resize(std::distance(tx_compose_buffer_.data(), iter));
    }

    template < class NextLayer >
    auto stream_impl< NextLayer >::compress_tx_frame(net::const_buffer frame_extent) -> void
    {
        assert(!"write me");
    }

    template < class NextLayer >
    auto stream_impl< NextLayer >::get_executor() -> executor_type
    {
        return next_layer_.get_executor();
    }

    template < class NextLayer >
    auto stream_impl< NextLayer >::next_layer() -> next_layer_type &
    {
        return next_layer_;
    }

    template < class NextLayer >
    auto stream_impl< NextLayer >::next_layer() const -> next_layer_type const &
    {
        return next_layer_;
    }

}   // namespace minecraft::protocol