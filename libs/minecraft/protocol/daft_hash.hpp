//
// Copyright (c) 2020 Richard Hodges (hodges.r@gmail.com)
//
// Official repository: https://github.com/AlexAndDad/gateway
//
#pragma once

#include "minecraft/net.hpp"
#include <openssl/sha.h>
#include <string>

namespace minecraft::protocol
{
    struct daft_hash_impl
    {
        daft_hash_impl();
        daft_hash_impl(daft_hash_impl const &) = delete;
        daft_hash_impl(daft_hash_impl &&)      = delete;
        daft_hash_impl &operator=(daft_hash_impl const &) = delete;
        daft_hash_impl &operator=(daft_hash_impl &&) = delete;
        ~daft_hash_impl() {}

        void update(net::const_buffer in);

        std::string finalise();

      private:
        SHA_CTX ctx_;
    };
}   // namespace minecraft::protocol