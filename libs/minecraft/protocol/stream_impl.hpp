#pragma once

#include "minecraft/protocol/stream_impl_base.hpp"
#include "minecraft/stream_traits.hpp"
#include "minecraft/report.hpp"

namespace minecraft::protocol
{
    template < class NextLayer >
    struct stream_impl : stream_impl_base
    {
        using next_layer_type = NextLayer;

        using executor_type = typename NextLayer::executor_type;

        auto as_base() -> stream_impl_base & { return *this; }

        stream_impl(next_layer_type &&next);

        /// Immediately close the underlying stream and destroy any encryption/compression state
        auto close() -> void;

        /// upgrades to encrypted mode
        auto enable_encryption(shared_secret const &secret) -> void;

        auto get_executor() -> executor_type;

        auto next_layer() -> next_layer_type &;
        auto next_layer() const -> next_layer_type const &;

        template < class CompletionToken >
        auto async_read_frame(CompletionToken &&token) ->
            typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type;

        template < class CompletionToken >
        auto async_read_more(CompletionToken &&token) ->
            typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type;

        /// Either writes the data in plaintext completely to the buffer (using multiple write operations if necessary)
        /// or fails with error. In either case the total number of plaintext bytes consumed will be reported.
        /// \tparam CompletionToken
        /// \param plaintext
        /// \param token
        /// \return DEDUCED
        template < class CompletionToken >
        auto async_write(net::const_buffer plaintext, CompletionToken &&token) ->
            typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type;

        template < class CompletionToken >
        auto async_write_composed_frame(CompletionToken &&token) ->
            typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type;

        template < class MutableBufferSequence, class CompletionToken >
        auto async_read_some(MutableBufferSequence const &sequence, CompletionToken &&token) ->
            typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type;

        auto current_frame() -> net::mutable_buffer { return current_frame_data_; }

        auto decode_frame_length(error_code &ec) -> void;

        bool compression_enabled() const { return compression_threshold_ >= 0; }

        auto set_encryption(shared_secret const &secret) -> void
        {
            assert(not encryption_);
            encryption_.emplace(secret);
        }

        std::string const &log_id()
        {
            if constexpr (has_remote_endpoint_v< NextLayer >)
            {
                if (not log_id_.empty())
                    return log_id_;

                struct
                {
                    error_code                               ec;
                    typename next_layer_type ::endpoint_type ep;
                } local, remote;

                local.ep = next_layer_.local_endpoint(local.ec);

                remote.ep = next_layer_.remote_endpoint(remote.ec);

                std::string *rep = (local.ec.failed() or remote.ec.failed()) ? std::addressof(this->unconnected_log_id_)
                                                                             : std::addressof(log_id_);
                *rep = fmt::format("[stream {}->{}]", report(local.ep), report(remote.ep));
                return *rep;
            }
            else
            {
                if (log_id_.empty())
                    log_id_ = "test";
                return log_id_;
            }
        }

        next_layer_type next_layer_;
        std::string     log_id_, unconnected_log_id_;
    };

    template < class NextLayer >
    std::ostream &operator<<(std::ostream &os, stream_impl< NextLayer > &impl);

}   // namespace minecraft::protocol

#include "stream_impl.ipp"
