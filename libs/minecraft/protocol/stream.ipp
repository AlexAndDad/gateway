namespace minecraft::protocol
{
    template < class NextLayer >
    template < class CompletionToken >
    auto stream< NextLayer >::async_read_frame(CompletionToken &&token) ->
        typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type
    {
        return impl_->async_read_frame(std::forward< CompletionToken >(token));
    }

    template < class NextLayer >
    template < class CompletionToken >
    auto stream< NextLayer >::async_write_frame(net::const_buffer frame_data, CompletionToken &&token) ->
        typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type
    {
        impl_->compose_tx_frame(frame_data);
        return impl_->async_write_composed_frame(std::forward< CompletionToken >(token));
    }

    template < class NextLayer >
    template < class Packet, class CompletionToken >
    auto stream< NextLayer >::async_write_packet(Packet const &p, CompletionToken &&token) ->
        typename net::async_result< std::decay_t< CompletionToken >, void(error_code, std::size_t) >::return_type
    {
        auto &buffer = impl_->compose_buffer;
        buffer.clear();
        compose(p, buffer);
        return async_write_frame(net::buffer(buffer), std::forward< CompletionToken >(token));
    }

    template < class NextLayer >
    auto stream< NextLayer >::close() noexcept -> void
    {
        try
        {
            return impl_->close();
        }
        catch (...)
        {
            // absorb exceptions
        }
    }

    template<class NextLayer>
    auto stream<NextLayer>::cancel() noexcept -> void
    {
        error_code ec;
        next_layer().cancel(ec);
    }

    template < class NextLayer >
    auto stream< NextLayer >::current_frame() -> net::mutable_buffer
    {
        return impl_->current_frame();
    }

    template < class NextLayer >
    auto stream< NextLayer >::get_executor() const -> executor_type
    {
        return impl_->get_executor();
    }

    template < class NextLayer >
    auto stream< NextLayer >::next_layer() -> next_layer_type &
    {
        return impl_->next_layer();
    }

    template < class NextLayer >
    auto stream< NextLayer >::next_layer() const -> next_layer_type const &
    {
        return impl_->next_layer();
    }

    template < class NextLayer >
    auto stream< NextLayer >::protocol_version(protocol::version_type version) -> void
    {
        impl_->protocol_version_ = version;
    }

    template < class NextLayer >
    auto stream< NextLayer >::protocol_version() const -> protocol::version_type
    {
        return impl_->protocol_version_;
    }

    template < class NextLayer >
    auto stream< NextLayer >::log_id() const -> const std::string &
    {
        return impl_->log_id();
    }

    template < class NextLayer >
    auto stream< NextLayer >::compression_threshold(std::int32_t threshold) -> void
    {
        impl_->compression_threshold_ = threshold;
    }

    template < class NextLayer >
    auto stream< NextLayer >::compression_threshold() const -> std::int32_t
    {
        return impl_->compression_threshold_;
    }

}   // namespace minecraft::protocol