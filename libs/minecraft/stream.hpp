#pragma once

#include "minecraft/net.hpp"
#include "minecraft/stream_impl.hpp"
namespace minecraft
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
        /// \return
        template < class CompletionToken >
        auto async_read_frame(CompletionToken &&token) ->
            typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type;

        template < class CompletionToken >
        auto async_write_frame(net::const_buffer frame_data, CompletionToken &&token) ->
            typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type;

        /// Return a mutable_buffer representing the data in last frame to be read.
        /// The user may modify the data in this buffer.
        /// The data in the buffer will be valid until the next async_read_frame call
        auto current_frame() -> net::mutable_buffer;

        auto get_executor() const -> executor_type;

        auto next_layer() -> next_layer_type &;

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
}   // namespace minecraft

#include "minecraft/stream.ipp"
