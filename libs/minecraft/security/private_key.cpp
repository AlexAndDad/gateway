#include "minecraft/security/private_key.hpp"
#include "minecraft/security/rsa.hpp"
#include <openssl/pem.h>

#include <stdexcept>
#include <utility>
#include <cassert>

namespace minecraft::security {
    private_key::private_key()
    : handle_(EVP_PKEY_new())
    {
        if (not handle_)
            throw std::runtime_error("failed to create private key");
    }

    private_key::private_key(private_key const &r)
    : handle_(r.dup())
    {
    }


    private_key::private_key(private_key &&r)
    : handle_(std::exchange(r.handle_, nullptr))
    {
    }

    private_key &
    private_key::operator=(private_key &&r)
    {
        EVP_PKEY_free(handle_);
        handle_ = std::exchange(r.handle_, nullptr);
        return *this;
    }

    private_key &
    private_key::operator=(private_key const &r)
    {
        EVP_PKEY_free(handle_);
        handle_ = r.dup();
        return *this;
    }

    private_key::~private_key() noexcept
    {
        EVP_PKEY_free(handle_);
    }

    auto
    private_key::dup() const -> native_handle_type
    {
        if (handle_)
        {
            EVP_PKEY_up_ref(handle_);
        }
        return handle_;
    }

    void private_key::assign(rsa && r)
    {
        EVP_PKEY_assign_RSA(handle_, r.release());
    }

    std::string private_key::public_pem() const
    {
        BIO* mem = BIO_new(BIO_s_mem());
        PEM_write_bio_PUBKEY(mem, native_handle());
        BUF_MEM* bptr;
        BIO_get_mem_ptr(mem, &bptr);
        auto result = std::string(bptr->data, bptr->data + bptr->length);
        BIO_free(mem);
        return result;
    }

    std::vector<std::uint8_t> private_key::public_asn1() const
    {
        BIO* mem = BIO_new(BIO_s_mem());
        i2d_PUBKEY_bio(mem, native_handle());
        BUF_MEM* bptr;
        BIO_get_mem_ptr(mem, &bptr);
        auto result = std::vector<std::uint8_t>(bptr->data, bptr->data + bptr->length);
        BIO_free(mem);
        return result;
    }

}