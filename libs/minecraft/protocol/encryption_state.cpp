//
// Created by rhodges on 15/04/2020.
//

#include "encryption_state.hpp"

namespace minecraft::protocol
{
    encryption_state::encryption_state(shared_secret const &secret)
    : tx_context_(net::buffer(secret), net::buffer(secret))
    , rx_context_(net::buffer(secret), net::buffer(secret))
    {
    }

    encryption_state::encryption_state(net::const_buffer secret)
    : tx_context_(secret, secret)
    , rx_context_(secret, secret)
    {
    }

}   // namespace minecraft::protocol