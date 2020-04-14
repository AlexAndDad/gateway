//
// Created by rhodges on 14/04/2020.
//

#pragma once

#include "minecraft/net.hpp"
#include "minecraft/security/error.hpp"

#include <openssl/aes.h>
#include <openssl/evp.h>
#include <wise_enum/wise_enum.h>

namespace minecraft::security
{
    inline auto check_success(EVP_CIPHER_CTX *p) -> EVP_CIPHER_CTX *
    {
        if (not p)
            throw_error();
        return p;
    }

    struct cipher_context
    {
        using native_handle_type = EVP_CIPHER_CTX *;

      protected:
        cipher_context()
            : handle_(check_success(EVP_CIPHER_CTX_new()))
        {
        }

      public:
        cipher_context(cipher_context &&other) noexcept
        : handle_(other.release())
        {
        }

        cipher_context &operator=(cipher_context &&other) noexcept
        {
            destroy(handle_);
            handle_ = other.release();
            return *this;
        }

        ~cipher_context() { destroy(handle_); }

        native_handle_type release() noexcept { return std::exchange(handle_, nullptr); }
        native_handle_type native_handle() noexcept { return handle_; }

      private:
        static void destroy(native_handle_type handle)
        {
            if (handle)
                EVP_CIPHER_CTX_cleanup(handle);
            EVP_CIPHER_CTX_free(handle);
        }

      private:
        native_handle_type handle_;

    };

    struct encryption_context : cipher_context
    {
        encryption_context(net::const_buffer key, net::const_buffer iv)
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

        template < class PlaintextDynamicBuffer, class CipherDynamicBuffer >
        auto update(PlaintextDynamicBuffer plaintext, CipherDynamicBuffer ciphertext) -> void
        {
            static_assert(net::is_dynamic_buffer_v2< CipherDynamicBuffer >::value);
            static_assert(std::is_same_v< typename CipherDynamicBuffer::mutable_buffers_type, net::mutable_buffer >);
            static_assert(net::is_dynamic_buffer_v2< PlaintextDynamicBuffer >::value);
            static_assert(std::is_same_v< typename PlaintextDynamicBuffer::const_buffers_type, net::const_buffer >);

            auto input_size = plaintext.size();
            if (input_size == 0)
                return;

            auto block_size = EVP_CIPHER_CTX_block_size(native_handle());
            auto grow_size  = input_size + block_size - 1;

            auto original_output_size = ciphertext.size();
            ciphertext.grow(grow_size);

            net::mutable_buffer out_buf = ciphertext.data(original_output_size, ciphertext.size());
            net::const_buffer   in_buf  = plaintext.data(0, plaintext.size());

            int outl = 0;
            check_success(EVP_EncryptUpdate(native_handle(),
                                            reinterpret_cast< std::uint8_t * >(out_buf.data()),
                                            &outl,
                                            reinterpret_cast< std::uint8_t const * >(in_buf.data()),
                                            in_buf.size()));
            ciphertext.shrink(grow_size - outl);
            plaintext.consume(plaintext.size());
        }

        template < class CipherDynamicBuffer >
        auto finalise(CipherDynamicBuffer ciphertext) -> void
        {
            static_assert(net::is_dynamic_buffer_v2< CipherDynamicBuffer >::value);
            static_assert(std::is_same_v< typename CipherDynamicBuffer::mutable_buffers_type, net::mutable_buffer >);

            auto block_size = EVP_CIPHER_CTX_block_size(native_handle());
            auto grow_size  = block_size - 1;

            auto original_output_size = ciphertext.size();
            ciphertext.grow(grow_size);

            net::mutable_buffer out_buf = ciphertext.data(original_output_size, ciphertext.size());

            int outl = 0;
            check_success(EVP_EncryptFinal(native_handle(),
                                           reinterpret_cast< std::uint8_t * >(out_buf.data()),
                                           &outl));
            ciphertext.shrink(grow_size - outl);
        }
    };

    struct decryption_context : cipher_context
    {
        decryption_context(net::const_buffer key, net::const_buffer iv)
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

        template < class CipherDynamicBuffer, class PlaintextDynamicBuffer >
        auto update(CipherDynamicBuffer ciphertext, PlaintextDynamicBuffer plaintext) -> void
        {
            static_assert(net::is_dynamic_buffer_v2< CipherDynamicBuffer >::value);
            static_assert(std::is_same_v< typename CipherDynamicBuffer::const_buffers_type, net::const_buffer >);
            static_assert(net::is_dynamic_buffer_v2< PlaintextDynamicBuffer >::value);
            static_assert(std::is_same_v< typename PlaintextDynamicBuffer::mutable_buffers_type, net::mutable_buffer >);

            auto input_size = ciphertext.size();
            if (input_size == 0)
                return;

            auto block_size = EVP_CIPHER_CTX_block_size(native_handle());
            auto grow_size  = input_size + block_size - 1;

            auto original_output_size = plaintext.size();
            plaintext.grow(grow_size);

            net::mutable_buffer out_buf = plaintext.data(original_output_size, plaintext.size());
            net::const_buffer   in_buf  = ciphertext.data(0, ciphertext.size());

            int outl = 0;
            check_success(EVP_DecryptUpdate(native_handle(),
                                            reinterpret_cast< std::uint8_t * >(out_buf.data()),
                                            &outl,
                                            reinterpret_cast< std::uint8_t const * >(in_buf.data()),
                                            in_buf.size()));
            plaintext.shrink(grow_size - outl);
            ciphertext.consume(ciphertext.size());
        }

        template < class PlaintextDynamicBuffer >
        auto finalise(PlaintextDynamicBuffer plaintext) -> void
        {
            static_assert(net::is_dynamic_buffer_v2< PlaintextDynamicBuffer >::value);
            static_assert(std::is_same_v< typename PlaintextDynamicBuffer::mutable_buffers_type, net::mutable_buffer >);

            auto block_size = EVP_CIPHER_CTX_block_size(native_handle());
            auto grow_size  = block_size - 1;

            auto original_output_size = plaintext.size();
            plaintext.grow(grow_size);

            net::mutable_buffer out_buf = plaintext.data(original_output_size, plaintext.size());

            int outl = 0;
            check_success(EVP_DecryptFinal(native_handle(),
                                           reinterpret_cast< std::uint8_t * >(out_buf.data()),
                                           &outl));
            plaintext.shrink(grow_size - outl);
        }
    };

}   // namespace minecraft::security
