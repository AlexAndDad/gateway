#pragma once

#include "minecraft/net.hpp"
#include "stream_impl.hpp"
namespace minecraft::protocol
{
    template < class NextLayer = net::basic_stream_socket< net::ip::tcp, net::io_context::executor_type > >
    struct stream
    {
        using implementation_class = stream_impl< NextLayer >;
        using implementation_type  = implementation_class *;
        using next_layer_type      = typename implementation_class::next_layer_type;
        using executor_type        = typename implementation_class::executor_type;

        stream(NextLayer &&next)
        : impl_(construct(std::move(next)))
        {
        }

        stream(stream &&other)
        : impl_(other.release())
        {
        }

        ~stream()
        {
            if (impl_)
            {
                impl_->close();
                destroy(std::exchange(impl_, nullptr));
            }
        }

        /// Read a complete frame into the internal frame buffer.
        /// The internal buffer will be available via the current_frame() method
        /// \tparam CompletionToken
        /// \param token
        /// \return DEDUCED
        template < class CompletionToken >
        auto async_read_frame(CompletionToken &&token) ->
            typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type;

        /// Asynchronously write a frame.
        /// The frame data is assumed to have already been composed by the caller.
        /// The frame data is copied by the implementation before the internal asynchronous operation starts.
        /// This is in general not a pesssimisation as almost all minecraft communications are encrypted
        /// \tparam CompletionToken
        /// \param frame_data
        /// \param token
        /// \return DEDUCED
        template < class CompletionToken >
        auto async_write_frame(net::const_buffer frame_data, CompletionToken &&token) ->
            typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type;

        template < class Packet, class CompletionToken >
        auto async_write_packet(Packet const &p, CompletionToken &&token) ->
            typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type;

        /// Return a mutable_buffer representing the data in last frame to be read.
        /// The user may modify the data in this buffer.
        /// The data in the buffer will be valid until the next async_read_frame call
        auto current_frame() -> net::mutable_buffer;

        auto get_executor() const -> executor_type;

        /// Enable encryption and set the shared secret
        /// \param secret is a net::const buffer containing the shared secret. secret.size() must be exactly 16
        /// \pre stream is not already encrypted
        /// \pre no async operations are in progress
        /// \post all subsequent reads and writes will be encrypted
        auto set_encryption(shared_secret secret) -> void
        {
            assert(secret.has_value());
            impl_->set_encryption(secret);
        }

        void protocol_version(protocol::version_type version);

        auto protocol_version() const -> protocol::version_type;

        auto next_layer() -> next_layer_type &;
        auto next_layer() const -> next_layer_type const &;

        auto close() noexcept -> void;

      private:
        implementation_type release() { return std::exchange(impl_, nullptr); }

        static implementation_type construct(NextLayer &&next) { return new stream_impl< NextLayer >(std::move(next)); }

        static void destroy(implementation_type impl)
        {
            impl->close();
            delete impl;
        }

        implementation_type impl_;
    };
}   // namespace minecraft::protocol

#include "stream.ipp"
