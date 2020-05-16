#include "connection.hpp"

namespace minecraft::chunks
{
    /*
    auto connection::wait() -> net::awaitable< value_type >
    {
        co_return async_wait(net::use_awaitable);
    }
     */

    void connection::cancel()
    {
        assert(impl_);
        impl_->cancel();
    }

    connection::~connection() {
        if(impl_)
            impl_->cancel();
    }
}   // namespace minecraft::chunks