//
// Created by rhodges on 12/04/2020.
//

#include "minecraft/security/x509.hpp"
#include "minecraft/security/private_key.hpp"

#include <utility>
#include <cassert>

#include <openssl/asn1.h>
namespace minecraft::security {

    x509::x509()
    : handle_(X509_new())
    {

    }

    x509::x509(x509&& r)
    : handle_(r.release())
    {

    }

    x509::x509(x509 const& r)
    : handle_(r.dup())
    {

    }

    x509 & x509::operator=(x509 &&r)
    {
        auto tmp = std::move(r);
        std::swap(handle_, r.handle_);
        return *this;
    }

    x509 & x509::operator=(x509 const&r)
    {
        auto tmp = r;
        std::swap(handle_, tmp.handle_);
        return *this;
    }

    x509::~x509()
    {
        X509_free(handle_);
    }

    void x509::serial_number(int val)
    {
        assert(native_handle());
        ASN1_INTEGER_set(X509_get_serialNumber(native_handle()), val);
    }

    void x509::not_before(std::chrono::seconds from_now)
    {
        X509_gmtime_adj(X509_get_notBefore(native_handle()), static_cast<int>(from_now.count()));
    }

    void x509::not_after(std::chrono::seconds from_now)
    {
        X509_gmtime_adj(X509_get_notAfter(native_handle()), static_cast<int>(from_now.count()));
    }

    void x509::public_key(const private_key &ppk)
    {
        X509_set_pubkey(native_handle(), ppk.native_handle());
    }

    auto x509::subject_name() -> x509_name_ref
    {
        return x509_name_ref(X509_get_subject_name(native_handle()));
    }

    auto x509::issuer_name(x509_name_ref name) -> void
    {
        X509_set_issuer_name(native_handle(), name.native_handle());
    }




}