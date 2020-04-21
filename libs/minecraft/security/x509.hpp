//
// Created by rhodges on 12/04/2020.
//

#pragma once

#include "minecraft/security/x509_name.hpp"

#include <chrono>
#include <openssl/x509.h>
#include <utility>

namespace minecraft::security
{
    struct private_key;

    struct x509
    {
        using native_handle_type = X509 *;

        x509();
        ~x509();
        x509(x509 &&r);
        x509(x509 const &r);
        x509 &operator=(x509 &&r);
        x509 &operator=(x509 const &r);

        auto dup() const -> native_handle_type { return X509_dup(handle_); }
        auto release() -> native_handle_type { return std::exchange(handle_, nullptr); }
        auto native_handle() const -> native_handle_type { return handle_; }

        // interface

        void serial_number(int val);
        void not_before(std::chrono::seconds from_now);
        void not_after(std::chrono::seconds from_now);
        void public_key(private_key const &ppk);
        auto subject_name() -> x509_name_ref;
        auto issuer_name(x509_name_ref name) -> void;

      private:
        native_handle_type handle_;
    };

}   // namespace minecraft::security
