#pragma once

#include "keep_alive_impl.hpp"

namespace gateway
{
    struct keep_alive_handler
    {
        using impl_type = keep_alive_impl;

        keep_alive_handler(impl_type &impl)
        : impl_(impl)
        {
            impl_.start();
        }

        ~keep_alive_handler() { impl_.reset(); }

        keep_alive_handler(const keep_alive_handler &) = delete;
        keep_alive_handler &operator=(const keep_alive_handler &) = delete;

      private:
        impl_type &impl_;
    };
}   // namespace gateway