#pragma once
#include "minecraft/encryption_state.hpp"
#include "minecraft/security/cipher_context.hpp"
#include "minecraft/types.hpp"
#include "minecraft/parse.hpp"

namespace minecraft
{

    struct frame_data
    {
        using store_type = std::vector<char>;

        std::size_t payload_size = 0; //! the size of the frame read from the input stream
        std::size_t data_position = 0; //! position in input stream where the frame's data starts
        store_type payload; //! the input stream

        /// remove one frame's worth of data from the stream
        void remove_one()
        {
            auto first = payload.begin();
            auto last = first + std::exchange(data_position, 0) + std::exchange(payload_size, 0);
            payload.erase(first, last);
        }

        /// erase the stream and metadata
        void reset()
        {
            payload_size = 0;
            data_position = 0;
            payload.clear();
        }

        /// decode the frame length from the stream and update the data_position accordingly.
        /// If the parse fails, state is left unchanged.
        /// @pre payload_size and data_position must be zero
        auto decode_frame_length(error_code &ec) -> error_code&
        {
            assert(payload_size == 0);
            assert(data_position == 0);

            var_int frame_size;
            auto first           = payload.begin();
            auto last            = payload.end();
            auto next            = parse(first, last, frame_size, ec);
            if (not ec.failed())
            {
                payload_size = std::size_t(frame_size.value());
                data_position = std::distance(first, next);
            }
            return ec;
        }

        /// create a net buffer bounding the frame's data
        auto get_data() -> net::mutable_buffer
        {
            assert(not shortfall());
            auto result = net::buffer(payload.data() + data_position, payload_size);
            return result;
        }

        /// point to the first byte of the frame's data
        auto begin() const -> const char*
        {
            assert(not shortfall());
            return payload.data() + data_position;
        }

        /// point to the last byte+1 of the frame's data
        auto end() const -> const char*
        {
            assert(not shortfall());
            return begin() + payload_size;
        }

        void consume(std::size_t n)
        {
            assert(not shortfall());
            data_position += n;
        }

        /// How many bytes we are short of having a complete payload
        /// \return
        auto shortfall() const ->std::size_t
        {
            auto size = payload.size();
            assert(data_position <= size);
            size -= data_position;
            if (size >= payload_size)
                return 0;
            else
                return payload_size - size;
        }
    };

    template < class NextLayer >
    struct stream_impl
    {
        using next_layer_type = NextLayer;

        using executor_type = typename NextLayer::executor_type;

        stream_impl(next_layer_type &&next);

        /// Immediately close the underlying stream and destroy any encryption/compression state
        auto close() -> void;

        /// upgrades to encrypted mode
        auto enable_encryption(shared_secret const &secret) -> void;

        auto get_executor() -> executor_type;

        auto next_layer() -> next_layer_type &;

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

        auto compose_tx_frame(net::const_buffer frame_extent) -> void;
        auto compress_tx_frame(net::const_buffer frame_extent) -> void;
        auto compose_tx_frame_uncompressed(net::const_buffer frame_extent) -> void;

        auto current_frame() -> net::mutable_buffer
        {
            return current_frame_data_;
        }

        auto decode_frame_length(error_code &ec) -> void;

        bool compression_enabled() const
        {
            return compression_threshold_ >= 0;
        }

        next_layer_type next_layer_;

        int compression_threshold_;

        // has_state if encryption is enabled
        std::optional< encryption_state > encryption_;

        // transmit state
        std::vector< char > tx_compose_buffer_;
        std::vector< char > tx_compressed_buffer_;

        // receive state
        frame_data compressed_rx_data_; // data is always read into the compressed buffer
        frame_data uncompressed_rx_data_; // and optionally uncompressed into here
        net::mutable_buffer current_frame_data_ = {};

    };

}   // namespace minecraft

#include "minecraft/stream_impl.ipp"
