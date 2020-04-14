//
// Created by rhodges on 12/04/2020.
//

#pragma once

#include <openssl/x509.h>
#include <utility>
#include <string_view>

struct x509_name_ref
{
    using native_handle_type = X509_NAME *;

    x509_name_ref(native_handle_type handle)
    : handle_(handle)
    {

    }

    void
    add_entry(const char *name, std::string_view value)
    {
        X509_NAME_add_entry_by_txt(native_handle(), name, MBSTRING_ASC,
                                   reinterpret_cast<const unsigned char *>(value.data()),
                                   static_cast<int>(value.size()), -1, 0);
    }

    auto
    native_handle() const -> native_handle_type
    { return handle_; }

private:
    native_handle_type handle_;
};


