//
// Created by rhodges on 12/04/2020.
//

#include "encryption_response.hpp"

#include "minecraft/hexdump.hpp"

#include <openssl/rsa.h>

namespace minecraft::packets::client
{
    auto operator<<(std::ostream &os, encryption_response const &arg) -> std::ostream &
    {
        os << "client::encryption_response"
              " : shared_secret="
           << hexstring(arg.shared_secret) << " : verify_token=" << hexstring(arg.verify_token);
        return os;
    }

    auto report_on(std::ostream &os, encryption_response const &arg) -> void { os << arg; }

    protocol::shared_secret
    encryption_response::decrypt_secret(minecraft::security::private_key const &server_key,
                                        std::vector< std::uint8_t > const &     original_verify_token,
                                        error_code &                            ec) const
    {
        auto result = protocol::shared_secret();
        static thread_local auto output = std::vector< std::uint8_t >();
        output.clear();
        ec.clear();
        try
        {
            auto rsa = EVP_PKEY_get0_RSA(server_key.native_handle());
            if (!rsa)
                throw error_code(error::not_rsa_key);
            output.resize(RSA_size(rsa));
            auto outsize =
                RSA_private_decrypt(verify_token.size(), verify_token.data(), output.data(), rsa, RSA_PKCS1_PADDING);
            if (outsize < 0)
                throw error_code(error::decryption_failure);
            output.resize(outsize);

            if (output != original_verify_token)
                throw error_code(error::shared_secret_failure);

            output.resize(RSA_size(rsa));
            outsize =
                RSA_private_decrypt(shared_secret.size(), shared_secret.data(), output.data(), rsa, RSA_PKCS1_PADDING);
            if (outsize < 0)
                throw error_code(error::decryption_failure);
            output.resize(outsize);

            auto iter = output.begin();
            parse(iter, output.end(), result, ec);
        }
        catch (error_code& err)
        {
            ec = err;
        }

        return result;
    }

}   // namespace minecraft::packets::client
