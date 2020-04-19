#pragma once
#include "encryption_state.hpp"
#include "minecraft/parse.hpp"
#include "minecraft/protocol/compose_area.hpp"
#include "minecraft/protocol/compression.hpp"
#include "minecraft/protocol/frame_data.hpp"
#include "minecraft/protocol/version.hpp"
#include "minecraft/report.hpp"
#include "minecraft/security/cipher_context.hpp"
#include "minecraft/stream_traits.hpp"
#include "minecraft/types.hpp"

#include <fmt/ostream.h>

namespace minecraft::protocol
{
    struct stream_impl_base
    {
        protocol::version_type protocol_version_ = protocol::version_type::not_set;

        int compression_threshold_ = -1;

        // has_state if encryption is enabled
        std::optional< encryption_state > encryption_;

        // buffer for composing packet structures into frame extents
        compose_area compose_area_;

        // transmit state
        std::vector< char > tx_compose_buffer_;
        std::vector< char > tx_compressed_buffer_;

        // receive state
        frame_data                compressed_rx_data_;   // data is always read into the compressed buffer
        compression::inflate_impl inflator_;
        frame_data                uncompressed_rx_data_;   // and optionally uncompressed into here
        net::mutable_buffer       current_frame_data_ = {};

        WISE_ENUM_CLASS_MEMBER(event, error, frame);
        std::function< void(event, std::string_view) > logger;   // optional logger

        // client parameters / discovered by server
        std::string   hostname;
        std::string   player_name;
        std::uint32_t port = 0;
    };

    inline std::ostream &operator<<(std::ostream &os, stream_impl_base const &base)
    {
        fmt::print(os,
                   "[player_name {}] [protocol {}] [compression {}] [encryption {}] [hostname {}] [port {}]",
                   base.player_name,
                   wise_enum::to_string(base.protocol_version_),
                   base.compression_threshold_,
                   (base.encryption_ ? "yes" : "no"),
                   base.hostname,
                   base.port);

        return os;
    }

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
    std::ostream &operator<<(std::ostream &os, stream_impl< NextLayer > &impl)
    {
        fmt::print(os, "[stream {} [transport {}]", impl.as_base(), report(impl.next_layer_));
        auto prefix = []() { return std::string_view("\n    "); };

        return os;
    }

}   // namespace minecraft::protocol

#include "stream_impl.ipp"
