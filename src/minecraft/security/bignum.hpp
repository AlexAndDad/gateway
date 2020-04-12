//
// Created by rhodges on 12/04/2020.
//

#pragma once

#include <openssl/bn.h>
#include <utility>

namespace minecraft::security
{
    struct bignum
    {
        using native_handle_type = BIGNUM*;

        explicit bignum(unsigned long word = 0)
        : handle_(BN_new())
        {
            BN_set_word(handle_, word);
        }

        bignum(bignum&& r)
        : handle_(r.release())
        {

        }

        bignum(bignum const& r)
        : handle_(r.dup())
        {

        }

        bignum& operator=(bignum&& r)
        {
            BN_free(handle_);
            handle_ = r.release();
            return *this;
        }

        bignum& operator=(bignum const& r)
        {
            if (handle_ && r.handle_)
            {
                BN_copy(handle_, r.handle_);
            }
            else if (r.handle_)
            {
                handle_ = BN_dup(r.handle_);
            }
            else
            {
                BN_free(handle_);
                handle_ = nullptr;
            }
            return *this;
        }

        ~bignum()
        {
            BN_free(handle_);
        }

        native_handle_type release() { return std::exchange(handle_, nullptr); }
        native_handle_type dup() const { return handle_ ? BN_dup(handle_) : nullptr; }
        native_handle_type native_handle() const { return handle_; }

    private:

        native_handle_type handle_;
    };

}

