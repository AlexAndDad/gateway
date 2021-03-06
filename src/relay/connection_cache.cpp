#include "connection_cache.hpp"

namespace relay
{
    void connection_cache::create(connection_config config, socket_type &&sock)
    {
        if (canceled_)
        {
            return;
        }
        auto ep    = sock.remote_endpoint();
        auto conn  = connection(std::move(config), std::move(sock));
        cache_[ep] = conn.get_weak_impl();
    }

    void connection_cache::cancel()
    {
        canceled_ = true;

        for (auto iter = cache_.begin(); iter != cache_.end();)
        {
            if (auto p = iter->second.lock())
                p->cancel();
            iter = cache_.erase(iter);
        }
    }

}   // namespace gateway