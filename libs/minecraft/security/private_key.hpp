#pragma once

#include "minecraft/security/error.hpp"

#include <openssl/evp.h>
#include <string>
#include <utility>
#include <vector>

namespace minecraft::security
{
    struct rsa;

    inline EVP_PKEY *check_success(EVP_PKEY *result)
    {
        if (not result)
            throw_error();
        return result;
    }

    struct private_key
    {
        using native_handle_type = EVP_PKEY *;

        explicit private_key();

        private_key(private_key const &r);

        private_key(private_key &&r);

        private_key &operator=(private_key &&r);

        private_key &operator=(private_key const &r);

        ~private_key() noexcept;

        void assign(rsa &&r);

        void public_encrypt(net::const_buffer plaintext, std::vector<uint8_t> target);

        native_handle_type dup() const;
        native_handle_type release() { return std::exchange(handle_, nullptr); }
        native_handle_type native_handle() const { return handle_; }

        std::string                 public_pem() const;
        std::vector< std::uint8_t > public_asn1() const;

        void public_key_from_asn1(net::const_buffer asn1);
        error_code &public_key_from_asn1(net::const_buffer asn1, error_code &ec);

      private:
        EVP_PKEY *handle_;
    };


}   // namespace minecraft::security