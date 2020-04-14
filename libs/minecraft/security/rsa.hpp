//
// Created by rhodges on 12/04/2020.
//

#pragma once

#include <openssl/rsa.h>
#include <utility>

namespace minecraft::security {

    struct rsa
    {
        using native_handle_type = RSA *;

        explicit rsa(std::size_t bits);

        rsa(rsa &&r);

        rsa &
        operator=(rsa &&r);

        ~rsa() noexcept;

        auto
        native_handle() const -> native_handle_type
        {
            return handle_;
        }

        auto release() -> native_handle_type
        {
            return std::exchange(handle_, nullptr);
        }

        native_handle_type handle_;
    };

}