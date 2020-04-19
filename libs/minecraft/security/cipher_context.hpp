//
// Created by rhodges on 14/04/2020.
//

#pragma once

#include "minecraft/net.hpp"
#include "minecraft/security/error.hpp"

#include <openssl/aes.h>
#include <openssl/evp.h>
#include <wise_enum/wise_enum.h>

namespace minecraft::security
{
    inline auto check_success(EVP_CIPHER_CTX *p) -> EVP_CIPHER_CTX *
    {
        if (not p)
            throw_error();
        return p;
    }

    struct cipher_context
    {
        using native_handle_type = EVP_CIPHER_CTX *;

      protected:
        cipher_context();

      public:
        cipher_context(cipher_context &&other) noexcept;

        cipher_context &operator=(cipher_context &&other) noexcept;

        ~cipher_context();

        native_handle_type release() noexcept;
        native_handle_type native_handle() noexcept;

      private:
        static void destroy(native_handle_type handle);

      private:
        native_handle_type handle_;

    };

    struct encryption_context : cipher_context
    {
        encryption_context(net::const_buffer key, net::const_buffer iv);

        template < class CipherDynamicBuffer >
        auto update(net::const_buffer plaintext, CipherDynamicBuffer ciphertext) -> void;

        template < class CipherDynamicBuffer >
        auto finalise(CipherDynamicBuffer ciphertext) -> void;
    };

    struct decryption_context : cipher_context
    {
        decryption_context(net::const_buffer key, net::const_buffer iv);

        template < class PlaintextDynamicBuffer >
        auto update(net::const_buffer ciphertext, PlaintextDynamicBuffer plaintext) -> void;

        template < class PlaintextDynamicBuffer >
        auto finalise(PlaintextDynamicBuffer plaintext) -> void;
    };

}   // namespace minecraft::security
