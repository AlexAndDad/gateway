//
// Created by rhodges on 12/04/2020.
//

#include "rsa.hpp"
#include <stdexcept>
#include <utility>

namespace minecraft::security {

    rsa::rsa(std::size_t bits)
    : handle_(RSA_generate_key(static_cast<int>(bits), RSA_F4, nullptr, nullptr))
    {
        if (not handle_)
            throw std::runtime_error("rsa keygen failed");
    }

    rsa::rsa(rsa &&r)
    :handle_(std::exchange(r.handle_, nullptr))
    {

    }

    rsa &
    rsa::operator=(rsa &&r)
    {
        auto tmp = std::move(r);
        std::swap(handle_, tmp.handle_);
        return *this;
    }

    rsa::~rsa() noexcept
    {
        RSA_free(handle_);
    }


}