#pragma once

#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/pkcs12.h>
#include <utility>
#include <stdexcept>

#include "minecraft/security/private_key.hpp"
#include "minecraft/security/rsa.hpp"
#include "minecraft/security/x509.hpp"

namespace minecraft::security {

    void seed_random()
    {

    }

    std::string generate_certficiate()
    {
        using namespace std::literals;

        auto key_pair = private_key();

        auto rsa_key = rsa(1024);
        key_pair.assign(std::move(rsa_key));

        auto cert = x509();
        cert.serial_number(1);
        cert.not_before(0s);
        cert.not_after(24h * 356 * 10); // 10 years
        cert.public_key(key_pair);
        auto name = cert.subject_name();
        name.add_entry("C", "AD");
        name.add_entry("O", "Sierra Global Experts S.L.");
        name.add_entry("CN", "localhost");
        cert.issuer_name(name);
        return "";
    }
}