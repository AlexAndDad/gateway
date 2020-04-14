//
// Created by rhodges on 11/04/2020.
//

#include "endpoint_hasher.hpp"
#include <boost/functional/hash.hpp>

namespace polyfill {

    auto
    address_hasher::operator()(net::ip::address const &v) const -> std::size_t
    {
        if (v.is_v4())
            return v.to_v4().to_ulong();
        else if (v.is_v6())
        {
            auto const &range = v.to_v6().to_bytes();
            return boost::hash_range(range.begin(), range.end());
        }
        else if (v.is_unspecified())
        {
            // guaranteed to be random: chosen by fair dice roll
            return static_cast<std::size_t>(0x4751301174351161ul);
        }
        else
            return boost::hash_value(v.to_string());
    }

    auto
    endpoint_hasher::operator()(net::ip::tcp::endpoint const& ep) const -> std::size_t
    {
        using boost::hash_combine;

        auto seed = std::size_t(0);
        hash_combine(seed, address_hasher()(ep.address()));
        hash_combine(seed, ep.port());
        return seed;
    }
}
