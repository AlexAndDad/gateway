//
// Created by rhodges on 12/04/2020.
//

#pragma once

#include <openssl/bn.h>
#include <utility>
#include "minecraft/security/error.hpp"

namespace minecraft::security {
    inline BIGNUM *
    check_success(BIGNUM *ptr)
    {
        if (not ptr)
            throw_error();
        return ptr;
    }

    struct bignum
    {
        using native_handle_type = BIGNUM *;

        explicit bignum(unsigned long word = 0)
        : handle_(BN_new())
        {
            check_success(handle_);
            check_success(BN_set_word(handle_, word));
        }

        bignum(bignum &&r)
        : handle_(r.release())
        {

        }

        bignum(bignum const &r)
        : handle_(r.dup())
        {

        }

        bignum &
        operator=(bignum &&r) noexcept
        {
            BN_free(handle_);
            handle_ = r.release();
            return *this;
        }

        bignum &
        operator=(bignum const &r)
        {
            if (this != &r)
            {
                if (r.handle_)
                    if (handle_)
                        check_success(BN_copy(handle_, r.handle_));
                    else
                        handle_ = r.dup();
                else
                    BN_free(std::exchange(handle_, nullptr));
            }

            return *this;
        }

        ~bignum()
        {
            BN_free(handle_);
        }

        native_handle_type
        release() noexcept
        { return std::exchange(handle_, nullptr); }

        native_handle_type
        dup() const
        {
            return check_success(BN_dup(handle_));
        }

        native_handle_type
        native_handle() const noexcept
        { return handle_; }

    private:

        native_handle_type handle_;
    };

}

