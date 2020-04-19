namespace minecraft::security
{

    // -- encryption_context

    template < class CipherDynamicBuffer >
    auto encryption_context::update(net::const_buffer plaintext, CipherDynamicBuffer ciphertext) -> void
    {
        static_assert(net::is_dynamic_buffer_v2< CipherDynamicBuffer >::value);
        static_assert(std::is_same_v< typename CipherDynamicBuffer::mutable_buffers_type, net::mutable_buffer >);

        auto input_size = plaintext.size();
        if (input_size == 0)
            return;

        auto block_size = EVP_CIPHER_CTX_block_size(native_handle());
        auto grow_size  = input_size + block_size - 1;

        auto original_output_size = ciphertext.size();
        ciphertext.grow(grow_size);

        net::mutable_buffer out_buf = ciphertext.data(original_output_size, ciphertext.size());

        int outl = 0;
        check_success(EVP_EncryptUpdate(native_handle(),
                                        reinterpret_cast< std::uint8_t * >(out_buf.data()),
                                        &outl,
                                        reinterpret_cast< std::uint8_t const * >(plaintext.data()),
                                        plaintext.size()));
        ciphertext.shrink(grow_size - outl);
    }

    template < class CipherDynamicBuffer >
    auto encryption_context::finalise(CipherDynamicBuffer ciphertext) -> void
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



    // -- decryption_context

    template < class PlaintextDynamicBuffer >
    auto decryption_context::update(net::const_buffer ciphertext, PlaintextDynamicBuffer plaintext) -> void
    {
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

        int outl = 0;
        check_success(EVP_DecryptUpdate(native_handle(),
                                        reinterpret_cast< std::uint8_t * >(out_buf.data()),
                                        &outl,
                                        reinterpret_cast< std::uint8_t const * >(ciphertext.data()),
                                        ciphertext.size()));
        plaintext.shrink(grow_size - outl);
    }

    template < class PlaintextDynamicBuffer >
    auto decryption_context::finalise(PlaintextDynamicBuffer plaintext) -> void
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

}