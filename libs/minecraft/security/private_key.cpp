#include "minecraft/security/private_key.hpp"

#include "minecraft/security/rsa.hpp"

#include <cassert>
#include <openssl/pem.h>
#include <stdexcept>
#include <utility>

namespace minecraft::security
{
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

    private_key &private_key::operator=(private_key &&r)
    {
        EVP_PKEY_free(handle_);
        handle_ = std::exchange(r.handle_, nullptr);
        return *this;
    }

    private_key &private_key::operator=(private_key const &r)
    {
        EVP_PKEY_free(handle_);
        handle_ = r.dup();
        return *this;
    }

    private_key::~private_key() noexcept { EVP_PKEY_free(handle_); }

    auto private_key::dup() const -> native_handle_type
    {
        if (handle_)
        {
            EVP_PKEY_up_ref(handle_);
        }
        return handle_;
    }

    void private_key::assign(rsa &&r) { EVP_PKEY_assign_RSA(handle_, r.release()); }

    std::string private_key::public_pem() const
    {
        BIO *mem = BIO_new(BIO_s_mem());
        PEM_write_bio_PUBKEY(mem, native_handle());
        BUF_MEM *bptr;
        BIO_get_mem_ptr(mem, &bptr);
        auto result = std::string(bptr->data, bptr->data + bptr->length);
        BIO_free(mem);
        return result;
    }

    std::vector< std::uint8_t > private_key::public_asn1() const
    {
        BIO *mem = BIO_new(BIO_s_mem());
        i2d_PUBKEY_bio(mem, native_handle());
        BUF_MEM *bptr;
        BIO_get_mem_ptr(mem, &bptr);
        auto result = std::vector< std::uint8_t >(bptr->data, bptr->data + bptr->length);
        BIO_free(mem);
        return result;
    }

    void private_key::public_key_from_asn1(net::const_buffer asn1)
    {
        auto iter   = reinterpret_cast< const unsigned char * >(asn1.data());
        check_success(d2i_PUBKEY(&handle_, &iter, asn1.size()));
    }

    error_code &private_key::public_key_from_asn1(net::const_buffer asn1, error_code &ec)
    {
        try
        {
            public_key_from_asn1(asn1);
        }
        catch(system_error& se)
        {
            ec = se.code();
        }
        catch(...)
        {
            ec = error::codeless::no_cde;
        }

        return ec;
    }

    void private_key::public_encrypt(net::const_buffer plaintext, std::vector<uint8_t> target)
    {
        auto rsa = EVP_PKEY_get0_RSA(native_handle());
        if (not rsa) throw system_error(error_code(error::not_rsa));
        auto pos = target.size();
        target.resize(pos + RSA_size(rsa));
        auto first = reinterpret_cast<const unsigned char*>(plaintext.data());
        check_positive(RSA_public_encrypt(plaintext.size(), first, target.data() + pos, rsa, RSA_PKCS1_PADDING));
    }


}   // namespace minecraft::security