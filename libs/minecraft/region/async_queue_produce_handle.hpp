#pragma once

#include "async_queue_impl.hpp"

#include <memory>

namespace minecraft::region
{
    template < class MessageType >
    struct async_queue_produce_handle
    {
        using impl_type = std::shared_ptr< async_queue_impl< MessageType > >;

        async_queue_produce_handle(impl_type impl)
        : impl_(impl)
        {
        }

        void      produce(MessageType message) { impl_->produce(std::move(message)); }
        impl_type get() { return impl_; }

      private:
        impl_type impl_;
    };

}   // namespace minecraft::region
