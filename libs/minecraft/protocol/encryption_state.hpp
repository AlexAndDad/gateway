//
// Created by rhodges on 15/04/2020.
//

#pragma once
#include "minecraft/net.hpp"
#include "minecraft/security/cipher_context.hpp"
#include "shared_secret.hpp"

#include <cstdint>
#include <vector>

namespace minecraft::protocol
{
    struct encryption_state
    {
        encryption_state(shared_secret const &secret);

        encryption_state(net::const_buffer secret);

        security::encryption_context tx_context_;
        std::vector< char >  tx_cipher_;

        security::decryption_context rx_context_;
        std::vector< char >  rx_cipher_;
    };
}   // namespace minecraft
