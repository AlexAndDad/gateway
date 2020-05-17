#include "provider.hpp"
namespace minecraft::chunks
{
    provider::provider(net::executor exec)
    : impl_(std::make_shared< provider_impl >(exec))
    {
    }

    auto provider::connect(connection_impl::executor_type e) -> connection
    {
        assert(impl_);
        return connection(impl_->create_connection_impl(e));
    }

    auto provider::operator=(provider &&other) -> provider &
    {
        auto old = std::exchange(impl_, nullptr);
        impl_ = std::exchange(other.impl_, nullptr);
        if (old)
            old->cancel();
        return *this;
    }

    provider::~provider()
    {
        if (impl_)
            impl_->cancel();
        impl_.reset();
    }

    auto provider::notify(chunk_column const& cc) -> void
    {
        assert(impl_);
        impl_->notify_chunk(cc);
    }

    auto provider::notify(chunk_column && cc) -> void
    {
        assert(impl_);
        impl_->notify_chunk(std::move(cc));
    }

    auto provider::notify(vector3 pos, blocks::block_type blk) -> void
    {
        assert(impl_);
        impl_->notify_update(pos, blk);
    }

}   // namespace minecraft::chunks