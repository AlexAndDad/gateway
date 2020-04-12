#pragma once

#include <openssl/evp.h>
#include <utility>
#include <string>
#include <vector>

namespace minecraft::security
{
    struct rsa;

    struct private_key
    {
        using native_handle_type = EVP_PKEY*;

        explicit private_key();

        private_key(private_key const& r);

        private_key(private_key && r);

        private_key& operator=(private_key&& r);

        private_key& operator=(private_key const& r);

        ~private_key() noexcept;

        void assign(rsa && r);

        native_handle_type dup() const;
        native_handle_type release() { return std::exchange(handle_, nullptr); }
        native_handle_type native_handle() const { return handle_; }

        std::string public_pem() const;
        std::vector<std::uint8_t> public_asn1() const;

    private:

        EVP_PKEY* handle_;
    };

}