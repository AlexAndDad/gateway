//
// Created by rhodges on 15/04/2020.
//

#pragma once
#include "minecraft/net.hpp"
#include "minecraft/security/cipher_context.hpp"
#include "minecraft/shared_secret.hpp"

#include <cstdint>
#include <vector>

namespace minecraft
{
    struct encryption_state
    {
        encryption_state(shared_secret const &secret)
        : tx_context_(net::buffer(secret), net::buffer(secret))
        , rx_context_(net::buffer(secret), net::buffer(secret))
        {
        }

        security::encryption_context tx_context_;
        std::vector< char >  tx_cipher_;

        security::decryption_context rx_context_;
        std::vector< char >  rx_cipher_;
    };
}   // namespace minecraft
