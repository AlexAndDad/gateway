//
// Created by rhodges on 14/04/2020.
//

#include "minecraft/security/cipher_context.hpp"

#include "minecraft/security/cipher_context.ipp"

namespace minecraft::security
{
    // -- ciper_context

    cipher_context::cipher_context()
    : handle_(check_success(EVP_CIPHER_CTX_new()))
    {
    }

    cipher_context::cipher_context(cipher_context &&other) noexcept
    : handle_(other.release())
    {
    }

    cipher_context &cipher_context::operator=(cipher_context &&other) noexcept
    {
        destroy(handle_);
        handle_ = other.release();
        return *this;
    }

    cipher_context::~cipher_context() { destroy(handle_); }

    auto cipher_context::release() noexcept -> native_handle_type { return std::exchange(handle_, nullptr); }
    auto cipher_context::native_handle() noexcept -> native_handle_type { return handle_; }

    void cipher_context::destroy(native_handle_type handle)
    {
        if (handle)
            EVP_CIPHER_CTX_cleanup(handle);
        EVP_CIPHER_CTX_free(handle);
    }

    // -- encryption_context

    encryption_context::encryption_context(net::const_buffer key, net::const_buffer iv)
    : cipher_context()
    {
        assert(key.size() == 16);
        assert(iv.size() == 16);

        check_success(EVP_EncryptInit_ex(native_handle(),
                                         EVP_aes_128_cfb8(),
                                         nullptr,
                                         reinterpret_cast< std::uint8_t const * >(key.data()),
                                         reinterpret_cast< std::uint8_t const * >(iv.data())));
    }

    template auto encryption_context::update(net::const_buffer                                          plaintext,
                                             net::dynamic_vector_buffer< char, std::allocator< char > > ciphertext)
        -> void;

    template auto encryption_context::finalise(net::dynamic_vector_buffer< char, std::allocator< char > > ciphertext)
        -> void;

    template auto encryption_context::update(
        net::const_buffer                                                                    plaintext,
        net::dynamic_string_buffer< char, std::char_traits< char >, std::allocator< char > > ciphertext) -> void;

    template auto encryption_context::finalise(
        net::dynamic_string_buffer< char, std::char_traits< char >, std::allocator< char > > ciphertext) -> void;

    // -- decryption_context

    decryption_context::decryption_context(net::const_buffer key, net::const_buffer iv)
    : cipher_context()
    {
        assert(key.size() == 16);
        assert(iv.size() == 16);

        check_success(EVP_DecryptInit_ex(native_handle(),
                                         EVP_aes_128_cfb8(),
                                         nullptr,
                                         reinterpret_cast< std::uint8_t const * >(key.data()),
                                         reinterpret_cast< std::uint8_t const * >(iv.data())));
    }

}   // namespace minecraft::security

namespace minecraft::security
{
    template auto decryption_context::update(net::const_buffer                                          ciphertext,
                                             net::dynamic_vector_buffer< char, std::allocator< char > > plaintext)
        -> void;

    template auto decryption_context::finalise(net::dynamic_vector_buffer< char, std::allocator< char > > plaintext)
        -> void;

    template auto decryption_context::update(
        net::const_buffer                                                                    ciphertext,
        net::dynamic_string_buffer< char, std::char_traits< char >, std::allocator< char > > plaintext) -> void;

    template auto decryption_context::finalise(
        net::dynamic_string_buffer< char, std::char_traits< char >, std::allocator< char > > plaintext) -> void;

}   // namespace minecraft::security
