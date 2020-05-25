#include "connection_cache.hpp"

namespace gateway
{
    connection connection_cache::create(polyfill::configuration & config, socket_type &&sock)
    {
        auto ep    = sock.remote_endpoint();
        auto conn  = connection(config, std::move(sock));
        cache_[ep] = conn.get_weak_impl();
        return conn;
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